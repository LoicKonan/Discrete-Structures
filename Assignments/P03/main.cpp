//***********************************************************************
//		Loic Konan                                                      *
//		Dr. Stringfellow                                                *
//		CMPS-2433-101                                                   *
//		November 18, 2020												*
//		Program # 3.													*
//																		*
//																		*
//		Description:                                                    *
//		To recover the original message from a secret encrypted			*
//		message. While utilizing a shift encryption and frequency		*
//		count as a technique to perform decryption. And to use modulo	*
//		arithmetic in shift encryption / decryption and to apply		*
//		an inverse function.											*
//																		*
//**********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;


// Funtion Prototype to Asked the user the files names to be use.
void openFiles(ifstream& infile, ofstream& outfile);


// Compare the letters of cipheredText to the Letters array and 
// Increments the element then pass it to the function setshiftRate.
void FrequencyAnalysis(int, ofstream&, string);


// Function prototype to compute how much should be shifted by using 
// modulo arithmetic.
void ShiftRate(string, int[], string, ofstream&);


// Function prototype to do the Calculation and Decrypt the message.
void Decrypt(string, int, ofstream&);


// Funtion Prototype to print the Decrypted, and original message.
void Print(string, string, ofstream&);


int main()
{
	ifstream infile;
	ofstream outfile;

	int numb_Case;
	string Cipher_Text;

	openFiles(infile, outfile);

	// Prints Heading.
	cout << "\nLoic Konan\n"
		<< "Program # 3: Frequency Count Decryption\n\n";
	
	outfile << "Loic Konan\n"
			<< "Program # 3: Frequency Count Decryption\n\n";


	// Read number of Test Cases from the input file.
	while (infile >> numb_Case)
	{
		cout << "Number of Case(s) = " << numb_Case << "\n\n\n";
		outfile << "Number of Case(s) = " << numb_Case << "\n\n\n";
		
		// Use the loop to read in the CipherText message and invoke
		// the frequency analysis function. 
		for (int i = 0; i < numb_Case; i++)
		{
			// Display this on screen.
			cout << "\n";
			cout << "=========================================================\n";
			cout << "Cipher Text: " << i + 1;
			cout << "\n";

			// Display this to the file.
			outfile << "\n";
			outfile << "======================================================\n";
			outfile << "Cipher Text: " << i + 1;
			outfile << "\n";

			getline(infile, Cipher_Text, '#');
			FrequencyAnalysis(numb_Case, outfile, Cipher_Text);
		}
	}
	cout << "=========================================================\n";
	outfile << "======================================================\n";

	// Closing outfile and infile.
	infile.close();
	outfile.close();

	return 0;
}



//***********************************************************************
//	Function Name:  FrequencyAnalysis () 								*
//	  Parameters: 	int Size, ofstream& out, string CT					*
//																		*
//		 Purpose:  	Compare each letters of our alphabet to each letter *
//					of the Cipher message and indicate the number of	*
//					time they appear. 									*
//																		*
//		 Returns:  Void.												*
//																		*
//***********************************************************************
void FrequencyAnalysis(int Size, ofstream& outfile, string CT)
{
	int count = 0;
	string Temp = CT;
	int Occurences[27];
	string Letters = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Initialize array elements to 0.
	for (int i = 0; i < 27; i++)
	{
		Occurences[i] = 0;
	}

	// As long as i is less than our Cipher message.
	for (unsigned int i = 0; i < Temp.length(); i++)
	{
		// And as long as j is less than our alphabet size.
		for (unsigned int j = 0; j < Letters.size(); j++)
		{
			// Compare each letters to each letter of the Cipher message
			// and indicate the number of time they appear. 
			if (Temp[i] == Letters[j])
			{
				count = (Occurences[j] + 1);
				Occurences[j] = count;
			}
		}
	}

	// Pass the CipherText, the array alphabet, string to the function.
	ShiftRate(CT, Occurences, Letters, outfile);
}



