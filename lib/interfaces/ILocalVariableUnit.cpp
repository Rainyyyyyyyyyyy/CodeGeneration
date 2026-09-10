#include "ILocalVariableUnit.h"

ILocalVariableUnit::ILocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier)
                       : name(name), type(type), prefixModifier(prefixModifier) {}

