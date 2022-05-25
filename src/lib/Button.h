#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:

	struct Options {
		double x;
		double y;
	};

	int keycode_;
	char character_;
	Color color_;
	Color character_color_;
	Options size_;
	Options position_;

public:

	Button(const double _width = 60, const double _height = 60, const double _x = 0, const double _y = 0, const int _character = NULL) {
		SetSize(_width, _height);
		SetKeyCode(_character);
		SetPosistion(_x, _y);
	}

	void SetSize(const double _width, const double _height) {
		this->size_.x = _width;
		this->size_.y = _height;
	}

	void SetKeyCode(const int _character) {
		this->keycode_ = _character;
	}

	void SetPosistion(const double _width, const double _height) {
		this->position_.x = _width;
		this->position_.y = _height;
	}

	void SetCharacter(const char _symbol) {
		this->character_ = _symbol;
	}

	void SetColor(const Color _color) {
		this->color_ = _color;
	}

	void SetCharacterColor(const Color _color) {
		this->character_color_ = _color;
	}

	int GetKeyCode() {
		return this->keycode_;
	}

	char GetCharacter() {
		return this->character_;
	}

	Options GetSize() {
		return this->size_;
	}

	Options GetPosition() {
		return this->position_;
	}

	Color GetColor() {
		return this->color_;
	}

	Color GetCharacterColor() {
		return this->character_color_;
	}

};