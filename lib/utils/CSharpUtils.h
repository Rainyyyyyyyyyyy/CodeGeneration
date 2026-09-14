#ifndef CSHARPUTILS_H
#define CSHARPUTILS_H

#include "Modifiers.h"

const std::string GetCSharpArgumentTypeName(const Modifiers::ArgumentTypes &type);

const std::string GetCSharpArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &modifier);

const std::string GetCSharpMethodPrefixModifierName(const Modifiers::MethodPrefixModifiers &modifier);

const std::string GetCSharpAccessModifierName(const Modifiers::AccessModifiers &modifier);

#endif // CSHARPUTILS_H