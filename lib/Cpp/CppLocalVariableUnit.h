#ifndef CPPLOCALVARIABLEUNIT_H
#define CPPLOCALVARIABLEUNIT_H

#include <vector>

#include "ILocalVariableUnit.h"

class CppLocalVariableUnit : public ILocalVariableUnit
{ // конструкция "локальная переменная в методе" для C++
private:
const static std::vector<std::string> ArgumentTypesNames;
const static std::vector<std::string> ArgumentPrefixModifierNames;
public:
    CppLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    std::string compile(unsigned int level = 0) const override;
};
#endif // CPPLOCALVARIABLEUNIT_H
