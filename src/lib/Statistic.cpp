#include "Statistic.h"

Statistic::Statistic(Settings* _settings) {
	this->settings_ = _settings;
}

void Statistic::Restart() {
	clock_.restart();
	this->time_ = 0;
	this->char_count_ = 0;
	this->error_count_ = 0;
}

void Statistic::Count(int _key_code) {
	if (_key_code < 26 && _key_code >= 0) {
		this->char_count_++;
	}
	else if (_key_code == 59) {
		this->char_count_--;
	}
}

void Statistic::TimeUpdate() {
	this->time_ = this->clock_.getElapsedTime().asSeconds();
}

std::string Statistic::ClockFormatString(double _seconds_total) {
	if (_seconds_total <= 0) {
		return std::string("00:00");
	}
	int minutes = (int)_seconds_total / 60;
	int seconds = (int)_seconds_total % 60;

	std::string s = (minutes < 10) ? "0" : "";
	s += to_string(minutes);
	s += ":";
	s += (seconds < 10) ? "0" : "";
	s += to_string(seconds);

	return s;
}

void Statistic::DrawRemainingTime(sf::RenderWindow* _window) {
	sf::Text text;
	text.setFont(this->settings_->GetDefaultFont());
	text.setFillColor(Color::Black);
	text.setPosition(100, 50);
	text.setString("Remaining time " + ClockFormatString(GetRemainingTime()));
	_window->draw(text);
}

void Statistic::Draw(sf::RenderWindow* _window) {
	sf::Text text;
	text.setFont(this->settings_->GetDefaultFont());
	text.setFillColor(Color::Black);
	text.setPosition(1200 / 2 - 50, 600 / 2 - 50);
	text.setString("WPM " + to_string(GetWPM()));
	_window->draw(text);
}

double Statistic::GetRemainingTime() {
	return this->settings_->GetTestLengthInSeconds() - this->time_;
}

bool Statistic::GetTimeState() {
	if (this->time_ > 0) {
		return true;
	}
	return false;
}

int Statistic::GetWPM() {
	if ((int)this->time_ < 1) {
		return 0;
	}
	return (int)(this->char_count_/((this->time_ / 60) * this->kCharNeed));
}

double Statistic::GetTime() {
	return this->time_;
}

