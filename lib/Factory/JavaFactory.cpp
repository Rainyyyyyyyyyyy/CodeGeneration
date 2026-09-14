#include "JavaFactory.h"

#include "JavaClassUnit.h"
#include "JavaFieldUnit.h"
#include "JavaMethodUnit.h"
#include "JavaMethodArgumentUnit.h"
#include "JavaPrintOperatorUnit.h"
#include "JavaLocalVariableUnit.h"

// Старая сигнатура сохраняется для истории:
// std::shared_ptr<IClassUnit> JavaFactory::createClassUnit(
//     const std::string &name,
//     Modifiers::ClassPrefixModifiers classPrefixModifier) const
// {
//     return std::make_shared<JavaClassUnit>(name, classPrefixModifier);
// }

std::shared_ptr<IClassUnit> JavaFactory::createClassUnit(const std::string &name,
                                                        const Modifiers::ClassPrefixModifiers &classPrefixModifier) const
                                                        //const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<JavaClassUnit>(name, classPrefixModifier);//, accessModifier); 
}

std::shared_ptr<IFieldUnit> JavaFactory::createFieldUnit(const std::string &name,
                                                        const Modifiers::ArgumentTypes &type,
                                                        const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
                                                        //const Modifiers::AccessModifiers &accessModifier) const
{
    return std::make_shared<JavaFieldUnit>(name, type, prefixModifier);//, accessModifier); 
}

std::shared_ptr<IMethodUnit> JavaFactory::createMethodUnit(const std::string &name,
                                                          const Modifiers::ArgumentTypes &type, 
                                                          const Modifiers::MethodPrefixModifiers &prefixModifier) const
                                                          //const Modifiers::AccessModifiers &accessModifier) const 
{
    return std::make_shared<JavaMethodUnit>(name, type, prefixModifier);//, accessModifier);
}

std::shared_ptr<IMethodArgumentUnit> JavaFactory::createMethodArgumentUnit(const std::string &name,
                                                                          const Modifiers::ArgumentTypes &type,
                                                                          const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<JavaMethodArgumentUnit>(name, type, prefixModifier);
}

std::shared_ptr<IPrintOperatorUnit> JavaFactory::createPrintOperatorUnit(const std::string &text) const
{
    return std::make_shared<JavaPrintOperatorUnit>(text);
}

std::shared_ptr<ILocalVariableUnit> JavaFactory::createLocalVariableUnit(const std::string &name,
                                                                        const Modifiers::ArgumentTypes &type,
                                                                        const Modifiers::ArgumentPrefixModifiers &prefixModifier) const
{
    return std::make_shared<JavaLocalVariableUnit>(name, type, prefixModifier);
}
