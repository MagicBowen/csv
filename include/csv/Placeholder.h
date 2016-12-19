#ifndef H533BE310_1CE9_459E_8667_5DEF9803C672
#define H533BE310_1CE9_459E_8667_5DEF9803C672

#include <csv/SchemaLabel.h>
#include <ostream>

CSV_NS_BEGIN

struct Placeholder{};

std::ostream& operator<<(std::ostream& o, const Placeholder&);

CSV_NS_END

#define __placeholder()    ::CSV_NS::SchemaLabel<::CSV_NS::Placeholder>(" ")

#endif
