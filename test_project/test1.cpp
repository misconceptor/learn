#include <gtest/gtest.h>
#include "../animal/Date.cpp"
#include "../animal/MicAnimal.cpp"
#include "../animal/Animal.cpp"

//namespace zootest {
	class AnimalFixture : public ::testing::Test {
	protected:
		void SetUp() override {
		}

		void TearDown() override {
		}

		std::vector<Animal*> animals_;
		std::vector<Date> dates_;
		std::vector<std::string> nickNames_;
		std::vector<int> ages_;
		Date current_{ 2023, 11, 23 };
    };
    TEST_F(AnimalFixture, TestCtorAnimal)
    {
        ASSERT_THROW(Date(111,3,22), std::invalid_argument);
        //ASSERT_EQ(dates_.size(),nickNames_.size());
    }
		
//TEST(HelloTest, BasicAssertions) {}
//};
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}