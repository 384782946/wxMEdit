SUBDIRS = syntax po

bin_PROGRAMS = wxmedit
INCLUDES = -I$(top_srcdir)/charset-detector/include -I$(top_srcdir)/charset-detector/src -I$(top_srcdir)/charset-detector/src/tables
wxmedit_CXXFLAGS = -DDATA_DIR=\"${datadir}\"
wxmedit_SOURCES =	src/wxmedit_about_dialog.cpp \
	src/wxmedit_about_dialog.h \
	src/wxm_command.h \
	src/wxm_conv_enc_dialog.cpp \
	src/wxm_conv_enc_dialog.h \
	src/wxmedit_app.cpp \
	src/wxmedit_app.h \
	src/wxmedit_frame.cpp \
	src/wxmedit_frame.h \
	src/wxm_find_in_files_dialog.cpp \
	src/wxm_find_in_files_dialog.h \
	src/wxm_highlighting_dialog.cpp \
	src/wxm_highlighting_dialog.h \
	src/wxm_options_dialog.cpp \
	src/wxm_options_dialog.h \
	src/wxm_plugin.cpp \
	src/wxm_printout.cpp \
	src/wxm_printout.h \
	src/wxm_replace_dialog.cpp \
	src/wxm_replace_dialog.h \
	src/wxm_search_dialog.cpp \
	src/wxm_search_dialog.h \
	src/wxm_sort_dialog.cpp \
	src/wxm_sort_dialog.h \
	src/wxm_utils.cpp \
	src/wxm_utils.h \
	src/wxm_word_count_dialog.cpp \
	src/wxm_word_count_dialog.h \
	src/plugin.h \
	src/wxmedit/caret_new.cpp \
	src/wxmedit/caret_new.h \
	src/wxmedit/clipbrd_gtk.cpp \
	src/wxmedit/clipbrd_gtk.h \
	src/wxmedit/wxm_deque.hpp \
	src/wxmedit/wxmedit.cpp \
	src/wxmedit/wxmedit.h \
	src/wxmedit/wxmedit_advanced.cpp \
	src/wxmedit/wxmedit_basic.cpp \
	src/wxmedit/wxmedit_command.cpp \
	src/wxmedit/wxmedit_command.h \
	src/wxmedit/wxmedit_search.cpp \
	src/wxmedit/wxmedit_gtk.cpp \
	src/wxmedit/wxm_encoding.cpp \
	src/wxmedit/wxm_encoding.h \
	src/wxmedit/wxm_lines.cpp \
	src/wxmedit/wxm_lines.h \
	src/wxmedit/wxm_syntax.cpp \
	src/wxmedit/wxm_syntax.h \
	src/wxmedit/wxm_undo.cpp \
	src/wxmedit/wxm_undo.h \
	src/wxmedit/wxm_wx_icu.cpp \
	src/wxmedit/wxm_wx_icu.h \
	src/wxmedit/trad_simp.cpp \
	src/wxmedit/trad_simp.h \
	src/wxmedit/ucs4_t.h \
	charset-detector/src/CharDistribution.cpp \
	charset-detector/src/CharDistribution.h \
	charset-detector/src/JpCntx.cpp \
	charset-detector/src/JpCntx.h \
	charset-detector/src/LangBulgarianModel.cpp \
	charset-detector/src/LangCyrillicModel.cpp \
	charset-detector/src/LangGreekModel.cpp \
	charset-detector/src/LangHebrewModel.cpp \
	charset-detector/src/LangHungarianModel.cpp \
	charset-detector/src/LangThaiModel.cpp \
	charset-detector/src/nsBig5Prober.cpp \
	charset-detector/src/nsBig5Prober.h \
	charset-detector/src/nsCharSetProber.cpp \
	charset-detector/src/nsCharSetProber.h \
	charset-detector/src/nsCodingStateMachine.h \
	charset-detector/src/nscore.h \
	charset-detector/src/nsEscCharsetProber.cpp \
	charset-detector/src/nsEscCharsetProber.h \
	charset-detector/src/nsEscSM.cpp \
	charset-detector/src/nsEUCJPProber.cpp \
	charset-detector/src/nsEUCJPProber.h \
	charset-detector/src/nsEUCKRProber.cpp \
	charset-detector/src/nsEUCKRProber.h \
	charset-detector/src/nsEUCTWProber.cpp \
	charset-detector/src/nsEUCTWProber.h \
	charset-detector/src/nsGB2312Prober.cpp \
	charset-detector/src/nsGB2312Prober.h \
	charset-detector/src/nsHebrewProber.cpp \
	charset-detector/src/nsHebrewProber.h \
	charset-detector/src/nsLatin1Prober.cpp \
	charset-detector/src/nsLatin1Prober.h \
	charset-detector/src/nsMBCSGroupProber.cpp \
	charset-detector/src/nsMBCSGroupProber.h \
	charset-detector/src/nsMBCSSM.cpp \
	charset-detector/src/nsPkgInt.h \
	charset-detector/src/nsSBCharSetProber.cpp \
	charset-detector/src/nsSBCharSetProber.h \
	charset-detector/src/nsSBCSGroupProber.cpp \
	charset-detector/src/nsSBCSGroupProber.h \
	charset-detector/src/nsSJISProber.cpp \
	charset-detector/src/nsSJISProber.h \
	charset-detector/src/nsUniversalDetector.cpp \
	charset-detector/src/nsUniversalDetector.h \
	charset-detector/src/nsUTF8Prober.cpp \
	charset-detector/src/nsUTF8Prober.h \
	charset-detector/src/prmem.h \
	charset-detector/src/entry/impl.cpp \
	charset-detector/include/chardetect.h

