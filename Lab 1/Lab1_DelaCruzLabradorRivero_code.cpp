#include <iostream>
using namespace std;

/* 
  This function checks if the character is Uppercase (0), Lowercase (1), or Neither (2).
  These integer values will be used to verify later on whether or not the character will be increased.

  Sources: 
  https://www.geeksforgeeks.org/dsa/check-whether-the-given-character-is-in-upper-case-lower-case-or-non-alphabetic-character/
  https://www.w3schools.com/cpp/cpp_conditions.asp
*/
int check(char x){
  if (x>='A' && x<='Z'){
    return 0;
  }
  else if (x>='a' && x<='z'){
    return 1;
  }
  else{
    return 2;
  }
}

/*
  This function fulfills requirement #3.
  The replace function is used to simply replace the characters starting from index 1 (2nd char) with '#'.

  Source: https://www.geeksforgeeks.org/cpp/std-string-replace-in-cpp/
*/
string censor(string name){
  string censored_name = name.replace(1, name.length()-1, name.length()-1, '#');
  return censored_name;
}

/*
  This function fulfills requirement #4.
  It uses the integer output of the check function to decide whether or not to increment the char.
  Since characters can be incremented in C++, it is easier to do so rather than making custom dictionary/array.

  Source: https://www.geeksforgeeks.org/cpp/character-arithmetic-in-cpp/
*/
string getNextLetter(string name){
  int string_length = name.length();

  for (int i = 0; i < string_length; i++){
    char current_char = name[i];
    int char_type = check(current_char);
    
    if (char_type == 2){
      continue;
    }
    current_char++;
    name[i] = current_char;
  }

  return name;
  
}



int main(void){
  string name;
  cout << "What is your name?: ";
  cin >> name;
  cout << name << endl;

  string censored_name = censor(name);
  cout << censored_name << endl;

  string increased_name = getNextLetter(name);
  cout << increased_name << endl;
}

/*
  TODO: 
  1) Make test cases for debugging.
  2) Requirement #5 (though im not sure if that's what I did already).
*/