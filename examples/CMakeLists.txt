message(STATUS "Configuring examples")

file(GLOB EXAMPLES_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*) # Get all directories in the current directory
foreach (EXAMPLE_DIR ${EXAMPLES_DIRS})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_DIR}/main.cpp)
        add_executable(${EXAMPLE_DIR} ${EXAMPLE_DIR}/main.cpp)
        file(GLOB_RECURSE EXAMPLES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_DIR}/*.hpp)
        target_sources(${EXAMPLE_DIR} PRIVATE ${EXAMPLES_FILES})

        target_link_libraries(${EXAMPLE_DIR} ${PROJECT_NAME})
    else ()
        message(STATUS "Skipping ${EXAMPLE_DIR}")
    endif ()
endforeach ()