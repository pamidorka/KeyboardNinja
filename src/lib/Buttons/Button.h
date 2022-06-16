#pragma once
#include <SFML/Graphics.hpp>

enum class ButtonStates {
	ButtonIdle = 0,
	ButtonHover,
	ButtonHoverInactive,
	ButtonHoverActive,
	ButtonUnhoverActive
};

struct ButtonColorSet {
public:
	sf::Color idle_color_;
	sf::Color hover_color_;
	sf::Color active_color_;

	ButtonColorSet(sf::Color _idle_color, sf::Color _hover_color, sf::Color _active_color)
		: idle_color_(_idle_color), hover_color_(_hover_color), active_color_(_active_color) {

	}
};

class Button {
private:
	ButtonStates button_state_;

	sf::RectangleShape shape_;
	const sf::Font* font_;

	sf::Text text_;
	ButtonColorSet colors_;
protected:
	void RefreshButtonColor();
	void RefreshTextLocation();
public:
	Button(float _x, float _y, float _width, float _height, const sf::Font* _font, const std::string &_text, unsigned int _text_size, const ButtonColorSet &_colors);
	~Button();

	bool IsMouseHover(sf::Vector2f _mouse_pos) const;

	void SetColorSet(const ButtonColorSet& _color_set);
	void SetText(const std::string& _s);

	ButtonStates GetButtonState() const;
	const sf::String& GetTextString() const;
	const sf::Font& GetTextFont() const;
	const sf::RectangleShape& GetBounds() const;
	const ButtonColorSet& GetButtonColorSet() const;

	bool Update(sf::Vector2f _mouse_pos, bool _mouse_pressed);
	void Render(sf::RenderTarget* _target);
};