# vim:set ts=8 sts=8 sw=8 noet:
project (m3gdecompile)
cmake_minimum_required (VERSION 2.6.0)

set (APPLICATION_VERSION_MAJOR "0")
set (APPLICATION_VERSION_MINOR "0")
set (APPLICATION_VERSION_PATCH "pre1")

set (CMAKE_BUILD_TYPE "Debug")

add_subdirectory (src)
add_subdirectory (zlib)

