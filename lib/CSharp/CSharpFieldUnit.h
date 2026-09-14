#include "IFieldUnit.h"
#include <vector>

class CSharpFieldUnit : public IFieldUnit
{
private:
    //Modifiers::AccessModifiers accessModifier;
public:
    //static const std::vector<std::string> AccessModifiersNames;

    explicit CSharpFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED
                        // const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED
                        );

    ~CSharpFieldUnit() override = default;

    std::string compile(unsigned int level = 0) const override;
};