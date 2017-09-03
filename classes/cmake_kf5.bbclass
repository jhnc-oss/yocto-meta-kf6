inherit cmake_qt5

EXTRA_OECMAKE += " \
    -DOE_KF5_PATH_HOST_ROOT=${STAGING_DIR_HOST} \
    -DBUILD_TESTING=OFF \
"

DEPENDS += "extra-cmake-modules qttools-native"

# don't bother with translations for host tools
do_configure_class-native_prepend() {
    rm -rf ${S}/po
}

# This function is rather offensive right now, but it seems to work
do_install_prepend() {
    if [ "0" -ne $(find . -name \*.cmake | grep _usr | wc -l) ]; then
        sed -i 's/\"\/usr\//\"\$\{OE_KF5_PATH_HOST_ROOT\}\/usr\//g' $(find . -name "*.cmake" | grep _usr)
        sed -i 's/\;\/usr\//\;\$\{OE_KF5_PATH_HOST_ROOT\}\/usr\//g' $(find . -name "*.cmake" | grep _usr)
    fi
}

BBCLASSEXTEND = "native nativesdk"

FILES_${PN}-dev += " \
    ${libdir}/cmake/KF5*/*.cmake \
    ${prefix}/mkspecs/modules/qt_*.pri \
"
