
cmake_minimum_required(VERSION 3.25)

project(PortLens
    VERSION 0.1.0
    LANGUAGES CXX
)

# Create executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Require C++23
target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_23
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Download Saucer
include(FetchContent)

FetchContent_Declare(
    saucer
    GIT_REPOSITORY https://github.com/saucer/saucer
    GIT_TAG v8.0.5
)

FetchContent_MakeAvailable(saucer)

# Link Saucer
target_link_libraries(${PROJECT_NAME}
    PRIVATE saucer::saucer
)
