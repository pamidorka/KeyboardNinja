#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum class ButtonStates {
	ButtonIdle = 0,
	ButtonHover,
	ButtonHoverInactive,
	ButtonHoverActive,
	ButtonUnhoverActive
};

struct ButtonColorSet {
public:
	Color idle_color_;
	Color hover_color_;
	Color active_color_;

	ButtonColorSet(Color _idle_color, Color _hover_color, Color _active_color)
		: idle_color_(_idle_color), hover_color_(_hover_color), active_color_(_active_color) {

	}
};

class Button {
private:
	ButtonStates button_state_;

	RectangleShape shape_;
	const Font* font_;

	Text text_;
	ButtonColorSet colors_;
protected:
	void RefreshButtonColor();
	void RefreshTextLocation();
public:
	Button(float _x, float _y, float _width, float _height, const Font* _font, string _text, unsigned int _text_size, const ButtonColorSet &_colors);
	~Button();

	bool IsMouseHover(Vector2f _mouse_pos) const;

	void SetColorSet(const ButtonColorSet& _color_set);
	void SetText(const string& _s);

	ButtonStates GetButtonState() const;
	const string& GetTextString() const;
	const Font& GetTextFont() const;
	const RectangleShape& GetBounds() const;
	const ButtonColorSet& GetButtonColorSet() const;

	bool Update(Vector2f _mouse_pos);
	void Render(RenderTarget* _target);
};