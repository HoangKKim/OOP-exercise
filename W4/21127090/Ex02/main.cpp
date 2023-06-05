#include "func2.h"

int main()
{
	int n;
	Hero player;
	
	// input
	player.input();
	cout << endl;
	// output
	player.output();

	// Check and output learned skills
	cout << endl << "Learned skills: " << endl;
	player.learnedSkill();

	// Cut n-last skills 
	cout << endl << "Input number of skills cut: ";
	cin >> n;
	player.cutSkill(n);

	player.~Hero();
	
}