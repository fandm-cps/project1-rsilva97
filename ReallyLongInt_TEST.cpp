#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing ReallyLongInt Class"){

    ReallyLongInt *test_rli;
    ReallyLongInt *test_rliNeg;
    ReallyLongInt *test_rliPos;
    ReallyLongInt *test_otherNeg;
    ReallyLongInt *test_otherPos;

    SECTION("Default Constructor"){

        test_rli = new ReallyLongInt();
        test_otherNeg = new ReallyLongInt(-10);
        test_otherPos = new ReallyLongInt(5);

        REQUIRE(test_rli->toString() == "0");
        REQUIRE_FALSE(test_rli->toString() != "0"); 

        REQUIRE(test_rli->toStringBinary() == "0");
        REQUIRE_FALSE(test_rli->toStringBinary() != "0");
        
        REQUIRE(test_rli->equal(*test_otherNeg) == false);
        REQUIRE_FALSE(test_rli->equal(*test_otherNeg) != false);

        REQUIRE(test_rli->equal(*test_rli) == true);
        REQUIRE_FALSE(test_rli->equal(*test_rli) != true);
        
        REQUIRE(test_rli->greater(*test_otherPos) == false);
        REQUIRE_FALSE(test_rli->greater(*test_otherPos) != false);
        
        REQUIRE(test_rli->greater(*test_otherNeg) == true);
        REQUIRE_FALSE(test_rli->greater(*test_otherNeg) != true);

        //delete test_rli;
        //delete test_otherNeg;
        //delete test_otherPos;
    }

    SECTION("long long num Constructor"){

        test_rliNeg = new ReallyLongInt(-5);
        test_rliPos = new ReallyLongInt(5);
        test_otherNeg = new ReallyLongInt(-10);
        test_otherPos = new ReallyLongInt(24);

        REQUIRE(test_rliNeg->toString() == "-5");
        REQUIRE_FALSE(test_rliNeg->toString() != "-5"); 

        REQUIRE(test_rliPos->toString() == "5");
        REQUIRE_FALSE(test_rliPos->toString() != "5");

        REQUIRE(test_rliPos->toStringBinary() == "101");
        REQUIRE_FALSE(test_rliPos->toStringBinary() != "101");

        REQUIRE(test_otherNeg->toStringBinary() == "-1010");
        REQUIRE_FALSE(test_otherNeg->toStringBinary() != "-1010");

        REQUIRE(test_rliNeg->equal(*test_rliPos) == false);
        REQUIRE_FALSE(test_rliNeg->equal(*test_rliPos) != false);

        REQUIRE(test_rliPos->equal(*test_rliPos) == true);
        REQUIRE_FALSE(test_rliPos->equal(*test_rliPos) != true);
        
        REQUIRE(test_rliNeg->greater(*test_otherNeg) == true);
        REQUIRE_FALSE(test_rliNeg->greater(*test_otherNeg) != true);
        
        REQUIRE(test_rliPos->greater(*test_otherNeg) == true);
        REQUIRE_FALSE(test_rliPos->greater(*test_otherNeg) != true);

        //delete test_rliNeg;
        //delete test_rliPos;
        //delete test_otherNeg;
        //delete test_otherPos;
        
    }

    SECTION("const string& numStr Constructor"){

        test_rliNeg = new ReallyLongInt("-6");
        test_rliPos = new ReallyLongInt("6");
        test_otherNeg = new ReallyLongInt("-15");
        test_otherPos = new ReallyLongInt("23");

        REQUIRE(test_rliNeg->toString() == "-6");
        REQUIRE_FALSE(test_rliNeg->toString() != "-6");
        
        REQUIRE(test_rliPos->toString() == "6");
        REQUIRE_FALSE(test_rliPos->toString() != "6");

        REQUIRE(test_rliNeg->toStringBinary() == "-110");
        REQUIRE_FALSE(test_rliNeg->toStringBinary() != "-110");
        
        REQUIRE(test_rliPos->toStringBinary() == "110");
        REQUIRE_FALSE(test_rliNeg->toStringBinary() != "110");

        REQUIRE(test_rliNeg->equal(*test_rliPos) == false);
        REQUIRE_FALSE(test_rliNeg->equal(*test_rliPos) != false);

        REQUIRE(test_rliPos->equal(*test_rliPos) == true);
        REQUIRE_FALSE(test_rliPos->equal(*test_rliPos) != true);
        
        REQUIRE(test_rliPos->greater(*test_rliNeg) == true);
        REQUIRE_FALSE(test_rliPos->greater(*test_rliNeg) != true);

        REQUIRE(test_rliPos->greater(*test_otherPos) == false);
        REQUIRE_FALSE(test_rliPos->greater(*test_otherPos) != false);
        
        REQUIRE(test_rliNeg->greater(*test_otherNeg) == true);
        REQUIRE_FALSE(test_rliNeg->greater(*test_otherNeg) != true);

        //delete test_rliNeg;
        //delete test_rliPos;
        //delete test_otherNeg;
        //delete test_otherPos;
    }
    
    SECTION("Copy Constructor"){

        test_rli = new ReallyLongInt();
        test_rliNeg = new ReallyLongInt(-9);
        test_rliPos = new ReallyLongInt("8");
        test_otherNeg = new ReallyLongInt(*test_rliNeg);
        test_otherPos = new ReallyLongInt(*test_rliPos);

        REQUIRE(test_otherNeg->toString() == "-9");
        REQUIRE_FALSE(test_otherNeg->toString() != "-9");

        REQUIRE(test_otherPos->toString() == "8");
        REQUIRE_FALSE(test_otherPos->toString() != "8");
        
        REQUIRE(test_otherPos->toStringBinary() == "1000");
        REQUIRE_FALSE(test_otherPos->toStringBinary() != "1000");

        REQUIRE(test_otherNeg->toStringBinary() == "-1001");
        REQUIRE_FALSE(test_otherNeg->toStringBinary() != "-1001");

        REQUIRE(test_otherPos->equal(*test_rliPos) == true);
        REQUIRE_FALSE(test_otherPos->equal(*test_rliPos) != true);

        REQUIRE(test_otherNeg->equal(*test_rliNeg) == true);
        REQUIRE_FALSE(test_otherNeg->equal(*test_rliNeg) != true);

        REQUIRE(test_otherNeg->greater(*test_rli) == false);
        REQUIRE_FALSE(test_otherNeg->greater(*test_rli) != false);

        REQUIRE(test_otherPos->greater(*test_rliPos) == false);
        REQUIRE_FALSE(test_otherPos->greater(*test_rliPos) != false);

        REQUIRE(test_otherPos->greater(*test_otherNeg) == true);
        REQUIRE_FALSE(test_otherPos->greater(*test_otherNeg) != true);
        
        //delete test_rli;
        //delete test_rliNeg;
        //delete test_rliPos;
        //delete test_otherNeg;
        //delete test_otherPos;
    }
}
