#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-extras" for configuration "Release"
set_property(TARGET gnuradio::gnuradio-extras APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gnuradio::gnuradio-extras PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgnuradio-extras.v1.0-compat-xxx-xunknown.dylib"
  IMPORTED_SONAME_RELEASE "/opt/local/lib/libgnuradio-extras.1.0.0git.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gnuradio::gnuradio-extras )
list(APPEND _IMPORT_CHECK_FILES_FOR_gnuradio::gnuradio-extras "${_IMPORT_PREFIX}/lib/libgnuradio-extras.v1.0-compat-xxx-xunknown.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
