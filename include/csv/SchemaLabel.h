#ifndef H79CFFD88_EFFD_473C_9E9F_9425E162D4B7
#define H79CFFD88_EFFD_473C_9E9F_9425E162D4B7

#include <csv/Placeholder.h>

CSV_NS_BEGIN

template<typename T>
struct SchemaLabel
{
    SchemaLabel(const char* label)
    : label(label)
    {
    }
    using type = T;
    const std::string label;
};

CSV_NS_END

#define __label(type, str) ::CSV_NS::SchemaLabel<type>(str)
#define __placeholder()    ::CSV_NS::SchemaLabel<::CSV_NS::Placeholder>(" ")

#endif
