#include "JavaClassUnit.h"
#include "Modifiers.h"
#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>


namespace {
    size_t GetJavaAccessModifierNumber(const Modifiers::AccessModifiers &flag)
    {
        switch (flag)
        {
        case Modifiers::AccessModifiers::PUBLIC:
            return 0;
        case Modifiers::AccessModifiers::PROTECTED:
            return 1;
        case Modifiers::AccessModifiers::PRIVATE:
            return 2;
        default:
            throw std::invalid_argument("Invalid access modifier"); // или по умолчанию ставить PRIVATE
        }
    }

    const std::vector<std::string> JavaAccessModifierNames = {"public", "protected", "private"};
} //namespace

JavaClassUnit::JavaClassUnit(const std::string &name,
                             const Modifiers::ClassPrefixModifiers &classPrefixModifier)
    : IClassUnit(name, classPrefixModifier
                 ), Members(3)
{
}

void JavaClassUnit::addMember(const std::shared_ptr<Unit> &unit,
                              const Modifiers::AccessModifiers &accessModifier)
{
    size_t AccIndex = GetJavaAccessModifierNumber(accessModifier);
    Members[AccIndex].push_back(unit);
};

std::string JavaClassUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + "class " + name + " {\n";
    for (size_t i = 0; i < 3; i++)
    {
        if (Members[i].empty())
        {
            continue;
        }
        for (const auto &unit : Members[i])
        {
            result += generateShift(level) + JavaAccessModifierNames[i] + unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}