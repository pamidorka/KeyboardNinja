#include "Keyboard.h"

VirtualKeyboard::VirtualKeyboard(Settings* _settings) {
	buttons_ = new VirtualButton[kNumberOfButtons_];
	this->settings_ = _settings;

	for (int i = 0; i < kNumberOfButtons_ - 2; i++) {
		buttons_[i].SetKeyCode(i);
		buttons_[i].SetCharacter(std::string((size_t)1, (char)('A' + i)));
		buttons_[i].SetColor(sf::Color::White);
	}

	{
		buttons_[0].SetPosition(0, 60 + kSizeOfOutline_);
		buttons_[1].SetPosition(4 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[2].SetPosition(2 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[3].SetPosition(2 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[4].SetPosition(2 * (60 + kSizeOfOutline_), 0);
		buttons_[5].SetPosition(3 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[6].SetPosition(4 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[7].SetPosition(5 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[8].SetPosition(7 * (60 + kSizeOfOutline_), 0);
		buttons_[9].SetPosition(6 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[10].SetPosition(7 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[11].SetPosition(8 * (60 + kSizeOfOutline_), 60 + kSizeOfOutline_);
		buttons_[12].SetPosition(6 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[13].SetPosition(5 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[14].SetPosition(8 * (60 + kSizeOfOutline_), 0);
		buttons_[15].SetPosition(9 * (60 + kSizeOfOutline_), 0);
		buttons_[16].SetPosition(0, 0);
		buttons_[17].SetPosition(3 * (60 + kSizeOfOutline_), 0);
		buttons_[18].SetPosition(60 + kSizeOfOutline_, 60 + kSizeOfOutline_);
		buttons_[19].SetPosition(4 * (60 + kSizeOfOutline_), 0);
		buttons_[20].SetPosition(6 * (60 + kSizeOfOutline_), 0);
		buttons_[21].SetPosition(3 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));
		buttons_[22].SetPosition(60 + kSizeOfOutline_, 0);
		buttons_[23].SetPosition(60 + kSizeOfOutline_, 2 * (60 + kSizeOfOutline_));
		buttons_[24].SetPosition(5 * (60 + kSizeOfOutline_), 0);
		buttons_[25].SetPosition(0, 120 + 2);
		buttons_[26].SetPosition(60 + kSizeOfOutline_, 3 * (60 + kSizeOfOutline_));
		buttons_[27].SetPosition(7 * (60 + kSizeOfOutline_), 2 * (60 + kSizeOfOutline_));

		buttons_[26].SetKeyCode(57);
		buttons_[26].SetColor(sf::Color::White);
		buttons_[26].SetCharacter("");
		buttons_[26].SetSize(4 * (60 + kSizeOfOutline_) - 1, 60);
		buttons_[27].SetKeyCode(sf::Keyboard::RShift);
		buttons_[27].SetCharacter("Shift");
		buttons_[27].SetSize(2 * (60 + kSizeOfOutline_) - 1, 60);
		buttons_[27].SetColor(sf::Color::White);
	}

	SetPosition(300, 300);
}

VirtualKeyboard::~VirtualKeyboard() {
	delete[] buttons_;
}

void VirtualKeyboard::SetPosition(double _x, double _y) {
	this->position_.x = _x;
	this->position_.y = _y;
}

void VirtualKeyboard::ChangePressedKey(int _key) {
	std::cout << _key << std::endl;
	if ((_key < 0 || _key > 25) && _key != 57 && _key != 42 && _key != 38) {
		return;
	}
	if (_key == 57) {
		buttons_[26].SetColor(sf::Color::Black);
		buttons_[26].SetCharacterColor(sf::Color::White);
		return;
	}
	if (_key == 42 || _key == 38) {
		buttons_[27].SetColor(sf::Color::Black);
		buttons_[27].SetCharacterColor(sf::Color::White);
		return;
	}

	buttons_[_key].SetColor(sf::Color::Black);
	buttons_[_key].SetCharacterColor(sf::Color::White);
}

void VirtualKeyboard::ChangeReleasedKey(int _key) {
	if ((_key < 0 || _key > 25) && _key != 57 && _key != 42 && _key != 38) {
		return;
	}
	if (_key == 57) {
		buttons_[26].SetColor(sf::Color::White);
		buttons_[26].SetCharacterColor(sf::Color::Black);
		return;
	}
	if (_key == 42 || _key == 38) {
		buttons_[27].SetColor(sf::Color::White);
		buttons_[27].SetCharacterColor(sf::Color::Black);
		return;
	}

	buttons_[_key].SetColor(sf::Color::White);
	buttons_[_key].SetCharacterColor(sf::Color::Black);
}

void VirtualKeyboard::Reset() {
	for (int i = 0; i < this->kNumberOfButtons_; i++) {
		buttons_[i].SetColor(sf::Color::White);
		buttons_[i].SetCharacterColor(sf::Color::Black);
	}
}

VirtualKeyboard::Position VirtualKeyboard::GetPosition() {
	return this->position_;
}

void VirtualKeyboard::Draw(sf::RenderWindow* _window) {
	for (int i = 0; i < kNumberOfButtons_; i++) {
		sf::RectangleShape btn;
		btn.setSize(sf::Vector2f(buttons_[i].GetSize().x, buttons_[i].GetSize().y));
		btn.setPosition(sf::Vector2f(position_.x + buttons_[i].GetPosition().x, position_.y + buttons_[i].GetPosition().y));
		btn.setFillColor(buttons_[i].GetColor());
		btn.setOutlineThickness(kSizeOfOutline_);
		btn.setOutlineColor(sf::Color::Black);

		sf::Text text;
		text.setFont(this->settings_->GetDefaultFont());
		text.setCharacterSize(kSizeOfCharacter_);
		text.setString(buttons_[i].GetCharacter());
		text.setPosition(sf::Vector2f(position_.x + buttons_[i].GetPosition().x + 5, position_.y + buttons_[i].GetPosition().y + 3));
		text.setFillColor(buttons_[i].GetCharacterColor());

		_window->draw(btn);
		_window->draw(text);
		SetPosition(300, 300);
	}
}


