#include "Textbox.h"

//texboxview functions

TextboxView::TextboxView(Settings* _settings) {
	this->settings_ = _settings;
	SetPosition(1200 / 4, 600 / 3);

	this->model_ = new TextboxModel(_settings);
}

TextboxView::~TextboxView() {
	delete model_;
}


void TextboxView::InteractionTextboxModel(int _key_code) {
	this->model_->MovePointer(_key_code);
}

void TextboxView::SetPosition(double _x, double _y) {
	this->position_.x = _x;
	this->position_.y = _y;
}

void TextboxView::SetSize(double _width, double _height) {
	this->size_.x = _width;
	this->size_.y = _height;
}

void TextboxView::Draw(sf::RenderWindow* _window) {
	sf::Text text;
	double dx = 0;
	text.setFont(this->settings_->GetFont());
	text.setCharacterSize(this->settings_->GetTextSize());
	for (size_t i = 0; i < this->model_->GetUsedStr().size(); i++) {
		text.setFillColor(this->model_->GetUsedStr()[i].color);
		text.setString(this->model_->GetUsedStr()[i].character);
		text.setPosition(position_.x + dx, position_.y);
		dx += this->settings_->GetFont().getGlyph(this->model_->GetUsedStr()[i].character, this->settings_->GetTextSize(), false, 0).advance;
		_window->draw(text);
	}
	dx += 10;
	for (auto i = this->model_->GetList().cbegin(); i != this->model_->GetList().cend(); i++) {
		text.setFillColor(sf::Color(190, 190, 190));
		text.setString((*i));
		text.setPosition(position_.x + dx, position_.y);
		dx += text.getLocalBounds().width + 10;
		_window->draw(text);
	}
}

//texboxmodel functions

TextboxModel::TextboxModel(Settings* _settings) {
	this->settings_ = _settings;
	LoadList();
	NewWord();
}

void TextboxModel::MovePointer(int _key_code) {
	if (_key_code == 57) NewWord();
	if (_key_code < 26 && _key_code >= 0) {
		if ((size_t)pointer_ >= used_str_.size()) NewWord();
		else {
			ChooseCharColor(_key_code);
			pointer_++;
		}
	}
	if (_key_code == 59 && pointer_ > 0) {
		pointer_--;
		ChangeCharColor(sf::Color(190, 190, 190));
	}
}

void TextboxModel::NewWord() {
	std::string temp = list_string_.front();
	list_string_.pop_front();
	LoadList();
	used_str_.clear();
	std::transform(temp.begin(), temp.end(), std::back_inserter(used_str_), [](char c) { return TextChar{ Color(190, 190, 190), c }; });
	pointer_ = 0;
}

void TextboxModel::LoadList() {
	std::string word = settings_->GetWordAt(rand() % settings_->GetVocabularySize());
	while (list_string_.size() < 5) {
		list_string_.push_back(word);
		word = settings_->GetWordAt(rand() % settings_->GetVocabularySize());
	}
}

void TextboxModel::ChangeCharColor(const sf::Color _color) {
	used_str_[pointer_].color = _color;
}

void TextboxModel::ChooseCharColor(const int _key) {
	if ((int)('a' + _key) == (int)used_str_[pointer_].character) ChangeCharColor(sf::Color::Black);
	else ChangeCharColor(sf::Color::Red);
}

const std::vector <TextboxModel::TextChar>& TextboxModel::GetUsedStr() {
	return this->used_str_;
}

const std::list <std::string>& TextboxModel::GetList() {
	return this->list_string_;
}
