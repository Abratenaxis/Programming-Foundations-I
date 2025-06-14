#include "Unique_Word.h"

namespace every_word {
	Unique_Word::Unique_Word(
		string word_name,
		list<int> line_numbers) {
		this->set_word_name(word_name);
		this->set_line_numbers(line_numbers);
	}
	string Unique_Word::get_word_name() const {
		return this->word_name;
	}

	int Unique_Word::get_occurance_count() const {
		return this->line_numbers.size();
	}

	list<int> Unique_Word::get_line_numbers() const {
		return this->line_numbers;
	}
	void Unique_Word::set_word_name(string word_name) {
		this->word_name = word_name;
	}

	void Unique_Word::set_line_numbers(list<int> line_numbers) {
		this->line_numbers = line_numbers;
	}
	void Unique_Word::add_to_line_numbers(int line_number) {
		this->line_numbers.push_back(line_number);
	}

	string Unique_Word::word_line_item(string word_name, int count, list<int> line_numbers) const {
		string result = "";
		result = word_name + "(" + to_string(count) + ")" + ": ";
		for (list<int>::iterator i = line_numbers.begin(); i != line_numbers.end(); ++i) {
			if (*i == 0) {
				result = result + to_string(*i);
			}
			result = result + ", " + to_string(*i);
		}
		return result;
	}
}
