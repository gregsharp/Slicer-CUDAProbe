
#-----------------------------------------------------------------------------
set(MODULE_NAME CUDAProbe)

#-----------------------------------------------------------------------------
# SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

# CUDA
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package (CUDA_wrap)
set (CUDA_FOUND ${CUDA_FOUND} CACHE BOOL "Did we find cuda?")
if (CUDA_FOUND)
  cuda_include_directories (${CMAKE_CURRENT_SOURCE_DIR})
endif ()

# Config file
configure_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/CUDAProbe.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/CUDAProbe.h
  @ONLY)

#-----------------------------------------------------------------------------
set(MODULE_INCLUDE_DIRECTORIES
  ${CMAKE_CURRENT_BINARY_DIR}
  )

set(MODULE_SRCS
  )

set(MODULE_TARGET_LIBRARIES
  )

#-----------------------------------------------------------------------------
SEMMacroBuildCLI(
  NAME ${MODULE_NAME}
  TARGET_LIBRARIES ${MODULE_TARGET_LIBRARIES}
  INCLUDE_DIRECTORIES ${MODULE_INCLUDE_DIRECTORIES}
  ADDITIONAL_SRCS ${MODULE_SRCS}
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)
  add_subdirectory(Testing)
endif()
