#include "Textbox.h"

//texboxview functions

TextboxView::TextboxView(Settings* _settings) {
	this->settings_ = _settings;
	this->font_ = this->settings_->GetFont();
	this->size_of_character_ = this->settings_->GetTextSize();

	this->model_ = new TextboxModel(_settings);
	this->model_->LoadList(this->settings_);
	this->model_->NewWord();
}


void TextboxView::InteractionTexboxModel(int _key_code) {
	this->model_->MovePointer(_key_code);
}

void TextboxView::SetPosition(double _x, double _y) {
	this->position_.x = _x;
	this->position_.y = _y;
}

void TextboxView::SetSize(double _width, double _height) {
	this->textbox_size_.x = _width;
	this->textbox_size_.y = _height;
}

//texboxmodel functions

TextboxModel::TextboxModel(Settings* _settings) {
	this->settings_ = _settings;
}

void TextboxModel::MovePointer(int _key_code) {
	if (_key_code == 57) NewWord();
	if (_key_code < 26 && _key_code > -1) {
		ChooseCharColor(_key_code);
		pointer_++;
	}
	if (_key_code == 59 && pointer_ > 0) {
		pointer_--;
		ChangeCharColor(sf::Color(190, 190, 190));
	}
	if ((size_t)pointer_ > used_str_.size()) NewWord();
}
