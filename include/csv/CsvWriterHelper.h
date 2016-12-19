#ifndef HA56C9BCD_540D_49FC_AAF2_9BDC7AC83E39
#define HA56C9BCD_540D_49FC_AAF2_9BDC7AC83E39

#include <csv/CsvWriter.h>
#include <csv/Placeholder.h>

CSV_NS_BEGIN

struct CsvWriterHelper
{
    CsvWriterHelper(const std::string& filename)
    : filename(filename)
    {
    }

    template<typename ... SCHEMA_ITEMS>
    auto make(SCHEMA_ITEMS&& ... items)
    {
        CsvWriter<typename SCHEMA_ITEMS::type...> csv(filename);
        collectLabel(std::forward<SCHEMA_ITEMS>(items)...);
        csv.writeTitle(title);
        return std::move(csv);
    }

private:
    template<typename ITEM, typename ...OTHERS>
    void collectLabel(ITEM&& item, OTHERS&& ...others)
    {
        title.push_back(item.label);
        collectLabel(std::forward<OTHERS>(others)...);
    }

    template<typename ITEM>
    void collectLabel(ITEM&& item)
    {
        title.push_back(item.label);
    }

private:
    std::string filename;
    std::vector<std::string> title;
};

template<typename ... SCHEMA_ITEMS>
auto make_csv_writer(const std::string& filename, SCHEMA_ITEMS&& ...items)
{
    CsvWriterHelper helper(filename);
    return helper.make(std::forward<SCHEMA_ITEMS>(items)...);
}

CSV_NS_END

#endif
