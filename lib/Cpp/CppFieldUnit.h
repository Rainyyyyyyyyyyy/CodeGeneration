#ifndef CPPFIELDUNIT_H
#define CPPFIELDUNIT_H

#include "IFieldUnit.h"
#include <vector>

class CppFieldUnit : public IFieldUnit
{
public:
    explicit CppFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                          const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~CppFieldUnit() override = default;

    std::string compile(unsigned int level) const override;
};

#endif // CPPFIELDUNIT_H