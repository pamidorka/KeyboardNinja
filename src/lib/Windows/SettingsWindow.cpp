#include "SettingsWindow.h"

const ButtonColorSet SettingsWindow::kColorsDisabled = ButtonColorSet(sf::Color(0x660000FF), sf::Color(0xAA3333FF), sf::Color(0xFF5555FF));
const ButtonColorSet SettingsWindow::kColorsEnabled = ButtonColorSet(sf::Color(0x006600FF), sf::Color(0x119911FF), sf::Color(0x22BB22FF));
const ButtonColorSet SettingsWindow::kColorsDefaultBtn = ButtonColorSet(sf::Color(0x666666FF), sf::Color(0x888888FF), sf::Color(0xAAAAAAFF));

SettingsWindow::SettingsWindow(Settings& _settings) : mouse_pos_(sf::Vector2f(-1, -1)), mouse_pressed_(false), settings_(&_settings),
font_size_button(290, 50, 80, 60, &settings_->GetDefaultFont(), std::to_string(settings_->kDefaultTextSize + 8), std::to_string(settings_->kDefaultTextSize), settings_->kDefaultTextSize, kColorsDefaultBtn, kColorsDefaultBtn),
test_length_increase_btn_(270, 350, 30, 15, &settings_->GetDefaultFont(), "", 12, kColorsDefaultBtn),
test_length_decrease_btn_(270, 367, 30, 15, &settings_->GetDefaultFont(), "", 12, kColorsDefaultBtn) {

    ToggleButton roboto_font_btn(50, 50, 220, 60, &settings_->GetDefaultFont(), "Roboto", "Roboto", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    ToggleButton open_sans_font_btn(50, 120, 220, 60, &settings_->GetDefaultFont(), "Open Sans", "Open Sans", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    ToggleButton times_new_roman_font_btn(50, 190, 220, 60, &settings_->GetDefaultFont(), "Times New Roman", "Times New Roman", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    text_font_buttons_.AddButton(roboto_font_btn);
    text_font_buttons_.AddButton(open_sans_font_btn);
    text_font_buttons_.AddButton(times_new_roman_font_btn);

    text_sample_.setPosition(290, 150);
    text_sample_.setFillColor(sf::Color::Black);
    text_sample_.setString("Text Sample");
    text_sample_.setFont(settings_->GetFont());
    text_sample_.setCharacterSize(settings_->GetTextSize());

    ToggleButton easy_diff_btn(50, 280, 150, 60, &settings_->GetDefaultFont(), "Easy", "Easy", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    ToggleButton normal_diff_btn(220, 280, 150, 60, &settings_->GetDefaultFont(), "Normal", "Normal", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    ToggleButton hard_diff_btn(390, 280, 150, 60, &settings_->GetDefaultFont(), "Hard", "Hard", settings_->kDefaultTextSize, kColorsEnabled, kColorsDisabled);
    difficulty_buttons_.AddButton(easy_diff_btn);
    difficulty_buttons_.AddButton(normal_diff_btn);
    difficulty_buttons_.AddButton(hard_diff_btn);

    test_length_label_.setPosition(50, 350);
    test_length_label_.setFillColor(sf::Color::Black);
    test_length_label_.setString("Test length:");
    test_length_label_.setFont(settings_->GetDefaultFont());
    test_length_label_.setCharacterSize(settings_->kDefaultTextSize);

    test_length_value_.setPosition(200, 350);
    test_length_value_.setFillColor(sf::Color::Black);
    test_length_value_.setString(ClockFormatString(settings_->GetTestLengthInSeconds()));
    test_length_value_.setFont(settings_->GetDefaultFont());
    test_length_value_.setCharacterSize(settings_->kDefaultTextSize);
}

void SettingsWindow::Show() {
    window_.create(sf::VideoMode(600, 430), "Settings", sf::Style::Close);

    difficulty_buttons_.SetActiveButtonId(settings_->GetDifficultySettingsId());
    text_font_buttons_.SetActiveButtonId(settings_->GetFontSettingsId());
    font_size_button.Toggle(settings_->GetFontSizeSettingsVal());

    Render();
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
                break;
            }
            else if (event.type == sf::Event::MouseMoved) {
                mouse_pos_ = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mouse_pressed_ = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                mouse_pressed_ = false;
            }

            if (difficulty_buttons_.Update(mouse_pos_, mouse_pressed_)) {
                int difficulty_btn_id = difficulty_buttons_.GetActiveButtonId();
                switch (difficulty_btn_id) {
                case 0:
                    settings_->LoadVocabularyFromCSV("Easy.txt");
                    break;
                case 1:
                    settings_->LoadVocabularyFromCSV("Normal.txt");
                    break;
                case 2:
                    settings_->LoadVocabularyFromCSV("Hard.txt");
                    break;
                }
                settings_->SetDifficultySettingsId(difficulty_btn_id);
            }
            if (text_font_buttons_.Update(mouse_pos_, mouse_pressed_)) {
                int font_btn_id = text_font_buttons_.GetActiveButtonId();
                switch (font_btn_id) {
                case 0:
                    settings_->LoadFont("Roboto-Regular.ttf");
                    break;
                case 1:
                    settings_->LoadFont("OpenSans-Regular.ttf");
                    break;
                case 2:
                    settings_->LoadFont("times.ttf");
                    break;
                }
                settings_->SetFontSettingsId(font_btn_id);

                text_sample_.setFont(settings_->GetFont());
            }
            if (font_size_button.Update(mouse_pos_, mouse_pressed_)) {
                bool font_size_btn_val = font_size_button.IsEnabled();
                settings_->SetTextSize(font_size_btn_val ? Settings::kDefaultTextSize + 8 : Settings::kDefaultTextSize);
                settings_->SetFontSizeSettingsVal(font_size_btn_val);

                text_sample_.setCharacterSize(settings_->GetTextSize());
            }
            if (test_length_increase_btn_.Update(mouse_pos_, mouse_pressed_)) {
                int new_length = std::min(settings_->GetTestLengthInSeconds() + kDeltaTime, 30 * 60);
                settings_->SetTestLengthInSeconds(new_length);
                test_length_value_.setString(ClockFormatString(settings_->GetTestLengthInSeconds()));
            }
            if (test_length_decrease_btn_.Update(mouse_pos_, mouse_pressed_)) {
                int new_length = std::max(settings_->GetTestLengthInSeconds() - kDeltaTime, 15);
                settings_->SetTestLengthInSeconds(new_length);
                test_length_value_.setString(ClockFormatString(settings_->GetTestLengthInSeconds()));
            }

            Render();
        }
    }
}

std::string SettingsWindow::ClockFormatString(int _seconds_total) {
    int minutes = _seconds_total / 60;
    int seconds = _seconds_total % 60;

    std::string s = (minutes < 10) ? "0" : "";
    s += std::to_string(minutes);
    s += ":";
    s += (seconds < 10) ? "0" : "";
    s += std::to_string(seconds);

    return s;
}

void SettingsWindow::Render() {
    window_.clear(sf::Color::White);

    window_.draw(text_sample_);
    difficulty_buttons_.Render(&window_);
    font_size_button.Render(&window_);
    text_font_buttons_.Render(&window_);

    window_.draw(test_length_label_);
    window_.draw(test_length_value_);
    test_length_increase_btn_.Render(&window_);
    test_length_decrease_btn_.Render(&window_);

    window_.display();
}