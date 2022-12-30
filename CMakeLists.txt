cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)

project(parser CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################



























set(PROJECT_NAME parser)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "README.md"
)
source_group("" FILES ${no_group_source_files})

set(Header_Files
    "src/parser/Parser.h"
    "src/pch.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__Common__Constants
    "src/common/constants/Lexeme.h"
)
source_group("Header Files\\Common\\Constants" FILES ${Header_Files__Common__Constants})

set(Header_Files__Common__String
    "src/common/string/util.hpp"
)
source_group("Header Files\\Common\\String" FILES ${Header_Files__Common__String})

set(Header_Files__Common__Types
    "src/common/types/BasicTypes.h"
    "src/common/types/MetaTypes.h"
)
source_group("Header Files\\Common\\Types" FILES ${Header_Files__Common__Types})

set(Header_Files__Methods
    "src/methods/Methods.h"
)
source_group("Header Files\\Methods" FILES ${Header_Files__Methods})

set(Header_Files__Parser
    "src/parser/common_parser.h"
    "src/parser/IParser.h"
    "src/parser/IParser_fwd.h"
)
source_group("Header Files\\Parser" FILES ${Header_Files__Parser})

set(Header_Files__Parser__Lexeme__CLexeme
    "src/parser/lexeme/CLexeme/CLexeme.hpp"
)
source_group("Header Files\\Parser\\Lexeme\\CLexeme" FILES ${Header_Files__Parser__Lexeme__CLexeme})

set(Header_Files__Parser__Lexeme__Exception
    "src/parser/lexeme/exception/ILexemeException.h"
)
source_group("Header Files\\Parser\\Lexeme\\Exception" FILES ${Header_Files__Parser__Lexeme__Exception})

set(Header_Files__Parser__Lexeme__Exception__CException
    "src/parser/lexeme/exception/CException/LexemeException.hpp"
)
source_group("Header Files\\Parser\\Lexeme\\Exception\\CException" FILES ${Header_Files__Parser__Lexeme__Exception__CException})

set(Header_Files__Parser__Lexeme__Token
    "src/parser/lexeme/token/all.h"
    "src/parser/lexeme/token/BaseToken.h"
)
source_group("Header Files\\Parser\\Lexeme\\Token" FILES ${Header_Files__Parser__Lexeme__Token})

set(Header_Files__Parser__Lexeme__Token__Delimeter
    "src/parser/lexeme/token/delimeter/TokenDelimeter.h"
)
source_group("Header Files\\Parser\\Lexeme\\Token\\Delimeter" FILES ${Header_Files__Parser__Lexeme__Token__Delimeter})

set(Header_Files__Parser__Lexeme__Token__Enum
    "src/parser/lexeme/token/enum/TokenEnum.hpp"
)
source_group("Header Files\\Parser\\Lexeme\\Token\\Enum" FILES ${Header_Files__Parser__Lexeme__Token__Enum})

set(Header_Files__Parser__Lexeme__Token__Iidentifier
    "src/parser/lexeme/token/identifier/TokenIdentifier.h"
)
source_group("Header Files\\Parser\\Lexeme\\Token\\Iidentifier" FILES ${Header_Files__Parser__Lexeme__Token__Iidentifier})

set(Header_Files__Parser__Lexeme__Token__Keyword
    "src/parser/lexeme/token/keyword/TokenKeyword.h"
)
source_group("Header Files\\Parser\\Lexeme\\Token\\Keyword" FILES ${Header_Files__Parser__Lexeme__Token__Keyword})

set(Header_Files__Parser__Lexeme__Token__Type
    "src/parser/lexeme/token/type/TokenType.h"
)
source_group("Header Files\\Parser\\Lexeme\\Token\\Type" FILES ${Header_Files__Parser__Lexeme__Token__Type})

set(Source_Files
    "src/main.cpp"
    "src/parser/Parser.cpp"
    "src/pch.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(Source_Files__Methods
    "src/methods/Methods.cpp"
)
source_group("Source Files\\Methods" FILES ${Source_Files__Methods})

set(ALL_FILES
    ${no_group_source_files}
    ${Header_Files}
    ${Header_Files__Common__Constants}
    ${Header_Files__Common__String}
    ${Header_Files__Common__Types}
    ${Header_Files__Methods}
    ${Header_Files__Parser}
    ${Header_Files__Parser__Lexeme__CLexeme}
    ${Header_Files__Parser__Lexeme__Exception}
    ${Header_Files__Parser__Lexeme__Exception__CException}
    ${Header_Files__Parser__Lexeme__Token}
    ${Header_Files__Parser__Lexeme__Token__Delimeter}
    ${Header_Files__Parser__Lexeme__Token__Enum}
    ${Header_Files__Parser__Lexeme__Token__Iidentifier}
    ${Header_Files__Parser__Lexeme__Token__Keyword}
    ${Header_Files__Parser__Lexeme__Token__Type}
    ${Source_Files}
    ${Source_Files__Methods}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE parser)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /std:c++latest;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /std:c++latest;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

