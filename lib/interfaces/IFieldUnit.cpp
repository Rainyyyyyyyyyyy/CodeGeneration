#include <stdexcept>

#include "IFieldUnit.h"
#include "utils.h"

IFieldUnit::IFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier
                        // , const Modifiers::AccessModifiers &accessModifier
                        )

{
    // if (IsValidVariableName(name) == false)
    // { // если имя некорректно, то исключение
    //     throw std::invalid_argument("Invalid argument name: " + name);
    // }
    // if (type == Modifiers::ArgumentTypes::VOID)
    // {
    //     throw std::invalid_argument("Invalid field type: " + GetArgumentTypeName(type));
    // }
    this->type = type;
    this->name = name;
    // this->accessModifier = accessModifier;
    this->prefixModifier = prefixModifier;
}

void IFieldUnit::SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    this->prefixModifier = prefixModifier;
}

void IFieldUnit::SetName(const std::string &name)
{
    this->name = name;
}

void IFieldUnit::SetType(const Modifiers::ArgumentTypes &type)
{
    this->type = type;
}

// void IFieldUnit::SetAccessModifier(const Modifiers::AccessModifiers &accessModifier)
// {
//     // this->accessModifier = accessModifier;
// }
