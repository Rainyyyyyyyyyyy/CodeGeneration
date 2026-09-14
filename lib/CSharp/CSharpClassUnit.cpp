#include "CSharpClassUnit.h"
#include "Modifiers.h"
#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>

namespace
{
    size_t GetCSharpAccessModifierNumber(const Modifiers::AccessModifiers &flag)
    {
        switch (flag)
        {
        case Modifiers::AccessModifiers::PUBLIC:
            return 0;
        case Modifiers::AccessModifiers::PROTECTED:
            return 1;
        case Modifiers::AccessModifiers::PRIVATE:
            return 2;
        case Modifiers::AccessModifiers::INTERNAL:
            return 3;
        case Modifiers::AccessModifiers::PROTECTED_INTERNAL:
            return 4;
        case Modifiers::AccessModifiers::PRIVATE_PROTECTED:
            return 5;
        case Modifiers::AccessModifiers::UNDEFINED:
            return 6;
        default:
            throw std::invalid_argument("Invalid access modifier"); // или по умолчанию ставить PRIVATE
        }
    }

    const std::vector<std::string> CSharpAccessModifierNames = {"public", "protected", "private", "internal", "protected internal", "private protected", ""};
} // namespace

CSharpClassUnit::CSharpClassUnit(const std::string &name,
                                 const Modifiers::ClassPrefixModifiers &classPrefixModifier)
    : IClassUnit(name, classPrefixModifier), Members(7) {}

void CSharpClassUnit::addMember(const std::shared_ptr<Unit> &unit,
                                const Modifiers::AccessModifiers &accessModifier)
{
    size_t AccIndex = GetCSharpAccessModifierNumber(accessModifier);
    Members[AccIndex].push_back(unit);
};

std::string CSharpClassUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + "class " + name + " {\n";
    for (size_t i = 0; i < 7; i++)
    {
        if (Members[i].empty())
        {
            continue;
        }
        for (const auto &unit : Members[i])
        {
            result += generateShift(level) + CSharpAccessModifierNames[i] + unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}