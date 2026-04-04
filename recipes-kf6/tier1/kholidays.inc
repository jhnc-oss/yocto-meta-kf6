# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-FileCopyrightText: 2020 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

SUMMARY = "KHolidays"
DESCRIPTION = "Library to assist determining when holidays occur"
HOMEPAGE = "https://invent.kde.org/frameworks/kholidays"
LICENSE = "LGPL-2.0-or-later & BSD-2-Clause"
PR = "r0"

DEPENDS += "qtbase"

inherit kf6_cmake_framework
inherit reuse_license_checksums

FILES:${PN} += "${libdir}/qml/org/kde/kholidays"
