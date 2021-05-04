#include "spreadsheet.hpp"

#include "gtest/gtest.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Select_Or, basicTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"shady"});
        sheet.add_row({"hippity"});
        sheet.add_row({"hoppity"});
        sheet.add_row({"rippity"});
        sheet.add_row({"flippity"});

        sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"shady","ip"),new Select_Contains(&sheet,"shady","op")));
        sheet.print_selection(ss);
        expS = "hippity \nhoppity \nrippity \nflippity \n";

        EXPECT_EQ(ss.str(), expS);

}

TEST(Select_Or, noneTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"fruity"});
        sheet.add_row({"loquat"});
        sheet.add_row({"mango"});
        sheet.add_row({"jackfruit"});
        sheet.add_row({"banana"});

        sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"fruity","p"),new Select_Contains(&sheet,"fruity","z")));
        sheet.print_selection(ss);
        expS = "";

        EXPECT_EQ(ss.str(), expS);

}
