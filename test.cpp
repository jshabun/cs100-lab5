#include "spreadsheet.cpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(Select_Not, normalTest){
        std::stringstream ss;
        std::string xp;

        Spreadsheet sheet;

        sheet.set_column_names({"fruit"});
        sheet.add_row({"PEAR"});
        sheet.add_row({"TOMATO"});
        sheet.add_row({"APPLE"});
        sheet.add_row({"KUMQUAT"});

        sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "fruit", "APPLE")));
        sheet.print_selection(ss);
        xp = "PEAR \nTOMATO \nKUMQUAT \n";

        EXPECT_EQ(ss.str(), xp);

}
TEST(Select_Not, SelectNotAll) {
        std::stringstream ss;
        std::string xp;

        Spreadsheet sheet;

        sheet.set_column_names({"veggies"});
        sheet.add_row({"broccoli"});
        sheet.add_row({"garlic"});
        sheet.add_row({"spinach"});
        sheet.add_row({"avocado"});

        sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "veggies", "z")));
        sheet.print_selection(ss);
        xp = "broccoli \ngarlic \nspinach \navocado \n";

        EXPECT_EQ(ss.str(), xp);

}
TEST(Select_Not, SelectNotNone) {
        std::stringstream ss;
        std::string xp;

        Spreadsheet sheet;

        sheet.set_column_names({"meat"});
        sheet.add_row({"pig"});
        sheet.add_row({"rabbit"});
        sheet.add_row({"fish"});
        sheet.add_row({"venison"});

        sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "meat", "i")));
        sheet.print_selection(ss);
        xp = "";

        EXPECT_EQ(ss.str(), xp);

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
