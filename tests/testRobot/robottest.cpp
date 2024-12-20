#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include"../../doctest.h"
#include"../../robot.h"

/*
ce qu'il faut tester

s'il detecte bien les obstacles
s'il avance et il change de direction
*/ 

TEST_CASE("test doctest"){
    SUBCASE("test bidon"){
        int x= 1;
        REQUIRE_EQ(x,1);
    }
}

