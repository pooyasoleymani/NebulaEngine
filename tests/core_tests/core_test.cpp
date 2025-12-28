#include "pch.hpp"
#include "nebula/core.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("Core Test", "[Core]"){

    nebula::Core core;
    
    REQUIRE( core.Version() == "0.1.0");
};