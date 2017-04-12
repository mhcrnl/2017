# Note this is NOT a relocatable thing :)
%define name		nautilus
%define ver		0.1.0
%define RELEASE		prw2
%define rel		%{?CUSTOM_RELEASE} %{!?CUSTOM_RELEASE:%RELEASE}
%define prefix		/usr
%define sysconfdir	/etc

Name:		%name
Summary:	Nautilus is an open-source file manager and graphical shell.
Version: 	%ver
Release: 	%rel
Copyright: 	GPL
Group:		User Interface/Desktop
Source: 	%{name}-%{ver}.tar.gz
URL: 		http://nautilus.eazel.com/
BuildRoot:	/var/tmp/%{name}-%{ver}-root
Docdir: 	%{prefix}/doc
Requires:	glib >= 1.2.8
Requires:	gtk+ >= 1.2.8
Requires:	imlib >= 1.9.8
Requires:	libxml >= 1.8.6
Requires:	w3c-libwww >= 5.2.8
Requires:	gnome-libs >= 1.2.1
Requires:	GConf >= 0.5
Requires:	ORBit >= 0.5.1
Requires:	oaf >= 0.3.0
Requires:	gnome-vfs >= 0.1
Requires:	gtkhtml >= 0.4
Requires:	gdk-pixbuf >= 0.8.0
Requires:	bonobo >= 0.15
Requires:	eog >= 0.3
Requires:	popt >= 1.5

%description
Nautilus is an open-source file manager and graphical shell being
developed by Eazel, Inc. and others. It is part of the GNOME project, and its
source code can be found in the GNOME CVS repository. Nautilus is still in
the early stages of development. It will become an integral part of the
GNOME desktop environment when it is finished.

%package devel
Summary:	Libraries and include files for developing nautilus components
Group:		Development/Libraries
Requires:	%name = %{PACKAGE_VERSION}
Obsoletes:	%{name}-devel

%description devel
This package provides the necessary development libraries and include
files to allow you to develop nautilus components.

%changelog
* Wed Apr 26 2000 Ramiro Estrugo <ramiro@eazel.com>
- created this thing

%prep
%setup

%build
%ifarch alpha
  MYARCH_FLAGS="--host=alpha-redhat-linux"
%endif

LC_ALL=""
LINGUAS=""
LANG=""
export LC_ALL LINGUAS LANG

CFLAGS="$RPM_OPT_FLAGS" ./configure $MYARCH_FLAGS --prefix=%{prefix} \
	--enable-eazel-services \
	--sysconfdir=%{sysconfdir}

if [ "$SMP" != "" ]; then
  (make "MAKE=make -k -j $SMP"; exit 0)
  make
else
  make
fi

%install
[ -n "$RPM_BUILD_ROOT" -a "$RPM_BUILD_ROOT" != / ] && rm -rf $RPM_BUILD_ROOT

make prefix=$RPM_BUILD_ROOT%{prefix} sysconfdir=$RPM_BUILD_ROOT%{sysconfdir} install

for FILE in "$RPM_BUILD_ROOT/bin/*"; do
	file "$FILE" | grep -q not\ stripped && strip $FILE
done

%clean
[ -n "$RPM_BUILD_ROOT" -a "$RPM_BUILD_ROOT" != / ] && rm -rf $RPM_BUILD_ROOT

%post
if ! grep %{prefix}/lib /etc/ld.so.conf > /dev/null ; then
  echo "%{prefix}/lib" >> /etc/ld.so.conf
fi
  
/sbin/ldconfig
  
%postun -p /sbin/ldconfig

%files

