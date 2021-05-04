#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

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

TEST(Select_And, basicTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"slimmy"});
        sheet.add_row({"flippity"});
        sheet.add_row({"dippity"});
        sheet.add_row({"hippity"});
        sheet.add_row({"hoppity"});

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


