#include "IMethodArgumentUnit.h"

IMethodArgumentUnit::IMethodArgumentUnit(const std::string &name, const ArgumentTypes &type)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    this->type = type;
    this->name = name;
}
ArgumentTypes IMethodArgumentUnit::getType() const
{
    return type;
}

std::string IMethodArgumentUnit::getName() const
{
    return name;
}