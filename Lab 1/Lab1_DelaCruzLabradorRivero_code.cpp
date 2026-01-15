#include <iostream>
using namespace std;

/* 
  This function checks if the character is Uppercase (0), Lowercase (1), or Neither (2).
  These integer values will be used to verify later on whether or not the character will be increased.
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
*/
string censor(string name){
  if (name.length() <= 1) {
    return name;
  }
  string censored_name = name.replace(1, name.length()-1, name.length()-1, '#');
  return censored_name;
}

/*
  This function fulfills requirement #4.
  It uses the integer output of the check function to decide whether or not to increment the char.
  Since characters can be incremented in C++, it is easier to do so rather than making custom dictionary/array.
*/
string getNextLetterV1(string name){
  int string_length = name.length();

  for (int i = 0; i < string_length; i++){
    char current_char = name[i];
    int char_type = check(current_char);
    
    if (char_type == 2){
      continue;
    }

    if (current_char == 'z'){
      name.replace(i, 1, 1, 'a');
      continue;
    }
    else if (current_char == 'Z'){
      name.replace(i, 1, 1, 'A');
      continue;
    }
    else{
      current_char++;
    }

    name[i] = current_char;
  }

  return name;
  
}

/*
  This function fulfills requirement #5.
  It uses a pointer input charP to increment the character *charP in-place.
*/

void getNextLetterV2(char* charP){
  if (check(*charP) != 2){
    if (*charP == 'z'){
      *charP = 'a';
    }
    else if (*charP == 'Z'){
      *charP = 'A';
    }
    else{
      (*charP) ++;
    }
  }  
}

int main(void){
  string name;
  cout << "What is your name?: ";
  getline(cin, name); // uses getline() method to handle empty strings.
  cout << name << endl;

  string censored_name = censor(name);
  cout << censored_name << endl;

  string increased_name = getNextLetterV1(name);
  cout << increased_name << endl;

  for (int i = 0; i < name.length(); i++) {
    getNextLetterV2(&name[i]); 
  }
  cout << name << endl;
}
