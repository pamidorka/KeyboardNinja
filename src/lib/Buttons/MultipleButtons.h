#pragma once
#include "ToggleButton.h"
#include <vector>

using namespace std;

class MultipleButtons {
private:
	vector<ToggleButton> buttons_;
	int active_button_id_;

public:
	MultipleButtons();
	
	void AddButton(ToggleButton& _button);
	void SetActiveButtonId(size_t _id);
	int GetActiveButtonId();

	bool Update(const Vector2f _mouse_pos, bool _mouse_pressed);
	void Render(RenderTarget* _target);
};
