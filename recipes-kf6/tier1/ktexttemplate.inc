# SPDX-FileCopyrightText: 2024 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

SUMMARY = "KTextTemplate"
DESCRIPTION = "Library to allow application developers to separate the structure of documents from the data they contain"
HOMEPAGE = "https://invent.kde.org/frameworks/ktexttemplate"
LICENSE = "LGPL-2.1-or-later"
PR = "r0"

DEPENDS += "qtbase qtdeclarative"

inherit kf6_cmake_framework
inherit reuse_license_checksums

INSANE_SKIP:${PN} = "dev-so"
FILES_SOLIBSDEV = "${libdir}/libKF6TextTemplate.so"
FILES:${PN} += "${libdir}/plugins/kf6/ktexttemplate/*.so"
