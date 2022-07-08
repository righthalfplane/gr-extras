find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_EXTRAS_UBUNTU22_04 gnuradio-extras_uBuntu22_04)

FIND_PATH(
    GR_EXTRAS_UBUNTU22_04_INCLUDE_DIRS
    NAMES gnuradio/extras_uBuntu22_04/api.h
    HINTS $ENV{EXTRAS_UBUNTU22_04_DIR}/include
        ${PC_EXTRAS_UBUNTU22_04_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_EXTRAS_UBUNTU22_04_LIBRARIES
    NAMES gnuradio-extras_uBuntu22_04
    HINTS $ENV{EXTRAS_UBUNTU22_04_DIR}/lib
        ${PC_EXTRAS_UBUNTU22_04_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-extras_uBuntu22_04Target.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_EXTRAS_UBUNTU22_04 DEFAULT_MSG GR_EXTRAS_UBUNTU22_04_LIBRARIES GR_EXTRAS_UBUNTU22_04_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_EXTRAS_UBUNTU22_04_LIBRARIES GR_EXTRAS_UBUNTU22_04_INCLUDE_DIRS)
