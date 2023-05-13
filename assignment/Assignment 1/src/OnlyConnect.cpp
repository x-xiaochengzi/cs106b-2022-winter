/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
string onlyConnectize(string phrase) {
    if (phrase.length() == 0) {
        return "";
    }else {
        if (isalpha(phrase[0])) {
            if (!isVowel(phrase[0])) {
                return charToString(toUpperCase(phrase[0])) + onlyConnectize(phrase.substr(1));
            }
        }
        return onlyConnectize(phrase.substr(1));
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}
STUDENT_TEST("Vowel") {
    EXPECT(isVowel('a'));
    EXPECT(isVowel('e'));
    EXPECT(isVowel('i'));
    EXPECT(isVowel('o'));
    EXPECT(isVowel('u'));
    EXPECT(isVowel('A'));
    EXPECT(isVowel('E'));
    EXPECT(isVowel('I'));
    EXPECT(isVowel('O'));
    EXPECT(isVowel('U'));
}
STUDENT_TEST("Extreme cases") {
    EXPECT_EQUAL(onlyConnectize("qwertyuioplkjhgfdsazxcvbnm"),"QWRTYPLKJHGFDSZXCVBNM");
    EXPECT_EQUAL(onlyConnectize(""), "");
}
STUDENT_TEST("Wired cases") {
    EXPECT_EQUAL(onlyConnectize("11111111111windows11linux111ubuntu11ios11andriod11111"),"WNDWSLNXBNTSNDRD");
    EXPECT_EQUAL(onlyConnectize("!@#@!#222dfds~;;fkgasfa"),"DFDSFKGSF");
}

