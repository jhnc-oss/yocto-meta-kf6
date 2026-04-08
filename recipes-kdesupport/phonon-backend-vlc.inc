# SPDX-FileCopyrightText: 2024 Marc Ferland <marc.ferland@sonatest.com>
#
# SPDX-License-Identifier: MIT

SUMMARY = "Phonon VLC backend"
DESCRIPTION = "VLC backend for the Phonon multimedia library"
HOMEPAGE = "https://invent.kde.org/libraries/phonon-vlc"
LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=46d98c0b7542668d6015b992889b2020"

DEPENDS += "extra-cmake-modules \
            phonon \
            qtbase \
            qttools-native \
            vlc \
"

SRC_URI = "https://download.kde.org/stable/phonon/${BPN}/${PV}/${BPN}-${PV}.tar.xz"

FILES:${PN} += "${libdir}/plugins/phonon4qt6_backend"

RDEPENDS:${PN} += "vlc"

inherit qt6-cmake

EXTRA_OECMAKE += "-DPHONON_BUILD_QT5=OFF \
                  -DPHONON_BUILD_QT6=ON \
"
