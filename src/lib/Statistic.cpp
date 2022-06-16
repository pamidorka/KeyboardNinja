#include "Statistic.h"

Statistic::Statistic(Settings* _settings)
{
    settings_ = _settings;
}

void Statistic::Restart()
{
    clock_.restart();
    time_ = 0;
    char_count_ = 0;
    error_count_ = 0;
}

void Statistic::Count(int _key_code, bool _correct)
{
    char_count_++;

    if ((_key_code < sf::Keyboard::Num0 && _key_code > sf::Keyboard::Unknown)
        || _key_code == sf::Keyboard::Space) {
        if (!_correct) {
            error_count_++;
        }
    } else if (_key_code == sf::Keyboard::BackSpace) {
        error_count_++;
    }
}

void Statistic::TimeUpdate()
{
    time_ = clock_.getElapsedTime().asSeconds();
}

std::string Statistic::ClockFormatString(double _seconds_total)
{
    if (_seconds_total <= 0) {
        return std::string("00:00");
    }
    int minutes = (int)_seconds_total / 60;
    int seconds = (int)_seconds_total % 60;

    std::string s = (minutes < 10) ? "0" : "";
    s += std::to_string(minutes);
    s += ":";
    s += (seconds < 10) ? "0" : "";
    s += std::to_string(seconds);

    return s;
}

void Statistic::DrawRemainingTime(sf::RenderWindow* _window)
{
    sf::Text text;
    text.setFont(settings_->GetDefaultFont());
    text.setFillColor(sf::Color::Black);
    text.setPosition(100, 50);
    text.setString("Remaining time " + ClockFormatString(GetRemainingTime()));
    _window->draw(text);
}

void Statistic::Draw(sf::RenderWindow* _window)
{
    sf::Text text;
    int x_pos = 1200 / 2 - 100;
    text.setFont(settings_->GetDefaultFont());
    text.setFillColor(sf::Color::Black);
    text.setPosition(x_pos, 600 / 2 - 50);
    text.setString("WPM " + std::to_string(GetWPM()));

    _window->draw(text);

    text.setPosition(x_pos, 600 / 2);
    switch (settings_->GetDifficultySettingsId()) {
    case 0:
        text.setString("Difficulty easy");
        break;
    case 1:
        text.setString("Difficulty normal");
        break;
    case 2:
        text.setString("Difficulty hard");
        break;
    default:
        text.setString("Unknow difficulty");
        break;
    }

    _window->draw(text);

    text.setPosition(x_pos, 600 / 2 + 50);
    text.setString(
            "Testing time "
            + ClockFormatString(settings_->GetTestLengthInSeconds()));

    _window->draw(text);

    text.setPosition(x_pos, 600 / 2 + 100);
    if (char_count_ > 0) {
        text.setString("Accuracy " + std::to_string(GetAccuracy()) + "%");
    } else {
        text.setString("Accuracy 0%");
    }

    _window->draw(text);
}

double Statistic::GetRemainingTime()
{
    return settings_->GetTestLengthInSeconds() - time_;
}

int Statistic::GetWPM()
{
    if ((int)time_ < 1) {
        return 0;
    }
    return (int)((char_count_ - error_count_) / ((time_ / 60) * kCharNeed));
}

int Statistic::GetAccuracy()
{
    return (int)((1 - error_count_ / (double)char_count_) * 100);
}

double Statistic::GetTime()
{
    return time_;
}

int Statistic::GetCharCount()
{
    return char_count_;
}

int Statistic::GetErrorCount()
{
    return error_count_;
}
