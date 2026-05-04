# SPDX-FileCopyrightText: 2017-2020 Volker Krause <vkrause@kde.org>
#
# SPDX-License-Identifier: MIT

SUMMARY = "Oxygen Icons"
DESCRIPTION = "Oxygen-icons is a freedesktop.org compatible icon theme"
HOMEPAGE = "https://invent.kde.org/frameworks/oxygen-icons"
LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1"

inherit kf6_cmake_framework

FILES:${PN} += "${datadir}/icons/oxygen/index.theme \
                ${datadir}/icons/oxygen/base/*/*/*.png \
                ${datadir}/icons/oxygen/applets/*/*.svg \
"
