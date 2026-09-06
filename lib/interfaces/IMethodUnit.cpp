#include "IMethodUnit.h"

std::string IMethodUnit::getName() const
{
    return name;
}

const std::vector<std::shared_ptr<Unit>> &IMethodUnit::getBody() const
{
    return body;
}

AccessModifiers IMethodUnit::getAccessModifier() const
{
    return accessModifier;
}

ArgumentTypes IMethodUnit::getReturnType() const
{
    return returnType;
}

const std::vector<std::shared_ptr<IMethodArgumentUnit>> &IMethodUnit::getArguments() const
{
    return arguments;
}

IMethodUnit::IMethodUnit(const std::string &name, const ArgumentTypes &returnType,
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
