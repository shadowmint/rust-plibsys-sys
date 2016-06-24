/*
 * Copyright (C) 2015-2016 Alexander Saprykin <xelfium@gmail.com>
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

/**
 * @file plibraryloader.h
 * @brief Shared library loader
 * @author Alexander Saprykin
 *
 * All modern operating systems support dynamic loadable objects. Such objects
 * are compiled with special flags and can be loaded by other programs and
 * libraries later at the runtime. These loadable objects often called as the
 * shared libraries, though some platforms even allow to treat the program
 * binary as a loadable object, too.
 *
 * When the program is linked with a shared library its dependency would be
 * resolved by the operating system automatically before starting the program.
 * But in some circumstances you may need to load a shared library object
 * explicitly (i.e. implementing a plugin subsystem, checking for API
 * availability).
 *
 * All functions and variables which a shared library is exporting are called
 * symbols. Usually only the exported symbols are available from outside the
 * shared library. Actually all those symbols represent a library API.
 *
 * Use p_library_loader_new() to load a shared library and
 * p_library_loader_get_symbol() to retrieve a pointer to a symbol within it.
 * Close the library after usage with p_library_loader_free().
 */

#if !defined (PLIBSYS_H_INSIDE) && !defined (PLIBSYS_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plibsys.h> instead."
#endif

#ifndef PLIBSYS_HEADER_PLIBRARYLOADER_H
#define PLIBSYS_HEADER_PLIBRARYLOADER_H

#include "pmacros.h"
#include "ptypes.h"

P_BEGIN_DECLS

/** Opaque data structure to handle a shared library. */
typedef struct PLibraryLoader_ PLibraryLoader;

/** Pointer to a function address. */
typedef void (*PFuncAddr) (void);

/**
 * @brief Loads a shared library.
 * @param path Path to the shared library file.
 * @return Pointer to #PLibraryLoader in case of success, NULL otherwise.
 * @since 0.0.1
 *
 * If you are loading the already loaded shared library, an operating system
 * increments corresponding reference count and decrements it after freeing
 * #PLibraryLoader, thus the shared library would be unloaded from the address
 * space only when the counter becomes zero.
 */
P_LIB_API PLibraryLoader *	p_library_loader_new		(const pchar	*path);

/**
 * @brief Gets a pointer to a symbol in the loaded shared library.
 * @param loader Pointer to the loaded shared library handle.
 * @param sym Name of the symbol.
 * @return Pointer to the symbol in case of success, NULL otherwise.
 * @since 0.0.1
 *
 * Since the symbol may have a NULL value, the returned NULL value from this
 * call actually doesn't mean the failed result. You can additionally check the
 * error result using p_library_loader_get_last_error().
 */
P_LIB_API PFuncAddr		p_library_loader_get_symbol	(PLibraryLoader	*loader,
								 const pchar	*sym);

/**
 * @brief Frees memory and allocated resources of #PLibraryLoader.
 * @param loader #PLibraryLoader object to free.
 * @since 0.0.1
 */
P_LIB_API void			p_library_loader_free		(PLibraryLoader	*loader);

/**
 * @brief Gets the last occurred error.
 * @return Human readable error string in case of success, NULL otherwise.
 * @since 0.0.1
 * @note Caller takes ownership of the returned string.
 *
 * The NULL result may indicate that no error was occurred since the last call.
 *
 * Different operating systems have different behavior on error indicating.
 * Some systems reset an error status before the call, some do not. Some
 * systems write the successful call result (usually zero) to the error status,
 * thus resetting an error from the previous call.
 */
P_LIB_API pchar *		p_library_loader_get_last_error	(void);

P_END_DECLS

#endif /* PLIBSYS_HEADER_PLIBRARYLOADER_H */
