/*
This program converts a file's contents into their ASCII values.
Then, it applies an encryption algorithm to the file.
Finally, it outputs the encoded text to a new file.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



string readFileContents(ifstream &);
string encodeText(string);
void writeFileContents(ofstream &, string);



int main() {
	const string inputFileName = "plain.txt";
	const string outputFileName = "coded.txt";
	ifstream plaintextFile;
	ofstream ciphertextFile;
	
	/*do {
		cout << "Please enter the name of the file to encrypt: ";
		getline(cin, inputFileName);
		plaintextFile.open(inputFileName);
	} while (!plaintextFile);

	do {
		cout << "Please enter the name of the file for the ciphertext: ";
		getline(cin, outputFileName);
		ciphertextFile.open(outputFileName);
	} while (!ciphertextFile);*/

	plaintextFile.open(inputFileName);
	ciphertextFile.open(outputFileName);

	string fileContents = readFileContents(plaintextFile);

	string encodedFileContents = encodeText(fileContents);

	writeFileContents(ciphertextFile, encodedFileContents);

	plaintextFile.close();
	ciphertextFile.close();
	return 0;
}



string readFileContents(ifstream &fileToRead) {
	string lineOfFile = "";
	string totalFile = "";

	getline(fileToRead, lineOfFile);
	while (fileToRead) {
		totalFile += (lineOfFile + "\n");
		getline(fileToRead, lineOfFile);
	}
	
	return totalFile;
}

string encodeText(string textToEncode) {
	string encodedText = "";
	int lineNumber = 1;
	int encryptionFactor = 1;

	for (int counter = 0; counter < textToEncode.length(); counter += 1) {
		if (textToEncode[counter] != '\n') {
			encodedText += static_cast<char>(static_cast<int>(textToEncode[counter]) + encryptionFactor);
		}
		if (textToEncode[counter] == '\n') {
			lineNumber += 1;
			encryptionFactor = ((lineNumber - 1) % 5) + 1;
			encodedText += "\n";
		}
	}

	return encodedText;
}

void writeFileContents(ofstream &fileToOverwrite, string textToWrite) {
	fileToOverwrite << textToWrite;
}