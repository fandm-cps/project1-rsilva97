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
        ReallyLongInt test_zero(0);

        CAPTURE(test_rliNeg.toString());
        
        REQUIRE(test_rliNeg.toString() == "-5");
        REQUIRE(test_rliPos.toString() == "5");
        REQUIRE(test_rliPos.toStringBinary() == "101");
        REQUIRE(test_otherNeg.toStringBinary() == "-1010");
        REQUIRE(test_zero.toString() == "0");

    }

    SECTION("const string& numStr Constructor"){

        ReallyLongInt test_rliNeg("-6");
        ReallyLongInt test_rliPos("6");
        ReallyLongInt test_otherNeg("-15");
        ReallyLongInt test_otherPos("23");
        ReallyLongInt test_zero("0");

        CAPTURE(test_rliNeg.toString());

        REQUIRE(test_rliNeg.toString() == "-6");
        REQUIRE(test_rliPos.toString() == "6");
        REQUIRE(test_rliNeg.toStringBinary() == "-110");
        REQUIRE(test_rliPos.toStringBinary() == "110");
        REQUIRE(test_zero.toString() == "0");
    
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

        ReallyLongInt test_zero, test_pos(5), test_oPos("5"), test_neg(-5), test_other(-6), test_oNeg(test_neg);

        REQUIRE(test_zero.equal(test_zero) == true);
        REQUIRE(test_pos.equal(test_oPos) == true);
        REQUIRE(test_neg.equal(test_oNeg) == true);
        REQUIRE(test_zero.equal(test_neg) == false);
        REQUIRE(test_pos.equal(test_zero) == false);
        REQUIRE(test_pos.equal(test_neg) == false);
        REQUIRE(test_other.equal(test_oPos) == false);
        

        /*ReallyLongInt test_rli;
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
        REQUIRE(test_rliPos.equal(test_another) == false);*/

    }

    SECTION("Greater"){

        ReallyLongInt zero, pos(5), oPos(254), another(4), neg(-5), oNeg(-12864);

        REQUIRE(zero.greater(neg) == true);
        REQUIRE(pos.greater(neg) == true);
        REQUIRE(oPos.greater(pos) == true);
        REQUIRE(neg.greater(oNeg) == true);
        REQUIRE(pos.greater(another) == true);

        REQUIRE(zero.greater(pos) == false);
        REQUIRE(zero.greater(zero) == false);
        REQUIRE(neg.greater(pos) == false);
        REQUIRE(oNeg.greater(neg) == false);
        REQUIRE(pos.greater(oPos) == false);
        REQUIRE(another.greater(pos) == false);
        

        /*ReallyLongInt test_rli;
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
        REQUIRE(test_another2.greater(test_rliPos) == false);*/

    }
    //Checkpoint 2
    
    SECTION("operator="){
        ReallyLongInt test_rli(10), test_another = test_rli;

        REQUIRE(test_another.toString() == "10");
        REQUIRE(test_rli.toString() == "10");
    }

    SECTION("absAdd"){

        ReallyLongInt zero, pos(5), oPos(456), neg(-5), oNeg(-8);

        REQUIRE(zero.absAdd(zero).toString() == "0");
        REQUIRE(zero.absAdd(pos).toString() == "5");
        REQUIRE(pos.absAdd(zero).toString() == "5");
        REQUIRE(zero.absAdd(neg).toString() == "-5");
        REQUIRE(neg.absAdd(zero).toString() == "-5");
        REQUIRE(pos.absAdd(oPos).toString() == "461");
        REQUIRE(neg.absAdd(oNeg).toString() == "13");
        REQUIRE(pos.absAdd(oNeg).toString() == "13");
        REQUIRE(neg.absAdd(oPos).toString() == "461");


        /*ReallyLongInt test_rli(5);
        ReallyLongInt test_another(6);
        ReallyLongInt test_rliNeg(-10);

        REQUIRE(test_rli.absAdd(test_another).toString() == "11");
        REQUIRE(test_another.absAdd(test_rliNeg).toString() == "16");
        REQUIRE(test_rliNeg.absAdd(test_rliNeg).toString() == "20");*/

    }

    SECTION("absSub"){

        ReallyLongInt zero, sPos(5), bPos(8), sNeg(-5), bNeg(-9);

        REQUIRE(zero.absSub(zero).toString() == "0");
        REQUIRE(zero.absSub(sPos).toString() == "-5");
        REQUIRE(zero.absSub(sNeg).toString() == "-5");
        REQUIRE(sPos.absSub(zero).toString() == "5");
        REQUIRE(sNeg.absSub(zero).toString() == "5");
        REQUIRE(bNeg.absSub(sNeg).toString() == "4");
        REQUIRE(sNeg.absSub(bNeg).toString() == "-4");
        REQUIRE(bPos.absSub(sPos).toString() == "3");
        REQUIRE(sPos.absSub(bPos).toString() == "-3");
        REQUIRE(sNeg.absSub(bPos).toString() == "-3");
        REQUIRE(sPos.absSub(bNeg).toString() == "-4");
        REQUIRE(bNeg.absSub(sPos).toString() == "4");
        REQUIRE(bPos.absSub(sNeg).toString() == "3");
        REQUIRE(bPos.absSub(bPos).toString() == "0");
        REQUIRE(sPos.absSub(sNeg).toString() == "0");
        REQUIRE(sNeg.absSub(sPos).toString() == "0");
        REQUIRE(bNeg.absSub(bPos).toString() == "1");
        REQUIRE(bPos.absSub(bNeg).toString() == "-1");
        
        /*ReallyLongInt test_rli(10), test_another(5), test_test(6);

        REQUIRE(test_rli.absSub(test_another).toString() == "5");
        REQUIRE(test_rli.absSub(test_rli).toString() == "0");
        
        ReallyLongInt test_rli1(6), test_another1(10);
        
        REQUIRE(test_rli1.absSub(test_another1).toString() == "-4");
        
        ReallyLongInt test_rli2(13), test_another2(10), test_rli4(9), test_another4(3);
        
        REQUIRE(test_rli2.absSub(test_another2).toString() == "3");
        REQUIRE(test_rli4.absSub(test_another4).toString() == "6");
        
        ReallyLongInt test_rli3(9), test_another3(15);

        REQUIRE(test_rli3.absSub(test_another3).toString() == "-6");
        REQUIRE(test_rli.absSub(test_test).toString() == "4");*/
    }

    SECTION("operator-"){
        ReallyLongInt pos(5), neg = -pos;

        REQUIRE(neg.toString() == "-5");
    }

    SECTION("add"){
        ReallyLongInt zero, pos(5), oPos(7), neg(-5), oNeg(-9), total = pos + oNeg;
        
        REQUIRE(zero.add(zero).toString() == "0");
        REQUIRE(zero.add(pos).toString() == "5");
        REQUIRE(zero.add(neg).toString() == "-5");
        REQUIRE(pos.add(zero).toString() == "5");
        REQUIRE(neg.add(zero).toString() == "-5");
        REQUIRE(pos.add(oPos).toString() == "12");
        REQUIRE(neg.add(oNeg).toString() == "-14");
        REQUIRE(pos.add(neg).toString() == "0");
        REQUIRE(oNeg.add(oPos).toString() == "-2");
        REQUIRE(total.toString() == "-4");

        /*ReallyLongInt test_pos(25), test_neg("-12"), test_oPos(10), test_oNeg(-6);

        REQUIRE(test_pos.add(test_pos).toString() == "50");
        REQUIRE(test_neg.add(test_neg).toString() == "-24");
        REQUIRE(test_neg.add(test_pos).toString() == "13");
        REQUIRE(test_neg.add(test_oPos).toString() == "-2");
        REQUIRE(test_oPos.add(test_oNeg).toString() == "4");

        ReallyLongInt test_neg1("-12"), test_oPos1(10);

        REQUIRE(test_oPos1.add(test_neg1).toString() == "-2");

        ReallyLongInt test_neg2(-8), test_oPos2(6);
        ReallyLongInt test_add = test_neg2 + test_oPos2;
        REQUIRE(test_add.toString() == "-2");*/
    }

    SECTION("sub"){
        ReallyLongInt zero, sPos(5), bPos(8), sNeg(-5), bNeg(-9), total = bPos - sNeg;

        REQUIRE(zero.sub(zero).toString() == "0");
        REQUIRE(zero.sub(sPos).toString() == "-5");
        REQUIRE(zero.sub(sNeg).toString() == "5");
        REQUIRE(sPos.sub(zero).toString() == "5");
        REQUIRE(sNeg.sub(zero).toString() == "-5");
        REQUIRE(bNeg.sub(sNeg).toString() == "-4");
        REQUIRE(sNeg.sub(bNeg).toString() == "4");
        REQUIRE(bPos.sub(sPos).toString() == "3");
        REQUIRE(sPos.sub(bPos).toString() == "-3");
        REQUIRE(sNeg.sub(bPos).toString() == "-13");
        REQUIRE(sPos.sub(bNeg).toString() == "14");
        REQUIRE(bNeg.sub(sPos).toString() == "-14");
        REQUIRE(bPos.sub(sNeg).toString() == "13");
        REQUIRE(bPos.sub(bPos).toString() == "0");
        REQUIRE(sPos.sub(sNeg).toString() == "10");
        REQUIRE(sNeg.sub(sPos).toString() == "-10");
        REQUIRE(total.toString() == "13");
        
        /*ReallyLongInt test_pos(25), test_neg("-12"), test_oPos(10), test_oNeg(-6);

        REQUIRE(test_neg.sub(test_pos).toString() == "-37");
        REQUIRE(test_pos.sub(test_neg).toString() == "37");
        REQUIRE(test_oPos.sub(test_pos).toString() == "-15");
        REQUIRE(test_neg.sub(test_oNeg).toString() == "-6");

        ReallyLongInt test_pos1(7), test_oPos1(4), test_neg1(-8), test_oNeg1(-10);
        REQUIRE(test_pos1.sub(test_oPos1).toString() == "3");
        REQUIRE(test_neg1.sub(test_oNeg1).toString() == "2");

        ReallyLongInt test_pos2(15), test_neg2(4), test_sub = test_pos2 - test_neg2;
        REQUIRE(test_sub.toString() == "11"); */
    }

    SECTION("mult"){
        ReallyLongInt test_pos(3), test_pos1(9), test_neg(-8), test_neg1(-2), test_zero, test_mult = test_pos * test_neg;

        REQUIRE(test_pos.mult(test_zero).toString() == "0");
        REQUIRE(test_neg.mult(test_zero).toString() == "0");
        REQUIRE(test_zero.mult(test_neg).toString() == "0");
        REQUIRE(test_zero.mult(test_pos).toString() == "0");
        REQUIRE(test_zero.mult(test_zero).toString() == "0");
        REQUIRE(test_pos.mult(test_pos1).toString() == "27");
        REQUIRE(test_pos1.mult(test_pos).toString() == "27");
        REQUIRE(test_pos.mult(test_pos).toString() == "9");
        REQUIRE(test_neg.mult(test_pos1).toString() == "-72");
        REQUIRE(test_neg.mult(test_pos).toString() == "-24");
        REQUIRE(test_neg.mult(test_neg1).toString() == "16");
        REQUIRE(test_neg1.mult(test_neg).toString() == "16");
        REQUIRE(test_neg.mult(test_neg).toString() == "64");
        REQUIRE(test_mult.toString() == "-24");

    }

    SECTION("div"){
        ReallyLongInt test_divQuot, test_divRem, test_pos(4), test_neg(-3), test_oPos(2), test_oNeg(-9);
        
        test_pos.div(test_oPos, test_divQuot, test_divRem);

        REQUIRE(test_divRem.toString() == "0");
        REQUIRE(test_divQuot.toString() == "0");
    }

}
