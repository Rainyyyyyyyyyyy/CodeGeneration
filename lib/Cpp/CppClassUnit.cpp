#include "CppClassUnit.h"
#include <stdexcept>

namespace
{
    unsigned int getAccessModifierNumber(Modifiers::AccessModifiers flag)
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
} // namespace

void CppClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    auto AccIndex = getAccessModifierNumber(static_cast<Modifiers::AccessModifiers>(flags));
    if (AccIndex >= Members.size())
    {
        Members.resize(AccIndex + 1);
    }
    Members[AccIndex].push_back(unit);
};

std::string CppClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + name + " {\n";
    if (Members.size() < AccessModifierNames.size())
    {
        return result + generateShift(level) + "};\n";
    }
    for (size_t i = 0; i < AccessModifierNames.size(); ++i)
    {
        result += generateShift(level) + AccessModifierNames[i] + ":\n";
        for (const auto &unit : Members[i])
        {
            result += unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}

CppClassUnit::CppClassUnit(const std::string &name,
                           Modifiers::ClassModifiers AccMod)
    : IClassUnit(name), Members(AccessModifierNames.size()) {}
// названия модификаторов на С++
const std::vector<std::string> CppClassUnit::AccessModifierNames = {"public", "protected", "private"};
