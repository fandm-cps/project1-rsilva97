#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing numberTheory Class"){

    SECTION("extendedEuclid"){

        ReallyLongInt result, fourteen(14), zero, one(1), seven(7), eleven(11), two(2), x, y;
        numberTheory test;

        result = test.extendedEuclid(fourteen, seven, x, y);

        REQUIRE(result.toString() == "7");
        REQUIRE(x.toString() == "0");
        REQUIRE(y.toString() == "1");

        result = test.extendedEuclid(fourteen, eleven, x, y);

        REQUIRE(result.toString() == "1");
        REQUIRE(x.toString() == "4");
        REQUIRE(y.toString() == "-5");

    }
    
}