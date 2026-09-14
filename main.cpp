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
#include "CppLocalVariableUnit.h"

#include "JavaClassUnit.h"
#include "JavaFieldUnit.h"
#include "JavaMethodUnit.h"
#include "JavaMethodArgumentUnit.h"
#include "JavaPrintOperatorUnit.h"
#include "JavaLocalVariableUnit.h"

#include "CSharpClassUnit.h"
#include "CSharpFieldUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpMethodArgumentUnit.h"
#include "CSharpPrintOperatorUnit.h"
#include "CSharpLocalVariableUnit.h"

#include "CppFactory.h"
#include "JavaFactory.h"
#include "CSharpFactory.h"


int main(int argc, char *argv[])
{

        /*
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

    CppMethodUnit prot_method2("Method2", Modifiers::ArgumentTypes::VOID, Modifiers::AccessModifiers::PROTECTED);
    prot_method2.addBody(std::make_shared<CppPrintOperatorUnit>(printOp1));
    prot_method2.addBody(std::make_shared<CppPrintOperatorUnit>(printOp2));


    claca.addMember(std::make_shared<CppFieldUnit>(pub_field1), Modifiers::AccessModifiers::PUBLIC);
    claca.addMember(std::make_shared<CppFieldUnit>(priv_field2), Modifiers::AccessModifiers::PRIVATE);
    claca.addMember(std::make_shared<CppFieldUnit>(prot_field3), Modifiers::AccessModifiers::PROTECTED);
    claca.addMember(std::make_shared<CppFieldUnit>(prot_field4), Modifiers::AccessModifiers::PROTECTED);

    claca.addMember(std::make_shared<CppMethodUnit>(pub_method1), Modifiers::AccessModifiers::PUBLIC);
    claca.addMember(std::make_shared<CppMethodUnit>(prot_method2), Modifiers::AccessModifiers::PROTECTED);
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
    
    jclaca.addMember(std::make_shared<JavaMethodUnit>(jmethod1), Modifiers::AccessModifiers::PUBLIC);
    jclaca.addMember(std::make_shared<JavaMethodUnit>(jmethod2), Modifiers::AccessModifiers::PRIVATE);
    
    */
    ///
    /// Factory fragment            (CPP)
    ///
    std::shared_ptr<IFactory> cppFactory = std::make_shared<CppFactory>();
    auto cppClassUnit = cppFactory->createClassUnit("MyCppClass");
    auto cppFieldUnit = cppFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);// Modifiers::AccessModifiers::PUBLIC);
    auto cppMethodUnit = cppFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID, Modifiers::MethodPrefixModifiers::STATIC);//, Modifiers::AccessModifiers::PRIVATE);
    auto cppMethodArgUnit = cppFactory->createMethodArgumentUnit("myArg", Modifiers::ArgumentTypes::STRING);
    auto cppLocalVarUnit = cppFactory->createLocalVariableUnit("LocalVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::ArgumentPrefixModifiers::STATIC);
    auto cppPrintOpUnit = cppFactory->createPrintOperatorUnit("Hello from CppFactory!");
    cppClassUnit->addMember(cppFieldUnit, Modifiers::AccessModifiers::PUBLIC);
    cppClassUnit->addMember(cppMethodUnit, Modifiers::AccessModifiers::PRIVATE);
    cppMethodUnit->addArgument(cppMethodArgUnit);
    cppMethodUnit->addBody(cppLocalVarUnit);
    cppMethodUnit->addBody(cppPrintOpUnit);

    //
    //  Factory fragment            (JAVA)
    //
    std::shared_ptr<IFactory> javaFactory = std::make_shared<JavaFactory>();
    auto javaClassUnit = javaFactory->createClassUnit("MyjavaClass");
    auto javaFieldUnit = javaFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);// Modifiers::AccessModifiers::PUBLIC);
    auto javaMethodUnit1 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto javaMethodUnit2 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto javaMethodUnit3 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto javaMethodUnit4 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    
    auto javaMethodArgUnit = javaFactory->createMethodArgumentUnit("myArg", Modifiers::ArgumentTypes::STRING);
    auto javaLocalVarUnit = javaFactory->createLocalVariableUnit("LocalVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::ArgumentPrefixModifiers::UNDEFINED);
    auto javaPrintOpUnit = javaFactory->createPrintOperatorUnit("Hello from javaFactory!");
    javaClassUnit->addMember(javaFieldUnit, Modifiers::AccessModifiers::PUBLIC);
    javaClassUnit->addMember(javaMethodUnit1, Modifiers::AccessModifiers::PRIVATE);
    javaClassUnit->addMember(javaMethodUnit2, Modifiers::AccessModifiers::PRIVATE);
    javaClassUnit->addMember(javaMethodUnit3, Modifiers::AccessModifiers::PRIVATE);
    javaClassUnit->addMember(javaMethodUnit4, Modifiers::AccessModifiers::PRIVATE);
    javaMethodUnit2->addArgument(javaMethodArgUnit);
    javaMethodUnit2->addBody(javaLocalVarUnit);
    javaMethodUnit3->addBody(javaPrintOpUnit);


    //
    //  Factory fragment            (CSharp)
    //
    std::shared_ptr<IFactory> cSharpFactory = std::make_shared<CSharpFactory>();
    auto CSharpClassUnit = cSharpFactory->createClassUnit("MyCSharpClass");
    auto CSharpFieldUnit = cSharpFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);// Modifiers::AccessModifiers::PUBLIC);
    auto CSharpMethodUnit1 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto CSharpMethodUnit2 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto CSharpMethodUnit3 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    auto CSharpMethodUnit4 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);//, Modifiers::AccessModifiers::PRIVATE);
    
    auto CSharpMethodArgUnit = cSharpFactory->createMethodArgumentUnit("myArg", Modifiers::ArgumentTypes::STRING);
    auto CSharpLocalVarUnit = cSharpFactory->createLocalVariableUnit("LocalVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::ArgumentPrefixModifiers::UNDEFINED);
    auto CSharpPrintOpUnit = cSharpFactory->createPrintOperatorUnit("Hello from CSharpFactory!");
    CSharpClassUnit->addMember(CSharpFieldUnit, Modifiers::AccessModifiers::PUBLIC);
    CSharpClassUnit->addMember(CSharpMethodUnit1, Modifiers::AccessModifiers::PRIVATE);
    CSharpClassUnit->addMember(CSharpMethodUnit2, Modifiers::AccessModifiers::PRIVATE);
    CSharpClassUnit->addMember(CSharpMethodUnit3, Modifiers::AccessModifiers::PRIVATE);
    CSharpClassUnit->addMember(CSharpMethodUnit4, Modifiers::AccessModifiers::PRIVATE);
    CSharpMethodUnit2->addArgument(CSharpMethodArgUnit);
    CSharpMethodUnit2->addBody(CSharpLocalVarUnit);
    CSharpMethodUnit3->addBody(CSharpPrintOpUnit);
    
    
    
    std::string stra = "Failed\n";
    try{
        stra = CSharpClassUnit->compile();
    } catch (std::invalid_argument &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout<<stra<<'\n';
    //std::cout << generateProgram() << std::endl;
    return 0;
}
