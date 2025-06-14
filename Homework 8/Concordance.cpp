#include "Concordance.h"

namespace every_word {
	Concordance::Concordance(
		list<every_word::Unique_Word> list_of_words) {}

	void Concordance::add_word_to_list(every_word::Unique_Word word) {
		this->list_of_words.push_back(word);
	}

	void Concordance::writeToFile(string& outfile) {
		ofstream myFile;
		myFile.open(outfile);
		for (auto p : this->list_of_words) {
			myFile << p.word_line_item(p.get_word_name(), p.get_occurance_count(), p.get_line_numbers()) << endl;
		}
	}
}