#include "IFieldUnit.h"
#include <vector>

class JavaFieldUnit : public IFieldUnit
{
public:
    explicit JavaFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~JavaFieldUnit() override = default;

    std::string compile(unsigned int level = 0) const override;
};