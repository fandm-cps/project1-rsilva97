#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing ReallyLongInt Class"){

    ReallyLongInt *test_rli;

    SECTION("Default Constructor"){
        
        test_rli = new ReallyLongInt();

        string a = test_rli->toString();

        //cout<<"test_rli: " << a << endl;

        REQUIRE(test_rli->toString() == "0");
        REQUIRE_FALSE(test_rli->toString() != "0"); 

        delete test_rli;
    }
}
