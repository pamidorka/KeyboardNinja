#include "Settings.h"

const string Settings::kDefaultVocabularyFileName = "vocab.txt";
const string Settings::kDefaultFontFileName = "Roboto-Regular.ttf";
const unsigned int Settings::kDefaultTextSize = 24;

void Settings::LoadDefaultFont() {
	if (!default_font_.loadFromFile("src/fonts/" + kDefaultFontFileName)) {
		throw runtime_error("Failed to open the default font file.");
	}
}

Settings::Settings() {
	if (!LoadVocabularyFromCSV("src/wordbase/" + kDefaultVocabularyFileName)) {
		throw runtime_error("Failed to open the default vocabulary file.");
	}
	LoadDefaultFont();

	font_ = default_font_;
	text_size_ = kDefaultTextSize;
}

Settings::Settings(vector<string> _vocabulary, Font _font, unsigned int _textSize) : vocabulary_(_vocabulary), font_(_font), text_size_(_textSize) {
	LoadDefaultFont();
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
	return font_.loadFromFile("src/fonts/" + _file_name);
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

const Font& Settings::GetDefaultFont() {
	return default_font_;
}

unsigned int Settings::GetTextSize() {
	return text_size_;
}