pixmapsdir = $(datadir)/pixmaps
pixmaps_DATA = wxmedit.xpm

appdir = $(datadir)/applications
app_DATA = wxmedit.desktop

EXTRA_DIST = m4/ChangeLog  $(pixmaps_DATA) $(app_DATA)

noinst_HEADERS =	description-pak \
	README.txt \
	autogen.sh \
	wxmedit.spec \
	wxmedit-static.spec \
	debian/changelog \
	debian/control \
	debian/copyright \
	debian/menu \
	debian/rules \
	freebsd/pkg-comment \
	freebsd/pkg-descr \
	freebsd/pkg-plist \
	freebsd/pkgcreate.txt \
	m4/gettext.m4 \
	m4/iconv.m4 \
	m4/lib-ld.m4 \
	m4/lib-link.m4 \
	m4/lib-prefix.m4 \
	m4/nls.m4 \
	m4/po.m4 \
	m4/progtest.m4 \
	m4/ChangeLog \
	src/wxmedit_app.rc \
	src/wxmedit_about_dialog.wxform \
	src/wxm_conv_enc_dialog.wxform \
	src/wxmedit_frame.wxform \
	src/wxm_file_association_dialog.cpp \
	src/wxm_file_association_dialog.h \
	src/wxm_file_association_dialog.wxform \
	src/wxm_find_in_files_dialog.wxform \
	src/wxm_highlighting_dialog.wxform \
	src/wxm_options_dialog.wxform \
	src/wxm_replace_dialog.wxform \
	src/wxm_search_dialog.wxform \
	src/wxm_sort_dialog.wxform \
	src/wxm_word_count_dialog.wxform \
	src/plugin_example/makefile.linux \
	src/plugin_example/makefile.mingw32 \
	src/plugin_example/makefile.vc \
	src/plugin_example/plugin.cpp \
	src/plugin_example/vc_cl.bat \
	src/plugin_example/wxwin16x16.xpm \
	devcpp/wxmedit.dev \
	devcpp/wxmedit.layout \
	devcpp/wxmedit_private.h \
	devcpp/wxmedit_private.rc \
	image2xpm/image2xpm.dev \
	image2xpm/image2xpm.layout \
	image2xpm/image2xpm_app.cpp \
	image2xpm/image2xpm_app.h \
	image2xpm/image2xpm_app.rc \
	image2xpm/image2xpm_frm.cpp \
	image2xpm/image2xpm_frm.h \
	image2xpm/image2xpm_frm.wxform \
	image2xpm/image2xpm_frm.xml \
	image2xpm/image2xpm_private.h \
	image2xpm/image2xpm_private.rc \
	images/closeall.xpm \
	images/columnmode.xpm \
	images/comment.xpm \
	images/copy.xpm \
	images/cut.xpm \
	images/down.xpm \
	images/fileclose.xpm \
	images/fileopen.xpm \
	images/filesave.xpm \
	images/filesaveas.xpm \
	images/find.xpm \
	images/findnext.xpm \
	images/findprev.xpm \
	images/font.xpm \
	images/fontname.xpm \
	images/fontsize.xpm \
	images/hexmode.xpm \
	images/indent.xpm \
	images/madedit.ico \
	images/madedit.xpm \
	images/new.xpm \
	images/nowrap.xpm \
	images/null.xpm \
	images/paste.xpm \
	images/preview.xpm \
	images/print.xpm \
	images/quit.xpm \
	images/redo.xpm \
	images/replace.xpm \
	images/saveall.xpm \
	images/textmode.xpm \
	images/uncomment.xpm \
	images/undo.xpm \
	images/unindent.xpm \
	images/wrapbycol.xpm \
	images/wrapbywin.xpm \
	images/wxmedit.ico \
	images/wxmedit.xpm \
	images/wxmedit_16x15.xpm \
	libunicows/libunicows.a \
	libunicows/README.txt \
	libunicows/unicows.lib \
	makefiles/Makefile.mac \
	makefiles/Makefile.mingw \
	makefiles/Makefile.install \
	makefiles/zcfg_wx_debug.sh \
	makefiles/zcfg_wx_release.sh \
	po/src.list \
	po/wxstd.po.cpp \
	po/xgettext.bat \
	po/xgettext_join.bat \
	vc71/build_debug.bat \
	vc71/build_release.bat \
	vc71/wxmedit.sln \
	vc71/wxmedit.vcproj \
	vc80/wxmedit.sln \
	vc80/wxmedit.vcproj \
	charset-detector/Makefile \
	charset-detector/MPL-1.1.txt \
	charset-detector/README \
	charset-detector/test/Makefile \
	charset-detector/test/test-chardetect.c \
	charset-detector/src/Makefile \
	charset-detector/src/tables/Big5Freq.tab \
	charset-detector/src/tables/EUCKRFreq.tab \
	charset-detector/src/tables/EUCTWFreq.tab \
	charset-detector/src/tables/GB2312Freq.tab \
	charset-detector/src/tables/JISFreq.tab \
	charset-detector/src/entry/export-symbol.list


DOMAIN = wxmedit
podir = $(top_srcdir)/po
LINGUAS = @ALL_LINGUAS@

loc:
	@linguas='$(LINGUAS)'; \
	for lang in $$linguas; do \
		dir=./locale/$$lang; \
		$(mkinstalldirs) $$dir; \
		if test -r $(podir)/$$lang.gmo; then \
			cp $(podir)/$$lang.gmo $$dir/$(DOMAIN).mo; \
			echo "installing $(podir)/$$lang.gmo as $$dir/$(DOMAIN).mo"; \
		fi; \
	done


#ACLOCAL_AMFLAGS = -I m4