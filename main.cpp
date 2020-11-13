// sitthiphol yuwanaboon
// CS 216
// LAB October 26, 2020 

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
void runAllTests();

// Returns the length of a string
int stringLength(const string STR) {
    int result = -1;
     // set result to the length of the string
    result = STR.length();
    
    return result;
}

// Returns the character of a string at a given index
char charAt(const string STR, const int IDX) {
    char result = '\0';
    // TODO 01:set result to the character of a string at a given index
    result = STR.at(IDX);
    // variables available: const string STR, const int IDX
    return result;
}

// Returns a concatenation of strings left and right
string stringAppend(const string LEFT, const string RIGHT) {
    string result = LEFT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    //string result = LEFT.append(RIGHT);
    result = LEFT+RIGHT;

    // variables available: const string LEFT, const string RIGHT
    return result;
}

// Returns the result of inserting a string into another at a given position
string stringInsert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    // TODO 03: set result to the result of inserting a string into another
    result.insert(IDX, TO_INSERT);
   
    
    // variables available: const string STR, const string TO_INSERT, const int IDX
    return result;
}

// Returns the first index of character c in string s
int stringFind(const string STR, const char C) {
    int result = -1;
    // TODO 04: set result to the index of the first occurrence of the character
    result=STR.find(C);
    // variables available: const string STR, const char C
    return result;
}

// Returns part of a string
string stringSubstring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    // TODO 05: set result to be a substring starting at index of given length
    result = STR.substr(IDX, LEN);
    // variables available: const string STR, const int IDX, const int LEN
    return result;
}

// Replaces part of a string
string stringReplace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    // TODO 06: set result to be the string with the given text replaced
   

    int start_pos = result.find(TEXT_TO_REPLACE);

    if(start_pos == std::string::npos)

    return result;

    result.replace( start_pos, TEXT_TO_REPLACE.length(), REPLACE_WITH);

   


    // variables available: const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH
    return result;
}

// Returns the first word, given a sentence
string firstWord(const string STR) {
    string result = STR;
    // TODO 07: set result to the first word from the string
    result = STR.substr(0, STR.find(" "));


    // variables available: const string STR
    return result;
}

// Returns the string with the first word removed
string removeFirstWord(const string STR) {
    string result = STR;
    // TODO 08: set result to be the string with the first word removed
    int index = STR.find_first_of(" ");

    if(index ==-1)

    return "";

    result=STR.substr(STR.find_first_of(" ")+1);

    // variables available: const string STR
    return result;
}

// Returns the second word, given a sentence
string secondWord(const string STR) {
    string result = STR;
    // TODO 09: set result to be the second word from the string
    int count = STR.find(" ");
       result = result.substr(count+1, STR.length());
       count = result.find(" ");
       result = result.substr(0, count);
       
    return result;
}

// Returns the third word, given a sentence
string thirdWord(const string STR) {
    string result = STR;

    // TODO 10: set result to be the third word from the string
    int count;
    for(int i = 0; i < 2; i++) {
          count = result.find(" ");
          result = result.substr(count+1, STR.length());
      }
      count = result.find(" ");
      result = result.substr(0, count);
      
    // variables available: const string STR
    return result;
}

// Returns the nth word, given a sentence
string nthWord(const string STR, const int N) {
    string result = STR;
    // TODO 11: set result to be the nth word from the string
   
                    if(N==1){

                    return result.substr(0,result.find(" "));

                    }

                   
                    result= nthWord(result.substr(result.find(" ")+1),N-1);


    // variables available: const string STR, const int N
    return result;
}

// Returns a string substituting character target with string replacement
string substitute(const string STR, const string TARGET, const string REPLACEMENT) {
    string result = STR;
    // TODO 12: set result to be the string with all instances of TARGET replaced
    result = "";
    int start = 0;
      int index = STR.find(TARGET, start);
      while(index != string::npos){
          result = result + STR.substr(start, index-start);
          result = result + REPLACEMENT;
         
          start = index + TARGET.length();
          if(start >= STR.length())
              break;
          index = STR.find(TARGET, start);
      }
     
      result = result + STR.substr(start);
     
    // variables available: const string STR, const string TARGET, const string REPLACEMENT
    return result;
}
//---------------------------------------------------------------------------
int main() {

    cout << "Testing your functions...\n\n";
    runAllTests();
    return 0;
}


void test(const string MESSAGE, const string LHS, const string RHS) {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " -->FAILED   \"" << LHS << "\" != \"" << RHS << "\"\n";
}

void test(const string MESSAGE, const char LHS, const char RHS) {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " -->FAILED '" << LHS << "' != '" << RHS << "'\n";
}

