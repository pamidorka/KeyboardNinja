#pragma once
#include "lib/Buttons/MultipleButtons.h"
#include "lib/Settings.h"

class SettingsWindow {
private:
    static const ButtonColorSet kColorsDisabled;
    static const ButtonColorSet kColorsEnabled;
    static const ButtonColorSet kColorsDefaultBtn;
    static const int kDeltaTime = 15;

    sf::RenderWindow window_;
    sf::Vector2f mouse_pos_;
    bool mouse_pressed_;

    Settings* settings_;

    MultipleButtons text_font_buttons_;
    MultipleButtons difficulty_buttons_;
    ToggleButton font_size_button;
    sf::Text text_sample_;

    sf::Text test_length_label_;
    sf::Text test_length_value_;
    Button test_length_increase_btn_;
    Button test_length_decrease_btn_;

    void Render();

public:
    SettingsWindow() = delete;
    SettingsWindow(Settings& _settings);

    void Show();
};