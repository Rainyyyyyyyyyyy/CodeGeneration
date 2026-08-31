//#include <QCoreApplication>
#include <iostream>


//#include "lib/MethodUnit.h"
//#include "lib/ClassUnit.h"
//#include "lib/PrintOperator.h"

/*
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

*/
// сборка: g++ main.cpp src/Unit.cpp -o build\Release\CodeGeneration.exe -Ilib/

// сборка через cmake: cmake -B build                                           *
/*                     cmake --build build --config Release                     *
 * из коммандной строки на уровне CMakeLists.txt                                *
 * исполняемый файл будет расположен по пути: build\Release\CodeGeneration.exe  *
 */ 

#include "CppClassUnit.h"
#include "CppFieldUnit.h"
#include "CppMethodUnit.h"
#include "CppMethodArgumentUnit.h"
int main(int argc, char *argv[])
{
    const std::string className = "MyClass";
    CppClassUnit claca(className, Modifiers::ClassModifiers::UNDEFINED);
    
    CppFieldUnit pub_field1("Field1", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PUBLIC);
    CppFieldUnit priv_field2("Field2", Modifiers::ArgumentTypes::STRING, Modifiers::AccessModifiers::PRIVATE);
    CppFieldUnit prot_field3("Field3", Modifiers::ArgumentTypes::DOUBLE, Modifiers::AccessModifiers::PROTECTED);
    CppFieldUnit prot_field4("Field4", Modifiers::ArgumentTypes::UNDEFINED, Modifiers::AccessModifiers::PROTECTED);

    CppMethodUnit pub_method1("Method1", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PROTECTED);
    pub_method1.addArgument(std::make_shared<CppMethodArgumentUnit>("arg1", Modifiers::ArgumentTypes::INT));
    pub_method1.addArgument(std::make_shared<CppMethodArgumentUnit>("arg2", Modifiers::ArgumentTypes::STRING));
    pub_method1.add(std::make_shared<CppFieldUnit>("localVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::AccessModifiers::PRIVATE), 0);

    claca.add(std::make_shared<CppFieldUnit>(pub_field1), static_cast<CppClassUnit::Flags>(pub_field1.getAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(priv_field2), static_cast<CppClassUnit::Flags>(priv_field2.getAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(prot_field3), static_cast<CppClassUnit::Flags>(prot_field3.getAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(prot_field4), static_cast<CppClassUnit::Flags>(prot_field4.getAccessModifier()));

    claca.add(std::make_shared<CppMethodUnit>(pub_method1), static_cast<CppClassUnit::Flags>(pub_method1.getAccessModifier()));
    //claca.add()

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
