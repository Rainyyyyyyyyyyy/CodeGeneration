cmake_minimum_required(VERSION 3.10)
project(CodeGeneration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание библиотеки из исходных файлов в src/
add_library(CodeGenLib
    lib/Factory/IFactory.cpp
    lib/Factory/CppFactory.cpp
    #lib/Factory/JavaFactory.cpp

    lib/interfaces/Unit.cpp
    lib/interfaces/IClassUnit.cpp
    lib/interfaces/IFieldUnit.cpp
    lib/interfaces/IMethodUnit.cpp
    lib/interfaces/IMethodArgumentUnit.cpp
    lib/interfaces/IPrintOperatorUnit.cpp

    lib/Cpp/CppClassUnit.cpp
    lib/Cpp/CppFieldUnit.cpp
    lib/Cpp/CppMethodUnit.cpp
    lib/Cpp/CppMethodArgumentUnit.cpp
    lib/Cpp/CppPrintOperatorUnit.cpp

    lib/Java/JavaClassUnit.cpp
    lib/Java/JavaMethodUnit.cpp
    lib/Java/JavaMethodArgumentUnit.cpp
    lib/Java/JavaFieldUnit.cpp

    lib/utils/utils.cpp
    lib/utils/Modifiers.h

    
    #lib/Cpp/MethodUnit.cpp
    #src/PrintOperator.cpp
    #src/CppClassUnit.cpp
    #src/ClassUnit.cpp
)
target_include_directories(CodeGenLib PUBLIC 
    lib/interfaces
    lib/Cpp
    lib/Java
    lib/utils
    lib/Factory
    )

# Создание исполняемого файла
add_executable(CodeGeneration main.cpp)
target_include_directories(CodeGeneration PRIVATE lib)
target_link_libraries(CodeGeneration CodeGenLib)

# Установка директории для выходного .exe файла
set_target_properties(CodeGeneration PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
