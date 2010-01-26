# vim:set ts=8 sts=8 sw=8 noet:
project (m3gdecompile-bin)

include_directories(${CMAKE_SOURCE_DIR}/zlib)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/objects)

#add_custom_command (
#	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/java.yy.c
#		${CMAKE_CURRENT_SOURCE_DIR}/java_lex.h
#	COMMAND flex -o ${CMAKE_CURRENT_SOURCE_DIR}/java.yy.c
#		--header-file=${CMAKE_CURRENT_SOURCE_DIR}/java_lex.h
#		${CMAKE_CURRENT_SOURCE_DIR}/java.l
#)

#add_custom_command(
#	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/java.tab.c
#		${CMAKE_CURRENT_SOURCE_DIR}/java.tab.h
#	COMMAND bison --defines=${CMAKE_CURRENT_SOURCE_DIR}/java.tab.h
#		-o ${CMAKE_CURRENT_SOURCE_DIR}/java.tab.c
#		${CMAKE_CURRENT_SOURCE_DIR}/java.y
#)

set(m3gdecompile_SRCS
	main.cpp
	m3gfile.cpp
	m3gformat.cpp
	stream.cpp
	type_props.cpp
)

add_executable (
	m3gdecompile
	${m3gdecompile_SRCS}
)

target_link_libraries(
	m3gdecompile
	zlib
)

