#include "MainWindow.h"

const ButtonColorSet MainWindow::kColorsSettingsBtn = ButtonColorSet(Color(0x666666FF), Color(0x888888FF), Color(0xAAAAAAFF));

MainWindow::MainWindow() {
	settings_ = new Settings;
	keyboard_ = new VirtualKeyboard(settings_);
	textbox_ = new TextboxView(settings_);
	settings_btn_ = new Button(1000, 50, 150, 50, &this->settings_->GetDefaultFont(), "Settings", this->settings_->kDefaultTextSize, MainWindow::kColorsSettingsBtn);
	statistic_ = new Statistic(settings_);
	mouse_pos_ = Vector2f(-1, -1);
}

MainWindow::~MainWindow() {
	delete keyboard_;
	delete textbox_;
	delete settings_;
	delete window_;
	delete settings_btn_;
}

void MainWindow::Reset() {
	test_ongoing_ = true;
	statistic_->Restart();
}

void MainWindow::Render() {
	window_->clear(sf::Color::White);
	keyboard_->Draw(window_);
	textbox_->Draw(window_);
	statistic_->DrawRemainingTime();
	window_->display();
}

void MainWindow::Show() {
	window_ = new sf::RenderWindow(sf::VideoMode(1200, 600), "Keyboard Ninja", Style::Close);
	while (window_->isOpen()) {
		if (statistic_->GetRemainingTime() <= 0) {
			test_ongoing_ = false;
		}
		sf::Event event;
		while (window_->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window_->close();
			}
			if (event.type == Event::MouseMoved) {
				mouse_pos_ = Vector2f(event.mouseMove.x, event.mouseMove.y);
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter) {
					Reset();
				}
				if (test_ongoing_) {
					keyboard_->ChangePressedKey(event.key.code);
					textbox_->InteractionTextboxModel(event.key.code);
					statistic_->AddCharCount();
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (test_ongoing_) {
					keyboard_->ChangeReleasedKey(event.key.code);
				}
			}
			if (settings_btn_->Update(this->mouse_pos_)) {
				SettingsWindow* settings_window = new SettingsWindow(*this->settings_);
				settings_window->Show();
				delete settings_window;
			}
		}
		if (test_ongoing_) {
			statistic_->TimeUpdate();
			Render();
		}
		else {
			statistic_->Draw(window_);
		}
		settings_btn_->Render(window_)
	}
}
