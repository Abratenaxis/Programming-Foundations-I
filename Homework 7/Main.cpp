//Main.cpp
//Author: Julio A Bonilla
//Due Date: November 27, 2018
//Topic: HW7 Are we there yet?

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Cities.h"


using namespace std;
vector<cityscape::Cities> readCityData(ifstream& infile);
int main()
{
	//Vector for cities
	vector<cityscape::Cities> cities;
	//Load list of cities
	ifstream in("worldcities.csv");
	//Copy list to vector
	cities = readCityData(in);
	//Constants
	const int kFistCity = 0;
	const int kLastCity = (cities.size() - 1);
	const int kSix = 6;
	//input dependant infinite loop
	while (true) {
		string userInput;
		//User Menu
		cout << "-----------------------------------" << endl;
		cout << "1: Show lists of cities" << endl;
		cout << "2: Type in [Name] of city to find the 5 NEAREST cities" << endl;
		cout << "3: Type in [Number] of city to find the 5 NEAREST cities" << endl;
		cout << "4: Type in [Name] of city to find the 5 FARTHEST cities" << endl;
		cout << "5: Type in [Number] of city to find the 5 FARTHEST cities" << endl;
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
			break;
		}
		//Loads list of all cities and city attributes
		else if (userInput == "1") {
			cities = readCityData(in);
			for (auto i : cities) {
				cout << i.get_number()
					<< " "
					<< i.get_city_name()
					<< ","
					<< i.get_country_name()
					<< " "
					<< i.get_latitude()
					<< " "
					<< i.get_longitude()
					<< endl;
			}
		}
		//Finds five closest cities by Name
		else if (userInput == "2") {
			cout << "Enter the name of the city you want: ";
			getline(cin, userInput);
			//Capitalizes input
			for (size_t i = 0; i < userInput.length(); i++)
			{
				userInput[i] = tolower(userInput[i]);

			}
			userInput[0] = toupper(userInput[0]);
			int counter = 0;
			//Search vector for matching city
			for (size_t i = 0; i < cities.size(); i++) {

				if (userInput == cities[i].get_city_name()) {
					counter++;
					cityscape::Cities home(cities[i].get_number(), cities[i].get_city_name(), cities[i].get_country_name(), cities[i].get_distance(), cities[i].get_latitude(), cities[i].get_longitude());
					for (size_t j = 0; j < cities.size(); j++) {
						cities[j].set_distance(cities[j].distanceEarth(home.get_latitude(), home.get_longitude(), cities[j].get_latitude(), cities[j].get_longitude()));
					}
				}


			}
			if (counter == 0) {
				cout << "No cities with this name were found. " << endl;
			}
			else {
				sort(cities.begin(), cities.end(), cityscape::Cities::sort_by_closest_distance);
				cout << "'Home' city: " << userInput << endl;
				cout << "The Five closest cites are: " << endl;
				for (unsigned int i = 1; i < kSix; i++) {
					cout << i << ". " << cities[i].get_city_name() << ", " << cities[i].get_country_name() << " is " << cities[i].get_distance() << " kilometers away" << endl;

				}
			}

		}
		//Finds five closest cities by Number
		else if (userInput == "3") {
			cout << "Enter the number of the city you want: ";
			getline(cin, userInput);
			int counter = 0;
			//Search vector for matching city
			for (size_t i = 0; i < cities.size(); i++) {
				
				if (userInput == to_string(cities[i].get_number())) {
					counter++;
					cityscape::Cities home(cities[i].get_number(), cities[i].get_city_name(), cities[i].get_country_name(), cities[i].get_distance(), cities[i].get_latitude(), cities[i].get_longitude());
					for (size_t j = 0; j < cities.size(); j++) {
						cities[j].set_distance(cities[j].distanceEarth(home.get_latitude(), home.get_longitude(), cities[j].get_latitude(), cities[j].get_longitude()));
					}
				}


			}
			if (counter == 0) {
				cout << "No cities with this number were found. " << endl;
			}
			else {
				sort(cities.begin(), cities.end(), cityscape::Cities::sort_by_closest_distance);
				cout << "'Home' city: " << cities[kFistCity].get_city_name() << endl;
				cout << "The Five closest cites are: " << endl;
				for (unsigned int i = 1; i < kSix; i++) {
					cout << i << ". " << cities[i].get_city_name() << ", " << cities[i].get_country_name() << " is " << cities[i].get_distance() << " kilometers away" << endl;

				}
			}

		}
		//Finds five farthest cities by Name
		else if (userInput == "4") {
			cout << "Enter the name of the city you want: ";
			getline(cin, userInput);
			//Capitalizes input
			for (size_t i = 0; i < userInput.length(); i++)
			{
				userInput[i] = tolower(userInput[i]);

			}
			userInput[0] = toupper(userInput[0]);
			int counter = 0;
			//Search vector for matching city
			for (size_t i = 0; i < cities.size(); i++) {

				if (userInput == cities[i].get_city_name()) {
					counter++;
					cityscape::Cities home(cities[i].get_number(), cities[i].get_city_name(), cities[i].get_country_name(), cities[i].get_distance(), cities[i].get_latitude(), cities[i].get_longitude());
					for (size_t j = 0; j < cities.size(); j++) {
						cities[j].set_distance(cities[j].distanceEarth(home.get_latitude(), home.get_longitude(), cities[j].get_latitude(), cities[j].get_longitude()));
					}
				}


			}
			if (counter == 0) {
				cout << "No cities with this name were found. " << endl;
			}
			else {
				sort(cities.begin(), cities.end(), cityscape::Cities::sort_by_farthest_distance);
				cout << "'Home' city: " << userInput << endl;
				cout << "The Five farthest cites are: " << endl;
				for (unsigned int i = 1; i < kSix; i++) {
					cout << i << ". " << cities[i].get_city_name() << ", " << cities[i].get_country_name() << " is " << cities[i].get_distance() << " kilometers away" << endl;

				}
			}

		}
		//Finds five farthest cities by Number
		else if (userInput == "5") {
			cout << "Enter the number of the city you want: ";
			getline(cin, userInput);
			int counter = 0;
			//Search vector for matching city
			for (size_t i = 0; i < cities.size(); i++) {

				if (userInput == to_string(cities[i].get_number())) {
					counter++;
					cityscape::Cities home(cities[i].get_number(), cities[i].get_city_name(), cities[i].get_country_name(), cities[i].get_distance(), cities[i].get_latitude(), cities[i].get_longitude());
					for (size_t j = 0; j < cities.size(); j++) {
						cities[j].set_distance(cities[j].distanceEarth(home.get_latitude(), home.get_longitude(), cities[j].get_latitude(), cities[j].get_longitude()));
					}
				}


			}
			if (counter == 0) {
				cout << "No cities with this name were found. " << endl;
			}
			else {
				sort(cities.begin(), cities.end(), cityscape::Cities::sort_by_farthest_distance);
				cout << "'Home' city: " << cities[kLastCity].get_city_name() << endl;
				cout << "The Five farthest cites are: " << endl;
				for (unsigned int i = 1; i < kSix; i++) {
					cout << i << ". " << cities[i].get_city_name() << ", " << cities[i].get_country_name() << " is " << cities[i].get_distance() << " kilometers away" << endl;

				}
			}

		}
		//Inform user to select available option
		else {
		cout << "Choose an option, bud." << endl;
		}


	}

	system("pause");
	return 0;
}

//Load ifstream into vector
vector<cityscape::Cities> readCityData(ifstream& infile)
{
	vector<cityscape::Cities> cities;
	string city_name, country_name;
	string line;
	double latitude, longitude;
	int number;
	double distance = 0;
	string myStringOne, myStringTwo;
	ifstream in;
	in.open("worldcities.csv");
	if (!in.is_open()) {
		cout << "File failed to open" << endl;
	} 
	int count = 1;
	while (getline(in, line))
	{
		//Grab each item
		stringstream ss(line);
		getline(ss, city_name, ',');
		getline(ss, country_name, ',');
		getline(ss, myStringOne, ',');
		latitude = stod(myStringOne);
		getline(ss, myStringTwo, ',');
		longitude = stod(myStringTwo);
		number = count;
		//Create Object to push into Object Vector
		cityscape::Cities p(number, city_name, country_name, distance, latitude, longitude);
		cities.push_back(p);
		count++;

	}
	in.close();

	return cities;
}