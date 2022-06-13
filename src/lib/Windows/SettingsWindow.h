#pragma once
#include "../Settings.h"
#include "../Buttons/MultipleButtons.h"

class SettingsWindow {
private:
    static const ButtonColorSet kColorsDisabled;
    static const ButtonColorSet kColorsEnabled;
    static const ButtonColorSet kColorsFontSizeBtn;

    RenderWindow window_;
    Vector2f mouse_pos_;

    Settings* settings_;
    
    MultipleButtons text_font_buttons_;
    MultipleButtons difficulty_buttons_;
    ToggleButton font_size_button;
    Text text_sample_;

    void Render();
public:
    SettingsWindow() = delete;
    SettingsWindow(Settings& _settings);

    void Show();
};