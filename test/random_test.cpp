#include "random.h"

#include <gtest/gtest.h>

#include <iostream>

TEST(RandomTest, Real)
{
    for (int i = 0; i < 100; i++)
    {
        float random_f = random::RandomReal<float>(0.F, 100.F);
        EXPECT_GE(random_f, 0.F);
        EXPECT_LT(random_f, 100.F);

        double random_lf = random::RandomReal(0.0, 100.0);
        EXPECT_GE(random_lf, 0.F);
        EXPECT_LT(random_lf, 100.F);
    }
}
