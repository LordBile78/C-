// Fiction Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>


using namespace std;

// define global variables
int humanity = 3;
int human_effergy = 0;
int win = 0;

void part3()
{


	// variable for the while loop, runs the while loop as long as variable is equal to zero
	int options = 0;

	// Run while loop while options variable is equal to zero
	while (options == 0)
	{
		std::cout << "Would you like to leave the castle, or go down the hallway? ";

		string input; // String variable

		// gets whole user input
		getline(cin, input);
		// checks the users input
		if ((input == "go down the hallway" || input == "Go down the hallway"))
		{
			cout << "You lose your sense of direction and are forever lost in the castle. \nWandering as a mindless ghoul\n";
			system("pause");
			// reduce amount of humanity
			--humanity;
			--humanity;
			--humanity;
			++options;
		}

		//checks users string input against required conditions
		else if ((input == "Leave the castle" || input == "leave the castle"))
		{
			//adds value to options variable
			++options;
			//adds value to win variable
			++win;
		}

		// if the user does not entered appropriate string display this error message
		else
		{
			cout << ("Please enter that differntly\n");
			system("pause");
			system("cls");
		}
	}
}

// function for the second part and calls second function
void part2()
{
	// Variables
	int items = 2;
	int map = 0;
	int leave_area = 1;

	cout << "With your humanity restored you regain your strength\n";

	// since this part requires key items run the loop until user has picked up all items in the area
	while (items != 0)
	{
		cout << "You find another pouch labled human effergy, and a map.\n";
		cout << "What would you like to do? \n";

		// string variable for users input
		string answer;
		//gets users whole input 
		getline(cin, answer); // puts users input into the string variable

		// checks the users string input, and the value of the human effergy variable as a condition
		if ((answer == "Take human effergy" || answer == "take human effergy") && (human_effergy < 1))
		{
			cout << "You took the human effergy\n";
			// add one to the value of human effergy
			++human_effergy;
			//decrease items value by one
			--items;
			system("pause");
			system("cls");
		}

		// checks the users string input, and the value of the human effergy variable as a condition
		else if ((answer == "take human effergy" || answer == "Take human effergy") && human_effergy == 1)
		{
			cout << "You already took the human effergy\n";
			system("pause");
			system("cls");
		}

		// checks users string input and value of map variable
		else if ((answer == "take the map" || answer == "Take the map") && map < 1)
		{
			cout << "You tool the map\n";
			cout << "The map shows you the path to leave the castle, but there is a hallway ahead of you, do you leave the area, or take the hallway?\n";
			// decreases items variable
			--items;
			//user picked up the map, add value to its variable
			++map;
			system("pause");
			system("cls");
		}

		// checks users string input and value of map variable
		else if ((answer == "grab the map" || answer == "Grab the map") && map == 1)
		{
			cout << "You already grabbed a map!\n";
			system("pause");
			system("cls");
		}

		// check users string input and leave area variable
		else if ((answer == "leave the area" || answer == "Leave the area") && leave_area == 0)
		{
			cout << "You cant leave yet!\n";
			cout << "hint you need something that shows directions\n";
			system("pause");
			system("cls");
		}

		// check users string input and leave area variable
		else if ((answer == "Leave the area" || answer == "leave the area") && leave_area == 1)
		{
			cout << "You cant leave yet!\n";
			cout << "Hint, you need to restore your humanity, and something to show you directions\n";
			system("pause");
			system("cls");
		}

		// if user enters a string that does not match conditions
		else
		{
			cout << ("Please enter that differntly\n");
			system("pause");
			system("cls");
		}
	}
}

void part1() // First story function
{
	// variable for user input
	string input;
	system("cls");
	cout << "You are lost in a dark castle and come across a discarded bag.\n";
	cout << "You search the bag and find a pouch labled human effergy, would you like to use the human effergy? y/n\n";
	// store the users input into the defined variable
	cin >> input;

	// if the user uses the effergy restore their humanity
	if (input == "y" || input == "Y")
	{
		system("cls");
		cout << "You absorb the human effergy restoring your humanity to " << humanity << endl;
		system("pause");
		system("cls");
		cout << ".\n";
		cout << ".\n";
		system("pause");
		system("cls");
	}

	//reduce humanity if user does not use effergy
	else if (input == "n" || input == "N")
	{
		--humanity;
		--humanity;
		--humanity;
		system("cls");
	}
}


// Main int function
int main()
{
	// get player name and stor as a string
	string player_name;
	cout << "Please enter your name: ";
	cin >> player_name;
rerun:
	system("cls");
	cout << "Welcome " << player_name << " to Hallowing" << endl;
	system("pause");
	system("cls");
	cout << "Hollowing is a text based game inspired by pick your adventure books.\n";
	system("cls");
	cout << "In this game you posess humanity, if your humanity becomes zero your become a ghoul. \n";
	system("pause");
	system("cls");
	cout << "We're about to begin, good luck.\n";
	system("pause");

	// Call part one functions and runs it
	part1();

	// make sure that the payer has humanity in order to continue to second part of the story
	if (humanity > 0)
	{
		// runs the second function
		part2();
	}

	// make sure that the player has humanity to further progress
	if (humanity > 0)
	{
		// begin the third part, call and run the next function
		part3();
	}

	// if the users humanity is less than, or is zero
	if (humanity <= 0)
	{
		// get user input and store it in string
		string input;
		system("cls");
		// if win variable = 1 congratulate the user has beat the game
		if (win == 1)
			cout << "Your humanity reached 0" << " you died!\n";
		cout << "Would you like to try again? y/n\n";
		cin >> input;

		if (input == "y" || input == "Y") // If user input y rerun code
		{
			system("cls");
			// Add to humanity count
			++humanity;
			++humanity;
			++humanity;
			// return to line rerun and reruns the program
			goto rerun;
		}

		// checks users string to exit the application
		else if (input == "n" || input == "N")
		{
			system("cls");
			cout << "Thank you for playing my game" << player_name << endl;
			cout << "\nPress enter to exit the game.\n";
			// Exits the application
			exit(0);
		}
	}

	if (win == 1) // if win variable = 1 the user has completed the game
	{
		system("cls");
		cout << player_name << " you beat the game";
		cout << "\nPress enter to quit the game.\n";
		system("pause");
		exit(0);
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
