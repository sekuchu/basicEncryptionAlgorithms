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

void vigenereCipher(string input) {
	string secondInput = "";
	int stepOver = 0;
	
	while (input.length() != secondInput.length()) {
		cout << "Please enter your second string (must be the same size): ";
		cin >> secondInput;

		cin.clear();	// in case of invalid entry use these two commands to reset the cin in 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // order to enable further re-input
	}

	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
		stepOver = 123 - input[i];
		if (stepOver <= 3) input[i] = 122 - (25 + stepOver);
		input[i] += 3;
	}
}
#endif 
