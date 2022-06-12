#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <iostream>
#include <exception>
#include <string>
#include <list>
#include <time.h>

class TextboxModel {
private:

	struct TextChar {
		sf::Color color;
		char character;
	};

	Settings* settings_;

	std::list <std::string> list_string_;
	std::vector <TextChar> used_str_;

	int mistakes_count_;
	int press_count_;
	int pointer_;
	double used_window_;

public:

	TextboxModel(Settings* _settings);

	void MovePointer(int _key_code);
	void ChooseCharColor(const int _key);
	void ChangeCharColor(const sf::Color _color);
	void LoadList();
	void NewWord();

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

	void InteractionTexboxModel(int _key_code);
	void Draw(sf::RenderWindow* _window);
	void SetSize(const double _width, const double _height);
	void SetPosition(const double _width, const double _height);

};

//class Textbox {
//private:
//	
//	struct Position {
//		double x;
//		double y;
//	};
//
//	struct TextChar {
//		sf::Color color;
//		char character;
//	};
//
//	std::vector <TextChar> used_str_;
//	Position position_;
//	Position textbox_size_;
//	sf::Font textbox_font_;
//	std::string string_;
//	std::list <std::string> list_string_;
//	int mistakes_count_;
//	int press_count_;
//	int pointer_;
//	double used_window_textbox_;
//	Settings* settings_;
//	size_t size_of_character_;
//
//	void StringToVector(std::string _string);
//	void ChooseCharColor(const int _key);
//	void ChangeCharColor(const sf::Color _color);
//	void FinishWord();
//	void UpdateList();
//	double SizeLineFont(std::string _string);
//
//public:
//
//	Textbox(Settings* settings);
//
//	void MovePointer(int _key_code);
//	void Draw(sf::RenderWindow* _window);
//	void SetSize(const double _width, const double _height);
//	void SetPosition(const double _width, const double _height);
//
//};