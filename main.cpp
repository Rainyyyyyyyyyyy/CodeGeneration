//#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>


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
#include "CppPrintOperatorUnit.h"

#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaMethodArgumentUnit.h"


#include "CppFactory.h"

int main(int argc, char *argv[])
{

    const std::string className = "MyClass";
    CppClassUnit claca(className, Modifiers::ClassPrefixModifiers::UNDEFINED); //Modifiers::ClassModifiers::UNDEFINED);
    
    CppFieldUnit pub_field1("Field1", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PUBLIC);
    CppFieldUnit priv_field2("Field2", Modifiers::ArgumentTypes::STRING, Modifiers::AccessModifiers::PRIVATE);
    CppFieldUnit prot_field3("Field3", Modifiers::ArgumentTypes::DOUBLE, Modifiers::AccessModifiers::PROTECTED);
    CppFieldUnit prot_field4("Field4", Modifiers::ArgumentTypes::UNDEFINED, Modifiers::AccessModifiers::PROTECTED);

    CppPrintOperatorUnit printOp1("Hello, world!");
    CppPrintOperatorUnit printOp2("This is a test message.");

    CppMethodUnit pub_method1("Method1", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PUBLIC);
    pub_method1.addArgument(std::make_shared<CppMethodArgumentUnit>("arg1", Modifiers::ArgumentTypes::INT));
    pub_method1.addArgument(std::make_shared<CppMethodArgumentUnit>("arg2", Modifiers::ArgumentTypes::STRING));
    pub_method1.add(std::make_shared<CppFieldUnit>("localVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::AccessModifiers::PRIVATE), 0);

    CppMethodUnit prot_method2("Method2", Modifiers::ArgumentTypes::VOID, Modifiers::AccessModifiers::PROTECTED);
    prot_method2.add(std::make_shared<CppPrintOperatorUnit>(printOp1), 0);
    prot_method2.add(std::make_shared<CppPrintOperatorUnit>(printOp2), 0);


    claca.add(std::make_shared<CppFieldUnit>(pub_field1), static_cast<CppClassUnit::Flags>(pub_field1.GetAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(priv_field2), static_cast<CppClassUnit::Flags>(priv_field2.GetAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(prot_field3), static_cast<CppClassUnit::Flags>(prot_field3.GetAccessModifier()));
    claca.add(std::make_shared<CppFieldUnit>(prot_field4), static_cast<CppClassUnit::Flags>(prot_field4.GetAccessModifier()));

    claca.add(std::make_shared<CppMethodUnit>(pub_method1), static_cast<CppClassUnit::Flags>(pub_method1.GetAccessModifier()));
    claca.add(std::make_shared<CppMethodUnit>(prot_method2), static_cast<CppClassUnit::Flags>(prot_method2.GetAccessModifier()));
    //claca.add()


    ///
    ///     Java fragment
    ///


    JavaClassUnit jclaca(className, Modifiers::ClassPrefixModifiers::UNDEFINED); //Modifiers::ClassModifiers::UNDEFINED);
    JavaMethodUnit jmethod1("Method1", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PUBLIC);
    JavaMethodUnit jmethod2("Method2", Modifiers::ArgumentTypes::DOUBLE, Modifiers::AccessModifiers::PRIVATE);
    
    JavaMethodArgumentUnit jarg1("arg1", Modifiers::ArgumentTypes::INT);
    JavaMethodArgumentUnit jarg2("arg2", Modifiers::ArgumentTypes::STRING);
    JavaMethodArgumentUnit jarg3("arg3", Modifiers::ArgumentTypes::DOUBLE);

    jmethod1.addArgument(std::make_shared<JavaMethodArgumentUnit>(jarg1));
    jmethod1.addArgument(std::make_shared<JavaMethodArgumentUnit>(jarg2));
    jmethod2.addArgument(std::make_shared<JavaMethodArgumentUnit>(jarg3));
    
    jclaca.add(std::make_shared<JavaMethodUnit>(jmethod1), static_cast<JavaClassUnit::Flags>(jmethod1.GetAccessModifier()));
    jclaca.add(std::make_shared<JavaMethodUnit>(jmethod2), static_cast<JavaClassUnit::Flags>(jmethod2.GetAccessModifier()));
    

    ///
    /// Factory fragment
    ///
    CppFactory cppFactory;
    auto cppClassUnit = cppFactory.createClassUnit("MyCppClass");
    auto cppFieldUnit = cppFactory.createFieldUnit("myField", Modifiers::ArgumentTypes::INT, Modifiers::AccessModifiers::PUBLIC);
    auto cppMethodUnit = cppFactory.createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID, Modifiers::AccessModifiers::PRIVATE);
    auto cppMethodArgUnit = cppFactory.createMethodArgumentUnit("myArg", Modifiers::ArgumentTypes::STRING);
    cppClassUnit->add(cppFieldUnit, static_cast<CppClassUnit::Flags>(cppFieldUnit->GetAccessModifier()));
    cppClassUnit->add(cppMethodUnit, static_cast<CppClassUnit::Flags>(cppMethodUnit->GetAccessModifier()));
    
    
    std::string stra = "Failed\n";
    try{
        stra = cppClassUnit->compile();
    } catch (std::invalid_argument &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout<<stra<<'\n';
    //std::cout << generateProgram() << std::endl;
    return 0;
}
