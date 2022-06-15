#include "Textbox.h"

const sf::Color TextboxModel::kStandartCharColor = sf::Color(190, 190, 190);

//texboxview functions

TextboxView::TextboxView(Settings* _settings) {
	this->settings_ = _settings;
	SetPosition(1200 / 4, 600 / 3);

	this->model_ = new TextboxModel(_settings);
}

TextboxView::~TextboxView() {
	delete model_;
}

void TextboxView::InteractionTextboxModel(int _key_code, bool _shift_pressed) {
	this->model_->MovePointer(_key_code, _shift_pressed);
}

void TextboxView::SetPosition(double _x, double _y) {
	this->position_.x = _x;
	this->position_.y = _y;
}

bool TextboxView::CheckCharCorrect(int _key_code, bool _shift_pressed) {
	return this->model_->CheckCharCorrect(_key_code, _shift_pressed);
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
		text.setFillColor(this->model_->kStandartCharColor);
		text.setString((*i));
		text.setPosition(position_.x + dx, position_.y);
		dx += text.getLocalBounds().width + 10;
		_window->draw(text);
	}
}

void TextboxView::Restart() {
	this->model_->Restart();
}

//texboxmodel functions

TextboxModel::TextboxModel(Settings* _settings) {
	this->settings_ = _settings;

	LoadList();
	NewWord();
}

void TextboxModel::MovePointer(int _key_code, bool _shift_pressed) {
	if (_key_code == 57) NewWord();
	if (_key_code < 26 && _key_code > -1) {
		if ((size_t)pointer_ >= used_str_.size()) NewWord();
		else {
			ChooseCharColor(_key_code, _shift_pressed);
			pointer_++;
		}
	}
	if (_key_code == 59 && pointer_ > 0) {
		pointer_--;
		ChangeCharColor(this->kStandartCharColor);
	}
}

void TextboxModel::NewWord() {
	std::string temp = list_string_.front();
	list_string_.pop_front();
	LoadList();
	used_str_.clear();
	std::transform(temp.begin(), temp.end(), std::back_inserter(used_str_), [](char c) { return TextChar{ kStandartCharColor, c }; });
	pointer_ = 0;
}

void TextboxModel::Restart() {
	this->list_string_.clear();
	LoadList();
	NewWord();
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

void TextboxModel::ChooseCharColor(const int _key, bool _shift_pressed) {
	if (CheckCharCorrect(_key, _shift_pressed)) {
		ChangeCharColor(sf::Color::Black);
	}
	else {
		ChangeCharColor(sf::Color::Red);
	}
}

bool TextboxModel::CheckCharCorrect(int _key_code, bool _shift_pressed) {
	if (_key_code == 57) {
		return pointer_ == used_str_.size();
	}
	if (_key_code > -1 && _key_code < 26) {
		if (pointer_ == used_str_.size()) {
			return false;
		}

		char temp = _shift_pressed ? 'A' : 'a';
		return (int)(temp + _key_code) == (int)used_str_[pointer_].character;
	}

	return false;
}

const std::vector <TextboxModel::TextChar>& TextboxModel::GetUsedStr() {
	return this->used_str_;
}

const std::list <std::string>& TextboxModel::GetList() {
	return this->list_string_;
}

int TextboxModel::GetPointer() {
	return this->pointer_;
}
