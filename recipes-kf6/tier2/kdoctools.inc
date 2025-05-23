# SPDX-FileCopyrightText: 2018-2020 Volker Krause <vkrause@kde.org>
# SPDX-FileCopyrightText: 2020 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

LICENSE = "LGPL-2.1-only"
PR = "r0"

DEPENDS = " \
    karchive \
    ki18n \
    libxslt \
    libxml2 \
    libxml2-native \
    docbook-xml-dtd4 \
    docbook-xsl-stylesheets \
    liburi-perl-native \
    kdoctools-native \
    docbook-xsl-stylesheets-native \
" 

require kdoctools_metainfo.inc
inherit kf6-cmake-framework
inherit gettext
inherit python3native
inherit perlnative
inherit reuse_license_checksums

EXTRA_OECMAKE:class-native = " \
    -DINSTALL_INTERNAL_TOOLS=ON \
    -DRELOCATABLE_DOCBOOK_FILES=ON \
"

EXTRA_OECMAKE:class-target = " \
    -DMEINPROC6_EXECUTABLE=${STAGING_DIR_NATIVE}/${bindir}/meinproc6 \
    -DDOCBOOKL10NHELPER_EXECUTABLE=${STAGING_DIR_NATIVE}/${bindir}/docbookl10nhelper \
    -DCHECKXML6_EXECUTABLE=${STAGING_DIR_NATIVE}/${bindir}/checkXML6 \
    -DRELOCATABLE_DOCBOOK_FILES=ON \
"

# TODO split recipe for native and target to avoid stripping warnings for applications
sysroot_stage_all:append:class-native () {
    mkdir -p ${SYSROOT_DESTDIR}${bindir}
    cp ${B}/bin/docbookl10nhelper ${SYSROOT_DESTDIR}${bindir}
}

sysroot_stage_all:append:class-target () {
    mkdir -p ${SYSROOT_DESTDIR}${bindir}
    cp ${STAGING_BINDIR_NATIVE}/checkXML6 ${SYSROOT_DESTDIR}${bindir}
    cp ${STAGING_BINDIR_NATIVE}/meinproc6 ${SYSROOT_DESTDIR}${bindir}
}

do_compile:append() {
    # TODO this reworks the all-l18n.xml paths to be host-independent
    # a better solution is to change this directly in docbookl18nhelper.cpp
    sed -i 's:${RECIPE_SYSROOT}::g' ${B}/src/customization/xsl/all-l10n.xml
}

FILES:${PN} += " \
    ${datadir}/kf6/kdoctools/customization/* \
    ${datadir}/kf6/kdoctools/customization/*/* \
    ${datadir}/kf6/kdoctools/customization/*/*/* \
"
