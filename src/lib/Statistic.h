#pragma once
#include "Settings.h"
#include <SFML/Graphics.hpp>

class Statistic {
private:
    Settings* settings_;

    const int kCharNeed = 5;

    sf::Clock clock_;
    double time_ = 0;
    int char_count_ = 0;
    int error_count_ = 0;

public:
    Statistic(Settings* _settings);

    void Restart();
    void Count(int _key_code, bool _correct);
    void TimeUpdate();
    void DrawRemainingTime(sf::RenderWindow* _window);
    void Draw(sf::RenderWindow* _window);
    std::string ClockFormatString(double _seconds_total);

    double GetRemainingTime();
    int GetWPM();
    int GetAccuracy();
    double GetTime();
    int GetCharCount();
    int GetErrorCount();
};