#include <csv/Placeholder.h>

CSV_NS_BEGIN

std::ostream& operator<<(std::ostream& o, const Placeholder&)
{
    o << " ";
    return o;
}

CSV_NS_END
