ACLOCAL_AMFLAGS = -I m4

bin_SCRIPTS = tntnet-config tntnet-wizzard
pkgdata_SCRIPTS = tntnet-conf2xml.pl

tntnet-config: tntnet-config.in

if MAKE_SERVER
SERVERDIRS = \
    framework/runtime \
    framework/defcomp \
    etc
endif

if MAKE_SDK
SDKDIRS = \
    sdk/tools/common \
    sdk/tools/ecppc \
    sdk/tools/ecppl \
    sdk/tools/ecppll
endif

if MAKE_DEMOS
DEMOSDIRS = \
    sdk/demos
endif

if MAKE_UNITTEST
  UNITTESTDIR = utest
endif

SUBDIRS = \
    framework/common \
    doc/man \
    $(SERVERDIRS) \
    $(CGIDIRS) \
    $(SDKDIRS) \
    $(DEMOSDIRS) \
    $(UNITTESTDIR)

EXTRA_DIST = ecpp.vim \
    doc/tntnet.pdf \
    doc/tntnet.odt \
    doc/logo-tntnet.cdr \
    doc/tntnet.svg \
    doc/tntnet-dynamite.svg \
    doc/jquery-howto.markdown \
    doc/quick-start-guide.markdown \
    doc/static-howto.markdown \
    doc/upload-howto.markdown \
    COPYING \
    sdk/demos/newsdb/Makefile \
    sdk/demos/newsdb/README \
    sdk/demos/newsdb/global.ecpp \
    sdk/demos/newsdb/index.ecpp \
    sdk/demos/newsdb/news.ecpp \
    sdk/demos/newsdb/newscss.css \
    sdk/demos/newsdb/newsdata.sh \
    sdk/demos/newsdb/newsdb.sql \
    sdk/demos/newsdb/tntnet.xml \
    m4/acx_pthread.m4 \
    m4/ax_check_compile_flag.m4 \
    m4/ax_compiler_vendor.m4 \
    m4/pkg.m4 \
    $(pkgdata_SCRIPTS)
