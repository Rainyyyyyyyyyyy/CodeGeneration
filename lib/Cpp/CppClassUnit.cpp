#include "CppClassUnit.h"
#include "utils.h"

#include <stdexcept>

namespace
{
    size_t GetCppAccessModifierNumber(const Modifiers::AccessModifiers &flag)
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

    const std::vector<std::string> CppAccessModifierNames = {"public", "protected", "private"};
} // namespace

void CppClassUnit::addMember(const std::shared_ptr<Unit> &unit,
                             const Modifiers::AccessModifiers &accessModifier)
{
    size_t AccIndex = GetCppAccessModifierNumber(accessModifier);
    Members[AccIndex].push_back(unit);
};

std::string CppClassUnit::compile(unsigned int level) const
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
        result += generateShift(level) + CppAccessModifierNames[i] + ":\n";
        for (const auto &unit : Members[i])
        {
            result += unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}

CppClassUnit::CppClassUnit(const std::string &name)
    : IClassUnit(name), Members(3) {}
// названия модификаторов на С++

// const std::vector<std::string> CppClassUnit::AccessModifierNames = {"public", "protected", "private"};
