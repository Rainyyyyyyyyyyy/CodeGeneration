#ifndef CPP_UTILS_H
#define CPP_UTILS_H

#include "Modifiers.h"

const std::string GetCppArgumentTypeName(const Modifiers::ArgumentTypes &type);

const std::string GetCppArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &modifier);

const std::string GetCppMethodPrefixName(const Modifiers::MethodPrefixModifiers &modifier);
#endif // CPP_UTILS_H