//***********************************************************************
//Function Name: ShiftRate ()											*
//	 Parameters: string CT, int array[], string L, ofstream& outfile	*
//																		*
//	   Purpose: Determine the index of the highest occurring letter,	*
//				and	the shift rate, also do the calculation to find		*
//				the Key.												*
//																		*
//	   Returns: Void.												    *
//																		*
//***********************************************************************
void ShiftRate(string CT, int array[], string Letter, ofstream& outfile)
{
	int Index, Highest,
		Key,shiftrate = 0;
	
	char ShiftTarget = 'E';
	Index = array[1];

	// Determine location of max frequency.
	for (int i = 2; i < 27; i++)
	{
		if (array[i] > Index)
		{
			Highest = i;
			Index = array[i];
		}
	}

	// Find the shift rate.
	for (unsigned int i = 0; i < Letter.size(); i++)
	{
		if (Letter[i] == ShiftTarget)
		{
			shiftrate = i;
		}
	}

	// Compute and find the key.
	if (Highest > shiftrate)
	{
		Key = Highest - shiftrate;
	}
	
	else
	{
		Key = (26 - (shiftrate - Highest));
	}

	// Pass the Decrypted and the original message to the function print.
	Decrypt(CT, Key, outfile);
}



//***********************************************************************
//	Function Name:  Decrypt () 											*
//	   Parameters: string CT, int Key, ofstream& out					*
//																		*
//		Purpose: Handle the non-Alpha characters, do the Calculation	*
//				 needed to Decrypted message. Then pass the Decrypted	*
//				 and the original message to the print function.		*
//																		*
//		Returns:  Void.													*
//																		*
//***********************************************************************
void Decrypt(string CT, int Key, ofstream& outfile)
{
	string TempDecrypt;

	// If the index is less than the size of the CipherText then proceed
	// to the Decryption of the message. 
	for (unsigned int i = 0; i < CT.length(); i++)
	{
		// Handles the non-Alpha characters.
		if (int(CT[i]) < 65 || int(CT[i]) > 91)
		{
			TempDecrypt += CT[i];
		}

		else
		{
			// Using modulo	arithmetic to Decrypted message.
			TempDecrypt += ((((CT[i] - Key) + 65) % 26) + 65);
		}
	}

	// Move the result to the variable below.
	string Decrypted = TempDecrypt;

	// Pass the Decrypted and the original message to the function print
	Print(Decrypted, CT, outfile);
}



//***********************************************************************
//		Function Name:  Print () 										*
//		Parameters: string PlainText, string CT, ofstream& outfile		*
//																		*
//		Purpose:  Ask the user if the Descripted text is correct or not	*
//				  and print the attempted Decrypted message and the		*
//				  original message.										*
//																		*
//		Returns:  Void.													*
//																		*
//***********************************************************************
void Print(string PlainText, string CT, ofstream& outfile)
{
	char Answer;

	// Print the Ciphertext.
	cout << CT;
	cout << "\n\n\n";
	cout << "Decrypted text";
	cout << "\n";

	// Print results to console.
	cout << PlainText;
	cout << "\n\n";

	// Prompt the user if the decryption works.
	cout << "Did the message decrypt successfully (y/n)?: ";
	cin >> Answer;
	cout << "\n";

	// input Validation.
	while ((Answer != 'Y') && (Answer != 'y') && (Answer != 'N') && (Answer != 'n'))
	{
		cout << "\nPlease Enter a valid input (y/n)?: ";
		cin >> Answer;
		cout << "\n";
	}
		// Prompt the user if the decryption works and display to the file.
		if (Answer == 'Y' || Answer == 'y')
		{
			// Print the Ciphertext.
			outfile << CT;
			outfile << "\n\n\n";
			outfile << "Decrypted text ";
			outfile << "\n";

			// Display the Decrypted message to the outfile.
			outfile << PlainText;
			outfile << "\n\n";
			outfile << "Decryption successfully.";
			outfile << "\n";
		}

		// Prompt the user if the decryption works and display to the file.
		else if (Answer == 'N' || Answer == 'n')
		{
			// Print the Ciphertext.
			outfile << CT;
			outfile << "\n\n\n";
			outfile << "Decrypted text";
			outfile << "\n";

			// Display the Decrypted message to the outfile.
			outfile << PlainText;
			outfile << "\n\n";
			outfile << "Decryption Not successfully.";
			outfile << "\n";
		}
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
	cin  >> inFileName;

	// open input file
	infile.open(inFileName);
	cout << "Enter the output file name: ";
	cin  >> outFileName;

	// Open output file.
	outfile.open(outFileName);
}