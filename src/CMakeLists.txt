set(BINARY ${PROJECT_NAME})
add_executable(${BINARY} main.cpp vec3.cpp ray.cpp sphere.cpp hittable_list.cpp camera.cpp)
target_include_directories(${BINARY} INTERFACE ${CMAKE_CURRENT_LIST_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
		target_link_libraries(${BINARY} stdc++fs)
	endif()
endif()