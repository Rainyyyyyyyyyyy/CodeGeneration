#include "CSharpMethodUnit.h"

#include "utils.h"
#include "CSharpUtils.h"

#include <stdexcept>

CSharpMethodUnit::CSharpMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                                   const Modifiers::MethodPrefixModifiers &methodPrefixModifier)
    : IMethodUnit(name, returnType, methodPrefixModifier) {}

std::string CSharpMethodUnit::compile(unsigned int level) const
{
    if (IsValidClassOrMethodName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid method name: " + name);
    }
    // формирование сигнатуры функции
    std::string result = generateShift(level) +
                         GetCSharpMethodPrefixModifierName(methodPrefixModifier) + ' ' +
                         GetCSharpArgumentTypeName(returnType) + ' ' +
                         name + '(';
    size_t numberOfArguments = arguments.size();
    if (numberOfArguments > 0)
    {
        for (size_t i = 0; i < numberOfArguments - 1; i++)
        {
            result += GetCSharpArgumentTypeName(arguments[i]->GetType()) + ' ' + arguments[i]->GetName() + ", ";
        }
        result += GetCSharpArgumentTypeName(arguments[numberOfArguments - 1]->GetType()) + ' ' + arguments[numberOfArguments - 1]->GetName();
    }
    result += "){\n";

    // формирование тела функции
    for (const auto &unit : body)
    {
        result += unit->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}