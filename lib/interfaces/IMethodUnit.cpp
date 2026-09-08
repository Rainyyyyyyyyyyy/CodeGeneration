#include "IMethodUnit.h"
#include "utils.h"
#include <stdexcept>

IMethodUnit::IMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                         const Modifiers::AccessModifiers &accessModifier,
                         const Modifiers::MethodPrefixModifiers &methodPrefixModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    this->returnType = returnType; // здесь же тип VOID уже может быть
    this->name = name;
    this->accessModifier = accessModifier;
    this->methodPrefixModifier = methodPrefixModifier;
}

void IMethodUnit::addArgument(const std::shared_ptr<IMethodArgumentUnit> &argument)
{
    arguments.push_back(argument);
}
void IMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    body.push_back(unit);
}
