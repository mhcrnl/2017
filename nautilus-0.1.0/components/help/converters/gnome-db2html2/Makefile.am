## Process this file with automake to produce Makefile.in.

INCLUDES = 			\
	-I$(includedir)		\
	-I$(top_srcdir)/intl -I$(top_builddir)/intl	\
	$(GNOME_CFLAGS) $(XML_CFLAGS)

LDADD = \
	$(GNOME_LIBS) $(XML_LIBS)

bin_PROGRAMS = gnome-db2html2

gnome_db2html2_SOURCES = \
	gdb3html.c \
	gdb3html.h \
	sect-elements.c \
	sect-elements.h \
	sect-preparse.c \
	sect-preparse.h \
	toc-elements.c \
	toc-elements.h
