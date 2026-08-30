//#include <QCoreApplication>
#include <iostream>


#include "lib/MethodUnit.h"
#include "lib/ClassUnit.h"
#include "lib/PrintOperator.h"


std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
                                               MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}


// сборка: g++ main.cpp src/Unit.cpp -o build\Release\CodeGeneration.exe -Ilib/

// сборка через cmake: cmake -B build                                           *
/*                     cmake --build build --config Release                     *
 * из коммандной строки на уровне CMakeLists.txt                                *
 * исполняемый файл будет расположен по пути: build\Release\CodeGeneration.exe  *
 */ 

 #include "CppClassUnit.h"
int main(int argc, char *argv[])
{
    const std::string className = "MyClass";
    CppClassUnit claca(className, Modifiers::ClassModifiers::UNDEFINED);
    std::string stra = "Failed\n";
    try{
        stra = claca.compile();
    } catch (std::invalid_argument &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout<<stra<<'\n';
    //std::cout << generateProgram() << std::endl;
    return 0;
}
