//***********************************************************************
//		Loic Konan                                                      *
//		Dr. Stringfellow                                                *
//		CMPS-2433-101                                                   *
//		December 02, 2020												*
//		Program # 4.													*
//																		*
//																		*
//		Description:                                                    *
//		This Program will read in data from a input file and the	    *
//		first character on each line will be either a P or a C, 		*
//		to indicate the calculation that will be perform				*
//		(permutation or combination).									*
//																		*
//**********************************************************************/

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;


// Prompt the user the files names.
void openFiles(ifstream&, ofstream&);


// Perform the Permutation Formula: nPr(n,r) = n!/(n-r)!
// by using the iterative function.
long long permutation(int n, int r);


// Perform the Combination Formula: nCr(n,r) = n!/r!(n-r)!
// by using the recursive function.
long long combination(int n, int r);


// Function that Calculate each term of a sequence using preceding term.
long long Recursive(int);


// Using a for loop to repeatedly executed until a certain condition 
// is satisfied.
long long iterative(int);



int main()
{
	ifstream infile;
	ofstream outfile;

	openFiles(infile, outfile);

	// Variables Declarations.
	char letter;
	int numbA, numbB, numb_Case = 0;
	long long Perm_Result,
		Comb_Result;


	// Prints Heading.
	outfile << "\n              Loic Konan            \n";
	outfile << "          CMPS 2433 Program 4         \n";
	outfile << "======================================\n";
	outfile << "Operation                       Result\n";
	outfile << "======================================\n\n";


	// If it is not the end of the file keep reading in data.
	while (!infile.eof())
	{
		// Read in the letter that will indicate what formula to use
		// and the 2 numbers to perform the equation from the input file.
		infile >> letter >> numbA >> numbB;


		// Assigning the return values of Permutation and Combination
		// to a local Variable.
		Perm_Result = permutation(numbA, numbB);
		Comb_Result = combination(numbA, numbB);


		// If the first character on the line is C perform this below.  
		if (letter == 'C' || letter == 'c')
		{
			outfile << letter << " (" << setw(2) << numbA << "," << setw(2)
				<< numbB << ")" << " = " << setw(25) << Comb_Result << "\n\n";
		}


		// If the first character on the line is P perform this below.  
		else
		{
			outfile << letter << " (" << setw(2) << numbA << "," << setw(2)
				<< numbB << ")" << " = " << setw(25) << Perm_Result << "\n\n";
		}
		// incrementing number of test cases.
		numb_Case++;
	}

	// Prints number of test cases.
	outfile << "======================================\n";
	outfile << "\tThe number of test cases: " << numb_Case << '\n';
	outfile << "======================================\n";

	// Closing the outfile and the infile.
	infile.close();
	outfile.close();

	return 0;
}



//***********************************************************************
//		Function Name: Recursive										*
//		Parameter: int num								 				*
//																		*
//		Purpose: If the number read in is 1 or 0 return 1 to the main 	*
//				 Function, else calculate each term of a sequence using	*
//				 the preceding term.								    *
//																		*
//		Returns:  long long												*
//																		*
//***********************************************************************

long long Recursive(int num)
{
	// In case the number is equal to 1 or 0 return 1.
	if (num == 1 || num == 0)
	{
		return 1;
	}

	// Perfom the calculation below if the number is not equal to 1 or 0. 
	else
	{
		// Defines the terms of a sequence using previous terms.
		return num * Recursive(num - 1);
	}
}



//***********************************************************************
//		Function Name: iterative										*
//		Parameter: int num								 				*
//																		*
//		Purpose: Initiate a simple For loop and multiply targetNumber	*
//				 with index in each iteration. index is also reduced	*
//				 by 1 in each iteration.								*
//																	    *
//																		*
//		Returns:  long long												*
//																		*
//***********************************************************************

long long iterative(int num)
{
	long long targetNumber = 1;

	//  Using a for loop to find the value of targetNumber.
	//  and reduce the value of i in each iteration by 1.
	for (int i = num; i > 1; i--)
	{
		targetNumber *= i;
	}
	return targetNumber;
}



//***********************************************************************
//		Function Name: permutation										*
//		Parameters: int n, int r										*
//																		*
//		Purpose: To find the number of ways to choose a sample of 'r'	*
//				 elements from a set of 'n' distinct objects, where		*
//				 order does matter.	When n = r	this reduces to (n!).	*
//				 This function invoke the iterative function to apply  	*
//				 this Formula = > Permutation = nPr(n,r) = n!/(n-r)!	*
//																		*
//		Returns:  long long												*
//																		*
//***********************************************************************

long long permutation(int n, int r)
{
	return (iterative(n) / iterative(n - r));
}



//***********************************************************************
//		Function Name: combination () 									*
//		Parameters: int n, int r						 				*
//																		*
//		Purpose: To find the number of ways to choose a sample of 'r'	*
//				 elements from a set of 'n' distinct objects, where		*
//				 order does not matter.									*
//				 This function invoke the recursive function and use 	*
//				 this Formula = > Combination = nCr(n,r) = n!/r!(n-r)!	*
//																		*
//	   Returns:  long long.												*
//																		*
//***********************************************************************

long long combination(int n, int r)
{
	return (Recursive(n) / (Recursive(r) * Recursive(n - r)));

}



//***********************************************************************
//		Function Name: openFiles () 									*
//		Parameters: ifstream& infile, ofstream& outfile 				*
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
	char inFileName[40];
	char outFileName[40];

	cout << "Enter the input file name: ";
	cin >> inFileName;

	// open input file
	infile.open(inFileName);
	cout << "Enter the output file name: ";
	cin >> outFileName;

	// Open output file.
	outfile.open(outFileName);
}