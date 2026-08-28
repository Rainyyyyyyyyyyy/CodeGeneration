cmake_minimum_required(VERSION 3.10)
project(CodeGeneration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание библиотеки из исходных файлов в src/
add_library(CodeGenLib src/Unit.cpp src/ClassUnit.cpp src/MethodUnit.cpp src/PrintOperator.cpp)
target_include_directories(CodeGenLib PUBLIC lib)

# Создание исполняемого файла
add_executable(CodeGeneration main.cpp)
target_include_directories(CodeGeneration PRIVATE lib)
target_link_libraries(CodeGeneration CodeGenLib)

# Установка директории для выходного .exe файла
set_target_properties(CodeGeneration PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
