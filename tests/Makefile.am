AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCLOCALE_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBCFILE_CPPFLAGS@ \
	@LIBFWSI_DLL_IMPORT@

if HAVE_PYTHON_TESTS
TESTS_PYFWSI =
endif

TESTS = \
	test_api_functions.sh \
	test_api_types.sh \
	$(TESTS_PYFWSI)

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fwsi_test_error \
	fwsi_test_extension_block \
	fwsi_test_item \
	fwsi_test_item_list \
	fwsi_test_item_list_copy_from_byte_stream \
	fwsi_test_support

fwsi_test_error_SOURCES = \
	fwsi_test_error.c \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_unused.h

fwsi_test_error_LDADD = \
	../libfwsi/libfwsi.la

fwsi_test_extension_block_SOURCES = \
	fwsi_test_extension_block.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_item_SOURCES = \
	fwsi_test_item.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_item_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_item_list_SOURCES = \
	fwsi_test_item_list.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_item_list_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_support_SOURCES = \
	fwsi_test_support.c \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_unused.h

fwsi_test_support_LDADD = \
	../libfwsi/libfwsi.la

fwsi_test_item_list_copy_from_byte_stream_SOURCES = \
	fwsi_test_libcfile.h \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_item_list_copy_from_byte_stream.c

fwsi_test_item_list_copy_from_byte_stream_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

