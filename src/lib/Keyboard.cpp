#include "Keyboard.h"

VirtualKeyboard::VirtualKeyboard(std::string _font_name) {
	buttons_ = new Button[27];

	for (int i = 0, j = 'a'; i <= 25; j++, i++) {
		buttons_[i].SetKeyCode(i);
		buttons_[i].SetCharacter(j);
		buttons_[i].SetColor(Color::White);
	}

	{
		buttons_[0].SetPosistion(0, 60 + kSizeOfOutline_);
		buttons_[1].SetPosistion(4 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[2].SetPosistion(2 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[3].SetPosistion(2 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[4].SetPosistion(2 * (60 + kSizeOfOutline_), 0);
		buttons_[5].SetPosistion(3 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[6].SetPosistion(4 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[7].SetPosistion(5 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[8].SetPosistion(7 * (60 + kSizeOfOutline_), 0);
		buttons_[9].SetPosistion(6 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[10].SetPosistion(7 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[11].SetPosistion(8 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[12].SetPosistion(6 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[13].SetPosistion(5 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[14].SetPosistion(8 * (60 + kSizeOfOutline_), 0);
		buttons_[15].SetPosistion(9 * (60 + kSizeOfOutline_), 0);
		buttons_[16].SetPosistion(0, 0);
		buttons_[17].SetPosistion(3 * (60 + kSizeOfOutline_), 0);
		buttons_[18].SetPosistion(60 + kSizeOfOutline_, 60 + kSizeOfOutline_);
		buttons_[19].SetPosistion(4 * (60 + kSizeOfOutline_), 0);
		buttons_[20].SetPosistion(6 * (60 + kSizeOfOutline_), 0);
		buttons_[21].SetPosistion(3 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[22].SetPosistion(60 + kSizeOfOutline_, 0);
		buttons_[23].SetPosistion(60 + kSizeOfOutline_, 2 * (60 + kSizeOfOutline_));
		buttons_[24].SetPosistion(5 * (60 + kSizeOfOutline_), 0);
		buttons_[25].SetPosistion(0, 120 + 2);
		buttons_[26].SetPosistion(60 + kSizeOfOutline_, 3 * (60 + kSizeOfOutline_));

		buttons_[26].SetKeyCode(57);
		buttons_[26].SetColor(Color::White);
		buttons_[26].SetCharacter(' ');
		buttons_[26].SetSize(3 * (60 + kSizeOfOutline_), 60);
	}

	if (!keyboard_font_.loadFromFile("src/fonts/" + _font_name)) {
		cout << "font not loaded" << endl;
		throw std::runtime_error("font not loaded");
	}

	SetPosition(0, 0);
}

void VirtualKeyboard::SetPosition(const double _x, const double _y) {
	this->position_.x = _x;
	this->position_.y = _y;
}

void VirtualKeyboard::ChangePressedKey(const int _key) {
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

void VirtualKeyboard::ChangeReleasedKey(const int _key) {
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

VirtualKeyboard::Position VirtualKeyboard::GetPosition() {
	return this->position_;
}

void VirtualKeyboard::Draw(sf::RenderWindow* _window) {
	for (int i = 0; i < 27; i++) {
		sf::RectangleShape butt;
		butt.setSize(Vector2f(buttons_[i].GetSize().x, buttons_[i].GetSize().y));
		butt.setPosition(Vector2f(position_.x + buttons_[i].GetPosition().x, position_.y + buttons_[i].GetPosition().y));
		butt.setFillColor(buttons_[i].GetColor());
		butt.setOutlineThickness(kSizeOfOutline_);
		butt.setOutlineColor(Color::Black);

		sf::Text text;
		text.setFont(keyboard_font_);
		text.setCharacterSize(kSizeOfCharacter_);
		text.setString((char)toupper(buttons_[i].GetCharacter()));
		text.setPosition(Vector2f(position_.x + buttons_[i].GetPosition().x + 5, position_.y + buttons_[i].GetPosition().y + 3));
		text.setFillColor(buttons_[i].GetCharacterColor());

		_window->draw(butt);
		_window->draw(text);
	}
}

Button* VirtualKeyboard::GetButtons() {
	return this->buttons_;
}

