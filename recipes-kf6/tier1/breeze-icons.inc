# SPDX-FileCopyrightText: 2017-2020 Volker Krause <vkrause@kde.org>
#
# SPDX-License-Identifier: MIT

LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1"
PR = "r0"

require breeze-icons_metainfo.inc
inherit kf6-cmake-framework
# bash is in the hosttools folder in PATH, but that's not detected automatically
# due to the CMAKE_FIND_ROOT_PATH settings
EXTRA_OECMAKE:class-target += " -DBASH_EXE=`which bash`"

do_install:append:class-native() {
    install -d ${D}/${bindir}
    install ${B}/bin/qrcAlias ${D}/${bindir}
}

DEPENDS += " \
    breeze-icons-native \
"

FILES:${PN} += " \
    ${datadir}/icons/breeze \
    ${datadir}/icons/breeze-dark \
"
