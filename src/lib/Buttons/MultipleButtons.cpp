#include "MultipleButtons.h"

MultipleButtons::MultipleButtons() : active_button_id_(-1) {

}

void MultipleButtons::AddButton(ToggleButton& _button) {
	buttons_.push_back(_button);
}

void MultipleButtons::SetActiveButtonId(int _id) {
	active_button_id_ = _id;

	for (int i = 0; i < buttons_.size(); i++) {
		buttons_[i].Toggle(i == _id);
	}
}

int MultipleButtons::GetActiveButtonId() {
	return active_button_id_;
}

bool MultipleButtons::Update(const Vector2f _mouse_pos) {
	bool result = false;
	for (int i = 0; i < buttons_.size(); i++) {
		if (buttons_[i].Update(_mouse_pos)) {
			active_button_id_ = i;
			result = true;
		}
	}

	SetActiveButtonId(active_button_id_);
	return result;
}

void MultipleButtons::Render(RenderTarget* _target) {
	for (int i = 0; i < buttons_.size(); i++) {
		buttons_[i].Render(_target);
	}
}