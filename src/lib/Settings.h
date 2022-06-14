#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class Settings {
private:
	vector<string> vocabulary_;
	Font default_font_;
	Font font_;
	unsigned int text_size_;

	int test_length_in_seconds;

	int difficulty_settings_id_;
	int font_settings_id_;
	bool font_size_settings_val_;

	void LoadDefaultFont();
public:
	static const string kDefaultVocabularyFileName; // CSV file
	static const string kDefaultFontFileName;
	static const unsigned int kDefaultTextSize;

	Settings();
	Settings(vector<string> _vocabulary, Font _font, unsigned int _textSize = kDefaultTextSize);

	bool LoadVocabularyFromCSV(string _file_name);
	bool LoadFont(string _file_name);
	void SetTextSize(unsigned int _text_size);

	size_t GetVocabularySize();
	const string& GetWordAt(size_t _pos);
	const Font& GetFont();
	const Font& GetDefaultFont();
	unsigned int GetTextSize();

	int GetTestLengthInSeconds();
	void SetTestLengthInSeconds(int _seconds);

	int GetDifficultySettingsId();
	int GetFontSettingsId();
	bool GetFontSizeSettingsVal();

	void SetDifficultySettingsId(int _id);
	void SetFontSettingsId(int _id);
	void SetFontSizeSettingsVal(bool _val);
};