#include <memory>
#include <vector>

#include "Unit.h"
#include "Modifiers.h"

/*
ClassUnit::ClassUnit( const std::string& name ) : m_name( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}


void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
*/
class IClassUnit : public Unit {
// private:
//     std::string name;                               // имя класса
//     Modifiers::ClassModifiers classModifier;        // модификатор класса (abstract, final, abstract final)

    //using Fields = std::vector <std::shared_ptr < Unit > >;
    //std::vector <Fields> fields;

    //static const std::vector< std::string > ACCESS_MODIFIERS; // = { "public", "protected", "private" };
public:
    IClassUnit(const std::string& t_name) : name(t_name) {
        //fields.resize(ACCESS_MODIFIERS.size());
    }

    virtual std::string compile( unsigned int level = 0 ) const = 0;

    virtual void add(const std::shared_ptr <Unit> &, Flags flags) = 0;


protected:

    std::string name;                               // имя класса
    Modifiers::ClassModifiers classModifier;        // модификатор класса (abstract, final, abstract final)
    
    std::string generateShift(unsigned int level = 0) const {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
        
};