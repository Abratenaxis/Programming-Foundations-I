//HW8.cpp
//Author:
//Due Date: 
//Topic: HW8 Pick a Word, Any Word


#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include "Concordance.h"
#include "Unique_Word.h"


using namespace std;
map<string, list<int>> readWordData(string& infile);
int main()
{
	//Map for cities
	map<string, list<int>> words;
	every_word::Concordance Tome_Master;
	string in1("MobyDick_W.txt");
	string in2("ModestProposal_W.txt");
	string in3("Apology_W.txt");
	string in4("WizardOfOz_W.txt");
	string in5("ShortHistory_W.txt");
	//string in6("test.txt");
	//string out6("test_concordance.txt");
	string out1("MobyDick_concordance.txt");
	string out2("ModestProposal_concordance.txt");
	string out3("Apology_concordance.txt");
	string out4("WizardOfOz_concordance.txt");
	string out5("ShortHistory_concordance.txt");
	auto isNotDone = true;
	while (isNotDone) {
		string userInput;
		cout << "-----------------------------------" << endl;
		cout << "Enter 1 to open Moby Dick" << endl;
		cout << "Enter 2 to open Modest Proposal" << endl;
		cout << "Enter 3 to open Apology" << endl;
		cout << "Enter 4 to open Wizard of Oz" << endl;
		cout << "Enter 5 to open Short History" << endl;
		cout << "Enter quit to exit program" << endl;
		cout << "-----------------------------------" << endl;
		getline(cin, userInput);
		// Input validation for string
		while (cin.fail() || userInput == "") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Try again. Type quit when you want to quit: ";

			getline(cin, userInput);

		}
		//If user inputs quit then it breaks out of the while loop.
		if (userInput == "quit" || userInput == "Quit") {
			isNotDone = false;
		}
		else if (userInput == "1") {
			words = readWordData(in1);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out1);
		}
		else if (userInput == "2") {
			words = readWordData(in2);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out2);
		}
		else if (userInput == "3") {
			words = readWordData(in3);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out3);
		}
		else if (userInput == "4") {
			words = readWordData(in4);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out4);
		}
		else if (userInput == "5") {
			words = readWordData(in5);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out5);
		}
		/*else if (userInput == "6") {
			words = readWordData(in6);
			for (auto p : words) {
				Tome_Master.add_word_to_list(every_word::Unique_Word(p.first, p.second));
			}
			Tome_Master.writeToFile(out6);
		}*/ // else doNothing(); //repeats loop
	}
	system("pause");
	return 0;

}

// Function to read in a file
map<string, list<int>> readWordData(string& infile)
{
	map<string, list<int>> words{};
	every_word::Unique_Word p;
	string line;
	string word_name;
	int line_number = 0;
	list<int> line_numbers;
	ifstream in(infile);
	if (!in.is_open()) {
		cout << "File failed to open" << endl;
	}

	while (getline(in, line)) {
		line_number++;
		stringstream ss(line);
		while (getline(ss, word_name, ' ')) {


			const string Punctuation = "-,.;:?\"'!@#$%^&*[]{}|_";
			while (word_name.length() > 0 && Punctuation.find(word_name[0]) != string::npos) {
				word_name = word_name.substr(1);

			}
			while (word_name.length() > 0 && Punctuation.find(word_name[word_name.length() - 1]) != string::npos) {
				word_name = word_name.substr(0, word_name.length() - 1);

			}
			for (size_t i = 0; i < word_name.length(); i++)
			{
				word_name[i] = tolower(word_name[i]);

			}
			p.set_word_name(word_name);
			auto iterator = words.find(word_name);
			if (iterator == words.end()) {
				p.add_to_line_numbers(line_number);
				words[word_name] = p.get_line_numbers();
			}
			else {
				p.add_to_line_numbers(line_number);
				words[word_name] = p.get_line_numbers();
			}
			words.insert_or_assign(word_name, p.get_line_numbers());
		}





	}
	in.close();
	return words;
}