#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <catch.hpp>
#include "CoreStats.h"

TEST_CASE( "", "Binomial" ) {
    SECTION("mean and variance converge")
    {
        auto N = 100000;
        auto nTrials = 10;
        auto p = 0.1;
        double firstMoment = 0;
        double secondMoment = 0;
        for (int i = 0; i < N; i++)
        {
            auto draw = binomial(nTrials, p);
            firstMoment += draw; 
            secondMoment += draw*draw;
        }
        firstMoment /= N;
        secondMoment /= N;
        auto variance = secondMoment - firstMoment*firstMoment;
        REQUIRE(firstMoment == Approx(nTrials*p).epsilon(0.001));
        REQUIRE(variance == Approx(nTrials*p*(1-p)).epsilon(0.001));
    }
}

TEST_CASE( "", "Multinomial" ) {
    SECTION("mean and variance converge")
    {
    }
}

