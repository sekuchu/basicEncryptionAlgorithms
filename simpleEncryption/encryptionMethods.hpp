#ifndef encryptionMethods_hpp
#define encryptionMethods_hpp

#include <iostream>

using namespace std;

void offByOneEncryption(string input) {	// encryption based on shifting each letter by one place in the alphabet
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);	// lower each letter
		if (input[i] == 'z') {	// if you reach the last letter (z), go to 'a'
			input[i] -= 25;
		}
		input[i] += 1;	// the encryption math
	}
	cout << "Encrypted string: " << input << endl;	// output
}

void caesarCipher(string input) {	// encryption based on shifting each letter by three places in the alphabet
	int stepOver = 0;	// an integer to keep track of how much did we "step over" the letter z 
	for (int i = 0; i < input.length(); i++) {	// (the stepOver could have been hardcoded but I kept it modular not to limit it to 3 steps)
		input[i] = tolower(input[i]);	// lower each letter
		stepOver = 123 - input[i];	// math to check for stepOvers
		if (stepOver <= 3) input[i] = 122 - (25 + stepOver);	// stepOver logic check
		input[i] += 3;	// shift by 3 as per encryption algorithm
	}
	cout << "Encrypted string: " << input << endl;	// output
}

void vigenereCipher(string input) {		// encryption based on adding the alphabetical number of the corresponding letter 
	string secondInput = "";											// position from the second string onto the first
	int add = 0;
	int stepOver = 0;
	
	while (input.length() != secondInput.length()) {	// second word input system
		cout << "Please enter your second string (must be the same size): ";
		cin >> secondInput;

		cin.clear();	// in case of invalid entry use these two commands to reset the cin in 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // order to enable further re-input
	}

	for (int i = 0; i < input.length(); i++) {	
		input[i] = tolower(input[i]);
		secondInput[i] = tolower(secondInput[i]);	// we need to lower both words onto the same ascii number category

		add = secondInput[i] - 96;	// calculate how many letter do we shift the corresponding letter of the first word
		stepOver = 123 - input[i];	// math to check for stepOvers (if we go over the last letter)
		if (stepOver <= add) input[i] = 97 + (add - stepOver);	// stepOver logic check
		else input[i] += add;	// shift by the number of letters as per encryption algorithm if there is no overStep
	}

	cout << "Encrypted string: " << input << endl;	// output
}

void atbashCipher(string input) {
	string reverse = "zyxwvutsrqponmlkjihgfedcba";

	for (int i = 0; i < input.length(); i++) {	// go trough all of the letters
		input[i] = tolower(input[i]);

		input[i] = reverse[abs(97 - input[i])];	// find what place the letter is and go to that place in reverse
	}

	cout << "Encrypted string: " << input << endl;	// output
}

void rot13Cipher(string input) { // encryption based on shifting each letter by 13 letters, its identical to ceasar
	int stepOver = 0;	
	for (int i = 0; i < input.length(); i++) {	
		input[i] = tolower(input[i]);	
		stepOver = 123 - input[i];	
		if (stepOver <= 13) input[i] = 122 - (25 + stepOver);	
		input[i] += 13;	
	}
	cout << "Encrypted string: " << input << endl;	// output
}



#endif 
