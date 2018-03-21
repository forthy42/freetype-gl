## ExampleLib Example: an example of using Automake to link with a library

AC_INIT([freetype-gl], [1.7], [bernd@net2o.de], [freetype-gl for Linux/Android],
        [https://github.com/forthy42/freetype-gl])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CC
AM_PROG_AR
LT_INIT

case $CC in
     *android*)
	LIBADD="-llog"
	;;
esac

>conftest.$ac_ext
echo -n "checking include directory for ft2build.h... "
FTINC=`eval $ac_compiler -E -Wp,-v conftest.$ac_ext 2>&1 | grep '^ ' | while read i; do test -f $i/freetype2/ft2build.h && echo -I$i/freetype2; done`
echo "$FTINC"
rm conftest.$ac_ext

SOURCE_PATH_SIZE=0 #$(echo $PWD | wc -c)

AC_SUBST(FTINC)
AC_SUBST(LIBADD)
AC_SUBST(SOURCE_PATH_SIZE)
AX_GCC_BUILTIN(__builtin_bswap32)

PRECC=${CC%gcc*}
PRECLANG=${PRECC%clang*}
AC_CHECK_PROGS(GNU_LIBTOOL,"glibtool --tag=CC" libtool)
AC_SUBST(LIBTOOL)

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([debian/control])
AC_CONFIG_FILES([debian/changelog])
AC_OUTPUT
