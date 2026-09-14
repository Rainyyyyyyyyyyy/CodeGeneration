#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include <memory>

#include "IFactory.h"

#include "IClassUnit.h"
#include "IFieldUnit.h"
#include "IMethodUnit.h"
#include "IMethodArgumentUnit.h"
#include "IPrintOperatorUnit.h"
#include "ILocalVariableUnit.h"

class JavaFactory : public IFactory
{
public:
     ~JavaFactory() override = default;

     std::shared_ptr<IClassUnit> createClassUnit(const std::string &name,
                                                 const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED) const override;

     std::shared_ptr<IFieldUnit> createFieldUnit(const std::string &name,
                                                 const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const override;
     std::shared_ptr<IMethodUnit> createMethodUnit(const std::string &name,
                                                   const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                   const Modifiers::MethodPrefixModifiers &prefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED) const override;
     std::shared_ptr<IMethodArgumentUnit> createMethodArgumentUnit(const std::string &name,
                                                                   const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                                   const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const override;
     std::shared_ptr<IPrintOperatorUnit> createPrintOperatorUnit(const std::string &text) const override;
     std::shared_ptr<ILocalVariableUnit> createLocalVariableUnit(const std::string &name,
                                                                 const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const override;
};

#endif // JAVAFACTORY_H