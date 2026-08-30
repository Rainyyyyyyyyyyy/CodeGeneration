#include "CppClassUnit.h"
#include <stdexcept>


namespace {
    unsigned int getAccessModifierNumber(Modifiers::AccessModifiers flag){
        switch(flag){
            case Modifiers::AccessModifiers::PUBLIC: return 0;
            case Modifiers::AccessModifiers::PROTECTED: return 1;
            case Modifiers::AccessModifiers::PRIVATE: return 2;
            default: throw std::invalid_argument("Invalid access modifier"); // или по умолчанию ставить PRIVATE
        }
    }
}   // namespace

CppClassUnit::~CppClassUnit() = default;

void CppClassUnit::add(const std::shared_ptr <Unit> &unit, Flags flags){
    auto AccIndex = getAccessModifierNumber(static_cast<Modifiers::AccessModifiers>(flags));
    if(AccIndex >= fields.size()){
        fields.resize(AccIndex+1);
    }
    fields[AccIndex].push_back(unit);
};


std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + name + " {\n";
    if (fields.size() < AccessModifierNames.size()) {
        return result + generateShift(level) + "};\n";
    }
    for(size_t i = 0; i < AccessModifierNames.size(); ++i){
        for(const auto &unit : fields[i]){
            result += unit->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}


const std::vector<std::string> CppClassUnit::AccessModifierNames = { "public", "protected", "private" };


