#include "JavaMethodUnit.h"

#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>

JavaMethodUnit::JavaMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                               const Modifiers::MethodPrefixModifiers &methodPrefixModifier)
    : IMethodUnit(name, returnType, methodPrefixModifier
                  // , accessModifier
                  )
{
}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    if (IsValidClassOrMethodName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid method name: " + name);
    }
    // формирование сигнатуры функции
    std::string result = generateShift(level) +
                         // GetJavaAccessModifierName(accessModifier) + ' ' +
                         GetJavaMethodPrefixModifierName(methodPrefixModifier) +
                         ' ' + GetJavaArgumentTypeName(returnType) +
                         ' ' + name + '(';
    size_t numberOfArguments = arguments.size();
    if (numberOfArguments > 0)
    {
        for (size_t i = 0; i < numberOfArguments - 1; i++)
        {
            result += GetJavaArgumentTypeName(arguments[i]->GetType()) + ' ' + arguments[i]->GetName() + ", ";
        }
        result += GetJavaArgumentTypeName(arguments[numberOfArguments - 1]->GetType()) + ' ' + arguments[numberOfArguments - 1]->GetName();
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