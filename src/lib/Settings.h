#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Settings {
private:
    std::vector<std::string> vocabulary_;
    sf::Font default_font_;
    sf::Font font_;
    unsigned int text_size_;

    int test_length_in_seconds;

    int difficulty_settings_id_;
    int font_settings_id_;
    bool font_size_settings_val_;

    void LoadDefaultFont();

public:
    static const std::string kDefaultVocabularyFileName; // CSV file
    static const std::string kDefaultFontFileName;
    static const unsigned int kDefaultTextSize;

    Settings();

    bool LoadVocabularyFromCSV(std::string _file_name);
    bool LoadFont(std::string _file_name);
    void SetTextSize(unsigned int _text_size);

    size_t GetVocabularySize();
    const std::string& GetWordAt(size_t _pos);
    const sf::Font& GetFont();
    const sf::Font& GetDefaultFont();
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