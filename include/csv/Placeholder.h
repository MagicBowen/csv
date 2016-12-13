#ifndef H533BE310_1CE9_459E_8667_5DEF9803C672
#define H533BE310_1CE9_459E_8667_5DEF9803C672

#include <csv/csv.h>
#include <ostream>

CSV_NS_BEGIN

struct Placeholder{};

std::ostream& operator<<(std::ostream& o, const Placeholder&)
{
    o << " ";
    return o;
}

CSV_NS_END

#endif
