#ifndef HD18C97D8_33E5_43DA_A620_7FC0DA496AE9
#define HD18C97D8_33E5_43DA_A620_7FC0DA496AE9

#include <csv/csv.h>
#include <string>
#include <fstream>
#include <vector>

CSV_NS_BEGIN

template<typename ... SCHEMA> struct CsvWriter;

template<>
struct CsvWriter<void>
{
    explicit CsvWriter(const std::string& filename)
    : csv(filename, std::ios::out | std::ios::trunc)
    {
    }

    void flush()
    {
        csv.flush();
    }

    void writeTitle(const std::vector<std::string>& title)
    {
        size_t column = 0;
        for(auto label : title)
        {
            csv << label;
            csv << (++column < title.size()? ", " : "\n");
        }
    }

    template<typename ...TS>
    void writeLine(TS&&... data)
    {
        output(std::forward<TS>(data)...);
    }

private:
    template<typename T, typename ...TS>
    void output(T&& t, TS&&... ts)
    {
        csv << std::forward<T>(t) << ", ";
        output(std::forward<TS>(ts)...);
    }

    template<typename T>
    void output(T&& t)
    {
        csv << std::forward<T>(t) << "\n";
    }

private:
    std::ofstream csv;
};

template<typename ... SCHEMA>
struct CsvWriter : CsvWriter<void>
{
    using CsvWriter<void>::CsvWriter;

    void writeLine(const SCHEMA&... data)
    {
        output(data...);
    }
};

CSV_NS_END

#endif
