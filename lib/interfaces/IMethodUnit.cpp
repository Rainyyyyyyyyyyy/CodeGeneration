#include "IMethodUnit.h"


std::string IMethodUnit::getName() const
{
    return name;
}

const std::vector<std::shared_ptr<Unit>>& IMethodUnit::getBody() const
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

const std::vector<std::shared_ptr<IMethodArgumentUnit>>& IMethodUnit::getArguments() const
{
    return arguments;
}

void IMethodUnit::addArgument(const std::shared_ptr<IMethodArgumentUnit>& argument){
    arguments.push_back(argument);
}
void IMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags flags){
    body.push_back(unit);
}
