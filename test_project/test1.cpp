#include <gtest/gtest.h>
#include "../animal/Date.cpp"

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(Date::daysInMonth(2000,5),5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}