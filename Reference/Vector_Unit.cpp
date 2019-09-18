#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"

/*More info on Catch
Git-Page: https://github.com/philsquared/Catch
*/

//What are we testing today?
#include "Vector.hpp"


TEST_CASE("TESTING Vector Class")
{
  Vector *test_vector;

  SECTION("Default Constructor")
    {
     
      test_vector = new Vector();

      //Information to be printed if error (optional stuff)
      INFO("Using default constructor") //Displayed if fails
      CAPTURE(test_vector->size()); //Display this if fails
     
      
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_vector->size() == 0); // Check if true
      REQUIRE_FALSE(test_vector->size() != 0); //Check if false

      
      //IF TEST FAIL -- CONTINUE TESTING
      //CHECK(test_vector->size() == 1);

      delete test_vector;
    }

  SECTION("Max function")
    {
      test_vector = new Vector(10, 5.5);      
      REQUIRE(test_vector->max() == 5.5);
    }
}

TEST_CASE("Testing Nothing")
{
  SECTION("Nothing One")
    {
      REQUIRE(true);
    }


}
