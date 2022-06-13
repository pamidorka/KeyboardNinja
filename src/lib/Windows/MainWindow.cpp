#include "MainWindow.h"

const ButtonColorSet MainWindow::kColorsSettingsBtn = ButtonColorSet(Color(0x666666FF), Color(0x888888FF), Color(0xAAAAAAFF));

MainWindow::MainWindow() {
	settings_ = new Settings;
	keyboard_ = new VirtualKeyboard(settings_);
	textbox_ = new TextboxView(settings_);
	settings_btn_ = new Button(50, 50, 150, 60, &this->settings_->GetDefaultFont(), "Settings", this->settings_->kDefaultTextSize, MainWindow::kColorsSettingsBtn);
	mouse_pos_ = Vector2f(-1, -1);
}

MainWindow::~MainWindow() {
	delete keyboard_;
	delete textbox_;
	delete settings_;
	delete window_;
	delete settings_btn_;
}

void MainWindow::Render() {
	window_->clear(sf::Color::White);
	keyboard_->Draw(window_);
	textbox_->Draw(window_);
	settings_btn_->Render(window_);
	window_->display();
}

void MainWindow::Show() {
	window_ = new sf::RenderWindow(sf::VideoMode(1200, 600), "Keyboard Ninja", Style::Close);
	while (window_->isOpen()) {
		sf::Event event;
		while (window_->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window_->close();
			}
			if (event.type == Event::MouseMoved) {
				mouse_pos_ = Vector2f(event.mouseMove.x, event.mouseMove.y);
			}
			if (event.type == sf::Event::KeyPressed) {
				keyboard_->ChangePressedKey(event.key.code);
				textbox_->InteractionTexboxModel(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased) {
				keyboard_->ChangeReleasedKey(event.key.code);
			}
			if (settings_btn_->Update(this->mouse_pos_)) {
				SettingsWindow* settings_window = new SettingsWindow(*this->settings_);
				settings_window->Show();
				delete settings_window;
			}
		}
		Render();
	}
}
