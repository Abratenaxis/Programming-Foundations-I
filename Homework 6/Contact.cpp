#include "Contact.h"
//#include "ContactList.h"


namespace do_i_know_you {
	Contact::Contact(
		std::string number,
		std::string gender,
		std::string title,
		std::string given_name,
		std::string middle_initial,
		std::string surname,
		std::string street_address,
		std::string city,
		std::string state,
		std::string zip_code,
		std::string email_address,
		std::string birthday_mm,
		std::string birthday_dd,
		std::string birthday_yyyy,
		std::string age) {
		this->set_number(number);
		this->set_gender(gender);
		this->set_title(title);
		this->set_given_name(given_name);
		this->set_middle_initial(middle_initial);
		this->set_surname(surname);
		this->set_street_address(street_address);
		this->set_city(city);
		this->set_state(state);
		this->set_zip_code(zip_code);
		this->set_email_address(email_address);
		this->set_birthday_mm(birthday_mm);
		this->set_birthday_dd(birthday_dd);
		this->set_birthday_yyyy(birthday_yyyy);
		this->set_age(age);
	}

	Contact::~Contact() {

	}

	std::string Contact::get_number() const {
		return this->number;
	}

	void Contact::set_number(std::string number) {
		this->number = number;
	}

	std::string Contact::get_gender() const {
		return this->gender;
	}

	void Contact::set_gender(std::string gender) {
		this->gender = gender;
	}

	std::string Contact::get_title() const {
		return this->title;
	}

	void Contact::set_title(std::string title) {
		this->title = title;
	}

	std::string Contact::get_given_name() const {
		return this->given_name;
	}

	void Contact::set_given_name(std::string given_name) {
		this->given_name = given_name;
	}

	std::string Contact::get_middle_initial() const {
		return this->middle_initial;
	}

	void Contact::set_middle_initial(std::string middle_initial) {
		this->middle_initial = middle_initial;
	}

	std::string Contact::get_surname() const {
		return this->surname;
	}

	void Contact::set_surname(std::string surname) {
		this->surname = surname;
	}

	std::string Contact::get_street_address() const {
		return this->street_address;
	}

	void Contact::set_street_address(std::string street_address) {
		this->street_address = street_address;
	}

	std::string Contact::get_city() const {
		return this->city;
	}

	void Contact::set_city(std::string city) {
		this->city = city;
	}

	std::string Contact::get_state() const {
		return this->state;
	}

	void Contact::set_state(std::string state) {
		this->state = state;
	}

	std::string Contact::get_zip_code() const {
		return this->zip_code;
	}

	void Contact::set_zip_code(std::string zip_code) {
		this->zip_code = zip_code;
	}

	std::string Contact::get_email_address() const {
		return this->email_address;
	}

	void Contact::set_email_address(std::string email_address) {
		this->email_address = email_address;
	}

	std::string Contact::get_birthday_mm() const {
		return this->birthday_mm;
	}

	void Contact::set_birthday_mm(std::string birthday_mm) {
		this->birthday_mm = birthday_mm;
	}

	std::string Contact::get_birthday_dd() const {
		return this->birthday_dd;
	}

	void Contact::set_birthday_dd(std::string birthday_dd) {
		this->birthday_dd = birthday_dd;
	}

	std::string Contact::get_birthday_yyyy() const {
		return this->birthday_yyyy;
	}

	void Contact::set_birthday_yyyy(std::string birthday_yyyy) {
		this->birthday_yyyy = birthday_yyyy;
	}

	std::string Contact::get_age() const {
		return this->age;
	}

	void Contact::set_age(std::string age) {
		int age_conversion = stoi(current_year) - stoi(birthday_yyyy);
		this->age = std::to_string(age_conversion);
	}

	/*Contact& Contact::operator=(const Contact &rh) {
		return *this;
	}

	bool Contact::operator< (const Contact &rhs) {
		return this->get_surname() < rhs.get_surname();
	}

	std::ostream& operator<< (std::ostream &out, const Contact &dude) {
		out << dude.get_number() << " "
			<< dude.get_gender() << " "
			<< dude.get_title() << " "
			<< dude.get_given_name() << " "
			<< dude.get_middle_initial() << " "
			<< dude.get_surname() << " "
			<< dude.get_street_address() << " "
			<< dude.get_city() << " "
			<< dude.get_state() << " "
			<< dude.get_zip_code() << " "
			<< dude.get_email_address() << " "
			<< dude.get_birthday_mm() << "/"
			<< dude.get_birthday_dd() << "/"
			<< dude.get_birthday_yyyy() << " "
			<< dude.get_age() << " ";
		return out;
	}*/
}