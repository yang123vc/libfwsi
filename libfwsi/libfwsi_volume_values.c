/*
 * Volume (shell item) values functions
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
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libuna.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_volume_values.h"

/* Creates volume values
 * Make sure the value volume_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_volume_values_initialize(
     libfwsi_volume_values_t **volume_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_volume_values_initialize";

	if( volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume values.",
		 function );

		return( -1 );
	}
	if( *volume_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid volume values value already set.",
		 function );

		return( -1 );
	}
	*volume_values = memory_allocate_structure(
	                  libfwsi_volume_values_t );

	if( *volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create volume values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *volume_values,
	     0,
	     sizeof( libfwsi_volume_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear volume values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *volume_values != NULL )
	{
		memory_free(
		 *volume_values );

		*volume_values = NULL;
	}
	return( -1 );
}

/* Frees volume values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_volume_values_free(
     libfwsi_volume_values_t **volume_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_volume_values_free";

	if( volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume values.",
		 function );

		return( -1 );
	}
	if( *volume_values != NULL )
	{
		memory_free(
		 *volume_values );

		*volume_values = NULL;
	}
	return( 1 );
}

/* Reads the volume values
 * Returns the number of bytes read, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_volume_values_read(
         libfwsi_volume_values_t *volume_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         int ascii_codepage,
         libcerror_error_t **error )
{
	static char *function         = "libfwsi_volume_values_read";
	size_t shell_item_data_offset = 0;
	size_t string_size            = 0;
	uint8_t class_type_indicator  = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint16_t value_16bit          = 0;
#endif

	if( volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume values.",
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
	if( shell_item_data_size < 20 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( ( shell_item_data[ 2 ] != 0x23 )
	 && ( shell_item_data[ 2 ] != 0x25 )
	 && ( shell_item_data[ 2 ] != 0x29 )
	 && ( shell_item_data[ 2 ] != 0x2a )
	 && ( shell_item_data[ 2 ] != 0x2e )
	 && ( shell_item_data[ 2 ] != 0x2f ) )
	{
		return( 0 );
	}
	class_type_indicator = shell_item_data[ 2 ];

	volume_values->ascii_codepage = ascii_codepage;

	if( class_type_indicator == 0x2e )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t\t: 0x%02" PRIx8 "\n",
			 function,
			 shell_item_data[ 3 ] );
		}
#endif
		volume_values->has_name = 0;

		if( memory_copy(
		     volume_values->identifier,
		     &( shell_item_data[ 4 ] ),
		     16 ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy volume identifier.",
			 function );

			return( -1 );
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_guid_value(
			     function,
			     "shell folder identifier\t\t\t",
			     volume_values->identifier,
			     16,
			     LIBFGUID_ENDIAN_LITTLE,
			     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print GUID value.",
				 function );

				return( -1 );
			}
			libcnotify_printf(
			 "%s: shell folder name\t\t\t\t: %s\n",
			 function,
			 libfwsi_shell_folder_identifier_get_name(
			  volume_values->identifier ) );
		}
#endif
		shell_item_data_offset = 20;
	}
	else
	{
		/* Do not try to parse unsupported shell item data sizes
		 */
		if( shell_item_data_size < 25 )
		{
			return( 0 );
		}
		volume_values->has_name = 1;

		if( memory_copy(
		     volume_values->name,
		     &( shell_item_data[ 3 ] ),
		     20 ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy volume name.",
			 function );

			return( -1 );
		}
		for( string_size = 0;
		     string_size < 20;
		     string_size++ )
		{
			if( volume_values->name[ string_size ] == 0 )
			{
				break;
			}
		}
		volume_values->name_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "volume name\t\t\t\t\t",
			     volume_values->name,
			     volume_values->name_size,
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
#endif
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( shell_item_data[ 23 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );
		}
#endif
		shell_item_data_offset = 25;

		if( shell_item_data_offset <= ( shell_item_data_size - 16 ) )
		{
			if( memory_copy(
			     volume_values->shell_folder_identifier,
			     &( shell_item_data[ shell_item_data_offset ] ),
			     16 ) == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
				 "%s: unable to copy shell folder identifier.",
				 function );

				return( -1 );
			}
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				if( libfwsi_debug_print_guid_value(
				     function,
				     "shell folder identifier\t\t\t",
				     volume_values->shell_folder_identifier,
				     16,
				     LIBFGUID_ENDIAN_LITTLE,
				     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
					 "%s: unable to print GUID value.",
					 function );

					return( -1 );
				}
				libcnotify_printf(
				 "%s: shell folder name\t\t\t\t: %s\n",
				 function,
				 libfwsi_shell_folder_identifier_get_name(
				  &( shell_item_data[ shell_item_data_offset ] ) ) );
			}
#endif
			shell_item_data_offset += 16;
		}
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

