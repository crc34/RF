#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <catch.hpp>
#include "ParticleSet.h"

TEST_CASE( "", "[MonteCarloSampler]" ) {
    auto nParticles = 1000000;
    auto dim = 10;
    auto auxDim = 10;

    SECTION("Particle set constructor works")
    {
        particleSet particles(nParticles, dim, auxDim);
        REQUIRE((particles.nParticles == nParticles));
        REQUIRE((particles.stateSpaceDimension == dim));
        REQUIRE((particles.auxStateSpaceDimension == auxDim));
    }

    SECTION("Particle set equality operator works")
    {
        particleSet particles1(nParticles, dim, auxDim);
        particleSet particles2(nParticles + 1, dim, auxDim);
        REQUIRE((particles1 != particles2));
        REQUIRE((particles1 == particles1));
    }

    SECTION("Copy constructor works")
    {
        particleSet particles1(nParticles, dim, auxDim);
        particleSet particles2(particles1);
        REQUIRE((particles1 == particles2));
    }
}

