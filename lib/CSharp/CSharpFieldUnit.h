#include "IFieldUnit.h"
#include <vector>

class CSharpFieldUnit : public IFieldUnit
{
public:
    explicit CSharpFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                             const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~CSharpFieldUnit() override = default;

    std::string compile(unsigned int level = 0) const override;
};