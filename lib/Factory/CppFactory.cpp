#include "CppFactory.h"

#include "CppClassUnit.h"
#include "CppFieldUnit.h"
#include "CppMethodUnit.h"
#include "CppMethodArgumentUnit.h"
#include "CppPrintOperatorUnit.h"
#include "CppLocalVariableUnit.h"


std::shared_ptr<IClassUnit> CppFactory::createClassUnit(const std::string &name, Modifiers::ClassPrefixModifiers classPrefixModifier) const
{
    return std::make_shared<CppClassUnit>(name, classPrefixModifier);
}

std::shared_ptr<IFieldUnit> CppFactory::createFieldUnit(const std::string &name,
                                                        const Modifiers::ArgumentTypes &type,
                                                        const Modifiers::AccessModifiers &accessModifier,
                                                        const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<CppFieldUnit>(name, type, accessModifier, prefixModifier);
}

std::shared_ptr<IMethodUnit> CppFactory::createMethodUnit(const std::string &name,
                                                          const Modifiers::ArgumentTypes &type,
                                                          const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<CppMethodUnit>(name, type, accessModifier);
}

std::shared_ptr<IMethodArgumentUnit> CppFactory::createMethodArgumentUnit(const std::string &name,
                                                                          const Modifiers::ArgumentTypes &type) const
{
    return std::make_shared<CppMethodArgumentUnit>(name, type);
}

std::shared_ptr<IPrintOperatorUnit> CppFactory::createPrintOperatorUnit(const std::string &text) const
{
    return std::make_shared<CppPrintOperatorUnit>(text);
}

std::shared_ptr<IStatementUnit> CppFactory::createLocalVariableUnit(
    const std::string &name,
    const Modifiers::ArgumentTypes &type,
    const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<CppLocalVariableUnit>(name, type, prefixModifier);
}