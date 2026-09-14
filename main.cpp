#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

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
    std::shared_ptr<IFactory> cppFactory = std::make_shared<CppFactory>();
    auto cppClassUnit = cppFactory->createClassUnit("MyCppClass");
    auto cppFieldUnit = cppFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);
    auto cppMethodUnit = cppFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID, Modifiers::MethodPrefixModifiers::STATIC);
    auto cppMethodArgUnit = cppFactory->createMethodArgumentUnit("myArg", Modifiers::ArgumentTypes::STRING);
    auto cppLocalVarUnit = cppFactory->createLocalVariableUnit("LocalVar1", Modifiers::ArgumentTypes::DOUBLE, Modifiers::ArgumentPrefixModifiers::STATIC);
    auto cppPrintOpUnit = cppFactory->createPrintOperatorUnit("Hello from CppFactory!");
    cppClassUnit->addMember(cppFieldUnit, Modifiers::AccessModifiers::PUBLIC);
    cppClassUnit->addMember(cppMethodUnit, Modifiers::AccessModifiers::PRIVATE);
    cppMethodUnit->addArgument(cppMethodArgUnit);
    cppMethodUnit->addBody(cppLocalVarUnit);
    cppMethodUnit->addBody(cppPrintOpUnit);

    std::shared_ptr<IFactory> javaFactory = std::make_shared<JavaFactory>();
    auto javaClassUnit = javaFactory->createClassUnit("MyjavaClass");
    auto javaFieldUnit = javaFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);
    auto javaMethodUnit1 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto javaMethodUnit2 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto javaMethodUnit3 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto javaMethodUnit4 = javaFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    
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


    std::shared_ptr<IFactory> cSharpFactory = std::make_shared<CSharpFactory>();
    auto CSharpClassUnit = cSharpFactory->createClassUnit("MyCSharpClass");
    auto CSharpFieldUnit = cSharpFactory->createFieldUnit("myField", Modifiers::ArgumentTypes::INT);
    auto CSharpMethodUnit1 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto CSharpMethodUnit2 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto CSharpMethodUnit3 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    auto CSharpMethodUnit4 = cSharpFactory->createMethodUnit("myMethod", Modifiers::ArgumentTypes::VOID);
    
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
        stra = cppClassUnit->compile();
    } catch (std::invalid_argument &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout<<stra<<'\n';
    return 0;
}
