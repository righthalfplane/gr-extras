INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_EXTRAS extras)

FIND_PATH(
    EXTRAS_INCLUDE_DIRS
    NAMES extras/api.h
    HINTS $ENV{EXTRAS_DIR}/include
        ${PC_EXTRAS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    EXTRAS_LIBRARIES
    NAMES gnuradio-extras
    HINTS $ENV{EXTRAS_DIR}/lib
        ${PC_EXTRAS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(EXTRAS DEFAULT_MSG EXTRAS_LIBRARIES EXTRAS_INCLUDE_DIRS)
MARK_AS_ADVANCED(EXTRAS_LIBRARIES EXTRAS_INCLUDE_DIRS)

