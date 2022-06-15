
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

COMPILE = obj/main/main.o obj/lib/VirtualButton.o obj/lib/Keyboard.o obj/lib/Settings.o obj/lib/Textbox.o obj/lib/MainWindow.o obj/lib/SettingsWindow.o obj/lib/Button.o obj/lib/MultipleButtons.o obj/lib/ToggleButton.o obj/lib/Statistic.o

bin/master: $(COMPILE) $(SFML)
	$(CPP) $(COMPILE) $(SFML) -o $@
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

-include Keyboard.d Button.d Settings.d main.d MainWindow.d SettingsWindow.d Button.d MultipleButtons.d ToggleButton.d Statistic.d

FF_TEST = -I ./

MAIN_TEST = test/TestMain.cpp
TEXTBOX_TEST = test/TextboxTest.cpp
STATISTIC_TEST = test/StatisticTest.cpp
KEYBOARD_TEST = test/KeyboardTest.cpp

COMPILE_TEST = obj/test/main/TestMain.o obj/test/lib/TextboxTest.o obj/test/lib/StatisticTest.o  obj/lib/Statistic.o obj/lib/Textbox.o obj/lib/VirtualButton.o obj/lib/Keyboard.o obj/lib/MainWindow.o obj/lib/SettingsWindow.o obj/lib/Button.o obj/lib/ToggleButton.o obj/lib/MultipleButtons.o obj/lib/Settings.o obj/test/lib/KeyboardTest.o

bin/utest: $(COMPILE_TEST) $(SFML)
	$(CPP) $(COMPILE_TEST) $(SFML) -o $@ 
obj/test/main/TestMain.o: $(MAIN_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(MAIN_TEST)
obj/test/lib/TextboxTest.o: $(TEXTBOX_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(TEXTBOX_TEST)
obj/test/lib/StatisticTest.o: $(STATISTIC_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(STATISTIC_TEST)
obj/test/lib/KeyboardTest.o: $(KEYBOARD_TEST) $(SFML)
	$(CPP) -c $(FF_TEST) $(CF) $(CPPF) -o $@ $(KEYBOARD_TEST)


-include TestMain.d TextboxTest.d StatisticTest.d KeyboardTest.d