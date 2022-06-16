#include "Settings.h"

const std::string Settings::kDefaultVocabularyFileName = "Easy.txt";
const std::string Settings::kDefaultFontFileName = "Roboto-Regular.ttf";
const unsigned int Settings::kDefaultTextSize = 24;

void Settings::LoadDefaultFont()
{
    if (!default_font_.loadFromFile("src/fonts/" + kDefaultFontFileName)) {
        throw std::runtime_error("Failed to open the default font file.");
    }
}

Settings::Settings()
{
    if (!LoadVocabularyFromCSV(kDefaultVocabularyFileName)) {
        throw std::runtime_error("Failed to open the default vocabulary file.");
    }
    LoadDefaultFont();

    font_ = default_font_;
    text_size_ = kDefaultTextSize;

    difficulty_settings_id_ = 0;
    font_settings_id_ = 0;
    font_size_settings_val_ = false;

    test_length_in_seconds = 30;
}

bool Settings::LoadVocabularyFromCSV(std::string _file_name)
{
    std::ifstream file;
    file.open("src/wordbase/" + _file_name, std::ifstream::in);

    if (!file.is_open()) {
        std::cerr << "Can't open the file \"" << _file_name << "\"."
                  << std::endl;
        return false;
    }

    vocabulary_.clear();

    std::string line;
    getline(file, line);

    std::stringstream line_stream(line);
    std::string cell;
    while (getline(line_stream, cell, ',')) {
        vocabulary_.push_back(cell);
    }

    return true;
}

bool Settings::LoadFont(std::string _file_name)
{
    return font_.loadFromFile("src/fonts/" + _file_name);
}

void Settings::SetTextSize(unsigned int _text_size)
{
    this->text_size_ = _text_size;
}

size_t Settings::GetVocabularySize()
{
    return vocabulary_.size();
}

const std::string& Settings::GetWordAt(size_t _pos)
{
    if (_pos >= vocabulary_.size()) {
        throw std::out_of_range("Index is out of range");
    }

    return vocabulary_[_pos];
}

const sf::Font& Settings::GetFont()
{
    return font_;
}

const sf::Font& Settings::GetDefaultFont()
{
    return default_font_;
}

unsigned int Settings::GetTextSize()
{
    return text_size_;
}

int Settings::GetTestLengthInSeconds()
{
    return test_length_in_seconds;
}

void Settings::SetTestLengthInSeconds(int _seconds)
{
    test_length_in_seconds = _seconds;
}

int Settings::GetDifficultySettingsId()
{
    return difficulty_settings_id_;
}

int Settings::GetFontSettingsId()
{
    return font_settings_id_;
}

bool Settings::GetFontSizeSettingsVal()
{
    return font_size_settings_val_;
}

void Settings::SetDifficultySettingsId(int _id)
{
    difficulty_settings_id_ = _id;
}

void Settings::SetFontSettingsId(int _id)
{
    font_settings_id_ = _id;
}

void Settings::SetFontSizeSettingsVal(bool _val)
{
    font_size_settings_val_ = _val;
}
