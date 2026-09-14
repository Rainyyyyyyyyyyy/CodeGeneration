#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "IClassUnit.h"
#include "IFactory.h"
#include "IFieldUnit.h"
#include "IMethodArgumentUnit.h"
#include "IMethodUnit.h"
#include "IPrintOperatorUnit.h"

#include "CSharpClassUnit.h"
#include "CSharpFactory.h"
#include "CSharpFieldUnit.h"
#include "CSharpMethodArgumentUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

#include "CppClassUnit.h"
#include "CppFactory.h"
#include "CppFieldUnit.h"
#include "CppMethodArgumentUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

#include "JavaClassUnit.h"
#include "JavaFactory.h"
#include "JavaFieldUnit.h"
#include "JavaMethodArgumentUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

namespace
{
    enum class Language
    {
        Cpp,
        Java,
        CSharp
    };

    std::shared_ptr<IFactory> createFactory(Language language)
    {
        switch (language)
        {
        case Language::Cpp:
            return std::make_shared<CppFactory>();
        case Language::Java:
            return std::make_shared<JavaFactory>();
        case Language::CSharp:
            return std::make_shared<CSharpFactory>();
        }

        throw std::invalid_argument("Unsupported language");
    }

    void testCppObjects()
    {
        CppFieldUnit field("count", Modifiers::ArgumentTypes::INT);
        CppMethodArgumentUnit argument("message", Modifiers::ArgumentTypes::STRING);
        CppPrintOperatorUnit print("Hello from C++ object");
        CppMethodUnit method("show", Modifiers::ArgumentTypes::VOID);
        CppClassUnit classUnit("CppClass");

        method.addArgument(std::make_shared<CppMethodArgumentUnit>(argument));
        method.addBody(std::make_shared<CppPrintOperatorUnit>(print));
        classUnit.addMember(std::make_shared<CppFieldUnit>(field), Modifiers::AccessModifiers::PRIVATE);
        classUnit.addMember(std::make_shared<CppMethodUnit>(method), Modifiers::AccessModifiers::PUBLIC);

        const std::string generated = classUnit.compile();
        std::cout << "====================================================\n";
        std::cout << "------------------ Cpp Generation ------------------\n"
                  << generated << "\n";
    }

    void testJavaObjects()
    {
        JavaClassUnit classUnit("JavaClass");
        JavaFieldUnit field("name", Modifiers::ArgumentTypes::STRING);
        JavaMethodUnit method("printName", Modifiers::ArgumentTypes::VOID);
        JavaMethodArgumentUnit argument("message", Modifiers::ArgumentTypes::STRING);
        JavaPrintOperatorUnit print("Hello from Java object");

        method.addArgument(std::make_shared<JavaMethodArgumentUnit>(argument));
        method.addBody(std::make_shared<JavaPrintOperatorUnit>(print));
        classUnit.addMember(std::make_shared<JavaFieldUnit>(field), Modifiers::AccessModifiers::PRIVATE);
        classUnit.addMember(std::make_shared<JavaMethodUnit>(method), Modifiers::AccessModifiers::PUBLIC);

        const std::string generated = classUnit.compile();
        std::cout << "=====================================================\n";
        std::cout << "------------------ Java Generation ------------------\n"
                  << generated << "\n";
    }

    void testCSharpObjects()
    {
        CSharpClassUnit classUnit("CSharpClass");
        CSharpFieldUnit field("enabled", Modifiers::ArgumentTypes::BOOL);
        CSharpMethodUnit method("write", Modifiers::ArgumentTypes::VOID);
        CSharpMethodArgumentUnit argument("value", Modifiers::ArgumentTypes::INT);
        CSharpPrintOperatorUnit print("Hello from CSharp object");

        method.addArgument(std::make_shared<CSharpMethodArgumentUnit>(argument));
        method.addBody(std::make_shared<CSharpPrintOperatorUnit>(print));
        classUnit.addMember(std::make_shared<CSharpFieldUnit>(field), Modifiers::AccessModifiers::PRIVATE);
        classUnit.addMember(std::make_shared<CSharpMethodUnit>(method), Modifiers::AccessModifiers::PUBLIC);

        const std::string generated = classUnit.compile();
        std::cout << "=======================================================\n";
        std::cout << "------------------ CSharp Generation ------------------\n"
                  << generated << "\n";
    }

    void testCppFactory()
    {
        CppFactory factory;
        const auto classUnit = factory.createClassUnit("FactoryCppClass");
        const auto field = factory.createFieldUnit("value", Modifiers::ArgumentTypes::DOUBLE);
        const auto method = factory.createMethodUnit("run", Modifiers::ArgumentTypes::VOID);
        const auto print = factory.createPrintOperatorUnit("Hello from Cpp factory");

        method->addBody(print);
        classUnit->addMember(field, Modifiers::AccessModifiers::PUBLIC);
        classUnit->addMember(method, Modifiers::AccessModifiers::PUBLIC);

        const std::string generated = classUnit->compile();
        std::cout << "=================================================================\n";
        std::cout << "------------------ Cpp Generation (CppFactory) ------------------\n"
                  << generated << "\n";
    }

    void testAbstractFactory(Language language, const std::string &className, const std::string &message)
    {
        const std::shared_ptr<IFactory> factory = createFactory(language);
        const auto classUnit = factory->createClassUnit(className);
        const auto method = factory->createMethodUnit("run", Modifiers::ArgumentTypes::VOID);
        const auto argument = factory->createMethodArgumentUnit("value", Modifiers::ArgumentTypes::STRING);
        const auto print = factory->createPrintOperatorUnit(message);

        method->addArgument(argument);
        method->addBody(print);
        classUnit->addMember(method, Modifiers::AccessModifiers::PUBLIC);

        const std::string generated = classUnit->compile();
        std::cout << "==================================================================\n";
        std::cout << "------------------ Generation (AbstractFactory) ------------------\n"
                  << generated << "\n";
    }

}

int main()
{
    try
    {
        testCppObjects();
        testJavaObjects();
        testCSharpObjects();
        testCppFactory();
        testAbstractFactory(Language::Cpp, "CppClassFromAbstractFactory", "Hello from abstract C++ factory");
        testAbstractFactory(Language::Java, "AJavaClassClassFromAbstractFactory", "Hello from abstract Java factory");
        testAbstractFactory(Language::CSharp, "CSharpClassClassFromAbstractFactory", "Hello from abstract C# factory");
    }
    catch (std::invalid_argument &error)
    {
        std::cout << "FAIL: " << error.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cout << "Unexpected error\n";
    }

    return 0;
}
