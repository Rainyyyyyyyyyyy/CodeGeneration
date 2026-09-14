#ifndef CSHARP_METHODARGUMENTUNIT_H
#define CSHARP_METHODARGUMENTUNIT_H

#include "IMethodArgumentUnit.h"

class CSharpMethodArgumentUnit : public IMethodArgumentUnit
{
public:
    explicit CSharpMethodArgumentUnit(const std::string &name,
                                      const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                      const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~CSharpMethodArgumentUnit() override = default;

    std::string compile(unsigned int level) const override;
};

#endif // CSHARP_METHODARGUMENTUNIT_H