#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <conio.h>


using namespace std;


class Puzzle

{

public:        //The following members can be called anywhere



	Puzzle(int dim);

	//      The constructor to initialize the puzzle.

	//      By default, just set the dimension to 3 and

	//      can initialize the puzzle properly as a 3 by 3 puzzle.



	void display();         //display the puzzle


	void Clear();

	void InteractPuzzle();

	void moveUp();          //move the space cell up

	void moveDown();                //move the space cell down

	void moveLeft();                //move the space cell left

	void moveRight();       //move the space cell right



	bool canMoveUp();       //check whether we can move the space cell up

	bool canMoveDown();     //check whether we can move the space cell down

	bool canMoveLeft();     //check whether we can move the space cell left

	bool canMoveRight();    //check whether we can move the space cell right



	bool isInOrder();       //check whether the puzzle is solved with all the cells in order



	void setRandomLayout(); //Reset the puzzle with a random layout



	void setUpLayoutManually();

	//Set up the puzzle manually:

	// Based on the dimension of the puzzle n, the method should ask the user to

	// enter the contents of the n by n puzzle.

	//If the user enter things that does not compose a valid puzzle,

	//      the program should ask the user to do it again until it is valid.

	Puzzle getUpNeighbor();  //get the neighbor reached when move up

	Puzzle getDownNeighbor();  //get the neighbor reached when move down

	Puzzle getLeftNeighbor();  //get the neighbor reached when move left

	Puzzle getRightNeighbor(); //get the neighbor reached when move right

	bool findSolution();

	//search to find a shortest solution by calling

	//one of the following implementation of breadth-first search



	bool searchSolution_BFS_vector();

	//breadth-first search for solution using vectors



	bool searchSolution_BFS_BST();

	//breadth-first search for solution using a binary search tree +vectors







	bool operator==(Puzzle anotherPuzzle);

	//Define the equality relational operator for comparing puzzles

	//needed for comparing puzzles stored in a binary search tree.



	bool operator<(const Puzzle anotherPuzzle)const;

	//Define the less than relational operator for comparing puzzles

	//needed for comparing puzzles stored in a binary search tree.





	friend ostream & operator<< (ostream & output, const Puzzle & aPuzzle);

	//Define the global output operator so that we can wtite code like

	//  output << aPuzzle;

	//to write a puzzle into file outputstream object.








private:

	int SizeOf;

	int dimension;

	//The dimension of the puzzle, i.e. the number of rows and columns of the puzzle.

	//By default dimension is 3, and the puzzle is a 3 by 3 puzzle.



	vector< vector<int> > layout;

	// layout is a vector of vector of integers to record

	// the current layout of the puzzle.

	// layout[i][j] stores the number appearing on row i and column j of the puzzle.

	//

	// For the empty cell,

	// we use the number 0 to indicate that the cell should be display as an empty cell.





	// The following two data members record the current location of the empty cell.

	// In other words, the empty cell is currently at row space_i and column space_j

	// of the puzzle and the contents of layout[space_i] [ space_j] is 0.

	int emptySpace_Row;            //The space cell is in layout[space_i][space_j] of the

	int emptySpace_Col;            //the puzzle.







};





#endif
