#ifndef CONTACT_H_
#define CONTACT_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

//class ContactList;

using namespace std;

namespace do_i_know_you {
	class Contact {
	private:
		std::string number;
		std::string gender;
		std::string title;
		std::string given_name;
		std::string middle_initial;
		std::string surname;
		std::string street_address;
		std::string city;
		std::string state;
		std::string zip_code;
		std::string email_address;
		std::string birthday_mm;
		std::string birthday_dd;
		std::string birthday_yyyy;
		std::string age;
		std::string current_year = "2018";
		vector<Contact> list_of_contacts;

		static const int kZeroZeroZeroZeroZero = 00000;
		static const int kZero = 0;
		static const int kOne = 1;
		static const int kTwo = 2;
		static const int kThree = 3;
		static const int kFour = 4;
		static const int kFive = 5;
		static const int kSix = 6;
		static const int kTen = 10;
	public:
		Contact(
			std::string number = "0",
			std::string gender = "N/A",
			std::string title = "N/A",
			std::string given_name = "N/A",
			std::string middle_initial = "N/A",
			std::string surname = "N/A",
			std::string street_address = "N/A",
			std::string city = "N/A",
			std::string state = "N/A",
			std::string zip_code = "00000",
			std::string email_address = "N/A",
			std::string birthday_mm = "00",
			std::string birthday_dd = "00",
			std::string birthday_yyyy = "0000",
			std::string age = "0");
		~Contact();
		std::string get_number() const;
		std::string get_gender() const;
		std::string get_title() const;
		std::string get_given_name() const;
		std::string get_middle_initial() const;
		std::string get_surname() const;
		std::string get_street_address() const;
		std::string get_city() const;
		std::string get_state() const;
		std::string get_zip_code() const;
		std::string get_email_address() const;
		std::string get_birthday_mm() const;
		std::string get_birthday_dd() const;
		std::string get_birthday_yyyy() const;
		std::string get_age() const;

		void set_number(std::string number = "0");
		void set_gender(std::string gender = "N/A");
		void set_title(std::string title = "N/A");
		void set_given_name(std::string given_name = "N/A");
		void set_middle_initial(std::string middle_initial = "N/A");
		void set_surname(std::string surname = "N/A");
		void set_street_address(std::string street_address = "N/A");
		void set_city(std::string city = "N/A");
		void set_state(std::string state = "N/A");
		void set_zip_code(std::string zip_code = "00000");
		void set_email_address(std::string email_address = "N/A");
		void set_birthday_mm(std::string birthday_mm = "N/A");
		void set_birthday_dd(std::string birthday_dd = "N/A");
		void set_birthday_yyyy(std::string birthday_yyyy = "N/A");
		void set_age(std::string birthday_yyyy = "N/A");

		/*Contact& operator=(const Contact &rh);
		bool operator< (const Contact&);
		friend std::ostream& operator<< (std::ostream&, const Contact&);*/
	};
}

#endif 
