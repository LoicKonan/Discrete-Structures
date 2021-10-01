//***********************************************************************
//																		*
//		Name:   Loic Arnaud Konan.										*
//																		*
//		Course: CMPS-2433-101, Fall 2020, Dr.Catherine Stringfellow.	*
//																		*
//		This program will find the highest bit that is set in a number	*
//		"k", and will print out the index. The program will then SET	*
//		the next highest bit to 1 and then print the new number,		*
//		"k2" using bitwise operators.									*
//																		*
//***********************************************************************

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

// Function Prototype for the HighestBitIndex. This function will
// find and return the index of the highest bit. 
int HighestBitIndex(int);


// Function Prototype for the NextHighestBit. This function will find 
// and return the next highest bit set in K as K2.
int NextHighestBit(int, int);


// Funtion Prototype to Asked the user for name of files to be use.
void openFiles(ifstream& infile, ofstream& outfile);


int main()
{
	// Ifstream and ofstream object to read data from the file.
	ifstream infile;
	ofstream outfile;


	// Calling the Function openFiles.
	openFiles(infile, outfile);


	// Declare Variables for number of Cases, the Number K and Bit Index.
	int numbCase, number_K,
		Bit_Index = 0;


	// Display Program Title / Header.
	outfile << "Loic Arnaud Konan.\n";
	outfile << "Highest Bit Program 1.\n\n";


	// Read Number of test cases from the data InFile.
	while (infile >> numbCase)
	{

		// Display the number of test cases in the required format. 
		outfile << "There are " << numbCase << " test cases.\n\n";
		outfile << "K         HighestBit       K2\n";
		outfile << "--------------------------------\n";


		// Read in the actual Cases from the data InFile.
		while (infile >> number_K)
		{

			// Calling the Function HighestBitIndex.
			Bit_Index = HighestBitIndex(number_K);

			// Calling the Function NextHighestBit.
			int number_K2 = NextHighestBit(number_K, Bit_Index);


			// If the case number is zero (0).
			if (number_K <= 0)
			{

				// Set Number K2 to one if number there is 0 case.
				number_K2 = 1;

				// Display the number K, and the next highest Bit K2.
				outfile << left		 << setw(15)	<< number_K << left
						<< setw(12)	 << '-' << left << setw(6)  << left
						<< number_K2 << '\n';
			}

			// If case number is greater than zero (0).
			else
			{
				// Display the number K, and the next highest Bit K2.
				outfile << left		<< setw(15)  << number_K << left
						<< setw(12) << Bit_Index << left	 << setw(6)
						<< left		<< number_K2 << '\n';
			}
		}
	}

	// Closing outfile and infile.
	infile.close();
	outfile.close();

	return 0;
}


//***********************************************************************
//					Function Name: openFiles () 						*
//					Parameters: ifstream& infile, ofstream& outfile 	*
//																		*
//		Purpose:  To prompt the user for the infile and outfile			*
//				  name to be use.										*
//		Receives: Will receives the infile and outfile characters		*
//				  letters from the user.								*
//		Returns:  Void.													*
//																		*
//***********************************************************************

void openFiles(ifstream& infile, ofstream& outfile)
{
	// Declare variable for the Files. 
	char inFileName[40];
	char outFileName[40];

	// Prompt the user for infile name
	cout << "Enter the input file name: ";
	cin  >> inFileName;

	// open input file
	infile.open(inFileName);

	// Prompt the user for outfile name
	cout << "Enter the output file name: ";
	cin  >> outFileName;

	// Open out putfile.
	outfile.open(outFileName);
}


//***********************************************************************
//					Function Name: HighestBitIndex () 					*
//					Parameters: int number_K 							*
//																		*
//		Purpose:  Find and return the index of the highest				* 
//				  bit set of number "K".								*
//		Receives: Use a loop to shift the bits of the number right		* 
//				  until the number is 0, count and update the index		*
//				  The number 0 is special return -1 for the index.		*
//		Returns:  Return the integer index of the highest bit back to   *
//				  main.													*
//																		*
//***********************************************************************

int HighestBitIndex(int number_K)
{

	int index = 1;

	// If number K isn't equal to 1 shift bits of K right until number is 0.
	while (number_K != 1)
	{

		// The number 0 is a special case return -1 for the index.
		if (number_K == 0)
		{
			return -1;
		}

		// Shift the bits of the number K right 1.
		number_K = number_K >> 1;

		index++;
	}

	return index;
}


//***********************************************************************
//					Function Name: HighestBitIndex () 					*
//					Parameters:  int number_K, int index				*
//																		*
//		Purpose:  Find and return the number "k2" with the next highest * 
//				  bit set in "k".										*
//		Receives: Shift a 1 left index number and use the result		*
//				  in a bitwise operation with k to get "k2".			*
//		Returns:  Return the integer number "k2" with the next highest  *
//				  bit in "k" back to main.								*
//																		*    
//***********************************************************************

int NextHighestBit(int number_K, int index)
{

	int someNumber, number_K2;

	// if Index less than 0 shift Number left 1.
	if (index < 0)
	{
		someNumber = 1 << 0;
	}

	// If Index greater or equal to 0 shift Number left 1.
	else
	{
		someNumber = 1 << index;
	}

	// Use a OR Bitwise operation to find the new number k2.
	number_K2 = number_K | someNumber;

	return number_K2;
}