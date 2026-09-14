#include "CSharpFactory.h"

#include "CSharpClassUnit.h"
#include "CSharpFieldUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpMethodArgumentUnit.h"
#include "CSharpPrintOperatorUnit.h"
#include "CSharpLocalVariableUnit.h"

// Старая сигнатура сохраняется для истории:
// std::shared_ptr<IClassUnit> JavaFactory::createClassUnit(
//     const std::string &name,
//     Modifiers::ClassPrefixModifiers classPrefixModifier) const
// {
//     return std::make_shared<JavaClassUnit>(name, classPrefixModifier);
// }

std::shared_ptr<IClassUnit> CSharpFactory::createClassUnit(const std::string &name,
                                                           const Modifiers::ClassPrefixModifiers &classPrefixModifier) const
// const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<CSharpClassUnit>(name, classPrefixModifier); //, accessModifier);
}

std::shared_ptr<IFieldUnit> CSharpFactory::createFieldUnit(const std::string &name,
                                                           const Modifiers::ArgumentTypes &type,
                                                           const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
// const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<CSharpFieldUnit>(name, type, prefixModifier); //, accessModifier);
}

std::shared_ptr<IMethodUnit> CSharpFactory::createMethodUnit(const std::string &name,
                                                             const Modifiers::ArgumentTypes &type,
                                                             const Modifiers::MethodPrefixModifiers &prefixModifier) const
// const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<CSharpMethodUnit>(name, type, prefixModifier); //, accessModifier);
}

std::shared_ptr<IMethodArgumentUnit> CSharpFactory::createMethodArgumentUnit(const std::string &name,
                                                                             const Modifiers::ArgumentTypes &type,
                                                                             const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<CSharpMethodArgumentUnit>(name, type, prefixModifier);
}

std::shared_ptr<IPrintOperatorUnit> CSharpFactory::createPrintOperatorUnit(const std::string &text) const
{
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}

std::shared_ptr<ILocalVariableUnit> CSharpFactory::createLocalVariableUnit(const std::string &name,
                                                                           const Modifiers::ArgumentTypes &type,
                                                                           const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<CSharpLocalVariableUnit>(name, type, prefixModifier);
}
