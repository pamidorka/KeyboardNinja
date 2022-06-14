#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <iostream>
#include <string>
#include <list>

class TextboxModel {
private:

	struct TextChar {
		sf::Color color;
		char character;
	};

	Settings* settings_;

	std::list <std::string> list_string_;
	std::vector <TextChar> used_str_;

	int pointer_;
	double used_window_;

public:

	static const sf::Color kStandartCharColor;

	TextboxModel(Settings* _settings);

	void MovePointer(int _key_code);
	void ChooseCharColor(const int _key);
	void ChangeCharColor(const sf::Color _color);
	void LoadList();
	void NewWord();
	void Restart();

	const std::vector <TextChar>& GetUsedStr();
	const std::list <std::string>& GetList();

};

class TextboxView {
private:

	struct Options {
		double x;
		double y;
	};

	Settings* settings_;
	TextboxModel* model_;

	sf::Font font_;
	Options position_;
	Options size_;


public:

	TextboxView(Settings* _settings);
	~TextboxView();

	void InteractionTextboxModel(int _key_code);
	void Restart();
	void Draw(sf::RenderWindow* _window);
	void SetSize(const double _width, const double _height);
	void SetPosition(const double _width, const double _height);

};
