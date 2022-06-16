#pragma once
#include "ToggleButton.h"
#include <vector>

class MultipleButtons {
private:
    std::vector<ToggleButton> buttons_;
    int active_button_id_;

public:
    MultipleButtons();

    void AddButton(ToggleButton& _button);
    const ToggleButton& GetButton(size_t _id) const;

    void SetActiveButtonId(int _id);
    int GetActiveButtonId() const;

    bool Update(sf::Vector2f _mouse_pos, bool _mouse_pressed);
    void Render(sf::RenderTarget* _target);
};
