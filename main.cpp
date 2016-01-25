#include <iostream>
#include <stack>
#include <vector>
#include "puzzle.h"
#include <iomanip> 

using namespace std;

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int main()
{	
	srand((unsigned int)time(00));
	int dim;
	int num, val;
	Puzzle Board(3);
	Board.setRandomLayout();


	bool inMenu = true;													// while the user is using the program this var is set to true and the menu keeps looping.
	// when the user wants to quit, it is set to false and the loop ends.

	char keyPressed;													// This var stores which menu selection the user picks.
	while (inMenu)
	{
		cout << endl << endl << endl;
		cout << "****************************************************" << endl;
		cout << "**  MENU:(press a character to select an option)  **" << endl;
		cout << "****************************************************" << endl;
		cout << "Q. [QUIT] QUIT" << endl;
		cout << endl;
		cout << "P. [PLAY] PLAY A PUZZLE" << endl;
		cout << endl;
		cout << "N. [NEW] START A NEW PUZZLE" << endl;
		cout << endl;
		cout << "M. [MANUAL] MANUALLY ENTER A PUZZLE" << endl;
		cout << endl;
		//cout << "S. [SOLVE] SOLVE THE CURRENT PUZZLE" << endl;
		cout << "****************************************************" << endl << endl;

		cout << "Your choice is: ";
		cin >> keyPressed;

		switch (keyPressed)
		{
		case 'Q': case 'q'://Quit
			cout << "[QUIT]:" << endl;
			inMenu = false;
			cout << "Program ending, thank you for using";
			break;

		case 'P': case 'p':
			cout << endl << "Playing puzzle" << endl;
			cout << "Press q to quit at any time" << endl;
			Board.display();
			Board.InteractPuzzle();
			break;

		case 'N': case 'n': 
			cout << endl << "What are the dimensions of the puzzle?" << endl;
			//cin >> dim;
			//Board = Puzzle::Puzzle(dim);
			cout << "Created a new puzzle";
			Board.display();
			cout << endl << "Playing puzzle" << endl;
			cout << "Press q to quit at any time" << endl;
			Board.display();
			Board.InteractPuzzle();
			break;

		case 'M': case 'm':
			Board.setUpLayoutManually();
			break;

		case 'S': case 's':
			cout << "Testing implementation of queue" << endl;
			cout << "Not implemented yet" << endl;
			break;

		}
	}
}
