# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\realProgect_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\realProgect_autogen.dir\\ParseCache.txt"
  "realProgect_autogen"
  )
endif()
