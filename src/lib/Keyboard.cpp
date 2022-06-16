#include "Keyboard.h"

VirtualKeyboard::VirtualKeyboard(Settings* _settings) {
	buttons_ = new VirtualButton[kNumberOfButtons_];
	this->settings_ = _settings;

	for (int i = 0; i < kNumberOfButtons_ - 2; i++) {
		buttons_[i].SetCharacter(std::string((size_t)1, (char)('A' + i)));
		buttons_[i].SetColor(sf::Color::White);
		buttons_[i].SetSize(button_size_, button_size_);
	}

	{
		buttons_[0].SetPosition(0, button_size_ + kSizeOfOutline_);
		buttons_[1].SetPosition(4 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));
		buttons_[2].SetPosition(2 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));
		buttons_[3].SetPosition(2 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[4].SetPosition(2 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[5].SetPosition(3 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[6].SetPosition(4 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[7].SetPosition(5 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[8].SetPosition(7 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[9].SetPosition(6 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[10].SetPosition(7 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[11].SetPosition(8 * (button_size_ + kSizeOfOutline_), button_size_ + kSizeOfOutline_);
		buttons_[12].SetPosition(6 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));
		buttons_[13].SetPosition(5 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));
		buttons_[14].SetPosition(8 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[15].SetPosition(9 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[16].SetPosition(0, 0);
		buttons_[17].SetPosition(3 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[18].SetPosition(button_size_ + kSizeOfOutline_, button_size_ + kSizeOfOutline_);
		buttons_[19].SetPosition(4 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[20].SetPosition(6 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[21].SetPosition(3 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));
		buttons_[22].SetPosition(button_size_ + kSizeOfOutline_, 0);
		buttons_[23].SetPosition(button_size_ + kSizeOfOutline_, 2 * (button_size_ + kSizeOfOutline_));
		buttons_[24].SetPosition(5 * (button_size_ + kSizeOfOutline_), 0);
		buttons_[25].SetPosition(0, 2 * (button_size_ + 2));
		buttons_[26].SetPosition(button_size_ + kSizeOfOutline_, 3 * (button_size_ + kSizeOfOutline_));
		buttons_[27].SetPosition(7 * (button_size_ + kSizeOfOutline_), 2 * (button_size_ + kSizeOfOutline_));

		buttons_[26].SetColor(sf::Color::White);
		buttons_[26].SetCharacter("");
		buttons_[26].SetSize(4 * (button_size_ + kSizeOfOutline_) - 1, button_size_);
		buttons_[27].SetCharacter("Shift");
		buttons_[27].SetSize(2 * (button_size_ + kSizeOfOutline_) - 1, button_size_);
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

void VirtualKeyboard::SetButtonSize(int _size) {
	button_size_ = _size;
}

void VirtualKeyboard::ChangePressedKey(int _key) {
	if ((_key < sf::Keyboard::A || _key > sf::Keyboard::Z) && _key != sf::Keyboard::Space && _key != sf::Keyboard::RShift && _key != sf::Keyboard::LShift) {
		return;
	}
	if (_key == sf::Keyboard::Space) {
		buttons_[26].SetColor(sf::Color::Black);
		buttons_[26].SetCharacterColor(sf::Color::White);
		return;
	}
	if (_key == sf::Keyboard::RShift || _key == sf::Keyboard::LShift) {
		buttons_[27].SetColor(sf::Color::Black);
		buttons_[27].SetCharacterColor(sf::Color::White);
		return;
	}

	buttons_[_key].SetColor(sf::Color::Black);
	buttons_[_key].SetCharacterColor(sf::Color::White);
}

void VirtualKeyboard::ChangeReleasedKey(int _key) {
	if ((_key < sf::Keyboard::A || _key > sf::Keyboard::Z) && _key != sf::Keyboard::Space && _key != sf::Keyboard::RShift && _key != sf::Keyboard::LShift) {
		return;
	}
	if (_key == sf::Keyboard::Space) {
		buttons_[26].SetColor(sf::Color::White);
		buttons_[26].SetCharacterColor(sf::Color::Black);
		return;
	}
	if (_key == sf::Keyboard::RShift || _key == sf::Keyboard::LShift) {
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
	}
}

VirtualButton* VirtualKeyboard::GetButtons() {
	return this->buttons_;
}


