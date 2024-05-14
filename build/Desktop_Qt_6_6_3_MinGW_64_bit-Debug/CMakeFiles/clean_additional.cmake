# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BudgetManager_autogen"
  "CMakeFiles\\BudgetManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BudgetManager_autogen.dir\\ParseCache.txt"
  )
endif()
