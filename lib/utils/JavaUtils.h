#ifndef JAVA_UTILS_H
#define JAVA_UTILS_H

#include "Modifiers.h"
#include <string>

std::string GetJavaArgumentTypeName(const Modifiers::ArgumentTypes &type);
std::string GetJavaAccessModifierName(const Modifiers::AccessModifiers &accessModifier);
std::string GetJavaClassPrefixModifierName(const Modifiers::ClassPrefixModifiers &classPrefixModifier);
std::string GetJavaMethodPrefixModifierName(const Modifiers::MethodPrefixModifiers &methodPrefixModifier);
std::string GetJavaArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier);


#endif // JAVA_UTILS_H