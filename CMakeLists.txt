cmake_minimum_required(VERSION 3.5)

project(CUDAProbe)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "http://slicer.org/slicerWiki/index.php/Documentation/Nightly/Extensions/CUDAProbe")
set(EXTENSION_CATEGORY "Utilities")
set(EXTENSION_CONTRIBUTORS "Gregory Sharp (Massachusetts General Hospital)")
set(EXTENSION_DESCRIPTION "This extension queries your computer for its CUDA capabilities.")
set(EXTENSION_ICONURL "http://www.example.com/Slicer/Extensions/CUDAProbe.png")
set(EXTENSION_SCREENSHOTURLS "http://www.example.com/Slicer/Extensions/CUDAProbe/Screenshots/1.png")
set(EXTENSION_DEPENDS "NA") # Specified as a space separated string, a list or 'NA' if any

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(CUDAProbe)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
