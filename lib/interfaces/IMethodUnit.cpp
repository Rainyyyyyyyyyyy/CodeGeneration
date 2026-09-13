#include "IMethodUnit.h"
#include "utils.h"
#include <stdexcept>

IMethodUnit::IMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                         const Modifiers::MethodPrefixModifiers &methodPrefixModifier
                         // , const Modifiers::AccessModifiers &accessModifier
                         )
{
    // if (IsValidVariableName(name) == false)
    // { // если имя некорректно, то исключение
    //     throw std::invalid_argument("Invalid argument name: " + name);
    // }
    this->returnType = returnType; // здесь же тип VOID уже может быть
    this->name = name;
    // this->accessModifier = accessModifier;
    this->methodPrefixModifier = methodPrefixModifier;
}

void IMethodUnit::addArgument(const std::shared_ptr<IMethodArgumentUnit> &argument)
{
    arguments.push_back(argument);
}
void IMethodUnit::addBody(const std::shared_ptr<IStatementUnit> &statement)
{
    body.push_back(statement);
}

void IMethodUnit::SetReturnType(const Modifiers::ArgumentTypes &returnType)
{
    this->returnType = returnType;
}

void IMethodUnit::SetMethodPrefixModifier(const Modifiers::MethodPrefixModifiers &methodPrefixModifier)
{
    this->methodPrefixModifier = methodPrefixModifier;
}
