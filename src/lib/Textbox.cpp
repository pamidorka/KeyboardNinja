#include "Textbox.h"

Textbox::Textbox(Settings* _settings){
    textbox_font_ = _settings->GetFont();
    size_of_character_ = _settings->GetTextSize();

    used_window_textbox_ = 0;
    pointer_ = 0;
    SetPosition(1200 / 4, 600 / 3);
    SetSize(500, 400);
    this->settings_ = _settings;
    UpdateList();
    FinishWord();
}

void Textbox::MovePointer(int _key_code) {
    if (_key_code == 57) FinishWord();
    if (_key_code < 26 && _key_code > -1) {
        ChooseCharColor(_key_code);
        pointer_++;
    }
    if (_key_code == 59 && pointer_ > 0) {
        pointer_--;
        ChangeCharColor(sf::Color(190, 190, 190));
    }
    if ((size_t)pointer_ > used_str_.size()) FinishWord();
}

double Textbox::SizeLineFont(std::string _string) {
    double size_temp = 0;
    for (size_t i = 0; i < _string.size(); i++) {
        size_temp += textbox_font_.getGlyph(_string[i], size_of_character_, false, 0).bounds.width;
    }

    return size_temp;
}

void Textbox::UpdateList() {
    std::string word = settings_->GetWordAt(rand() % settings_->GetVocabularySize());
    while (SizeLineFont(word) < (textbox_size_.x - used_window_textbox_)) {
        list_string_.push_back(word);
        used_window_textbox_ += SizeLineFont(word);
        word = settings_->GetWordAt(rand() % settings_->GetVocabularySize());
    }
}

void Textbox::StringToVector(std::string _string) {
    TextChar temp;
    const sf::Color color(190, 190, 190);
    for (size_t i = 0; i < _string.size(); i++) {
        temp.character = _string[i];
        temp.color = color;
        used_str_.push_back(temp);
    }
}

void Textbox::SetPosition(const double _width, const double _height) {
    this->position_.x = _width;
    this->position_.y = _height;
}

void Textbox::SetSize(const double _width, const double _height) {
    this->textbox_size_.x = _width;
    this->textbox_size_.y = _height;
}

void Textbox::FinishWord() {
    std::string temp = list_string_.front();
    list_string_.pop_front();
    double size_temp = 0;
    for (size_t i = 0; i < used_str_.size(); i++) {
        size_temp += textbox_font_.getGlyph(used_str_[i].character, size_of_character_, false, 0).bounds.width;
    }
    used_window_textbox_ -= size_temp;
    UpdateList();
    used_str_.clear();
    StringToVector(temp);
    pointer_ = 0;
}

void Textbox::Draw(sf::RenderWindow* _window) {
    sf::Text text;
    double dx = 0;
    text.setFont(textbox_font_);
    text.setCharacterSize(size_of_character_);
    for (size_t i = 0; i < used_str_.size(); i++) {
        text.setFillColor(used_str_[i].color);
        text.setString(used_str_[i].character);
        text.setPosition(position_.x + dx, position_.y);
        dx += textbox_font_.getGlyph(used_str_[i].character, size_of_character_, false, 0).advance;
        _window->draw(text);
    }
    dx += 10;
    for (auto i = list_string_.begin(); i != list_string_.end(); i++) {
        text.setFillColor(sf::Color(190, 190, 190));
        text.setString((*i));
        text.setPosition(position_.x + dx, position_.y);
        dx += text.getLocalBounds().width + 10;
        _window->draw(text);
    }
}

void Textbox::ChangeCharColor(const sf::Color _color) {
    used_str_[pointer_].color = _color;
}

void Textbox::ChooseCharColor(const int _key) {
    if ((int)('a' + _key) == (int)used_str_[pointer_].character) ChangeCharColor(sf::Color::Black);
    else ChangeCharColor(sf::Color::Red);
}
 