#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Select_And, basicTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"slimmy"});
        sheet.add_row({"flippity"});
        sheet.add_row({"dippity"});
        sheet.add_row({"hippity"});
        sheet.add_row({"rippity"});

        sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","ipp"),new Select_Contains(&sheet,"slimmy","ity")));
        sheet.print_selection(ss);
        expS = "flippity \ndippity \nhippity \n";

        EXPECT_EQ(ss.str(), expS);

}

TEST(Select_And, noneTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"pokes"});
        sheet.add_row({"bidoof"});
        sheet.add_row({"arceus"});
        sheet.add_row({"luxio"});
        sheet.add_row({"tepig"});

        sheet.set_selection(new Select_And(new Select_Contains(&sheet,"pokes","ipp"),new Select_Contains(&sheet,"pokes","t")));
        sheet.print_selection(ss);
        expS = "";

        EXPECT_EQ(ss.str(), expS);
}
