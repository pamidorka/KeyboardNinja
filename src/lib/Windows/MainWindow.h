#pragma once
#include "lib/Keyboard.h"
#include "lib/Statistic.h"
#include "lib/Textbox.h"
#include "lib/Windows/SettingsWindow.h"
#include <SFML/Graphics.hpp>

class MainWindow {
private:
    enum class TestState { WAITING, TESTING, RESULT };

    sf::RenderWindow* window_;
    sf::Vector2f mouse_pos_;
    bool mouse_pressed_;

    Settings* settings_;
    VirtualKeyboard* keyboard_;
    TextboxView* textbox_;
    Button* settings_btn_;
    Statistic* statistic_;

    bool shift_pressed_ = false;
    TestState state_;

    static const ButtonColorSet kColorsSettingsBtn;

    void Render();
    void RenderResult();
    void Reset();

public:
    MainWindow();
    ~MainWindow();

    void Show();
};