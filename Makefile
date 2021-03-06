#############################################################################
# Makefile for building: rocketbook
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  rocketbook.pro
# Template: subdirs
# Command: /usr/bin/qmake-qt5 -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile rocketbook.pro
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/bin/qmake-qt5
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = rocketbook1.0.0
DISTDIR = /auto/bunter_usr23/townleym/wc20160420/.tmp/rocketbook1.0.0
SUBTARGETS    =  \
		sub-model \
		sub-unittest-unittest \
		sub-database \
		sub-gui \
		sub-textui


sub-model-qmake_all:  FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile
	cd model/ && $(MAKE) -f Makefile qmake_all
sub-model: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile
sub-model-make_first: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile 
sub-model-all: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile all
sub-model-clean: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-model-distclean: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-model-install_subtargets: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile install
sub-model-uninstall_subtargets: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-unittest-unittest-qmake_all:  FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile
	cd unittest/unittest/ && $(MAKE) -f Makefile qmake_all
sub-unittest-unittest: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile
sub-unittest-unittest-make_first: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile 
sub-unittest-unittest-all: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile all
sub-unittest-unittest-clean: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-unittest-unittest-distclean: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-unittest-unittest-install_subtargets: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile install
sub-unittest-unittest-uninstall_subtargets: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-database-qmake_all:  FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile
	cd database/ && $(MAKE) -f Makefile qmake_all
sub-database: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile
sub-database-make_first: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile 
sub-database-all: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile all
sub-database-clean: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-database-distclean: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-database-install_subtargets: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile install
sub-database-uninstall_subtargets: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-gui-qmake_all:  FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile
	cd gui/ && $(MAKE) -f Makefile qmake_all
sub-gui: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile
sub-gui-make_first: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile 
sub-gui-all: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile all
sub-gui-clean: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-gui-distclean: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-gui-install_subtargets: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile install
sub-gui-uninstall_subtargets: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-textui-qmake_all:  FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile
	cd textui/ && $(MAKE) -f Makefile qmake_all
sub-textui: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile
sub-textui-make_first: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile 
sub-textui-all: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile all
sub-textui-clean: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-textui-distclean: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-textui-install_subtargets: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile install
sub-textui-uninstall_subtargets: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile uninstall

Makefile: rocketbook.pro /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		rocketbook.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile rocketbook.pro
/usr/lib64/qt5/mkspecs/features/spec_pre.prf:
/usr/lib64/qt5/mkspecs/common/unix.conf:
/usr/lib64/qt5/mkspecs/common/linux.conf:
/usr/lib64/qt5/mkspecs/common/sanitize.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt5/mkspecs/common/g++-base.conf:
/usr/lib64/qt5/mkspecs/common/g++-unix.conf:
/usr/lib64/qt5/mkspecs/qconfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib64/qt5/mkspecs/features/qt_functions.prf:
/usr/lib64/qt5/mkspecs/features/qt_config.prf:
/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib64/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt5/mkspecs/features/default_pre.prf:
/usr/lib64/qt5/mkspecs/features/resolve_config.prf:
/usr/lib64/qt5/mkspecs/features/default_post.prf:
/usr/lib64/qt5/mkspecs/features/qml_debug.prf:
/usr/lib64/qt5/mkspecs/features/warn_on.prf:
/usr/lib64/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib64/qt5/mkspecs/features/exceptions.prf:
/usr/lib64/qt5/mkspecs/features/yacc.prf:
/usr/lib64/qt5/mkspecs/features/lex.prf:
rocketbook.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile rocketbook.pro

qmake_all: sub-model-qmake_all sub-unittest-unittest-qmake_all sub-database-qmake_all sub-gui-qmake_all sub-textui-qmake_all FORCE

make_first: sub-model-make_first sub-unittest-unittest-make_first sub-database-make_first sub-gui-make_first sub-textui-make_first  FORCE
all: sub-model-all sub-unittest-unittest-all sub-database-all sub-gui-all sub-textui-all  FORCE
clean: sub-model-clean sub-unittest-unittest-clean sub-database-clean sub-gui-clean sub-textui-clean  FORCE
distclean: sub-model-distclean sub-unittest-unittest-distclean sub-database-distclean sub-gui-distclean sub-textui-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash
install_subtargets: sub-model-install_subtargets sub-unittest-unittest-install_subtargets sub-database-install_subtargets sub-gui-install_subtargets sub-textui-install_subtargets FORCE
uninstall_subtargets: sub-model-uninstall_subtargets sub-unittest-unittest-uninstall_subtargets sub-database-uninstall_subtargets sub-gui-uninstall_subtargets sub-textui-uninstall_subtargets FORCE

sub-model-check:
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile check
sub-unittest-unittest-check:
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile check
sub-database-check:
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile check
sub-gui-check:
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile check
sub-textui-check:
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -f Makefile check
check: sub-model-check sub-unittest-unittest-check sub-database-check sub-gui-check sub-textui-check
install:install_subtargets  FORCE

uninstall: uninstall_subtargets FORCE

FORCE:

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: sub-model-distdir sub-unittest-unittest-distdir sub-database-distdir sub-gui-distdir sub-textui-distdir FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents /usr/lib64/qt5/mkspecs/features/spec_pre.prf /usr/lib64/qt5/mkspecs/common/unix.conf /usr/lib64/qt5/mkspecs/common/linux.conf /usr/lib64/qt5/mkspecs/common/sanitize.conf /usr/lib64/qt5/mkspecs/common/gcc-base.conf /usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf /usr/lib64/qt5/mkspecs/common/g++-base.conf /usr/lib64/qt5/mkspecs/common/g++-unix.conf /usr/lib64/qt5/mkspecs/qconfig.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri /usr/lib64/qt5/mkspecs/features/qt_functions.prf /usr/lib64/qt5/mkspecs/features/qt_config.prf /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_post.prf .qmake.stash /usr/lib64/qt5/mkspecs/features/exclusive_builds.prf /usr/lib64/qt5/mkspecs/features/default_pre.prf /usr/lib64/qt5/mkspecs/features/resolve_config.prf /usr/lib64/qt5/mkspecs/features/default_post.prf /usr/lib64/qt5/mkspecs/features/qml_debug.prf /usr/lib64/qt5/mkspecs/features/warn_on.prf /usr/lib64/qt5/mkspecs/features/testcase_targets.prf /usr/lib64/qt5/mkspecs/features/exceptions.prf /usr/lib64/qt5/mkspecs/features/yacc.prf /usr/lib64/qt5/mkspecs/features/lex.prf rocketbook.pro $(DISTDIR)/

sub-model-distdir: FORCE
	@test -d model/ || mkdir -p model/
	cd model/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/model/model.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/model

sub-unittest-unittest-distdir: FORCE
	@test -d unittest/unittest/ || mkdir -p unittest/unittest/
	cd unittest/unittest/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/unittest/unittest/unittest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/unittest/unittest

sub-database-distdir: FORCE
	@test -d database/ || mkdir -p database/
	cd database/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/database/database.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/database

sub-gui-distdir: FORCE
	@test -d gui/ || mkdir -p gui/
	cd gui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/gui/gui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/gui

sub-textui-distdir: FORCE
	@test -d textui/ || mkdir -p textui/
	cd textui/ && ( test -e Makefile || $(QMAKE) /auto/bunter_usr23/townleym/wc20160420/textui/textui.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/textui

