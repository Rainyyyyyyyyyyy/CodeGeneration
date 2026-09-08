#include "JavaClassUnit.h"
#include "Modifiers.h"
#include "stdexcept"


namespace{ // ПЕРЕДЕЛАТЬ ПОД JAVA

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
}   // namespace

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    auto AccIndex = getAccessModifierNumber(static_cast<Modifiers::AccessModifiers>(flags));
    if (AccIndex >= Members.size())
    {
        Members.resize(AccIndex + 1);
    }
    Members[AccIndex].push_back(unit);
};

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + name + " {\n";
}