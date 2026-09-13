#include "IFieldUnit.h"
#include <vector>

class JavaFieldUnit : public IFieldUnit
{
private:
    //Modifiers::AccessModifiers accessModifier;
public:
    //static const std::vector<std::string> AccessModifiersNames;

    explicit JavaFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED
                        // const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED
                        );

    ~JavaFieldUnit() override = default;

    std::string compile(unsigned int level = 0) const override;
};