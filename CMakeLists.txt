cmake_minimum_required(VERSION 3.5)

project(CUDAProbe)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "https://github.com/gregsharp/Slicer-CUDAProbe")
set(EXTENSION_CATEGORY "Developer Tools")
set(EXTENSION_CONTRIBUTORS "Gregory Sharp (Massachusetts General Hospital)")
set(EXTENSION_DESCRIPTION "This extension queries your computer for its CUDA capabilities.  It also serves as an example of how to use CUDA in your Slicer Extension.")
set(EXTENSION_ICONURL "https://raw.githubusercontent.com/gregsharp/Slicer-CUDAProbe/master/CUDAProbe.png")
set(EXTENSION_SCREENSHOTURLS "https://raw.githubusercontent.com/gregsharp/Slicer-CUDAProbe/master/CUDAProbe-screenshot.png")
set(EXTENSION_DEPENDS "NA") # Specified as a space separated string, a list or 'NA' if any
set(EXTENSION_STATUS "Work in progress")

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

# Some systems such as pcBSD don't have libdl
find_library (LIBDL_FOUND dl)

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(CUDAProbe)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
