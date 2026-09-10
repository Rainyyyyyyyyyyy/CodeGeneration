#ifndef IFACTORY_H
#define IFACTORY_H

#include <memory>

#include "IClassUnit.h"
#include "IFieldUnit.h"
#include "IMethodUnit.h"
#include "IMethodArgumentUnit.h"
#include "IPrintOperatorUnit.h"
#include "ILocalVariableUnit.h"

class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual std::shared_ptr<IClassUnit> createClassUnit(const std::string &name, Modifiers::ClassPrefixModifiers classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED) const = 0;
    virtual std::shared_ptr<IFieldUnit> createFieldUnit(const std::string &name,
                                                        const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                        const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED,
                                                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const = 0;
    virtual std::shared_ptr<IMethodUnit> createMethodUnit(const std::string &name,
                                                          const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                          const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED) const = 0;
    virtual std::shared_ptr<IMethodArgumentUnit> createMethodArgumentUnit(const std::string &name,
                                                                          const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED) const = 0;
    virtual std::shared_ptr<IPrintOperatorUnit> createPrintOperatorUnit(const std::string &text) const = 0;
    virtual std::shared_ptr<ILocalVariableUnit> createLocalVariableUnit(const std::string &name,
                                                                        const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const = 0;
};

#endif // IFACTORY_H