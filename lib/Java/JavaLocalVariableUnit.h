#ifndef JAVALOCALVARIABLEUNIT_H
#define JAVALOCALVARIABLEUNIT_H

#include <vector>

#include "ILocalVariableUnit.h"

class JavaLocalVariableUnit : public ILocalVariableUnit
{ // конструкция "локальная переменная в методе" для Java
private:
//const static std::vector<std::string> ArgumentTypesNames; 
//const static std::vector<std::string> ArgumentPrefixModifierNames;
public:
    JavaLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    std::string compile(unsigned int level = 0) const override;
};
#endif // JAVALOCALVARIABLEUNIT_H
