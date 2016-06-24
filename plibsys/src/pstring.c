/*
 * Copyright (C) 2011-2016 Alexander Saprykin <xelfium@gmail.com>
 * Copyright (C) 2009 Tom Van Baak (tvb) www.LeapSecond.com
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

#include "pmem.h"
#include "pstring.h"

#include <string.h>
#include <ctype.h>

#define P_STR_MAX_EXPON		308

P_LIB_API pchar *
p_strdup (const pchar *str)
{
	pchar	*ret;
	psize	len;

	if (P_UNLIKELY (str == NULL))
		return NULL;

	len = strlen (str) + 1;

	if (P_UNLIKELY ((ret = p_malloc (len)) == NULL))
		return NULL;

	memcpy (ret, str, len);

	return ret;
}

P_LIB_API pchar *
p_strchomp (const pchar *str)
{
	pssize		pos_start, pos_end;
	psize		str_len;
	pchar		*ret;
	const pchar	*ptr;

	if (P_UNLIKELY (str == NULL))
		return NULL;

	ptr       = str;
	pos_start = 0;
	pos_end   = ((pssize) strlen (str)) - 1;

	while (pos_start < pos_end && isspace (* ((const puchar *) ptr++)))
		++pos_start;

	ptr = str + pos_end;

	while (pos_end > 0 && isspace (* ((const puchar *) ptr--)))
		--pos_end;

	if (pos_end < pos_start)
		return p_strdup ("\0");

	if (pos_end == pos_start && isspace (* ((const puchar *) (str + pos_end))))
		return p_strdup ("\0");

	str_len = (psize) (pos_end - pos_start + 2);

	if (P_UNLIKELY ((ret = p_malloc0 (str_len)) == NULL))
		return NULL;

	memcpy (ret, str + pos_start, str_len - 1);
	*(ret + str_len - 1) = '\0';

	return ret;
}

P_LIB_API pchar *
p_strtok (pchar *str, const pchar *delim, pchar **buf)
{
	if (P_UNLIKELY (delim == NULL))
		return str;

#ifdef P_OS_WIN
#  ifdef P_CC_MSVC
	if (P_UNLIKELY (buf == NULL))
		return str;
#    if _MSC_VER < 1400
	P_UNUSED (buf);
	return strtok (str, delim);
#    else
	return strtok_s (str, delim, buf);
#    endif
#  else
	P_UNUSED (buf);
	return strtok (str, delim);
#  endif
#else
	if (P_UNLIKELY (buf == NULL))
		return str;

	return strtok_r (str, delim, buf);
#endif
}

P_LIB_API double
p_strtod (const pchar *str)
{
	double	sign;
	double	value;
	double	scale;
	double	pow10;
	puint	expon;
	pint	frac;
	pchar	*orig_str, *strp;

	orig_str = p_strchomp (str);

	if (P_UNLIKELY (orig_str == NULL))
		return 0.0;

	strp = orig_str;
	sign = 1.0;

	if (*strp == '-') {
		sign = -1.0;
		strp += 1;
	} else if (*strp == '+')
		strp += 1;

	/* Get digits before decimal point or exponent, if any */
	for (value = 0.0; isdigit ((pint) *strp); strp += 1)
		value = value * 10.0 + (*strp - '0');

	/* Get digits after decimal point, if any */
	if (*strp == '.') {
		pow10 = 10.0;
		strp += 1;

		while (isdigit ((pint) *strp)) {
			value += (*strp - '0') / pow10;
			pow10 *= 10.0;
			strp += 1;
		}
	}

	/* Handle exponent, if any */
	frac  = 0;
	scale = 1.0;

	if ((*strp == 'e') || (*strp == 'E')) {
		/* Get sign of exponent, if any */
		strp += 1;

		if (*strp == '-') {
			frac = 1;
			strp += 1;

		} else if (*strp == '+')
			strp += 1;

		/* Get digits of exponent, if any */
		for (expon = 0; isdigit ((pint) *strp); strp += 1)
			expon = expon * 10 + (puint) ((*strp - '0'));

		if (P_UNLIKELY (expon > P_STR_MAX_EXPON))
			expon = P_STR_MAX_EXPON;

		/* Calculate scaling factor */
		while (expon >= 50) {
			scale *= 1e50;
			expon -= 50;
		}

		while (expon >= 8) {
			scale *= 1e8;
			expon -= 8;
		}

		while (expon > 0) {
			scale *= 10.0;
			expon -= 1;
		}
	}

	p_free (orig_str);

	/* Return signed and scaled floating point result */
	return sign * (frac ? (value / scale) : (value * scale));
}
