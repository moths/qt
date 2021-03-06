# Copyright (C) 2012 O.S. Systems Software LTDA.
# Copyright (C) 2013 Martin Jansa <martin.jansa@gmail.com>

## @useflag qtexamples Build examples and demos. Disabled by default.

inherit qmake5

QT_MODULE ?= "${PN}"

#Examples are present in all Qt modules
RECIPE_FLAGS += "qtexamples"
DEFAULT_USE_qtexamples = "1"
PACKAGES:<USE_qtexamples = "${PN}-examples-dbg ${PN}-examples "

RECIPE_FLAGS += "qtdbus"
EXTRA_OECONF:>USE_qtdbus = "-dbus"
DEPENDS:>USE_qtdbus = " libdbus"

PACKAGES =. "${PN}-qmlplugins-dbg ${PN}-tools-dbg ${PN}-plugins-dbg ${PN}-qmlplugins ${PN}-tools ${PN}-plugins ${PN}-mkspecs ${PN}-examples-dev ${PN}-examples-staticdev "
RDEPENDS_${PN} += "${PN}-plugins_${PV} ${PN}-qmlplugins_${PV}"

# extra -dbg packages
FILES_${PN}-qmlplugins-dbg = " \
    ${OE_QMAKE_PATH_QML}/*/.debug \
    ${OE_QMAKE_PATH_QML}/*/*/.debug \
    ${OE_QMAKE_PATH_QML}/*/*/*/.debug \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/.debug \
    ${OE_QMAKE_PATH_IMPORTS}/*/.debug \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/.debug \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/.debug \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*/.debug \
"
FILES_${PN}-tools-dbg = " \
    ${OE_QMAKE_PATH_BINS}/.debug \
"
FILES_${PN}-plugins-dbg = " \
    ${OE_QMAKE_PATH_PLUGINS}/*/.debug/* \
"

# extra packages
# qmlplugins 1-3 levels of subdirs qmldir + *{.so,*.qmltypes,*.qml,*js}
FILES_${PN}-qmlplugins = " \
    ${OE_QMAKE_PATH_QML}/*.qmltypes \
    ${OE_QMAKE_PATH_QML}/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_QML}/*/qmldir \
    ${OE_QMAKE_PATH_QML}/*/*.qmltypes \
    ${OE_QMAKE_PATH_QML}/*/*.qml \
    ${OE_QMAKE_PATH_QML}/*/*.js \
    ${OE_QMAKE_PATH_QML}/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_QML}/*/*/qmldir \
    ${OE_QMAKE_PATH_QML}/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_QML}/*/*/*.qml \
    ${OE_QMAKE_PATH_QML}/*/*/*.js \
    ${OE_QMAKE_PATH_QML}/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_QML}/*/*/*/qmldir \
    ${OE_QMAKE_PATH_QML}/*/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_QML}/*/*/*/*.qml \
    ${OE_QMAKE_PATH_QML}/*/*/*/*.js \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/qmldir \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/*.qml \
    ${OE_QMAKE_PATH_QML}/*/*/*/*/*.js \
    ${OE_QMAKE_PATH_IMPORTS}/*.qmltypes \
    ${OE_QMAKE_PATH_IMPORTS}/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_IMPORTS}/*/*.qmltypes \
    ${OE_QMAKE_PATH_IMPORTS}/*/qmldir \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/qmldir \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/qmldir \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*/*.qmltypes \
    ${OE_QMAKE_PATH_IMPORTS}/*/*/*/*/qmldir \
    ${OE_QMAKE_PATH_QML}/*/*/images/ \
"
FILES_${PN}-tools = " \
    ${OE_QMAKE_PATH_BINS}/* \
"
FILES_${PN}-plugins = " \
    ${OE_QMAKE_PATH_PLUGINS}/*/*${SOLIBSDEV} \
"
FILES_${PN}-mkspecs = "\
    ${OE_QMAKE_PATH_ARCHDATA}/mkspecs \
"

# modifications to normal packages
FILES_${PN} += " \
    ${OE_QMAKE_PATH_LIBS}/lib*${SOLIBS} \
    ${OE_QMAKE_PATH_LIBEXECS} \
"
FILES_${PN}-dev += " \
    ${OE_QMAKE_PATH_LIBS}/lib*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_LIBS}/pkgconfig \
    ${OE_QMAKE_PATH_LIBS}/cmake/* \
    ${OE_QMAKE_PATH_LIBS}/*.prl \
    ${OE_QMAKE_PATH_LIBS}/*.la \
    ${OE_QMAKE_PATH_DATA}/* \
    ${OE_QMAKE_PATH_HEADERS}/* \
"
FILES_${PN}-dbg += " \
    ${OE_QMAKE_PATH_LIBS}/.debug \
    ${OE_QMAKE_PATH_LIBEXECS}/.debug \
"
FILES_${PN}-staticdev += " \
    ${OE_QMAKE_PATH_LIBS}/*.a \
"
FILES_${PN}-examples = " \
    ${OE_QMAKE_PATH_EXAMPLES}/*/* \
"
FILES_${PN}-examples-dev = " \
    ${OE_QMAKE_PATH_EXAMPLES}/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/*${SOLIBSDEV} \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/*/*${SOLIBSDEV} \
"
FILES_${PN}-examples-dbg = " \
    ${OE_QMAKE_PATH_EXAMPLES}/.debug \
    ${OE_QMAKE_PATH_EXAMPLES}/*/.debug \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/.debug \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/.debug \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/.debug \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/*/.debug \
"
FILES_${PN}-examples-staticdev = " \
    ${OE_QMAKE_PATH_EXAMPLES}/*.a \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*.a \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*.a \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*.a \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/*.a \
    ${OE_QMAKE_PATH_EXAMPLES}/*/*/*/*/*/*.a \
"
