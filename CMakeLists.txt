cmake_minimum_required(VERSION 3.10)
project(CodeGeneration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание библиотеки из исходных файлов в src/
add_library(CodeGenLib
    lib/Factory/IFactory.h
    lib/Factory/CppFactory.cpp
    lib/Factory/JavaFactory.cpp
    lib/Factory/CSharpFactory.cpp

    lib/interfaces/Unit.cpp
    lib/interfaces/IClassUnit.cpp
    lib/interfaces/IFieldUnit.cpp
    lib/interfaces/IMethodUnit.cpp
    lib/interfaces/IMethodArgumentUnit.cpp
    lib/interfaces/IPrintOperatorUnit.cpp
    lib/interfaces/ILocalVariableUnit.cpp

    lib/Cpp/CppClassUnit.cpp
    lib/Cpp/CppFieldUnit.cpp
    lib/Cpp/CppMethodUnit.cpp
    lib/Cpp/CppMethodArgumentUnit.cpp
    lib/Cpp/CppPrintOperatorUnit.cpp
    lib/Cpp/CppLocalVariableUnit.cpp

    lib/Java/JavaClassUnit.cpp
    lib/Java/JavaMethodUnit.cpp
    lib/Java/JavaMethodArgumentUnit.cpp
    lib/Java/JavaFieldUnit.cpp
    lib/Java/JavaPrintOperatorUnit.cpp
    lib/Java/JavaLocalVariableUnit.cpp

    lib/CSharp/CSharpClassUnit.cpp
    lib/CSharp/CSharpMethodUnit.cpp
    lib/CSharp/CSharpMethodArgumentUnit.cpp
    lib/CSharp/CSharpFieldUnit.cpp
    lib/CSharp/CSharpPrintOperatorUnit.cpp
    lib/CSharp/CSharpLocalVariableUnit.cpp

    lib/utils/utils.cpp
    lib/utils/CppUtils.cpp
    lib/utils/JavaUtils.cpp
    lib/utils/CSharpUtils.cpp
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
    lib/Factory
    lib/CSharp
    lib/utils
    )

# Создание исполняемого файла
add_executable(CodeGeneration main.cpp)
target_include_directories(CodeGeneration PRIVATE lib)
target_link_libraries(CodeGeneration CodeGenLib)

add_executable(CodeGenerationTests test_main.cpp)
target_include_directories(CodeGenerationTests PRIVATE lib)
target_link_libraries(CodeGenerationTests CodeGenLib)

# Установка директории для выходного .exe файла
set_target_properties(CodeGeneration PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
