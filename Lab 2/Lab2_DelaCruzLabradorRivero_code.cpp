#include <string>
#include <iostream>
using namespace std;

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
    cout << message << endl;
    counter += 1;
  }
}
