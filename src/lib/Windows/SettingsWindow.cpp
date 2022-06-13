#include "SettingsWindow.h"

const ButtonColorSet SettingsWindow::kColorsDisabled = ButtonColorSet(Color(0x660000FF), Color(0xAA3333FF), Color(0xFF5555FF));
const ButtonColorSet SettingsWindow::kColorsEnabled = ButtonColorSet(Color(0x006600FF), Color(0x119911FF), Color(0x22BB22FF));
const ButtonColorSet SettingsWindow::kColorsFontSizeBtn = ButtonColorSet(Color(0x666666FF), Color(0x888888FF), Color(0xAAAAAAFF));

SettingsWindow::SettingsWindow(Settings& _settings) : settings_(&_settings),
    font_size_button(290, 50, 80, 60, &settings_->GetDefaultFont(), to_string(Settings::kDefaultTextSize + 8), to_string(Settings::kDefaultTextSize), Settings::kDefaultTextSize, kColorsFontSizeBtn, kColorsFontSizeBtn) {
    ToggleButton roboto_font_btn(50, 50, 220, 60, &settings_->GetDefaultFont(), "Roboto", "Roboto", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    ToggleButton open_sans_font_btn(50, 120, 220, 60, &settings_->GetDefaultFont(), "Open Sans", "Open Sans", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    ToggleButton times_new_roman_font_btn(50, 190, 220, 60, &settings_->GetDefaultFont(), "Times New Roman", "Times New Roman", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    text_font_buttons_.AddButton(roboto_font_btn);
    text_font_buttons_.AddButton(open_sans_font_btn);
    text_font_buttons_.AddButton(times_new_roman_font_btn);

    text_sample_.setPosition(290, 150);
    text_sample_.setFillColor(Color::Black);
    text_sample_.setString("Text Sample");
    
    ToggleButton easy_diff_btn(50, 280, 150, 60, &settings_->GetDefaultFont(), "Easy", "Easy", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    ToggleButton normal_diff_btn(220, 280, 150, 60, &settings_->GetDefaultFont(), "Normal", "Normal", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    ToggleButton hard_diff_btn(390, 280, 150, 60, &settings_->GetDefaultFont(), "Hard", "Hard", settings_->GetTextSize(), kColorsEnabled, kColorsDisabled);
    difficulty_buttons_.AddButton(easy_diff_btn);
    difficulty_buttons_.AddButton(normal_diff_btn);
    difficulty_buttons_.AddButton(hard_diff_btn);

    mouse_pos_ = Vector2f(-1, -1);
    settings_ = &_settings;
}

void SettingsWindow::Show() {
    window_.create(VideoMode(600, 400), "Settings", Style::Close);

    settings_->LoadFont(settings_->kDefaultFontFileName);
    text_font_buttons_.SetActiveButtonId(0);

    settings_->LoadVocabularyFromCSV(settings_->kDefaultVocabularyFileName);
    difficulty_buttons_.SetActiveButtonId(0);

    while (window_.isOpen()) {
        Event event;
        while (window_.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window_.close();
                break;
            }
            else if (event.type == Event::MouseMoved) {
                mouse_pos_ = Vector2f(event.mouseMove.x, event.mouseMove.y);
            }
            
            if (difficulty_buttons_.Update(mouse_pos_)) {
                switch (difficulty_buttons_.GetActiveButtonId()) {
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
            }
            if (text_font_buttons_.Update(mouse_pos_)) {
                switch (text_font_buttons_.GetActiveButtonId()) {
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
            }
            if (font_size_button.Update(mouse_pos_)) {
                settings_->SetTextSize(font_size_button.IsEnabled() ? Settings::kDefaultTextSize + 8 : Settings::kDefaultTextSize);
            }

            text_sample_.setFont(settings_->GetFont());
            text_sample_.setCharacterSize(settings_->GetTextSize());

            window_.clear(Color::White);
            Render();
            window_.display();
        }
    }
}

void SettingsWindow::Render() {
    window_.draw(text_sample_);
    difficulty_buttons_.Render(&window_);
    font_size_button.Render(&window_);
    text_font_buttons_.Render(&window_);
}