void test(const string MESSAGE, const int LHS, const int RHS) {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " -->FAILED " << LHS << " != " << RHS << "\n";
}
// Do not modify, this function.
void runAllTests() {
    test("Testing length()", stringLength("Fun"), 3);
    test("Testing length()", stringLength("TheEnd"), 6);
    test("Testing at()", charAt("California", 3), 'i');
    test("Testing at()", charAt("Angeles", 2), 'g');
    test("Testing append()", stringAppend("There's a ", "Cat on the tree."), "There's a Cat on the tree.");
    test("Testing append()", stringAppend("It is my ", "first exam."), "It is my first exam.");
    test("Testing insert()", stringInsert("If you safely.", "pass ", 7), "If you pass safely.");
    test("Testing insert()", stringInsert("Happy.", "Be ", 0), "Be Happy.");
    test("Testing find()", stringFind("Have to face reality now.", 'o'), 6);
    test("Testing find()", stringFind("Have to face reality now.", 'e'), 3);
    test("Testing substr()", stringSubstring("Such a natural mystic", 7, 7), "natural");
    test("Testing substr()", stringSubstring("Such a natural mystic", 0, 4), "Such");
    test("Testing replace()", stringReplace("Strings are not the way", "Strings", "Things"), "Things are not the way");
    test("Testing replace()", stringReplace("Show me the things", "things", "way"), "Show me the way");
    test("Testing firstWord()", firstWord("We'll cross that bridge when we come to it"), "We'll");
    test("Testing firstWord()", firstWord("five birds are flying in the sky"), "five");
    test("Testing firstWord()", firstWord("you have to repeat your test"), "you");
    test("Testing removeFirstWord()", removeFirstWord("We'll cross that bridge when we come to it"), "cross that bridge when we come to it");
    test("Testing removeFirstWord()", removeFirstWord("Nothing"), "");
    test("Testing removeFirstWord()", removeFirstWord(removeFirstWord("We'll cross that bridge when we come to it")), "that bridge when we come to it");
    test("Testing secondWord()", secondWord("We'll cross that bridge when we come to it"), "cross");
    test("Testing secondWord()", secondWord("five birds are flying in the sky"), "birds");
    test("Testing secondWord()", secondWord("you have to repeat your test"), "have");
    test("Testing thirdWord()", thirdWord("We'll cross that bridge when we come to it"), "that");
    test("Testing thirdWord()", thirdWord("five birds are flying in the sky"), "are");
    test("Testing thirdWord()", thirdWord("you have to repeat your test"), "to");
    test("Testing nthWord(1)", nthWord("We'll cross that bridge when we come to it", 1), "We'll");
    test("Testing nthWord(2)", nthWord("We'll cross that bridge when we come to it", 2), "cross");
    test("Testing nthWord(3)", nthWord("We'll cross that bridge when we come to it", 3), "that");
    test("Testing nthWord(4)", nthWord("We'll cross that bridge when we come to it", 4), "bridge");
    test("Testing nthWord(5)", nthWord("We'll cross that bridge when we come to it", 5), "when");
    test("Testing nthWord(6)", nthWord("We'll cross that bridge when we come to it", 6), "we");
    test("Testing nthWord(7)", nthWord("We'll cross that bridge when we come to it", 7), "come");
    test("Testing nthWord(8)", nthWord("We'll cross that bridge when we come to it", 8), "to");
    test("Testing nthWord(9)", nthWord("We'll cross that bridge when we come to it", 9), "it");
    test("Testing substitute()", substitute("The Gxxgle", "x", "o"), "The Google");
    test("Testing substitute()", substitute("$chool of Mine$", "$", "s"), "school of Mines");
    test("Testing substitute()", substitute(substitute("D--", "-", "+"), "D", "C"), "C++");
}

/*
 
 Testing length():     PASSED
 Testing length():     PASSED
     Testing at():     PASSED
     Testing at():     PASSED
 Testing append():     PASSED
 Testing append():     PASSED
 Testing insert():     PASSED
 Testing insert():     PASSED
   Testing find():     PASSED
   Testing find():     PASSED
 Testing substr():     PASSED
 Testing substr():     PASSED
Testing replace():     PASSED
Testing replace():     PASSED
Testing firstWord():     PASSED
Testing firstWord():     PASSED
Testing firstWord():     PASSED
Testing removeFirstWord():     PASSED
Testing removeFirstWord():     PASSED
Testing removeFirstWord():     PASSED
Testing secondWord():     PASSED
Testing secondWord():     PASSED
Testing secondWord():     PASSED
Testing thirdWord():     PASSED
Testing thirdWord():     PASSED
Testing thirdWord():     PASSED
Testing nthWord(1):     PASSED
Testing nthWord(2):     PASSED
Testing nthWord(3):     PASSED
Testing nthWord(4):     PASSED
Testing nthWord(5):     PASSED
Testing nthWord(6):     PASSED
Testing nthWord(7):     PASSED
Testing nthWord(8):     PASSED
Testing nthWord(9):     PASSED
Testing substitute():     PASSED
Testing substitute():     PASSED
Testing substitute():     PASSED
 */
