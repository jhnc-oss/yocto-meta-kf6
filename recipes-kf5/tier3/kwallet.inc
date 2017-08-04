DESCRIPTION = "KWallet"
HOMEPAGE = "https://api.kde.org/frameworks/kwallet/html/index.html"
LICENSE = "LGPL-2.1"
LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1"
PR = "r0"

DEPENDS = " \
    qtbase \
    kconfig \
    kconfigwidgets \
    kcoreaddons \
    kdbusaddons \
    kiconthemes \
    knotifications \
    ki18n \
    kservice \
    kwidgetsaddons \
    kwindowsystem \
    libgcrypt \
"

SRC_URI = " \
    git://anongit.kde.org/kwallet;nobranch=1 \
    file://0001-no-find-file.patch \
"
S = "${WORKDIR}/git"

inherit cmake_kf5
inherit gettext
inherit python3native

FILES_${PN} += " \
    ${datadir}/knotifications5/*.notifyrc \
    ${datadir}/kservices5/*.desktop \
    ${datadir}/dbus-1/services/*.service \
"

FILES_${PN}-dev += " \
    ${datadir}/dbus-1/interfaces/*.xml \
"