#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include "puzzle.h"
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


Puzzle::Puzzle(int dim)
{
	dimension = dim;
	vector<int> Row1, Row2, Row3;
	Row1.push_back(1); Row1.push_back(2); Row1.push_back(3);
	Row2.push_back(4); Row2.push_back(5); Row2.push_back(6);
	Row3.push_back(7); Row3.push_back(8); Row3.push_back(9);
	layout.push_back(Row1); layout.push_back(Row2); layout.push_back(Row3);
	SizeOf = dimension * dimension;
	emptySpace_Row = emptySpace_Col = SizeOf/dimension - 1;
	layout[emptySpace_Row][emptySpace_Col] = NULL;

}


void Puzzle::InteractPuzzle()
{

	bool playing = true;
	while (playing)
	{
		if (Puzzle::isInOrder())
		{
			cout << "CONGRATULATOINS YOU SOLVED THE PUZZLE" << endl;
			playing = false;
			cin.clear();
		}
		char inp = _getch();
		switch (inp)
		{
		case UP:
			Puzzle::moveUp();
			Puzzle::display();
			if (Puzzle::isInOrder())
			{
				cout << "CONGRATULATOINS YOU SOLVED THE PUZZLE" << endl;
				playing = false;
				cin.clear();
			}
			break;
		case DOWN:
			Puzzle::moveDown();
			Puzzle::display();
				if (Puzzle::isInOrder())
				{
					cout << "CONGRATULATOINS YOU SOLVED THE PUZZLE" << endl;
					playing = false;
					cin.clear();
				}
			break;
		case LEFT:
			Puzzle::moveLeft();
			Puzzle::display();
			if (Puzzle::isInOrder())
			{
				cout << "CONGRATULATOINS YOU SOLVED THE PUZZLE" << endl;
				playing = false;
				cin.clear();
			}
			break;
		case RIGHT:
			Puzzle::moveRight();
			Puzzle::display();
			if (Puzzle::isInOrder())
			{
				cout << "CONGRATULATOINS YOU SOLVED THE PUZZLE" << endl;
				playing = false;
				cin.clear();
			}
			break;
		case 'Q': case 'q':
			playing = false;
			break;
			}
	}
}

void Puzzle::display()
{
	cout << endl << endl;
	cout << "****************" << endl;
	cout << setw(3);
	for (int irow = 0; irow < dimension; irow++)
	{
		for (int icol = 0; icol < dimension; icol++)
		{
			if (layout[irow][icol])
				cout << setw(3) << layout[irow][icol] << "  ";
			else
				cout << setw(3) << " " << "  ";
		}
		cout << endl;
	}
	cout << "****************" << endl;

}


bool Puzzle::canMoveUp()
{
	if (emptySpace_Row - 1 < 0)
		return false;
	else
		return true;
}

bool Puzzle::canMoveDown()
{
	if (emptySpace_Row + 1 >= dimension)
		return false;
	else
		return true;
}

bool Puzzle::canMoveLeft()
{
	if (emptySpace_Col - 1 < 0)
		return false;
	else
		return true;
}

bool Puzzle::canMoveRight()
{
	if (emptySpace_Col + 1 >= dimension)
		return false;
	else
		return true;
}

void Puzzle::moveUp()
{
	if (canMoveUp())
	{
		int empty = layout[emptySpace_Row][emptySpace_Col];
		int to_move = layout[emptySpace_Row - 1][emptySpace_Col];
		layout[emptySpace_Row][emptySpace_Col] = to_move;
		layout[emptySpace_Row - 1][emptySpace_Col] = empty;
		emptySpace_Row--;
	}
}

void Puzzle::moveDown()
{
	if (canMoveDown())
	{
		int empty = layout[emptySpace_Row][emptySpace_Col];
		int to_move = layout[emptySpace_Row + 1][emptySpace_Col];
		layout[emptySpace_Row][emptySpace_Col] = to_move;
		layout[emptySpace_Row + 1][emptySpace_Col] = empty;
		emptySpace_Row++;
	}
	else{}
}

void Puzzle::moveLeft()
{
	if (canMoveLeft())
	{
		int empty = layout[emptySpace_Row][emptySpace_Col];
		int to_move = layout[emptySpace_Row][emptySpace_Col - 1];
		layout[emptySpace_Row][emptySpace_Col] = to_move;
		layout[emptySpace_Row][emptySpace_Col - 1] = empty;
		emptySpace_Col--;
	}
	else{}
}

void Puzzle::moveRight()
{
	if (canMoveRight())
	{
		int empty = layout[emptySpace_Row][emptySpace_Col];
		int to_move = layout[emptySpace_Row][emptySpace_Col + 1];
		layout[emptySpace_Row][emptySpace_Col] = to_move;
		layout[emptySpace_Row][emptySpace_Col + 1] = empty;
		emptySpace_Col++;
	}
	else{}
}


bool Puzzle::isInOrder()
{
	vector < vector <int> > PuzzleBoard;
	PuzzleBoard.resize(dimension, vector<int>(dimension));
	int i = 1;
	for (int irow = 0; irow < dimension; irow++)
	{
		for (int icol = 0; icol < dimension; icol++)
		{
			PuzzleBoard[irow][icol] = i;
			i++;
		}
	}

PuzzleBoard[dimension-1][dimension-1] = NULL;
	
	if (layout == PuzzleBoard)
	{
		return true;
	}
	else
		return false;
}

void Puzzle::setRandomLayout()
{
	int num;
	int amount = rand() + 1 ;
	for (int i = 0; i < amount; i++)
	{
		num = (rand() % 2);
		if (num)
			Puzzle::moveUp();
		num = (rand() % 2);
		if (num)
			Puzzle::moveDown();
		num = (rand() % 2);
		if (num)
			Puzzle::moveLeft();
		num = (rand() % 2);
		if (num)
			Puzzle::moveRight();
	}
}
	

void Puzzle::Clear()
{
	int i = 1;
	for (int irow = 0; irow < dimension; irow++)
	{
		for (int icol = 0; icol < dimension; icol++)
		{
			layout[irow][icol] = NULL;
		}
	} 
	SizeOf = 0;
}
 

void Puzzle::setUpLayoutManually()
{
	vector <int> used;
	bool exist = true;
	int val;
	Puzzle::Clear();

	cout << "Enter the values to create a puzzle" << endl;
	while (SizeOf < dimension*dimension)
	for (int irow = 0; irow < dimension; irow++)
	{
		for (int icol = 0; icol < dimension; icol++)
		{
			enter:
			cin >> val;
			lastvalue:
			exist = true;
			for (int i = 0; i < used.size(); i++)
			{
				if (val == used[i] || (val > (dimension*dimension) - 1) || (val < 0))
					exist = false;
				cout << "Not a valid value" << endl;
			}

			if (exist)
			{
				used.push_back(val);
				layout[irow][icol] = val;
				Puzzle::display();
				SizeOf++;
				if (val == 0)
				{
					emptySpace_Col = icol;
					emptySpace_Row = irow;
				}
			}
			else
			{
				Puzzle::display();
				goto enter;
			}
			//if (irow == dimension - 1 && icol == dimension - 1)
			//{
			//	while (used == val[i])
			//}
		}
	}
	created:
	cout << "Puzzle created." << endl;
}
