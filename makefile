
CPP = g++
FF = -I src
CPPF = -MMD
CF = -Wall -Wextra -Werror

BUTTON = src/lib/Button.cpp
KEYBOARD = src/lib/Keyboard.cpp
SETTINGS = src/lib/Settings.cpp
MAIN = src/main/main.cpp

COMPILE = obj/lib/main.o obj/lib/Button.o obj/lib/Keyboard.o obj/lib/Settings.o

bin/master: $(COMPILE)
	$(CPP) $(COMPILE) $(SFML) -o $@
obj/lib/main.o: $(MAIN)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(MAIN)
obj/lib/Button.o: $(BUTTON)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(BUTTON)
obj/lib/Keyboard.o: $(KEYBOARD) 
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(KEYBOARD)
obj/lib/Settings.o: $(SETTINGS)
	$(CPP) -c $(FF) $(CF) $(CPPF) -o $@ $(SETTINGS)

-include Keyboard.d Button.d Settings.d main.d
