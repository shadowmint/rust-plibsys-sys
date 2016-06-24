/*
 * Copyright (C) 2013-2016 Alexander Saprykin <xelfium@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLIBSYS_TESTS_STATIC
#  define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MODULE pinifile_test

#include "plibsys.h"

#include <stdio.h>
#include <float.h>

#ifdef PLIBSYS_TESTS_STATIC
#  include <boost/test/included/unit_test.hpp>
#else
#  include <boost/test/unit_test.hpp>
#endif

#include <boost/test/floating_point_comparison.hpp>

#define PINIFILE_STRESS_LINE	2048
#define PINIFILE_MAX_LINE	1024

extern "C" ppointer pmem_alloc (psize nbytes)
{
	P_UNUSED (nbytes);
	return (ppointer) NULL;
}

extern "C" ppointer pmem_realloc (ppointer block, psize nbytes)
{
	P_UNUSED (block);
	P_UNUSED (nbytes);
	return (ppointer) NULL;
}

extern "C" void pmem_free (ppointer block)
{
	P_UNUSED (block);
}

static bool create_test_ini_file (bool last_empty_section)
{
	FILE *file = fopen ("." P_DIR_SEPARATOR "p_ini_test_file.ini", "w");

	if (file == NULL)
		return false;

	pchar *buf = (pchar *) p_malloc0 (PINIFILE_STRESS_LINE + 1);

	for (int i = 0; i < PINIFILE_STRESS_LINE; ++i)
		buf[i] = (pchar) (97 + i % 20);

	/* Empty section */
	fprintf (file, "[empty_section]\n");

	/* Numeric section */
	fprintf (file, "[numeric_section]\n");
	fprintf (file, "int_parameter_1 = 4\n");
	fprintf (file, "int_parameter_2 = 5 ;This is a comment\n");
	fprintf (file, "int_parameter_3 = 6 #This is another type of a comment\n");
	fprintf (file, "# Whole line is a comment\n");
	fprintf (file, "; Yet another comment line\n");
	fprintf (file, "float_parameter_1 = 3.24\n");
	fprintf (file, "float_parameter_2 = 0.15\n");

	/* String section */
	fprintf (file, "[string_section]\n");
	fprintf (file, "string_parameter_1 = Test string\n");
	fprintf (file, "string_parameter_2 = \"Test string with #'\"\n");
	fprintf (file, "string_parameter_3 = \n");
	fprintf (file, "string_parameter_4 = 12345 ;Comment\n");
	fprintf (file, "string_parameter_4 = 54321\n");
	fprintf (file, "string_parameter_5 = 'Test string'\n");
	fprintf (file, "string_parameter_6 = %s\n", buf);
	fprintf (file, "string_parameter_7 = ''\n");
	fprintf (file, "string_parameter_8 = \"\"\n");
	fprintf (file, "%s = stress line\n", buf);

	/* Boolean section */
	fprintf (file, "[boolean_section]\n");
	fprintf (file, "boolean_parameter_1 = TRUE ;True value\n");
	fprintf (file, "boolean_parameter_2 = 0 ;False value\n");
	fprintf (file, "boolean_parameter_3 = false ;False value\n");
	fprintf (file, "boolean_parameter_4 = 1 ;True value\n");

	/* List section */
	fprintf (file, "[list_section]\n");
	fprintf (file, "list_parameter_1 = {1\t2\t5\t10} ;First list\n");
	fprintf (file, "list_parameter_2 = {2.0 3.0 5.0} #Second list\n");
	fprintf (file, "list_parameter_3 = {true FALSE 1} #Last list\n");

	/* Empty section */
	if (last_empty_section)
		fprintf (file, "[empty_section_2]\n");

	p_free (buf);

	return fclose (file) == 0;
}

