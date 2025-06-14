#ifndef CONCORDANCE_H_
#define CONCORDANCE_H_

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Unique_Word.h"

using namespace std;

namespace every_word {
	class Concordance {
	private:
		list<every_word::Unique_Word> list_of_words = {};

	public:
		Concordance(list<every_word::Unique_Word> list_of_words = {});

		void add_word_to_list(every_word::Unique_Word word);
		void writeToFile(string& outfile);


	};
}
#endif // !CONCORDANCE_H_