%defattr(0555, bin, bin)
%doc AUTHORS COPYING COPYING.LIB ChangeLog NEWS README
%{prefix}/bin/*.sh
%{prefix}/bin/eazel-gen-xml
%{prefix}/bin/eazel-helper
%{prefix}/bin/eazel-install
%{prefix}/bin/eazel-package-query
%{prefix}/bin/eazel-revert
%{prefix}/bin/eazel-sample-client
%{prefix}/bin/eazel-time
%{prefix}/bin/eazel-uninstall
%{prefix}/bin/eazel-vault
%{prefix}/bin/gnome-db2html2
%{prefix}/bin/gnome-info2html2
%{prefix}/bin/gnome-man2html2
%{prefix}/bin/hyperbola
%{prefix}/bin/nautilus
%{prefix}/bin/nautilus-authenticate
%{prefix}/bin/nautilus-content-loser
%{prefix}/bin/nautilus-hardware-view
%{prefix}/bin/nautilus-history-view
%{prefix}/bin/nautilus-inventory-view
%{prefix}/bin/nautilus-login-view
%{prefix}/bin/nautilus-mozilla-content-view
%{prefix}/bin/nautilus-music-view
%{prefix}/bin/nautilus-notes
%{prefix}/bin/nautilus-rpm-view
%{prefix}/bin/nautilus-sample-content-view
%{prefix}/bin/nautilus-sample-service-view
%{prefix}/bin/nautilus-service-install-view
%{prefix}/bin/nautilus-service-startup-view
%{prefix}/bin/nautilus-sidebar-loser
%{prefix}/bin/nautilus-summary-view
%{prefix}/bin/nautilus-tree-view
%{prefix}/bin/ntl-web-browser
%{prefix}/bin/ntl-web-search
%{prefix}/bin/run-nautilus
%{prefix}/bin/test-ft
%{prefix}/bin/test-rsvg
%{prefix}/bin/trilobite-eazel-install-service
%{prefix}/bin/trilobite-eazel-sample-service
%{prefix}/bin/trilobite-eazel-time-service
%{prefix}/bin/trilobite-eazel-time-view
%{prefix}/idl/*.idl
%{prefix}/lib/*.0
%{prefix}/lib/*.so
%{prefix}/lib/vfs/modules/*.so

%defattr (0444, bin, bin)
%config %{sysconfdir}/vfs/modules/*.conf
%{prefix}/share/gnome/apps/Applications/*.desktop
%{prefix}/share/hyperbola/maps/*.map
%{prefix}/share/locale/*/LC_MESSAGES/*.mo
%{prefix}/share/nautilus/*.xml
%{prefix}/share/nautilus/backgrounds/*.jpg
%{prefix}/share/nautilus/backgrounds/*.png
%{prefix}/share/nautilus/backgrounds/.*.png
%{prefix}/share/nautilus/emblems/*.gif
%{prefix}/share/nautilus/emblems/*.png
%{prefix}/share/nautilus/linksets/*.xml
%{prefix}/share/nautilus/top/*.html
%{prefix}/share/nautilus/top/Computer
%{prefix}/share/nautilus/top/Services
%{prefix}/share/oaf/*.oafinfo
%{prefix}/share/pixmaps/*.png
%{prefix}/share/pixmaps/nautilus/*.gif
%{prefix}/share/pixmaps/nautilus/*.png
%{prefix}/share/pixmaps/nautilus/*.svg
%{prefix}/share/pixmaps/nautilus/*.xml
%{prefix}/share/pixmaps/nautilus/arlo/*.png
%{prefix}/share/pixmaps/nautilus/arlo/*.xml
%{prefix}/share/pixmaps/nautilus/arlo/backgrounds/*.png
%{prefix}/share/pixmaps/nautilus/arlo/sidebar_tab_pieces/*.png
%{prefix}/share/pixmaps/nautilus/eazel/*.png
%{prefix}/share/pixmaps/nautilus/eazel/*.xml
%{prefix}/share/pixmaps/nautilus/vector/*.png
%{prefix}/share/pixmaps/nautilus/vector/*.svg
%{prefix}/share/pixmaps/nautilus/vector/*.xml
%{prefix}/share/websearch/*.eng

%files devel

%defattr(0555, bin, bin)
%{prefix}/lib/*.la
%{prefix}/lib/vfs/modules/*.la

%defattr(0444, bin, bin)
%{prefix}/include/eazel-install/*.h
%{prefix}/include/libnautilus/*.h
%{prefix}/include/libtrilobite/*.h
