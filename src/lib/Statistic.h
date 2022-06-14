#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Statistic {
private:

	Settings* settings_;

	const int kCharNeed = 5;

	Clock clock_;
	double time_;
	int char_count_;
	int error_count_;

public:

	Statistic(Settings* _settings);

	void Restart();
	void AddCharCount();
	void AddErrorCount();
	void TimeUpdate();
	void DrawRemainingTime(sf::RenderWindow* _window);
	void Draw(sf::RenderWindow* _window);

	double GetRemainingTime();
	bool GetTimeState();
	int GetWPM();
	double GetTime();

};