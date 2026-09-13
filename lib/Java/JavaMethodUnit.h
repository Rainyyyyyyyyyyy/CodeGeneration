#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "IMethodUnit.h"

class JavaMethodUnit : public IMethodUnit
{
public:
    explicit JavaMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                            const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED, 
                            const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED);

    ~JavaMethodUnit() override = default;

    std::string compile(unsigned int level) const override;
};

#endif // JAVAMETHODUNIT_H