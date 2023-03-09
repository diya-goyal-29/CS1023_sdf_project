#include<gtest/gtest.h>
#include"dice.h"
#include"build.h"
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}