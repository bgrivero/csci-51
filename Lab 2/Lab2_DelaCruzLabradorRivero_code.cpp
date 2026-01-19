#include <string>
#include <iostream>
using namespace std;

//TODO: Check for trailing whitespaces
string leftTrim(string message){
  int length = message.length();
  int blank_count = 0;

  for (int i = 0; i < length; i++){
    if (isblank(message[i])){
      blank_count++;
      continue;
    }
    break;
  }

  string left_trimmed_message = message.substr(blank_count);
  return left_trimmed_message;
}

string rightTrim(string message){
  int length = message.length();
  int blank_count = 0;
  cout << "right length: " << length << endl;

  for (int i = length-1; i > 0; i--){
    if (isblank(message[i])){
      cout << "Trailing whitespace!" << endl;
      blank_count++;
      continue;
    }
    cout << "char hit: " << message[i] << endl;
    break;
  }

  string right_trimmed_message = message.substr(0, length - blank_count);
  return right_trimmed_message;
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

    //To Do: Refactor the following message printing mechanism
    getline(cin, message);
    string left_trimmed_message = leftTrim(message);
    cout << "left trimmed: " << left_trimmed_message << endl;
    string trimmed_message = rightTrim(left_trimmed_message);
    cout << "Agent #" << counter << " getline:" << trimmed_message;
    counter += 1;
  }
}
