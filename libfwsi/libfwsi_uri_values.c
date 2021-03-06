/*
 * URI (shell item) values functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_debug.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"
#include "libfwsi_uri_values.h"

/* Creates URI values
 * Make sure the value uri_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_uri_values_initialize(
     libfwsi_uri_values_t **uri_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_uri_values_initialize";

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
		 function );

		return( -1 );
	}
	if( *uri_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid URI values value already set.",
		 function );

		return( -1 );
	}
	*uri_values = memory_allocate_structure(
	               libfwsi_uri_values_t );

	if( *uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create URI values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *uri_values,
	     0,
	     sizeof( libfwsi_uri_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear URI values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *uri_values != NULL )
	{
		memory_free(
		 *uri_values );

		*uri_values = NULL;
	}
	return( -1 );
}

/* Frees URI values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_uri_values_free(
     libfwsi_uri_values_t **uri_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_uri_values_free";

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
		 function );

		return( -1 );
	}
	if( *uri_values != NULL )
	{
		memory_free(
		 *uri_values );

		*uri_values = NULL;
	}
	return( 1 );
}

/* Reads the URI values
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_uri_values_read(
         libfwsi_uri_values_t *uri_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         int ascii_codepage,
         libcerror_error_t **error )
{
	static char *function         = "libfwsi_uri_values_read";
	size_t shell_item_data_offset = 0;
	size_t string_size            = 0;
	uint32_t string_data_size     = 0;
	uint16_t data_size            = 0;
	uint8_t flags                 = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit          = 0;
	uint16_t value_16bit          = 0;
#endif

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
		 function );

		return( -1 );
	}
	if( shell_item_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid shell item data.",
		 function );

		return( -1 );
	}
	if( shell_item_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: shell item data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported shell item data sizes
	 */
	if( shell_item_data_size < 6 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( shell_item_data[ 2 ] != 0x61 )
	{
		return( 0 );
	}
	flags = shell_item_data[ 3 ];

	byte_stream_copy_to_uint16_little_endian(
	 &( shell_item_data[ 4 ] ),
	 data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: flags\t\t\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 flags );

		libcnotify_printf(
		 "%s: data size\t\t\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );
	}
#endif
	shell_item_data_offset = 6;

	if( data_size > 0 )
	{
		if( ( data_size < 2 )
		 && ( data_size > ( shell_item_data_size - 6 ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid data size value out of bounds.",
			 function );

			return( -1 );
		}
		data_size -= 2;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: data:\n",
			 function );
			libcnotify_print_data(
			 &( shell_item_data[ 6 ] ),
			 data_size,
			 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
		}
#endif
	}
#if defined( HAVE_DEBUG_OUTPUT )
	else if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	if( data_size >= 40 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 42 ] ),
		 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 6 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 10 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			if( libfwsi_debug_print_filetime_value(
			     function,
			     "unknown3 time\t\t\t\t\t",
			     &( shell_item_data[ 14 ] ),
			     8,
			     LIBFDATETIME_ENDIAN_LITTLE,
			     LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print filetime value.",
				 function );

				return( -1 );
			}
			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 22 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown4\t\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			libcnotify_printf(
			 "%s: unknown5:\n",
			 function );
			libcnotify_print_data(
			 &( shell_item_data[ 26 ] ),
			 12,
			 0 );

			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 38 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			libcnotify_printf(
			 "%s: string1 data size\t\t\t\t: %" PRIu32 "\n",
			 function,
			 string_data_size );
		}
#endif
		shell_item_data_offset += 40;
		data_size              -= 40;
	}
/* TODO complete parsing of the 3 strings */
	if( data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown data:\n",
			 function );
			libcnotify_print_data(
			 &( shell_item_data[ shell_item_data_offset ] ),
			 data_size,
			 0 );
		}
#endif
		shell_item_data_offset += data_size;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ shell_item_data_offset ] ),
		 value_16bit );

		libcnotify_printf(
		 "%s: unknown7\t\t\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );
	}
#endif
	shell_item_data_offset += 2;

	/* Determine the URI size
	 */
	if( ( flags & 0x80 ) != 0 )
	{
		for( string_size = shell_item_data_offset;
		     ( string_size + 1 ) < shell_item_data_size;
		     string_size += 2 )
		{
			if( ( shell_item_data[ string_size ] == 0 )
			 && ( shell_item_data[ string_size + 1 ] == 0 ) )
			{
				string_size += 2;

				break;
			}
		}
		string_size -= shell_item_data_offset;
	}
	else
	{
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size++ )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size++;

				break;
			}
		}
		string_size -= shell_item_data_offset;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( ( flags & 0x80 ) != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "URI\t\t\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
		else
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "URI\t\t\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print string value.",
				 function );

				return( -1 );
			}
		}
	}
#endif
	shell_item_data_offset += string_size;

/* TODO value likely controlled by flags */
	if( shell_item_data_offset < shell_item_data_size )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( shell_item_data[ shell_item_data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown9\t\t\t\t\t: %" PRIu16 "\n",
			 function,
			 value_16bit );
		}
#endif
		shell_item_data_offset += 2;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( (ssize_t) shell_item_data_offset );
}

