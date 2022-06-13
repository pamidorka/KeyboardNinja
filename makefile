
CPP = g++
FF = -I src
CPPF = -MMD
CF = -Wall -Wextra -Werror

BUTTON = src/lib/VirtualButton.cpp
KEYBOARD = src/lib/Keyboard.cpp
SETTINGS = src/lib/Settings.cpp
TEXTBOX = src/lib/Textbox.cpp

MAIN = src/main/main.cpp

SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = obj/main/main.o obj/lib/VirtualButton.o obj/lib/Keyboard.o obj/lib/Settings.o obj/lib/Textbox.o

bin/master: $(COMPILE) $(SFML)
	$(CPP) $(COMPILE) $(SFML) -o $@
obj/main/main.o: $(MAIN) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(MAIN)
obj/lib/VirtualButton.o: $(BUTTON) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(BUTTON)
obj/lib/Keyboard.o: $(KEYBOARD) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(KEYBOARD)
obj/lib/Settings.o: $(SETTINGS) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(SETTINGS)
obj/lib/Textbox.o: $(TEXTBOX) $(SFML)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(TEXTBOX)

-include Keyboard.d Button.d Settings.d main.d
