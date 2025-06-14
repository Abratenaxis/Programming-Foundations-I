#ifndef UNIQUE_WORD_H_
#define UNIQUE_WORD_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace every_word {
	class Unique_Word {
	private:
		string word_name;
		list<int> line_numbers;
	public:
		Unique_Word(string word_name = "",
			list<int> line_numbers = {});
		string get_word_name() const;
		int get_occurance_count() const;
		list<int> get_line_numbers() const;

		void set_word_name(string word_name);
		void set_line_numbers(list<int> line_numbers);
		void add_to_line_numbers(int line_number);


		string word_line_item(string word_name, int count, list<int> line_numbers) const;


	};
}
#endif // !UNIQUE_WORD_H_
