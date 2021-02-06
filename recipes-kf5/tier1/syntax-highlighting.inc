# SPDX-FileCopyrightText: 2017-2020 Volker Krause <vkrause@kde.org>
# SPDX-FileCopyrightText: 2020 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

LICENSE = "MIT"
PR = "r0"

DEPENDS = " \
    qtbase \
    ${BPN}-native \
"

SRC_URI = "git://invent.kde.org/frameworks/syntax-highlighting;nobranch=1;protocol=https"
S = "${WORKDIR}/git"

require syntax-highlighting_metainfo.inc
inherit cmake_kf5
inherit perlnative
inherit reuse_license_checksums

EXTRA_OECMAKE_class-native += " -DKSYNTAXHIGHLIGHTING_USE_GUI=OFF"
EXTRA_OECMAKE_class-target += " -DKATEHIGHLIGHTINGINDEXER_EXECUTABLE=${STAGING_DIR_NATIVE}/${bindir}/katehighlightingindexer"

sysroot_stage_all_append_class-native () {
    mkdir -p ${SYSROOT_DESTDIR}/${bindir}
    cp ${B}/bin/katehighlightingindexer ${SYSROOT_DESTDIR}/${bindir}
}