# SPDX-FileCopyrightText: 2020 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

DESCRIPTION = "Plasma Wayland Protocols"
LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1"
PR = "r0"

DEPENDS = "extra-cmake-modules qtwayland-native"

BBCLASSEXTEND = "native nativesdk"

inherit qt6-cmake

FILES:${PN}-dev += " \
    ${libdir}/cmake/* \
    ${datadir}/plasma-wayland-protocols/* \
"
