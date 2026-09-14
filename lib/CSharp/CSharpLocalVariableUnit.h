#ifndef CSHARPLOCALVARIABLEUNIT_H
#define CSHARPLOCALVARIABLEUNIT_H

#include <vector>

#include "ILocalVariableUnit.h"

class CSharpLocalVariableUnit : public ILocalVariableUnit
{ // конструкция "локальная переменная в методе" для Java
private:
//const static std::vector<std::string> ArgumentTypesNames; 
//const static std::vector<std::string> ArgumentPrefixModifierNames;
public:
    CSharpLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    std::string compile(unsigned int level = 0) const override;
};
#endif // CSHARPLOCALVARIABLEUNIT_H
