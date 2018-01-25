//
// Created by Bjørn Lindi on 25/10/17.
//

#ifndef STLTUTORIAL_REGEXPTEST_HPP
#define STLTUTORIAL_REGEXPTEST_HPP

#include <regex>
// setting namespaces
using namespace testing;
using namespace std;

class STLregex : public testing::Test{
public:
    regex  reg1{"<.*>.*</.*>"};
    regex  reg2{"<(.*)>.*</\\1>"};
    regex  reg3{"<\\(.*\\("};
};

TEST_F(STLregex, FindXML_HTMLtaggedvalue){
    bool found = regex_match("<tag>value</tag>",  // the data
                           reg1);                 // the regex

    EXPECT_THAT(found, true);
}

TEST_F(STLregex, FindXML_HTMLtaggedvalue_beforeandafter){
    bool found = regex_match("<tag>value</txg>",   // the data
                              reg2);               // the regex
    EXPECT_THAT(found, false);

}

#endif //STLTUTORIAL_REGEXPTEST_HPP
