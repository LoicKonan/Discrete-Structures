//***********************************************************************
//																		*
//		Name:   Loic  Konan.									    	*
//																		*
//		Course: CMPS-2433-101, Fall 2020, Dr.Catherine Stringfellow.	*
//																		*
//	The purpose of this Program is to reinforce the concepts of sets,   *
//  to use the sets container class in C++ Standard Template Library.	*	
//  The program, will read integers from an input file into 2 separate  *
//  sets. It will then list the elements in both sets, and find and     *
//  display their intersection, union, difference and both complements. *
//																		*
//***********************************************************************


#include<iostream>
#include<fstream>
#include<set>

using namespace std;

// Global constant for the Universe set of this program.
const int universe_Size = 20;


// Funtion Prototype to Asked the user for name of files to be use.
void openFiles(ifstream&, ofstream&);


// Function Prototype to display all the sets of the program.
// (set A & B, Union, Intersection, Difference and Complements.)
void display_Set(ofstream&, set<int>);


// Function Prototype to Find the Intersection of set A & B.
void intersection(ofstream&, set<int>, set<int>);


// Function Prototype to Find the Union of set A & B.
void union_Set(ofstream&, set<int>, set<int>);


// Function Prototype to Find elements of Set A minus Set B.
void A_Minus_B(ofstream&, set<int>, set<int>);


// Function Prototype to Find elements of Set B minus Set A.
void B_Minus_A(ofstream&, set<int>, set<int>);


// Function Prototype to Find elements of the complements of Set A.
void Complement_Of_A(ofstream&, set<int>, set<int>);


// Function Prototype to Find elements of the complements of Set B.
void Complement_Of_B(ofstream&, set<int>, set<int>);


int main()
{
	// Declaring the sets A & B and the Universe set.
	set<int> A_Set, B_Set, Universe_Set;

	// Ifstream and ofstream object to read data from the file.
	ifstream infile;
	ofstream outfile;

	// Calling the Function openFiles.
	openFiles(infile, outfile);

	// Declaring and initializing the input data. 
	int input = 0;

	// Boolean Condition to know the Value is read.
	bool Value = false;


	// Filling the Universe set with integer from 1-20.
	for (int i = 0; i < universe_Size;)
	{
		++i;
		Universe_Set.insert(i);
	}


	// If it is not the end of the file keep reading in data.
	while (!infile.eof())
	{
		infile >> input;


		// If the input isn't equal to the sentinel value then fill Set A.
		if (input != -999 && Value == false)
		{
			A_Set.insert(input);
		}


		// If input is equal to the sentinel then it's the end of Set A.
		if (input == -999)
		{
			infile >> input;
			Value = true;
		}


		// If the input isn't equal to the sentinel value then fill Set B.
		if (Value == true)
		{
			B_Set.insert(input);
		}
	}

	// Display Program Title / Header.
	outfile << "Loic Konan\nProgram 2 Sets\n\n";


	// Calling the function that will display Set A in a formatted output.
	outfile << "Set A = {";
	display_Set(outfile, A_Set);
	outfile << "}\n\n";


	// Calling the function that will display Set B in a formatted output.
	outfile << "Set B = {";
	display_Set(outfile, B_Set);
	outfile << " }\n\n";


	// Calling the function that will display the Intersection of Set A & B.
	outfile << "The Intersection of Sets A and B = {";
	intersection(outfile, A_Set, B_Set);
	outfile << "}\n\n";


	// Calling the function that will display the Union of Set A & B.
	outfile << "The Uninon of Sets A and B = {";
	union_Set(outfile, A_Set, B_Set);
	outfile << "}\n\n";


	// Calling the function to display the Difference between Set A - B.
	outfile << "A - B = {";
	A_Minus_B(outfile, A_Set, B_Set);
	outfile << "}\n\n";


	// Calling the function to display the Difference between Set B - A.
	outfile << "B - A = {";
	B_Minus_A(outfile, A_Set, B_Set);
	outfile << "}\n\n";


	// Calling the function to display the Complement of Set A.
	outfile << "A complement = {";
	Complement_Of_A(outfile, A_Set, Universe_Set);
	outfile << "}\n\n";


	// Calling the function to display the Complement of Set B.
	outfile << "B complement = {";
	Complement_Of_B(outfile, B_Set, Universe_Set);
	outfile << "}\n\n";


	// Closing our files
	infile.close();
	outfile.close();

	return 0;
}


