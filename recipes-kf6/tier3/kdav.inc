# SPDX-FileCopyrightText: 2020 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

LICENSE = "LGPL-2.0-or-later"
PR = "r0"

DEPENDS = " \
    qtbase \
    kio \
    kcoreaddons \
    kcoreaddons-native \
    kdoctools \
    ki18n \
"

require kdav_metainfo.inc
inherit kf6_cmake_framework
inherit kf6_kdoctools
inherit kf6_kconfig
inherit kf6_kauth
inherit reuse_license_checksums
