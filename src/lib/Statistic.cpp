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

void Statistic::AddCharCount() {
	this->char_count_++;
}

void Statistic::AddErrorCount() {
	this->error_count_++;
}

void Statistic::TimeUpdate() {
	this->time_ = this->clock_.getElapsedTime().asSeconds();
}

void Statistic::DrawRemainingTime(sf::RenderWindow* _window) {
	sf::Text text;
	text.setFont(this->settings_->GetDefaultFont());
	text.setFillColor(Color::Black);
	text.setPosition(100, 50);
	text.setString("Remaining time " + to_string(this->settings_->GetTestLengthInSeconds() - this->time_));
	_window->draw(text);
}

void Statistic::Draw(sf::RenderWindow* _window) {
	sf::Text text;
	text.setFont(this->settings_->GetDefaultFont());
	text.setFillColor(Color::Black);
	text.setPosition(1200 / 2, 600 / 2);
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

	return (int)(this->char_count_/(this->time_ * this->kCharNeed));
}

double Statistic::GetTime() {
	return this->time_;
}

