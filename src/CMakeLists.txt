set(PROJECT_LIBRARY_SRC_DIR
	${CMAKE_CURRENT_SOURCE_DIR}
	CACHE PATH "Recursive descent Parser' src directory"
)
set(PROJECT_LIBRARY_TARGET
	recursive_descent_library
	CACHE INTERNAL "Recursive descent Parser lib"
)

add_library(${PROJECT_LIBRARY_TARGET}
	lexer/Lexer.hpp

	parser/Parser.h
	parser/Parser.cpp

	parser_context/ParserContext.hpp

	syntax_analyzer/SyntaxAnalyzer.hpp

	token/definitions/BaseToken.h
	token/definitions/definitions.h
	token/definitions/TokenDelimeter.h
	token/definitions/TokenKeyword.h
	token/definitions/TokenOperator.h
	token/definitions/TokenSpecial.h
	token/definitions/TokenType.h

	token/values/TokenDelimiterValue.hpp
	token/values/TokenKeywordValue.hpp
	token/values/TokenOperatorValue.hpp
	token/values/TokenSpecialValue.hpp
	token/values/TokenTypeValue.hpp
	token/values/TokenValue.hpp
	token/values/values.h
)

target_include_directories(
	${PROJECT_LIBRARY_TARGET}
PRIVATE
	${PROJECT_LIBRARY_SRC_DIR}
)
