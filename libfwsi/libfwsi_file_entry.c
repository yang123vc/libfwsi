/*
 * File entry (shell item) functions
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#include "libfwsi_codepage.h"
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_file_entry.h"
#include "libfwsi_file_entry_values.h"
#include "libfwsi_item.h"
#include "libfwsi_libuna.h"

/* Retrieves the file size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_file_size(
     libfwsi_item_t *item,
     uint32_t *file_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_file_size";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file size.",
		 function );

		return( -1 );
	}
	*file_size = file_entry_values->file_size;

	return( 1 );
}

/* Retrieves the modification time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_modification_time(
     libfwsi_item_t *item,
     uint32_t *modification_time,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_modification_time";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( modification_time == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid modification time.",
		 function );

		return( -1 );
	}
	*modification_time = file_entry_values->modification_time;

	return( 1 );
}

/* Retrieves the file attribute flags
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_file_attribute_flags(
     libfwsi_item_t *item,
     uint32_t *file_attribute_flags,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_file_attribute_flags";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_attribute_flags == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file attribute flags.",
		 function );

		return( -1 );
	}
	*file_attribute_flags = file_entry_values->file_attribute_flags;

	return( 1 );
}

/* Retrieves the size of the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_utf8_name_size(
     libfwsi_item_t *item,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_utf8_name_size";
	int result                                     = 0;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_entry_values->is_unicode != 0 )
	{
		result = libuna_utf8_string_size_from_utf16_stream(
			  file_entry_values->name,
			  file_entry_values->name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  utf8_string_size,
			  error );
	}
	else
	{
		result = libuna_utf8_string_size_from_byte_stream(
			  file_entry_values->name,
			  file_entry_values->name_size,
		          internal_item->ascii_codepage,
			  utf8_string_size,
			  error );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_utf8_name(
     libfwsi_item_t *item,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_utf8_name";
	int result                                     = 0;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_entry_values->is_unicode != 0 )
	{
		result = libuna_utf8_string_copy_from_utf16_stream(
		          utf8_string,
		          utf8_string_size,
			  file_entry_values->name,
			  file_entry_values->name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
	}
	else
	{
		result = libuna_utf8_string_copy_from_byte_stream(
		          utf8_string,
		          utf8_string_size,
			  file_entry_values->name,
			  file_entry_values->name_size,
		          internal_item->ascii_codepage,
			  error );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_utf16_name_size(
     libfwsi_item_t *item,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_utf16_name_size";
	int result                                     = 0;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_entry_values->is_unicode != 0 )
	{
		result = libuna_utf16_string_size_from_utf16_stream(
			  file_entry_values->name,
			  file_entry_values->name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  utf16_string_size,
			  error );
	}
	else
	{
		result = libuna_utf16_string_size_from_byte_stream(
			  file_entry_values->name,
			  file_entry_values->name_size,
		          internal_item->ascii_codepage,
			  utf16_string_size,
			  error );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_get_utf16_name(
     libfwsi_item_t *item,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item         = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	static char *function                          = "libfwsi_file_entry_get_utf16_name";
	int result                                     = 0;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( ( internal_item->class_type & 0x70 ) != LIBFWSI_CLASS_TYPE_FILE_ENTRY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item - missing value.",
		 function );

		return( -1 );
	}
	file_entry_values = (libfwsi_file_entry_values_t *) internal_item->value;

	if( file_entry_values->is_unicode != 0 )
	{
		result = libuna_utf16_string_copy_from_utf16_stream(
		          utf16_string,
		          utf16_string_size,
			  file_entry_values->name,
			  file_entry_values->name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
	}
	else
	{
		result = libuna_utf16_string_copy_from_byte_stream(
		          utf16_string,
		          utf16_string_size,
			  file_entry_values->name,
			  file_entry_values->name_size,
		          internal_item->ascii_codepage,
			  error );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

