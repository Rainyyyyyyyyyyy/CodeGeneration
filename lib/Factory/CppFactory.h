#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "IFactory.h"

class CppFactory : public IFactory
{
public:
    ~CppFactory() override = default;

    std::shared_ptr<IClassUnit> createClassUnit(const std::string &name, Modifiers::ClassPrefixModifiers classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED) const override;
    std::shared_ptr<IFieldUnit> createFieldUnit(const std::string &name,
                                                const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED,
                                                const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const override;
    std::shared_ptr<IMethodUnit> createMethodUnit(const std::string &name,
                                                  const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                  const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED) const override;
    std::shared_ptr<IMethodArgumentUnit> createMethodArgumentUnit(const std::string &name,
                                                                  const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED) const override;
    std::shared_ptr<IPrintOperatorUnit> createPrintOperatorUnit(const std::string &text) const override;

    std::shared_ptr<IStatementUnit> createLocalVariableUnit(const std::string &name,
                                                            const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                                            const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED) const;
};

#endif // CPPFACTORY_H