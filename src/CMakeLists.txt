set(BINARY ${PROJECT_NAME})
add_executable(${BINARY} main.cpp vec3.hpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
		target_link_libraries(${BINARY} stdc++fs)
	endif()
endif()