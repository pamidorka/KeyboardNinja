#pragma once
#include <SFML/Graphics.hpp>

class VirtualKeyboard {
private:

	struct Position {
		double x;
		double y;
	};

	Button* buttons_;
	Font keyboard_font_;
	Position position_;

public:

	GKeyboard() {
		buttons_ = new Button[27];

		for (int i = 0, j = 'a'; i <= 25; j++, i++) {
			buttons_[i].SetKeyCode(i);
			buttons_[i].SetCharacter(j);
			buttons_[i].SetColor(Color::White);
		}

		{
		buttons_[0].SetPosistion(0, 60 + 1);
		buttons_[1].SetPosistion(4 * (60 + 1), 120 + 2);
		buttons_[2].SetPosistion(2 * (60 + 1), 120 + 2);
		buttons_[3].SetPosistion(2 * (60 + 1), 60 + 1);
		buttons_[4].SetPosistion(2 * (60 + 1), 0);
		buttons_[5].SetPosistion(3 * (60 + 1), 60 + 1);
		buttons_[6].SetPosistion(4 * (60 + 1), 60 + 1);
		buttons_[7].SetPosistion(5 * (60 + 1), 60 + 1);
		buttons_[8].SetPosistion(7 * (60 + 1), 0);
		buttons_[9].SetPosistion(6 * (60 + 1), 60 + 1);
		buttons_[10].SetPosistion(7 * (60 + 1), 60 + 1);
		buttons_[11].SetPosistion(8 * (60 + 1), 60 + 1);
		buttons_[12].SetPosistion(6 * (60 + 1), 120 + 2);
		buttons_[13].SetPosistion(5 * (60 + 1), 120 + 2);
		buttons_[14].SetPosistion(8 * (60 + 1), 0);
		buttons_[15].SetPosistion(9 * (60 + 1), 0);
		buttons_[16].SetPosistion(0, 0);
		buttons_[17].SetPosistion(3 * (60 + 1), 0);
		buttons_[18].SetPosistion(60 + 1, 60 + 1);
		buttons_[19].SetPosistion(4 * (60 + 1), 0);
		buttons_[20].SetPosistion(6 * (60 + 1), 0);
		buttons_[21].SetPosistion(3 * (60 + 1), 120 + 2);
		buttons_[22].SetPosistion(60 + 1, 0);
		buttons_[23].SetPosistion(60 + 1, 120 + 2);
		buttons_[24].SetPosistion(5 * (60 + 1), 0);
		buttons_[25].SetPosistion(0, 120 + 2);
		buttons_[26].SetPosistion(60 + 1, 180 + 3);

		buttons_[26].SetKeyCode(57);
		buttons_[26].SetColor(Color::White);
		buttons_[26].SetCharacter(' ');
		buttons_[26].SetSize(243, 60);
		}

		SetPosition(0, 0);
	}

	void SetPosition(const double _x, const double _y) {
		this->position_.x = _x;
		this->position_.y = _y;
	}

	void SetFont(Font _font) {
		this->keyboard_font_ = _font;
	}

	void ChangePressedKey(const int _key) {
		if (_key > 25 && _key != 57) {
			return;
		}
		if (_key == 57) {
			buttons_[26].SetColor(Color::Black);
			buttons_[26].SetCharacterColor(Color::White);
			return;
		}

		buttons_[_key].SetColor(Color::Black);
		buttons_[_key].SetCharacterColor(Color::White);
	}

	void ChangeReleasedKey(const int _key) {
		if (_key > 25 && _key != 57) {
			return;
		}
		if (_key == 57) {
			buttons_[26].SetColor(Color::White);
			buttons_[26].SetCharacterColor(Color::Black);
			return;
		}

		buttons_[_key].SetColor(Color::White);
		buttons_[_key].SetCharacterColor(Color::Black);
	}

	Button* GetButtons() {
		return this->buttons_;
	}

	Position GetPosition() {
		return this->position_;
	}

	Font GetFont() {
		return this->keyboard_font_;
	}

};