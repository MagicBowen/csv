#include <gtest/gtest.h>
#include <csv/CsvWriterHelper.h>
#include <csv/PlaceHolder.h>
#include <sstream>

USING_CSV_NS;

struct TestCsv : testing::Test
{
    void expectContent(const std::string& expect)
    {
        csv.open(filename, std::ios::in);
        ASSERT_TRUE(csv.good());
        ASSERT_EQ(expect, getContent());
    }

private:
    std::string getContent()
    {
        std::stringstream ss;

        const size_t LINE_LENGTH = 1000;
        char line[LINE_LENGTH];
        while(csv.getline(line, LINE_LENGTH))
        {
            ss << line << "\n";
        }

        return ss.str();
    }

    std::ifstream csv;

protected:
    std::string filename{"test.csv"};
};

TEST_F(TestCsv, should_write_without_schema)
{
    {
        CsvWriter<void> csv(filename);

        csv.writeTitle({"id", "speed"});
        csv.writeLine(1, 1.2f, 3);
    }

    expectContent("id, speed\n1, 1.2, 3\n");
}

TEST_F(TestCsv, should_write_with_schema)
{
    {
        CsvWriter<int, double> csv(filename);

        csv.writeTitle({"id", "speed"});
        csv.writeLine(1, 1.2f);
    }

    expectContent("id, speed\n1, 1.2\n");
}

TEST_F(TestCsv, should_write_with_placeholder)
{
    {
        CsvWriter<int, Placeholder, double> csv(filename);

        csv.writeTitle({"id", " ", "speed"});
        csv.writeLine(1, Placeholder(), 1.2f);
    }

    expectContent("id,  , speed\n1,  , 1.2\n");
}

TEST_F(TestCsv, should_write_with_helper)
{
    {
        auto csv = make_csv_writer( filename
                                  , __label(int, "id")
                                  , __placeholder()
                                  , __label(double, "speed")
                                  , __label(std::string, "info"));

        csv.writeLine(1, Placeholder(), 1.2f, "vehicle info");
    }

    expectContent("id,  , speed, info\n1,  , 1.2, vehicle info\n");
}
