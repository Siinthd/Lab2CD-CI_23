#include <gtest/gtest.h>
#include "../src/filter.h"
#include <string>


TEST(FilterTest, SplitTest) {
  std::string teststr1("185.89.100.249	752	0");
  std::string teststr2("119.42.115.97	11	0");

  std::vector<std::string> res1 = split(teststr1, '\t');
  std::vector<std::string> res2 = split(teststr2, '\t');
 
  std::vector<std::string> res3 = split(res1.at(0), '.');
  std::vector<std::string> res4 = split(res2.at(0), '.');
  
  std::vector<std::string> answ1{{"185"},{"89"},{"100"},{"249"}};
  std::vector<std::string> answ2{{"119"},{"42"},{"115"},{"97"}};
  
  ASSERT_TRUE(res1[0] == "185.89.100.249");
  ASSERT_TRUE(res2[0] == "119.42.115.97");
  ASSERT_TRUE(res3 == answ1);
  ASSERT_TRUE(res4 == answ2);
 
}

TEST(FilterTest, sort_reverseTest) {
	pool question{	{37,188,189,227},
						{188,69,198,152},
						{98,196,145,69},
						{68,202,216,62},
						{5,189,203,79}};
						
  	pool answer{	{188,69,198,152},
						{98,196,145,69},
						{68,202,216,62},
						{37,188,189,227},
						{5,189,203,79}};
	pool result = sort_reverse(question);
	ASSERT_TRUE(result == answer);
	
}

TEST(FilterTest, filterTest_one) {
	pool question{		{177,66,186,82},
				{107,209,121,224},
				{213,103,211,108},
				{27,49,172,153},
				{78,158,5,183},
				{78,158,5,183},
				{27,109,142,224},
				{103,101,109,70}};
	pool result = filter(question,27);
	pool result2 = filter(question,103);
	pool answer1{{27,109,142,224},{27,49,172,153}};
	pool answer2{{103,101,109,70}};
  ASSERT_TRUE(result == answer1);
  ASSERT_TRUE(result2 == answer2);
}

TEST(FilterTest, filterTest_two) {
  	pool question{		{177,66,186,82},
				{107,209,121,224},
				{213,103,211,108},
				{27,49,172,153},
				{78,158,5,183},
				{78,158,5,183},
				{27,109,142,224},
				{103,101,109,70}};
	pool result = filter(question,27,49);
	pool result2 = filter(question,103,101);
	pool answer1{{27,49,172,153}};
	pool answer2{{103,101,109,70}};
  ASSERT_TRUE(result == answer1);
  ASSERT_TRUE(result2 == answer2);
}

TEST(FilterTest, filterTest_any) {
    	pool question{		{177,66,183,82},
				{107,209,121,224},
				{213,103,211,108},
				{27,49,172,153},
				{78,158,5,183},
				{78,158,5,183},
				{27,109,142,224},
				{103,101,109,70}};
	pool result = filter_any(question,183);
	pool result2 = filter_any(question,103);
	pool answer1{{177,66,183,82},{78,158,5,183},{78,158,5,183}};
	pool answer2{{213,103,211,108},{103,101,109,70}};
  ASSERT_TRUE(result == answer1);
  ASSERT_TRUE(result2 == answer2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
