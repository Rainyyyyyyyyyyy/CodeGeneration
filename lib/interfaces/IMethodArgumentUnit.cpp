#include "IMethodArgumentUnit.h"


ArgumentTypes IMethodArgumentUnit::getType() const
{
    return type;
}

std::string IMethodArgumentUnit::getName() const
{
    return name;
}