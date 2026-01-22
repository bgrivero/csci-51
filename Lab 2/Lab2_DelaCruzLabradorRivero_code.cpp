#include <string>
#include <iostream>
using namespace std;

// Function trims leading whitespaces by iterating through the start of the "message" string and stops until it hits the first character.
string leftTrim(string message){
  int length = message.length();
  int blank_count = 0;

  for (int i = 0; i < length; i++){
    if (isspace(message[i])){
      blank_count++;
      continue;
    }
    break;
  }

  string left_trimmed_message = message.substr(blank_count);
  return left_trimmed_message;
}

// Function trims trailing whitespaces by starting at the end of the "message" string and stops until it hits the last character.
string rightTrim(string message){
  int length = message.length();
  int blank_count = 0;

  for (int i = length-1; i > 0; i--){
    if (isspace(message[i])){
      blank_count++;
      continue;
    }
    break;
  }

  string right_trimmed_message = message.substr(0, length - blank_count);
  return right_trimmed_message;
}

// Helper function to check if string is a message.
bool isInteger(string message){
  if (message.empty()){
    return false;
  }

  int length = message.length();
  for (int i = 0; i < length ; i++){
    // Check for integers starting with a positive or negative sign, e.g. -200 must be recognized as an int
    // Checks the length for single-input '-' or '+' messages.
    if (i == 0 && (message[0] == '-' || message[0] == '+') && length > 1){
      continue;
    }
    if (!(isdigit(message[i]))){
      return false;
    }
  }
  return true;
}

int main(void){
  int num_agents;
  
  //First line simply contains the number of agents to expect, which we parse through cin
  cin >> num_agents;

  //Create a counter and a while loop to iterate through the agents
  int counter = 1;
  while (counter <= num_agents){
    int x; int y; string message;

    //Parse agent position and message
    cin >> x >> y;
    cout << "Agent #" << counter << " is at " << "(" << x << ", " << y << ") " << endl; 

    //Prints out the lines as indicated in the specs
    getline(cin, message);
    string left_trimmed_message = leftTrim(message);
    string trimmed_message = rightTrim(left_trimmed_message);
    if (isInteger(trimmed_message)){
      cout << "Agent #" << counter << " holds up the number: " << trimmed_message << endl;
    }
    else{
      cout << "Agent #" << counter << " yells: \"" << trimmed_message << "\"" << endl;
    }
    counter += 1;
  }
}

/*
TODO:
3) Check edge cases / potential errors.
4) Add robust checking if lines match N.
5) Check if any needed code to deal with the redirected way of adding input.


SOURCES:
https://www.geeksforgeeks.org/cpp/substring-in-cpp/
https://www.programiz.com/cpp-programming/library-function/cctype/isdigit
*/