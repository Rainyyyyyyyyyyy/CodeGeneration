#include "JavaClassUnit.h"
#include "Modifiers.h"
#include "stdexcept"
#include "utils.h"

namespace
{ // ПЕРЕДЕЛАТЬ ПОД JAVA

    size_t getAccessModifierNumber(Modifiers::AccessModifiers flag)
    {
        switch (flag)
        {
        case Modifiers::AccessModifiers::UNDEFINED: // без модификатора (default-package)
            return 0;
        case Modifiers::AccessModifiers::PUBLIC:
            return 1;
        case Modifiers::AccessModifiers::PROTECTED:
            return 2;
        case Modifiers::AccessModifiers::PRIVATE:
            return 3;
        default:
            throw std::invalid_argument("Invalid access modifier"); // или по умолчанию ставить PRIVATE
        }
    }
    size_t getClassPrefixModifierNumber(Modifiers::ClassPrefixModifiers flag)
    {
        switch (flag)
        {
        case Modifiers::ClassPrefixModifiers::UNDEFINED:
            return 0;
        case Modifiers::ClassPrefixModifiers::ABSTRACT:
            return 1;
        case Modifiers::ClassPrefixModifiers::FINAL:
            return 2;
        default:
            throw std::invalid_argument("Invalid class prefix modifier");
        }
    }

} // namespace

JavaClassUnit::JavaClassUnit(const std::string &name,
                             Modifiers::ClassPrefixModifiers classPrefixModifier)
    : IClassUnit(name), Members(AccessModifierNames.size())
{
    this->classPrefixModifier = classPrefixModifier;
}

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    auto AccIndex = getAccessModifierNumber(static_cast<Modifiers::AccessModifiers>(flags));
    if (AccIndex >= Members.size())
    {
        Members.resize(AccIndex + 1);
    }
    Members[AccIndex].push_back(unit);
};

std::string JavaClassUnit::compile(unsigned int level) const
{
    if (IsValidClassOrMethodName(name) == false)
    {
        throw std::invalid_argument("Invalid class name: " + name);
    }
    std::string result = generateShift(level) + GetClassPrefixModifierName(classPrefixModifier) + " class " + name + " {\n";
    if (Members.size() < AccessModifierNames.size())
    {
        return result + generateShift(level) + "};\n";
    }
    for (size_t i = 0; i < AccessModifierNames.size(); ++i)
    {
        if (Members[i].empty())
        {
            continue;
        }
        result += generateShift(level); // + AccessModifierNames[i] + ":\n";
        for (const auto &unit : Members[i])
        {
            result += unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}

const std::vector<std::string> JavaClassUnit::AccessModifierNames = {
    "", // для UNDEFINED (default-package)
    "public",
    "protected",
    "private"};

const std::vector<std::string> JavaClassUnit::ClassPrefixModifierNames = {
    "",         // UNDEFINED
    "abstract", // ABSTRACT
    "final"     // FINAL
    //"public",    // PUBLIC
    //"protected", // PROTECTED
    //"private"    // PRIVATE
};