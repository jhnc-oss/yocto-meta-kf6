DESCRIPTION = "KJSEmbed"
HOMEPAGE = "https://api.kde.org/frameworks/kjsembed/html/index.html"
LICENSE = "LGPL-2.1"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1 \
    "
PR = "r0"

DEPENDS = " \
    qttools \
    qtsvg \
    kjs \
    ki18n \
"

SRC_URI = " \
    git://anongit.kde.org/${PN};nobranch=1 \
    file://0001-optional-kdoctools.patch \
    file://0002-unexport-kjscmd.patch \
"
S = "${WORKDIR}/git"

inherit cmake_kf5
inherit gettext
inherit python3native