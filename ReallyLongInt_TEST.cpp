#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing ReallyLongInt Class"){

    SECTION("Default Constructor"){

        ReallyLongInt test_rli;
    
        REQUIRE(test_rli.toString() == "0");

    }
    
    SECTION("long long num Constructor"){

        ReallyLongInt test_rliNeg(-5);
        ReallyLongInt test_rliPos(5);
        ReallyLongInt test_otherNeg(-10);
        ReallyLongInt test_otherPos(24);

        CAPTURE(test_rliNeg.toString());
        
        REQUIRE(test_rliNeg.toString() == "-5");
        REQUIRE(test_rliPos.toString() == "5");
        REQUIRE(test_rliPos.toStringBinary() == "101");
        REQUIRE(test_otherNeg.toStringBinary() == "-1010");

    }

    SECTION("const string& numStr Constructor"){

        ReallyLongInt test_rliNeg("-6");
        ReallyLongInt test_rliPos("6");
        ReallyLongInt test_otherNeg("-15");
        ReallyLongInt test_otherPos("23");

        CAPTURE(test_rliNeg.toString());

        REQUIRE(test_rliNeg.toString() == "-6");
        REQUIRE(test_rliPos.toString() == "6");
        REQUIRE(test_rliNeg.toStringBinary() == "-110");
        REQUIRE(test_rliPos.toStringBinary() == "110");
    
    } 
    
    SECTION("Copy Constructor"){

        ReallyLongInt test_rliNeg(-9);
        ReallyLongInt test_rliPos("8");
        ReallyLongInt test_otherNeg(test_rliNeg);
        ReallyLongInt test_otherPos(test_rliPos);

        REQUIRE(test_otherNeg.toString() == "-9");
        REQUIRE(test_otherPos.toString() == "8");
        REQUIRE(test_otherPos.toStringBinary() == "1000");
        REQUIRE(test_otherNeg.toStringBinary() == "-1001");

    }

    SECTION("Equal"){

        ReallyLongInt test_rli;
        ReallyLongInt test_rliNeg(-9);
        ReallyLongInt test_rliPos("8");
        ReallyLongInt test_otherNeg("-9");
        ReallyLongInt test_otherPos(test_rliPos);
        ReallyLongInt test_another(9);

        REQUIRE(test_rliNeg.equal(test_rliPos) == false);
        REQUIRE(test_rliPos.equal(test_otherPos) == true);
        REQUIRE(test_otherPos.equal(test_rliPos) == true);
        REQUIRE(test_otherNeg.equal(test_rliNeg) == true);
        REQUIRE(test_rliNeg.equal(test_rliPos) == false);
        REQUIRE(test_rliPos.equal(test_rliPos) == true);
        REQUIRE(test_rliPos.equal(test_another) == false);

    }

    SECTION("Greater"){

        ReallyLongInt test_rli;
        ReallyLongInt test_rliNeg(-9);
        ReallyLongInt test_rliPos("8");
        ReallyLongInt test_otherNeg(test_rliNeg);
        ReallyLongInt test_otherPos(test_rliPos);
        ReallyLongInt test_another(256);
        ReallyLongInt test_another1(9);
        ReallyLongInt test_another2(4);

        REQUIRE(test_otherNeg.greater(test_rli) == false);
        REQUIRE(test_otherPos.greater(test_rliPos) == false);
        REQUIRE(test_otherPos.greater(test_otherNeg) == true);
        REQUIRE(test_rliPos.greater(test_rliNeg) == true);
        REQUIRE(test_rliPos.greater(test_otherPos) == false);
        REQUIRE(test_rliNeg.greater(test_otherNeg) == true); 
        REQUIRE(test_rliNeg.greater(test_otherNeg) == true);
        REQUIRE(test_rliPos.greater(test_otherNeg) == true);
        REQUIRE(test_another.greater(test_rliPos) == true);
        REQUIRE(test_another1.greater(test_rliPos) == true);
        REQUIRE(test_rliPos.greater(test_another1) == false);
        REQUIRE(test_another2.greater(test_rliPos) == false);

    }
    //Checkpoint 2
    SECTION("removeLeadingZeros"){

    }
    
    SECTION("operator="){
        ReallyLongInt test_rli(10);
        ReallyLongInt test_another = test_rli;

        REQUIRE(test_another.toString() == "10");
        REQUIRE(test_rli.toString() == "10");


    }

    SECTION("absAdd"){

        ReallyLongInt test_rli(5);
        ReallyLongInt test_another(6);
        ReallyLongInt test_rliNeg(-10);

        REQUIRE(test_rli.absAdd(test_another).toString() == "11");
        REQUIRE(test_another.absAdd(test_rliNeg).toString() == "16");
        REQUIRE(test_rliNeg.absAdd(test_rliNeg).toString() == "20");

    }

    SECTION("absSub"){

        ReallyLongInt test_rli(10);
        ReallyLongInt test_another(5);
        ReallyLongInt test_otherPos(13);

        REQUIRE(test_rli.absSub(test_another).toString() == "5");
        REQUIRE(test_rli.absSub(test_rli).toString() == "0");
        REQUIRE(test_another.absSub(test_rli).toString() == "-5");
        //REQUIRE(test_otherPos.absSub(test_rli).toString() == "-7");
        //REQUIRE(test_rli.absSub(test_otherPos).toString() == "-3");
        

    }

}
