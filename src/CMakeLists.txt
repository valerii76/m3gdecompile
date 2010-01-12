project (freeassistant-bin)

add_custom_command (
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/java.yy.c
		${CMAKE_CURRENT_SOURCE_DIR}/java_lex.h
	COMMAND flex -o ${CMAKE_CURRENT_SOURCE_DIR}/java.yy.c
		--header-file=${CMAKE_CURRENT_SOURCE_DIR}/java_lex.h
		${CMAKE_CURRENT_SOURCE_DIR}/java.l
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/java.tab.c
		${CMAKE_CURRENT_SOURCE_DIR}/java.tab.h
	COMMAND bison --defines=${CMAKE_CURRENT_SOURCE_DIR}/java.tab.h
		-o ${CMAKE_CURRENT_SOURCE_DIR}/java.tab.c
		${CMAKE_CURRENT_SOURCE_DIR}/java.y
)

set(freeassistant_SRCS
	main.c
	java.yy.c
	java.tab.c
)

add_executable (
	freeassistant
	${freeassistant_SRCS}
)

target_link_libraries(
	freeassistant
)

