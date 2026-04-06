# SPDX-FileCopyrightText: none
# SPDX-License-Identifier: CC0-1.0

SUMMARY = "All meta-kf6 packages"
DESCRIPTION = "This packagegroup is pimarily meant for release testing."
BUGTRACKER = "https://invent.kde.org/packaging/yocto-meta-kf6/"
REQUIRED_DISTRO_FEATURES = "wayland x11"
PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup features_check

RDEPENDS:${PN} += "\
    attica \
    baloo \
    bluez-qt \
    breeze-icons \
    frameworkintegration \
    karchive \
    kauth \
    kbookmarks \
    kcalendarcore \
    kcmutils \
    kcodecs \
    kcolorscheme \
    kcompletion \
    kconfig \
    kconfigwidgets \
    kcontacts \
    kcoreaddons \
    kcrash \
    kdav \
    kdbusaddons \
    kdeclarative \
    kded \
    kdesu \
    kdnssd \
    kdoctools \
    kfilemetadata \
    kglobalaccel \
    kguiaddons \
    kholidays \
    ki18n \
    kiconthemes \
    kidletime \
    kimageformats \
    kio \
    kirigami \
    kitemmodels \
    kitemviews \
    kjobwidgets \
    knewstuff \
    knotifications \
    knotifyconfig \
    kpackage \
    kparts \
    kpeople \
    kplotting \
    kpty \
    kquickcharts \
    krunner \
    kservice \
    kstatusnotifieritem \
    ksvg \
    ktexteditor \
    ktexttemplate \
    ktextwidgets \
    kunitconversion \
    kuserfeedback \
    kwallet \
    kwidgetsaddons \
    kwindowsystem \
    kxmlgui \
    modemmanager-qt \
    networkmanager-qt \
    prison \
    purpose \
    qqc2-desktop-style \
    solid \
    sonnet \
    syndication \
    syntax-highlighting \
    threadweaver \
"
