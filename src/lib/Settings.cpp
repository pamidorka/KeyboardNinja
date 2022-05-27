#include "Settings.h"

const string Settings::kDefaultVocabularyFileName = "vocab.txt";
const string Settings::kDefaultFontFileName = "Roboto-Regular.ttf";
const unsigned int Settings::kDefaultTextSize = 16;

Settings::Settings() {
	if (!LoadVocabularyFromCSV(kDefaultVocabularyFileName)) {
		throw exception("Failed to open the default vocabulary file.");
	}
	if (!LoadFont(kDefaultFontFileName)) {
		throw exception("Failed to open the default font file.");
	}
	text_size_ = kDefaultTextSize;
}

Settings::Settings(vector<string> _vocabulary, Font _font, unsigned int _textSize) : vocabulary_(_vocabulary), font_(_font), text_size_(_textSize) {

}

bool Settings::LoadVocabularyFromCSV(string _file_name) {
	ifstream file;
	file.open(_file_name, ifstream::in);

	if (!file.is_open()) {
		cerr << "Can't open the file \"" << _file_name << "\"." << endl;
		return false;
	}

	vocabulary_.clear();

	string line;
	getline(file, line);

	stringstream line_stream(line);
	string cell;
	while (getline(line_stream, cell, ',')) {
		vocabulary_.push_back(cell);
	}

	return true;
}

bool Settings::LoadFont(string _file_name) {
	return font_.loadFromFile(_file_name);
}

void Settings::SetTextSize(unsigned int _text_size) {
	this->text_size_ = _text_size;
}

size_t Settings::GetVocabularySize() {
	return vocabulary_.size();
}

const string& Settings::GetWordAt(size_t _pos) {
	if (_pos >= vocabulary_.size()) {
		throw out_of_range("Index is out of range");
	}

	return vocabulary_[_pos];
}

const Font& Settings::GetFont() {
	return font_;
}

unsigned int Settings::GetTextSize() {
	return text_size_;
}