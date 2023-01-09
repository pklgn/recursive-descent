Include(FetchContent)

## Catch2 ##

function(fetch_catch)

	FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.2.1
	)

	FetchContent_MakeAvailable(Catch2)
	list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

	include(Catch)

endfunction()

