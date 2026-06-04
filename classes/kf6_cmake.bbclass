# SPDX-FileCopyrightText: 2023 Andreas Cord-Landwehr <cordlandwehr@kde.org>
#
# SPDX-License-Identifier: MIT

inherit qt6-cmake

# ECM commit e698433a warns when CMAKE_INSTALL_* cache entries are set
# before KDEInstallDirs is included. Yocto's cmake.bbclass adds those
# entries through OECMAKE_ARGS, so pass KDE_INSTALL_* equivalents instead.
# KDEInstallDirs consumes these variables directly, preserving the install
# layout without triggering the warning.
#
# See:
# https://invent.kde.org/frameworks/extra-cmake-modules/-/commit/e698433a55a03eeeac33f275caa30098d810ecb1
# nooelint: oelint.task.noanonpython - we need to change this at parse time, hence the anonymous function
python() {
    args = d.getVar("OECMAKE_ARGS")
    replacements = [
        ("-DCMAKE_INSTALL_BINDIR", "-DKDE_INSTALL_BINDIR"),
        ("-DCMAKE_INSTALL_SBINDIR", "-DKDE_INSTALL_SBINDIR"),
        ("-DCMAKE_INSTALL_LIBDIR", "-DKDE_INSTALL_LIBDIR"),
        ("-DCMAKE_INSTALL_LIBEXECDIR", "-DKDE_INSTALL_LIBEXECDIR"),
        ("-DCMAKE_INSTALL_INCLUDEDIR", "-DKDE_INSTALL_INCLUDEDIR"),
        ("-DCMAKE_INSTALL_LOCALSTATEDIR", "-DKDE_INSTALL_LOCALSTATEDIR"),
        ("-DCMAKE_INSTALL_SHAREDSTATEDIR", "-DKDE_INSTALL_SHAREDSTATEDIR"),
        ("-DCMAKE_INSTALL_DATAROOTDIR", "-DKDE_INSTALL_DATAROOTDIR"),
        ("-DCMAKE_INSTALL_SYSCONFDIR", "-DKDE_INSTALL_SYSCONFDIR"),
    ]
    for old, new in replacements:
        args = args.replace(old, new)
    d.setVar("OECMAKE_ARGS", args)
}

do_install:append() {
    # imported targets may leak full paths to system targets
    if [ "0" -ne $(find ${D} \( -name "*.cmake" \) | wc -l) ]; then
        find ${D} \( -name "*.cmake" \) -exec \
            sed -i -e 's|${RECIPE_SYSROOT}/usr|\$\{_IMPORT_PREFIX\}|g' \
                {} \;
    fi
    if [ "0" -ne $(find ${D} \( -name "*.pc" \) | wc -l) ]; then
        find ${D} \( -name "*.pc" \) -exec \
            sed -i -e 's|-I${RECIPE_SYSROOT}/usr/|-I\$\{prefix\}/|g' \
                {} \;
    fi
}
