#ifndef CPP_METHOD_UNIT_H
#define CPP_METHOD_UNIT_H

#include "IMethodUnit.h"

class CppMethodUnit : public IMethodUnit
{
public:
    explicit CppMethodUnit(const std::string &name,
                           const Modifiers::ArgumentTypes &returnType = Modifiers::ArgumentTypes::VOID,
                           const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED);

    ~CppMethodUnit() override = default;

    std::string compile(unsigned int level = 0) const override;
};
#endif // CPP_METHOD_UNIT_H
