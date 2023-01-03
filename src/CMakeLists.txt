set(PROJECT_LIBRARY_SRC_DIR
	${CMAKE_CURRENT_SOURCE_DIR}
	CACHE PATH "Recursive descent Parser' src directory"
)
set(PROJECT_LIBRARY_TARGET
	recursive_descent_lib
	CACHE STRING "Recursive descent Parser lib"
)
set(PROJECT_APP_TARGET
	recursive_descent_app
	CACHE STRING "Recursive descent Parser app"
)

set(_lib_headers_list
	pch.h

	parser/lexer/Lexer.h

	parser/Parser.h

	parser/context/ParserContext.h

	parser/syntax_analyzer/SyntaxAnalyzer.h

	parser/token/definitions/BaseToken.h
	parser/token/definitions/definitions.h
	parser/token/definitions/TokenDelimeter.h
	parser/token/definitions/TokenKeyword.h
	parser/token/definitions/TokenOperator.h
	parser/token/definitions/TokenSpecial.h
	parser/token/definitions/TokenType.h

	parser/token/values/TokenDelimiterValue.hpp
	parser/token/values/TokenKeywordValue.hpp
	parser/token/values/TokenOperatorValue.hpp
	parser/token/values/TokenSpecialValue.hpp
	parser/token/values/TokenTypeValue.hpp
	parser/token/values/TokenValue.hpp
	parser/token/values/values.h
)

set(_lib_src_list
	pch.cpp

	parser/lexer/Lexer.cpp

	parser/Parser.cpp

	parser/syntax_analyzer/SyntaxAnalyzer.cpp
)

add_library(${PROJECT_LIBRARY_TARGET}
	${_lib_headers_list}
	${_lib_src_list}
)

add_executable(${PROJECT_APP_TARGET}
	pch.h
	pch.cpp

	main.cpp
)

target_link_libraries(
	${PROJECT_APP_TARGET}
PRIVATE
	${PROJECT_LIBRARY_TARGET}	
)

target_include_directories(
	${PROJECT_LIBRARY_TARGET}
PRIVATE
	${PROJECT_LIBRARY_SRC_DIR}
)

target_include_directories(
	${PROJECT_APP_TARGET}
PRIVATE
	${PROJECT_LIBRARY_SRC_DIR}
)

if(MSVC)
	source_group(
		TREE ${CMAKE_CURRENT_SOURCE_DIR}
		PREFIX "Source Files"
		FILES ${_lib_src_list}
	)
	source_group(
		TREE ${CMAKE_CURRENT_SOURCE_DIR}
		PREFIX "Header Files"
		FILES ${_lib_headers_list}
	)
endif()
