#include "CppMethodUnit.h"

CppMethodUnit::CppMethodUnit(const std::string &name, const ArgumentTypes &returnType,
                             const Modifiers::AccessModifiers &accessModifier)
    : IMethodUnit(name, returnType, accessModifier) {}

std::string CppMethodUnit::compile(unsigned int level) const
{
    // формирование сигнатуры функции
    std::string result = generateShift(level) + GetArgumentTypeName(returnType) + ' ' + name + '(';
    size_t numberOfArguments = arguments.size();
    if (numberOfArguments > 0)
    {
        for (size_t i = 0; i < numberOfArguments - 1; i++)
        {
            result += GetArgumentTypeName(arguments[i]->getType()) + ' ' + arguments[i]->getName() + ", ";
        }
        result += GetArgumentTypeName(arguments[numberOfArguments - 1]->getType()) + ' ' + arguments[numberOfArguments - 1]->getName();
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