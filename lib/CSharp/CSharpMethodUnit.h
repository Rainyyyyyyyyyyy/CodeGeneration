#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "IMethodUnit.h"

class CSharpMethodUnit : public IMethodUnit
{
public:
    explicit CSharpMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                              const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED);

    ~CSharpMethodUnit() override = default;
    std::string compile(unsigned int level) const override;
};

#endif // CSHARPMETHODUNIT_H