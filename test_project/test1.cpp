#include <gtest/gtest.h>
#include "f.cpp"

TEST(HelloTest, BasicAssertions) {
  EXPECT_EQ(f(5),9);
  ASSERT_EQ(f(4),9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}