#include "spreadsheet.cpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(Select_Contains, NormalInput) {
	std::stringstream ss;
	std::string xp;
	Spreadsheet sheet;

	sheet.set_column_names({"First","Last"});
        sheet.add_row({"Ash","Ketchum"});
        sheet.add_row({"Brock","Harrison"});
        sheet.add_row({"Misty","Williams"});
        sheet.add_row({"Gary","Oak"});

        sheet.set_selection(new Select_Contains(&sheet,"Last","Harrison"));
        sheet.print_selection(ss);
        xp = "Brock Harrison \n";

        EXPECT_EQ(ss.str(),xp);

}
TEST(Select_Contains, EmptyString) {
	std::stringstream ss;
        std::string xp;

        Spreadsheet sheet;

        sheet.set_column_names({"First"});
        sheet.add_row({"Ash"});
        sheet.add_row({"Brock"});
        sheet.add_row({"Misty"});
        sheet.add_row({"Gary"});

        sheet.set_selection(new Select_Contains(&sheet,"First",""));
        sheet.print_selection(ss);
        xp = "Ash \nBrock \nMisty \nGary \n";

        EXPECT_EQ(ss.str(),xp);
}

TEST(Select_Contains, NonexistentColumn) {
        std::stringstream ss;
        std::string xp;
	bool exists = true;

        Spreadsheet sheet;

        sheet.set_column_names({"test"});
        sheet.add_row({"Pikachu"});

	if(sheet.get_column_by_name("Raichu") == -1){
		ss << "not found";
	}
	else {
		sheet.print_selection(ss);
	}       
	
        xp = "not found";

        EXPECT_EQ(ss.str(), xp);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