BOOST_AUTO_TEST_SUITE (BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE (pinifile_nomem_test)
{
	p_libsys_init ();

	BOOST_REQUIRE (create_test_ini_file (false));

	PIniFile *ini = p_ini_file_new  ("." P_DIR_SEPARATOR "p_ini_test_file.ini");
	BOOST_CHECK (ini != NULL);

	PMemVTable vtable;

	vtable.free    = pmem_free;
	vtable.malloc  = pmem_alloc;
	vtable.realloc = pmem_realloc;

	BOOST_CHECK (p_mem_set_vtable (&vtable) == TRUE);

	BOOST_CHECK (p_ini_file_new ("." P_DIR_SEPARATOR "p_ini_test_file.ini") == NULL);
	BOOST_CHECK (p_ini_file_parse (ini, NULL) == TRUE);
	BOOST_CHECK (p_ini_file_sections (ini) == NULL);

	p_mem_restore_vtable ();

	p_ini_file_free (ini);

	ini = p_ini_file_new ("." P_DIR_SEPARATOR "p_ini_test_file.ini");
	BOOST_CHECK (ini != NULL);

	BOOST_CHECK (p_ini_file_parse (ini, NULL) == TRUE);
	PList *section_list = p_ini_file_sections (ini);
	BOOST_CHECK (section_list != NULL);
	BOOST_CHECK (p_list_length (section_list) == 4);

	p_list_foreach (section_list, (PFunc) p_free, NULL);
	p_list_free (section_list);
	p_ini_file_free (ini);

	BOOST_CHECK (p_file_remove ("." P_DIR_SEPARATOR "p_ini_test_file.ini", NULL) == TRUE);

	p_libsys_shutdown ();
}

BOOST_AUTO_TEST_CASE (pinifile_bad_input_test)
{
	PIniFile *ini = NULL;

	p_libsys_init ();

	p_ini_file_free (ini);
	BOOST_CHECK (p_ini_file_new (NULL) == NULL);
	BOOST_CHECK (p_ini_file_parse (ini, NULL) == FALSE);
	BOOST_CHECK (p_ini_file_is_parsed (ini) == FALSE);
	BOOST_CHECK (p_ini_file_is_key_exists (ini, "string_section", "string_paramter_1") == FALSE);
	BOOST_CHECK (p_ini_file_sections (ini) == NULL);
	BOOST_CHECK (p_ini_file_keys (ini, "string_section") == NULL);
	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_parameter_1", FALSE) == FALSE);
	BOOST_CHECK_CLOSE (p_ini_file_parameter_double (ini, "numeric_section", "float_parameter_1", 1.0), 1.0, 0.0001);
	BOOST_CHECK (p_ini_file_parameter_int (ini, "numeric_section", "int_parameter_1", 0) == 0);
	BOOST_CHECK (p_ini_file_parameter_list (ini, "list_section", "list_parameter_1") == NULL);
	BOOST_CHECK (p_ini_file_parameter_string (ini, "string_section", "string_parameter_1", NULL) == NULL);

	ini = p_ini_file_new ("./bad_file_path/fake.ini");
	BOOST_CHECK (ini != NULL);
	BOOST_CHECK (p_ini_file_parse (ini, NULL) == FALSE);
	p_ini_file_free (ini);

	BOOST_REQUIRE (create_test_ini_file (true));

	p_libsys_shutdown ();
}

BOOST_AUTO_TEST_CASE (pinifile_read_test)
{
	p_libsys_init ();

	PIniFile *ini = p_ini_file_new ("." P_DIR_SEPARATOR "p_ini_test_file.ini");
	BOOST_REQUIRE (ini != NULL);
	BOOST_CHECK (p_ini_file_is_parsed (ini) == FALSE);

	BOOST_REQUIRE (p_ini_file_parse (ini, NULL) == TRUE);
	BOOST_CHECK (p_ini_file_is_parsed (ini) == TRUE);
	BOOST_REQUIRE (p_ini_file_parse (ini, NULL) == TRUE);
	BOOST_CHECK (p_ini_file_is_parsed (ini) == TRUE);

	/* Test list of sections */
	PList *list = p_ini_file_sections (ini);
	BOOST_CHECK (list != NULL);
	BOOST_CHECK (p_list_length (list) == 4);

	p_list_foreach (list, (PFunc) p_free, NULL);
	p_list_free (list);

	/* Test empty section */
	list = p_ini_file_keys (ini, "empty_section");
	BOOST_CHECK (list == NULL);

	/* Test numeric section */
	list = p_ini_file_keys (ini, "numeric_section");
	BOOST_CHECK (p_list_length (list) == 5);
	p_list_foreach (list, (PFunc) p_free, NULL);
	p_list_free (list);

	BOOST_CHECK (p_ini_file_parameter_list (ini, "numeric_section", "int_parameter_1") == NULL);
	BOOST_CHECK (p_ini_file_parameter_int (ini, "numeric_section", "int_parameter_1", -1) == 4);
	BOOST_CHECK (p_ini_file_parameter_int (ini, "numeric_section", "int_parameter_2", -1) == 5);
	BOOST_CHECK (p_ini_file_parameter_int (ini, "numeric_section", "int_parameter_3", -1) == 6);
	BOOST_CHECK (p_ini_file_parameter_int (ini, "numeric_section", "int_parameter_def", 10) == 10);
	BOOST_CHECK_CLOSE (p_ini_file_parameter_double (ini, "numeric_section", "float_parameter_1", -1.0), 3.24, 0.0001);
	BOOST_CHECK_CLOSE (p_ini_file_parameter_double (ini, "numeric_section", "float_parameter_2", -1.0), 0.15, 0.0001);
	BOOST_CHECK_CLOSE (p_ini_file_parameter_double (ini, "numeric_section_no", "float_parameter_def", 10.0), 10.0, 0.0001);
	BOOST_CHECK (p_ini_file_is_key_exists (ini, "numeric_section", "int_parameter_1") == TRUE);
	BOOST_CHECK (p_ini_file_is_key_exists (ini, "numeric_section", "float_parameter_1") == TRUE);
	BOOST_CHECK (p_ini_file_is_key_exists (ini, "numeric_section_false", "float_parameter_1") == FALSE);

	/* Test string section */
	list = p_ini_file_keys (ini, "string_section");
	BOOST_CHECK (p_list_length (list) == 8);
	p_list_foreach (list, (PFunc) p_free, NULL);
	p_list_free (list);

	pchar *str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_1", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "Test string") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_2", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "Test string with #'") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_3", NULL);
	BOOST_REQUIRE (str == NULL);
	BOOST_CHECK (p_ini_file_is_key_exists (ini, "string_section", "string_parameter_3") == FALSE);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_4", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "54321") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_5", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "Test string") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_6", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strlen (str) > 0 && strlen (str) < PINIFILE_MAX_LINE);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_7", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_8", NULL);
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "") == 0);
	p_free (str);

	str = p_ini_file_parameter_string (ini, "string_section", "string_parameter_def", "default_value");
	BOOST_REQUIRE (str != NULL);
	BOOST_CHECK (strcmp (str, "default_value") == 0);
	p_free (str);

	/* Test boolean section */
	list = p_ini_file_keys (ini, "boolean_section");
	BOOST_CHECK (p_list_length (list) == 4);
	p_list_foreach (list, (PFunc) p_free, NULL);
	p_list_free (list);

	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_parameter_1", FALSE) == TRUE);
	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_parameter_2", TRUE) == FALSE);
	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_parameter_3", TRUE) == FALSE);
	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_parameter_4", FALSE) == TRUE);
	BOOST_CHECK (p_ini_file_parameter_boolean (ini, "boolean_section", "boolean_section_def", TRUE) == TRUE);

	/* Test list section */
	list = p_ini_file_keys (ini, "list_section");
	BOOST_CHECK (p_list_length (list) == 3);
	p_list_foreach (list, (PFunc) p_free, NULL);
	p_list_free (list);

	/* -- First list parameter */
	PList *list_val = p_ini_file_parameter_list (ini, "list_section", "list_parameter_1");
	BOOST_CHECK (list_val != NULL);
	BOOST_CHECK (p_list_length (list_val) == 4);

	pint int_sum = 0;
	for (PList *iter = list_val; iter != NULL; iter = iter->next)
		int_sum +=  atoi ((const pchar *) (iter->data));

	BOOST_CHECK (int_sum == 18);
	p_list_foreach (list_val, (PFunc) p_free, NULL);
	p_list_free (list_val);

	/* -- Second list parameter */
	list_val = p_ini_file_parameter_list (ini, "list_section", "list_parameter_2");
	BOOST_CHECK (list_val != NULL);
	BOOST_CHECK (p_list_length (list_val) == 3);

	double flt_sum = 0;
	for (PList *iter = list_val; iter != NULL; iter = iter->next)
		flt_sum +=  atof ((const pchar *) (iter->data));

	BOOST_CHECK_CLOSE (flt_sum, 10.0, 0.0001);
	p_list_foreach (list_val, (PFunc) p_free, NULL);
	p_list_free (list_val);

	/* -- Third list parameter */
	list_val = p_ini_file_parameter_list (ini, "list_section", "list_parameter_3");
	BOOST_CHECK (list_val != NULL);
	BOOST_CHECK (p_list_length (list_val) == 3);

	pboolean bool_sum = TRUE;
	for (PList *iter = list_val; iter != NULL; iter = iter->next)
		bool_sum = bool_sum && atoi ((const pchar *) (iter->data));

	BOOST_CHECK (bool_sum == FALSE);
	p_list_foreach (list_val, (PFunc) p_free, NULL);
	p_list_free (list_val);

	/* -- False list parameter */
	BOOST_CHECK (p_ini_file_parameter_list (ini, "list_section_no", "list_parameter_def") == NULL);

	p_ini_file_free (ini);

	BOOST_CHECK (p_file_remove ("." P_DIR_SEPARATOR "p_ini_test_file.ini", NULL) == TRUE);

	p_libsys_shutdown ();
}

BOOST_AUTO_TEST_SUITE_END()
