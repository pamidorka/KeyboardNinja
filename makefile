
CPP = g++
FF = -I src
CPPF = -MMD
CF = -Wall -Wextra -Werror

VIRTUALBUTTON = src/lib/VirtualButton.cpp
KEYBOARD = src/lib/Keyboard.cpp
SETTINGS = src/lib/Settings.cpp
TEXTBOX = src/lib/Textbox.cpp
MAINWINDOW = src/lib/Windows/MainWindow.cpp
SETTINGSWINDOW = src/lib/Windows/SettingsWindow.cpp
BUTTON = src/lib/Buttons/Button.cpp
TOGGLEBUTTON = src/lib/Buttons/ToggleButton.cpp
MULTIPLEBUTTONS = src/lib/Buttons/MultipleButtons.cpp
STATISTIC = src/lib/Statistic.cpp

MAIN = src/main/main.cpp

SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = obj/lib/VirtualButton.o obj/lib/Keyboard.o obj/lib/Settings.o obj/lib/Textbox.o obj/lib/MainWindow.o obj/lib/SettingsWindow.o obj/lib/Button.o obj/lib/MultipleButtons.o obj/lib/ToggleButton.o obj/lib/Statistic.o

MAIN_COMPILE = obj/main/main.o

bin/master: $(COMPILE) $(MAIN_COMPILE) $(SFML)
	$(CPP) $(COMPILE) $(MAIN_COMPILE) $(SFML) -o $@
obj/main/main.o: $(MAIN) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(MAIN)
obj/lib/VirtualButton.o: $(VIRTUALBUTTON) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(VIRTUALBUTTON)
obj/lib/Keyboard.o: $(KEYBOARD) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(KEYBOARD)
obj/lib/Settings.o: $(SETTINGS) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(SETTINGS)
obj/lib/Textbox.o: $(TEXTBOX) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(TEXTBOX)
obj/lib/MainWindow.o: $(MAINWINDOW) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(MAINWINDOW)
obj/lib/SettingsWindow.o: $(SETTINGSWINDOW) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(SETTINGSWINDOW)
obj/lib/Button.o: $(BUTTON) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(BUTTON)
obj/lib/ToggleButton.o: $(TOGGLEBUTTON) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(TOGGLEBUTTON)
obj/lib/MultipleButtons.o: $(MULTIPLEBUTTONS) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(MULTIPLEBUTTONS)
obj/lib/Statistic.o: $(STATISTIC) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(STATISTIC)

-include main.d Keyboard.d Button.d Settings.d MainWindow.d SettingsWindow.d Button.d MultipleButtons.d ToggleButton.d Statistic.d

FF_TEST = -I ./ -I ./src

MAIN_TEST = test/TestMain.cpp
TEXTBOX_TEST = test/TextboxTest.cpp
STATISTIC_TEST = test/StatisticTest.cpp
KEYBOARD_TEST = test/KeyboardTest.cpp
SETTINGS_TEST = test/SettingsTest.cpp
BUTTON_TEST = test/ButtonTest.cpp
TOGGLEBUTTON_TEST = test/ToggleButtonTest.cpp
MULTIPLEBUTTONS_TEST = test/MultipleButtonsTest.cpp

COMPILE_TEST = obj/test/main/TestMain.o obj/test/lib/TextboxTest.o obj/test/lib/StatisticTest.o obj/test/lib/KeyboardTest.o obj/test/lib/SettingsTest.o obj/test/lib/ButtonTest.o obj/test/lib/ToggleButtonTest.o obj/test/lib/MultipleButtonsTest.o

bin/utest: $(COMPILE_TEST) $(SFML)
	$(CPP) $(COMPILE) $(COMPILE_TEST) $(SFML) -o $@ 
obj/test/main/TestMain.o: $(MAIN_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(MAIN_TEST)
obj/test/lib/TextboxTest.o: $(TEXTBOX_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(TEXTBOX_TEST)
obj/test/lib/StatisticTest.o: $(STATISTIC_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(STATISTIC_TEST)
obj/test/lib/KeyboardTest.o: $(KEYBOARD_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(KEYBOARD_TEST)
obj/test/lib/SettingsTest.o: $(SETTINGS_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(SETTINGS_TEST)
obj/test/lib/ButtonTest.o: $(BUTTON_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(BUTTON_TEST)
obj/test/lib/ToggleButtonTest.o: $(TOGGLEBUTTON_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(TOGGLEBUTTON_TEST)
obj/test/lib/MultipleButtonsTest.o: $(MULTIPLEBUTTONS_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(MULTIPLEBUTTONS_TEST)


-include TestMain.d TextboxTest.d StatisticTest.d KeyboardTest.d SettingsTest.d ButtonTest.d ToggleButtonTest.d MultipleButtonsTest.d