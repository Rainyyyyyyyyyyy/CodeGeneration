#include "IClassUnit.h"


// std::string IClassUnit::compile( unsigned int level ) const = 0 {
//     std::string result = generateShift( level ) + "class " + name + " {\n";
//         for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
//             if( fields[ i ].empty() ) {
//                 continue;
//             }
//             result += ACCESS_MODIFIERS[ i ] + ":\n";
//             for( const auto& f : fields[ i ] ) {
//                 result += f->compile( level + 1 );
//             }
//             result += "\n";
//         }
//     result += generateShift( level ) + "};\n";
//     return result;
// }

//const std::vector< std::string > IClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };