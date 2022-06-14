#pragma once
#include "lib/Settings.h"
#include "lib/Buttons/MultipleButtons.h"

class SettingsWindow {
private:
    static const ButtonColorSet kColorsDisabled;
    static const ButtonColorSet kColorsEnabled;
    static const ButtonColorSet kColorsDefaultBtn;
    static const int kDeltaTime = 15;

    RenderWindow window_;
    Vector2f mouse_pos_;

    Settings* settings_;
    
    MultipleButtons text_font_buttons_;
    MultipleButtons difficulty_buttons_;
    ToggleButton font_size_button;
    Text text_sample_;

    Text test_length_label_;
    Text test_length_value_;
    Button test_length_increase_btn_;
    Button test_length_decrease_btn_;

    string ClockFormatString(int _seconds);
    void Render();
public:
    SettingsWindow() = delete;
    SettingsWindow(Settings& _settings);

    void Show();
};