lib_LTLIBRARIES = libmyproject02-@API_VERSION@.la

libmyproject02_@API_VERSION@_la_SOURCES = \
	myproject02-version.h \
	myproject02.h \
	$(NULL)

libmyproject02_@API_VERSION@_la_CFLAGS = \
	$(MYPROJECT02_CFLAGS) \
	$(WARN_CFLAGS) \
	$(NULL)

libmyproject02_@API_VERSION@_la_LIBADD = \
	$(MYPROJECT02_LIBS) \
	$(NULL)

libmyproject02_@API_VERSION@_la_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(NULL)

-include $(top_srcdir)/git.mk