//***********************************************************************
//					Function Name: display_Set () 						*
//					Parameters: set<int> New, ofstream& outfile 	    *
//																		*
//		Purpose:  To insert the right elements in the different sets    *
//																		*
//		Receives: Will receives the set elements from the file and	    *
//				  the outfile is passed by reference.					*
//		Returns:  Void.													*
//																		*
//***********************************************************************

void display_Set(ofstream& outfile, set<int> New)
{
	// Declare and Initialize the sets size and elements.
	int size_Of_Set = New.size();
	auto elements = New.begin();


	// Display the value pointed to by (*) elements, plus the commas.
	for (int i = 0; i < size_Of_Set - 1; i++)
	{
		outfile << *elements << ", ";
		elements++;
	}
	outfile << *elements;
}


//***********************************************************************
//				Function Name: intersection_Set () 				     	*
//				Parameters: ofstream& outfile, set<int> A, set<int> B	*
//																		*
//		Purpose:  To Find the elements that goes in the set             *
//				  intersection.											*
//                                                                      *
//		Receives: Will receives the set of element A & B and the		*
//				  outfile is passed by reference.					    *
//		Returns:  Void.													*
//																		*
//***********************************************************************

void intersection(ofstream& outfile, set<int> A, set<int> B)
{
	// Declare the set intersection.
	set<int> itersection_Set;


	// Declare and Initialize the sets size and elements.
	auto A_elements = A.begin(), B_elements = B.begin();
	int Size_Of_A = A.size(), Size_Of_B = B.size();


	// Find the common elements to insert in the set intersection.
	for (int i = 0; i < Size_Of_A; i++)
	{

		// Referring to the first element in the set container.
		B_elements = B.begin();


		for (int j = 0; j < Size_Of_B; j++)
		{

			// Comparing each element to see if they the same values.
			if (*B_elements == *A_elements)
			{
				itersection_Set.insert(*B_elements);
			}
			B_elements++;
		}
		A_elements++;
	}

	// Passing the result to the Display function.
	display_Set(outfile, itersection_Set);
}


//***********************************************************************
//				Function Name: union_Set () 				         	*
//				Parameters: ofstream& outfile, set<int> A, set<int> B	*
//																		*
//		Purpose:  To Find the elements that goes in the set   Union     *	
//                                                                      *
//		Receives: Will receives the set of element A & B and the		*
//				   outfile is passed by reference.					    *
//		Returns:  Void.													*
//																		*
//***********************************************************************

void union_Set(ofstream& outfile, set<int> A, set<int> B)
{
	// Inserting the elements of Set B in Set A without duplication.
	A.insert(B.begin(), B.end());


	// Passing the result to the Display function.
	display_Set(outfile, A);
}


//***********************************************************************
//				Function Name: A_Minus_B_Set () 				       	*
//				Parameters: ofstream& outfile, set<int> A, set<int> B	*
//																		*
//		Purpose:  To Find the elements that goes in the Difference of   *
//				  of set A - B										    *	
//                                                                      *
//		Receives: Will receives the set of element A & B and the		*
//				   outfile is passed by reference.					    *
//		Returns:  Void.													*
//																		*
//***********************************************************************

void A_Minus_B(ofstream& outfile, set<int> A, set<int> B)
{
	// Declare the set A minus B.
	set<int> A_Minus_B_Set;


	// Declare and Initialize the sets size and elements.
	auto A_elements = A.begin(), B_elements = B.begin();
	int Size_Of_A = A.size(), Size_Of_B = B.size();


	// Populate the set A minus B with A elements.
	for (int i = 0; i < Size_Of_A; i++)
	{
		A_Minus_B_Set.insert(*A_elements);
		A_elements++;
	}

	// Referring to the first element in the set container
	A_elements = A.begin();


	// Find and remove common elements.
	for (int i = 0; i < Size_Of_A; i++)
	{

		// Referring to the first element in the set container
		B_elements = B.begin();

		for (int j = 0; j < Size_Of_B; j++)
		{

			// In case the elements have the same value, erase it.
			if (*A_elements == *B_elements)
			{
				A_Minus_B_Set.erase(*A_elements);
				B_elements = B.begin();
			}
			else
				B_elements++;
		}
		A_elements++;
	}

	// Passing the result to the Display function.
	display_Set(outfile, A_Minus_B_Set);
}


//***********************************************************************
//				Function Name: B_Minus_A_Set () 				       	*
//				Parameters: ofstream& outfile, set<int> A, set<int> B	*
//																		*
//		Purpose:  To Find the elements that goes in the Difference of   *
//				  of set B - A										    *	 
//                                                                      *
//		Receives: Will receives the set of element A & B and the		*
//				   outfile is passed by reference.					    *
//		Returns:  Void.													*
//																		*
//***********************************************************************

