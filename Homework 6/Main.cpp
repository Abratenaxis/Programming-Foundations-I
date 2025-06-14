// Julio A. Bonilla
// HW6
// Do I Know You?
// Allen Baker (Shane Carroll May)
// Prog 1203
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "Contact.h"

using namespace std;

vector<do_i_know_you::Contact> list_of_contacts(ifstream& infile);
//Lets user load, search, and delete from a list of contacts
int main() {
	vector<do_i_know_you::Contact> main_contacts;

	while (true)
	{
		string menu_option;
		cout << "_____________DO_I_KNOW_YOU?____________" << endl;
		cout << "_____All_names_must_be_capitalized_____" << endl;
		cout << "Enter 1 to load contacts" << endl;
		cout << "Enter 2 to search by given name" << endl;
		cout << "Enter 3 to search by surname" << endl;
		cout << "Enter 4 to search by city" << endl;
		cout << "Enter 5 to search by birth month" << endl;
		cout << "Enter 6 to search by birth year" << endl;
		cout << "Enter 7 to search by age" << endl;
		cout << "Enter 8 to delete by given name" << endl;
		cout << "Enter 9 to delete by surname" << endl;
		cout << "Enter 10 to delete by city" << endl;
		cout << "Enter 11 to delete by birth month" << endl;
		cout << "Enter 12 to delete by birth year" << endl;
		cout << "Enter 13 to delete by age" << endl;
		cout << "Enter 14 to delete all contacts" << endl;
		cout << "enter exit to exit" << endl;
		cout << "________________________________________" << endl;
		getline(cin, menu_option);
		// validation
		while (cin.fail() || menu_option == "") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Try another option. Type exit when you want to exit: ";

			getline(cin, menu_option);
		}
		// how to exit the loop
		if (menu_option == "exit" || menu_option == "Exit") {
			break;
		}
		// load from csv file
		else if (menu_option == "1"){
			ifstream input("FakeNames.csv");
			main_contacts = list_of_contacts(input);
		}
		// search by criteria
		else if (menu_option == "2") {
			cout << "Enter the given name to search for: ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_given_name())
				{
					cout << "Number is: " << i.get_number() 
						 << "\nSurname is:  " << i.get_surname() 
						 << "\nGiven name is: " << i.get_given_name() << "<---"
						 << "\nCity is: " << i.get_city() 
						 << "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
						 << "\nAge is: " << i.get_age() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this given name exist." << endl;
			}
		}
		
		else if (menu_option == "3") {
			cout << "Enter the surname to search for: ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_surname())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname() << "<---"
						<< "\nGiven name is: " << i.get_given_name() 
						<< "\nCity is: " << i.get_city()
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
						<< "\nAge is: " << i.get_age() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this surname exist." << endl;
			}
		}

		else if (menu_option == "4") {
			cout << "Enter the city to search for: ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_city())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname() 
						<< "\nGiven name is: " << i.get_given_name()
						<< "\nCity is: " << i.get_city() << "<---"
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
						<< "\nAge is: " << i.get_age() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts whom live in this city exist." << endl;
			}
		}

		else if (menu_option == "5") {
			cout << "Enter the month to search for (1-12): ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_birthday_mm())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname()
						<< "\nGiven name is: " << i.get_given_name()
						<< "\nCity is: " << i.get_city() 
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy() << "<---"
						<< "\nAge is: " << i.get_age() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this birth month exist." << endl;
			}
		}

		else if (menu_option == "6") {
			cout << "Enter the year to search for: ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_birthday_yyyy())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname()
						<< "\nGiven name is: " << i.get_given_name()
						<< "\nCity is: " << i.get_city()
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy() << "<---"
						<< "\nAge is: " << i.get_age() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this birth year exist." << endl;
			}
		}

		else if (menu_option == "7") {
			cout << "Enter an age to search for: ";
			getline(cin, menu_option);
			int counter = 0;
			for (auto i : main_contacts)
			{
				if (menu_option == i.get_age())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname()
						<< "\nGiven name is: " << i.get_given_name()
						<< "\nCity is: " << i.get_city()
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy() 
						<< "\nAge is: " << i.get_age() << "<---" << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this age exist." << endl;
			}
		}
		// delete by criteria

		else if (menu_option == "8") {
			cout << "Enter the given name to search for deletion: ";
			getline(cin, menu_option);
			int counter = 0;
			int pos = 0;
			vector<int> numbers;
			for (auto i : main_contacts) {
			pos++;
			if (menu_option == i.get_given_name()){
				cout << "Number is: " << i.get_number()
					<< "\nSurname is:  " << i.get_surname() 
					<< "\nGiven name is: " << i.get_given_name() << "<---"
					<< "\nCity is: " << i.get_city()
					<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
					<< "\nAge is: " << i.get_age() << endl;
				counter++;
				numbers.push_back(pos - 1);
				}
			}
			if (counter == 0) {
				cout << "No contacts with this given name exist." << endl;
			}
			else {
				cout << "Do you want to confirm this deletion? ";
				getline(cin, menu_option);
				if (menu_option == "Yes" || menu_option == "yes"){
				for (unsigned int i = numbers.size(); i > 0; i--){
					main_contacts.erase(main_contacts.begin() + numbers[i - 1]);
				}
					cout << "Deletion: [COMPLETE]" << endl;
				}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}
		}
		}

		else if (menu_option == "9") {
			cout << "Enter the surname to search for deletion: ";
			getline(cin, menu_option);
			int counter = 0;
			int pos = 0;
			vector<int> numbers;
			for (auto i : main_contacts)
			{
				pos++;
				if (menu_option == i.get_surname())
				{
					cout << "Number is: " << i.get_number()
						<< "\nSurname is:  " << i.get_surname() << "<---"
						<< "\nGiven name is: " << i.get_given_name()
						<< "\nCity is: " << i.get_city()
						<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
						<< "\nAge is: " << i.get_age() << endl;
					counter++;
					numbers.push_back(pos - 1);
				}
			}
			if (counter == 0)
			{
				cout << "No contacts with this last name exist." << endl;
			}
			else {
				cout << "Do you want to confirm this deletion? ";
				getline(cin, menu_option);
				if (menu_option == "Yes" || menu_option == "yes")
				{
					for (unsigned int i = numbers.size(); i > 0; i--)
					{
						main_contacts.erase(main_contacts.begin() + numbers[i - 1]);
						
					}
					cout << "Deletion: [COMPLETE]" << endl;
				}
				else
				{
					cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
				}
			}
		}

		else if (menu_option == "10") {
		cout << "Enter the city to search for deletion: ";
		getline(cin, menu_option);
		int counter = 0;
		int pos = 0;
		vector<int> numbers;
		for (auto i : main_contacts)
		{
			pos++;
			if (menu_option == i.get_city())
			{
				cout << "Number is: " << i.get_number()
					<< "\nSurname is:  " << i.get_surname() << "<---"
					<< "\nGiven name is: " << i.get_given_name()
					<< "\nCity is: " << i.get_city()
					<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
					<< "\nAge is: " << i.get_age() << endl;
				counter++;
				numbers.push_back(pos - 1);
			}
		}
		if (counter == 0)
		{
			cout << "No contacts with this city exist." << endl;
		}
		else {
			cout << "Do you want to confirm this deletion? ";
			getline(cin, menu_option);
			if (menu_option == "Yes" || menu_option == "yes")
			{
				for (unsigned int i = numbers.size(); i > 0; i--)
				{
					main_contacts.erase(main_contacts.begin() + numbers[i - 1]);

				}
				cout << "Deletion: [COMPLETE]" << endl;
			}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}
		}
		}

		else if (menu_option == "11") {
		cout << "Enter the birth month to search for deletion: ";
		getline(cin, menu_option);
		int counter = 0;
		int pos = 0;
		vector<int> numbers;
		for (auto i : main_contacts)
		{
			pos++;
			if (menu_option == i.get_birthday_mm())
			{
				cout << "Number is: " << i.get_number()
					<< "\nSurname is:  " << i.get_surname()
					<< "\nGiven name is: " << i.get_given_name()
					<< "\nCity is: " << i.get_city()
					<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
					<< "\nAge is: " << i.get_age() << endl;
				counter++;
				numbers.push_back(pos - 1);
			}
		}
		if (counter == 0)
		{
			cout << "No contacts with this month exist." << endl;
		}
		else {
			cout << "Do you want to confirm this deletion? ";
			getline(cin, menu_option);
			if (menu_option == "Yes" || menu_option == "yes")
			{
				for (unsigned int i = numbers.size(); i > 0; i--)
				{
					main_contacts.erase(main_contacts.begin() + numbers[i - 1]);

				}
				cout << "Deletion: [COMPLETE]" << endl;
			}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}
		}
		}

		else if (menu_option == "12") {
		cout << "Enter the year to search for deletion: ";
		getline(cin, menu_option);
		int counter = 0;
		int pos = 0;
		vector<int> numbers;
		for (auto i : main_contacts)
		{
			pos++;
			if (menu_option == i.get_birthday_yyyy())
			{
				cout << "Number is: " << i.get_number()
					<< "\nSurname is:  " << i.get_surname()
					<< "\nGiven name is: " << i.get_given_name()
					<< "\nCity is: " << i.get_city()
					<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
					<< "\nAge is: " << i.get_age() << endl;
				counter++;
				numbers.push_back(pos - 1);
			}
		}
		if (counter == 0)
		{
			cout << "No contacts with this year exist." << endl;
		}
		else {
			cout << "Do you want to confirm this deletion? ";
			getline(cin, menu_option);
			if (menu_option == "Yes" || menu_option == "yes")
			{
				for (unsigned int i = numbers.size(); i > 0; i--)
				{
					main_contacts.erase(main_contacts.begin() + numbers[i - 1]);

				}
				cout << "Deletion: [COMPLETE]" << endl;
			}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}
		}
		}

		else if (menu_option == "13") {
		cout << "Enter the surname to search for deletion: ";
		getline(cin, menu_option);
		int counter = 0;
		int pos = 0;
		vector<int> numbers;
		for (auto i : main_contacts)
		{
			pos++;
			if (menu_option == i.get_age())
			{
				cout << "Number is: " << i.get_number()
					<< "\nSurname is:  " << i.get_surname() << "<---"
					<< "\nGiven name is: " << i.get_given_name()
					<< "\nCity is: " << i.get_city()
					<< "\nDate of birth is: " << i.get_birthday_mm() << "/" << i.get_birthday_dd() << "/" << i.get_birthday_yyyy()
					<< "\nAge is: " << i.get_age() << endl;
				counter++;
				numbers.push_back(pos - 1);
			}
		}
		if (counter == 0)
		{
			cout << "No contacts with this age exist." << endl;
		}
		else {
			cout << "Do you want to confirm this deletion? ";
			getline(cin, menu_option);
			if (menu_option == "Yes" || menu_option == "yes")
			{
				for (unsigned int i = numbers.size(); i > 0; i--)
				{
					main_contacts.erase(main_contacts.begin() + numbers[i - 1]);

				}
				cout << "Deletion: [COMPLETE]" << endl;
			}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}
		}
		}

		else if (menu_option == "14") {
			cout << "Do you want to delete all contacts? ";
			getline(cin, menu_option);
			if (menu_option == "Yes" || menu_option == "yes")
			{
				main_contacts.clear();
				cout << "Mass Deletion: [COMPLETE]" << endl;
			}
			else
			{
				cout << "Deletion cancelled. The contact(s) were not deleted." << endl;
			}		
		}
		else {
		cout << "pick an option!" << endl;
		}
	}
	
	
	system("pause");
	return 0;
}
vector<do_i_know_you::Contact> list_of_contacts(ifstream& infile) {
	std::string number, gender, title, given_name, middle_initial, surname, street_address, city, state, zip_code, email_address, birthday_mm, birthday_dd, birthday_yyyy;
	std::string headers;
	std::vector<do_i_know_you::Contact> contacts_list;
	std::ifstream fake_names("FakeNames.csv");
	//fake_names.open("FakeNames.csv");
	//getline(fake_names, headers);

	while (getline(fake_names, headers)) {
		stringstream stream(headers);
		getline(stream, number, ',');
		getline(stream, gender, ',');
		getline(stream, title, ',');
		getline(stream, given_name, ',');
		getline(stream, middle_initial, ',');
		getline(stream, surname, ',');
		getline(stream, street_address, ',');
		getline(stream, city, ',');
		getline(stream, state, ',');
		getline(stream, zip_code, ',');
		getline(stream, email_address, ',');
		getline(stream, birthday_mm, '/');
		getline(stream, birthday_dd, '/');
		getline(stream, birthday_yyyy, ',');
		do_i_know_you::Contact dude(number, gender, title, given_name, middle_initial, surname, street_address, city, state, zip_code, email_address, birthday_mm, birthday_dd, birthday_yyyy);
		contacts_list.push_back(dude);
	}
	fake_names.close();
	sort(contacts_list.begin(), contacts_list.end(), [](const do_i_know_you::Contact &a, const do_i_know_you::Contact &b)
	{ if (a.get_surname() == b.get_surname()) {
		return a.get_given_name() < b.get_given_name();
	}
	else {
		return a.get_surname() < b.get_surname();
	}
	});
	return contacts_list;
}