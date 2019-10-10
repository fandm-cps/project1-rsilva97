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

    }

    SECTION("absSub"){

        ReallyLongInt zero, sPos(5), bPos(8), sNeg(-5), bNeg(-9), two(2), one(1);

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
        ReallyLongInt divQuot, divRem, pos(21), oPos(3), neg(-18), oNeg(-3), thirteen(13), two(2), bigNum(439), oBigNum(67), mod = oBigNum % thirteen;
        
        REQUIRE(mod.toString() == "2");

        pos.div(oPos, divQuot, divRem);
        REQUIRE(divQuot.toString() == "7");
        REQUIRE(divRem.toString() == "0");

        neg.div(oNeg, divQuot, divRem);
        REQUIRE(divQuot.toString() == "6");
        REQUIRE(divRem.toString() == "0");

        neg.div(oPos, divQuot, divRem);
        REQUIRE(divQuot.toString() == "-6");
        REQUIRE(divRem.toString() == "0");

        oPos.div(oNeg, divQuot, divRem);
        REQUIRE(divQuot.toString() == "-1");
        REQUIRE(divRem.toString() == "0");

        pos.div(neg, divQuot, divRem);
        REQUIRE(divQuot.toString() == "-1");
        REQUIRE(divRem.toString() == "3");

        thirteen.div(two, divQuot, divRem);
        REQUIRE(divQuot.toString() == "6");
        REQUIRE(divRem.toString() == "1");

        bigNum.div(oBigNum, divQuot, divRem);
        REQUIRE(divQuot.toString() == "6");
        REQUIRE(divRem.toString() == "37"); 



    }

    SECTION("isPrime"){

        ReallyLongInt zero, one(1), two(2), three(3), fifteen(15), bigEven(5498), smallPrime(11), bigPrime(7321);

        REQUIRE(two.isPrime() == true);
        REQUIRE(zero.isPrime() == false);
        REQUIRE(bigEven.isPrime() == false);
        REQUIRE(one.isPrime() == false);
        REQUIRE(bigPrime.isPrime() == true);
        REQUIRE(smallPrime.isPrime() == true);
        REQUIRE(fifteen.isPrime() == false);
        REQUIRE(three.isPrime() == true);

    }

    SECTION("exp"){
        ReallyLongInt zero, two(2), three(3), five(5), negSeven(-7);

        REQUIRE(two.exp(three).toString() == "8");
        REQUIRE(two.exp(five).toString() == "32");
        REQUIRE(five.exp(zero).toString() == "1");
        REQUIRE(negSeven.exp(two).toString() == "49");
        REQUIRE(negSeven.exp(three).toString() == "-343");

    }

}
