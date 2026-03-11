#include<iostream>
#include "encryptionMethods.hpp"	// header that contains all the encryptors

using namespace std;
void message();
int executeChoice(int);

int main() {
	int choice = -1; // dictates the choice of input
	message(); // hardcoded message function
	while (choice < 1 || choice > 9) {	// force a valid choice of input
		cout << "Enter your choice: ";

		cin >> choice;

		if (choice > 0 && choice < 10) break;	// once a valid choice is made, exit the loop
		
		cout << "Invalid choice. Please try again." << endl;
		cout << endl;

		cin.clear();	// in case of invalid entry use these two commands to reset the cin in 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // order to enable further re-input
	}
	executeChoice(choice);	// function for execution of implemented encryption algorithms

	return 0;
}

void message() {	// hardcoded message function
	cout << "Select your way of encryption: " << endl;
	cout << "1. Off by one encryption" << endl;
	cout << "2. Caesar cipher" << endl;
	cout << "3. Vigenere cipher" << endl;
	cout << "4. Atbash cipher" << endl;
	cout << "5. ROT13 cipher" << endl;
	cout << "6. Morse code" << endl;
	cout << "7. Binary code" << endl;
	cout << "8. Qwerty Encryption" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
}

int executeChoice(int choice) {	// encypher executer function && exit
	string input;

	if(choice != 9){
		cout << "Enter a string to encrypt: ";
		cin >> input;
	}

	switch (choice)
	{
	default:
		break;
	case 1:
		offByOneEncryption(input);
		break;
	case 2:
		caesarCipher(input);
		break;
	case 3:
		vigenereCipher(input);
		break;
	case 4:
		atbashCipher(input);
		break;
	case 5:
		rot13Cipher(input);
		break;
	case 6:
		morseCode(input);
		break;
	case 7:
		binaryCode(input);
		break;
	case 8:
		qwertyEncryption(input);
		break;
	case 9:
		cout << "Exiting the program. Goodbye!" << endl;
		return 0;
	}
}
