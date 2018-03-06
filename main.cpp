#include<iostream>
#include <vector>
#include <string>

class Automaton
{
public:
	Automaton();
	bool read_commands(const std::vector<char>& commands);

private:
	static unsigned int transition(unsigned int state, unsigned int x);
	unsigned int start_state;
};

Automaton::Automaton() : start_state(1) {} //setting the initial state through the constructor

unsigned int Automaton::transition(unsigned int state, unsigned int x) { //function to handle the transitions of the state


	int table[3][2] = { { 1,2 },{ 3,2 },{ 2,2 } }; //2d array to hold the transition states - the 3 row headers would be the present states 
	//and the column headers the commands (i.e 0 or 1)
	int transitioned_state = table[state - 1][x]; //assigning the array element that corresponds to the present state and command 
	//to int transitioned_state
	return transitioned_state;

}

bool Automaton::read_commands(const std::vector<char>& commands) { //function to read the commands and call the transition function

	int z;
	int present_state = start_state;

	for (int n = 0; n < commands.size(); n++) { //looping through the commands

		z = commands[n] - '0'; //converting from char to int. '0' has ascii numerical representation of 48
		Automaton::transition(present_state, z); //calling the tranistion function
		present_state = Automaton::transition(present_state, z); //assigning the newly transitioned state to int present_state so that 
		//in the next iteration of the for loop it can be treated as the present state

	}

	if (present_state == 2) //checking if the end state equals the accepted state

	{
		return true;
	}

	else

	{
		return false;
	}
}

int main()
{
	Automaton object;

	std::cout << object.read_commands({ '1','0','0','1' }) << "\n";

	return 0;
}