void B_Minus_A(ofstream& outfile, set<int> A, set<int> B)
{
	// Declare the set B minus A.
	set<int> B_Minus_A_Set;


	// Declare and Initialize the sets size and elements.
	auto A_elements = A.begin(), B_elements = B.begin();
	int SizeA = A.size(), SizeB = B.size();


	// Populating the set B minus A with all elements of B.
	for (int i = 0; i < SizeB; i++)
	{
		B_Minus_A_Set.insert(*B_elements);
		B_elements++;
	}

	// Referring to the first element in the set container
	B_elements = B.begin();


	// Find and remove common elements.
	for (int i = 0; i < SizeB; i++)
	{

		// Referring to the first element in the set container
		A_elements = A.begin();


		for (int j = 0; j < SizeA; j++)
		{

			// In case the elements have the same value, erase it.
			if (*B_elements == *A_elements)
			{
				B_Minus_A_Set.erase(*B_elements);
				A_elements = B.begin();
			}
			else
				A_elements++;
		}
		B_elements++;
	}

	// Passing the result to the Display function.
	display_Set(outfile, B_Minus_A_Set);
}


//***********************************************************************
//				Function Name: A_Complement_Set () 				       	*
//				Parameters: ofstream& outfile, set<int> A, set<int> U	*
//																		*
//		Purpose:  To Find the elements that goes in the Complement of   *
//				  of set A by using the Universe set.				    *	
//                                                                      *
//		Receives: Will receives the set of element A & U the Universe	*
//				  set  and the outfile is passed by reference.			*
//		Returns:  Void.													*
//																		*
//***********************************************************************

void Complement_Of_A(ofstream& outfile, set<int> A, set<int> U)
{
	// Declare the set of A complement.
	set<int> A_Complement_Sets;


	// Declare and Initialize the sets size and elements.
	auto A_elements = A.begin(), Universe_Elements = U.begin();
	int SizeA = A.size();


	// Populate A Complement Set with the Universe elements.
	for (int i = 0; i < universe_Size; i++)
	{
		A_Complement_Sets.insert(*Universe_Elements);
		Universe_Elements++;
	}

	// Referring to the first element in the set container.
	Universe_Elements = A.begin();


	// Find and remove common elements.
	for (int i = 0; i < SizeA; i++)
	{

		// Referring to the first element in the set container.
		A_elements = U.begin();


		for (int j = 0; j < universe_Size; j++)
		{

			// In case the elements have the same value, erase it.
			if (*Universe_Elements == *A_elements)
			{
				A_Complement_Sets.erase(*Universe_Elements);
				A_elements = A.begin();
			}
			else
				A_elements++;
		}
		Universe_Elements++;
	}

	// Passing the result to the Display function.
	display_Set(outfile, A_Complement_Sets);
}


//***********************************************************************
//				Function Name: B_Complement_Set () 				       	*
//				Parameters: ofstream& outfile, set<int> B, set<int> U	*
//																		*
//		Purpose:  To Find the elements that goes in the Complement of   *
//				  of set B by using the Universe set.				    *	
//                                                                      *
//		Receives: Will receives the set of element B & U the Universe	*
//				  set  and the outfile is passed by reference.			*
//		Returns:  Void.													*
//																		*
//***********************************************************************


void Complement_Of_B(ofstream& outfile, set<int> B, set<int> U)
{
	// Declare the set of B complement.
	set<int> B_Complement_Sets;


	// Declare and Initialize the sets size and elements.
	auto B_elements = B.begin(), Universe_Elements = U.begin();
	int SizeB = B.size();


	// Populate the B Complement with the Universe elements.
	for (int i = 0; i < universe_Size; i++)
	{
		B_Complement_Sets.insert(*Universe_Elements);
		Universe_Elements++;
	}

	// Referring to the first element in the set container
	Universe_Elements = B.begin();


	// Find and remove common elements.
	for (int i = 0; i < SizeB; i++)
	{

		// Referring to the first element in the set container
		B_elements = U.begin();


		for (int j = 0; j < universe_Size; j++)
		{
			// In case the elements have the same value, erase it.
			if (*Universe_Elements == *B_elements)
			{
				B_Complement_Sets.erase(*Universe_Elements);
				B_elements = B.begin();
			}
			else
				B_elements++;
		}
		Universe_Elements++;
	}

	// Passing the result to the Display function.
	display_Set(outfile, B_Complement_Sets);
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
