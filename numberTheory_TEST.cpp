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

    }
    
}