#include "src/lib/Keyboard.h"
#include "thirdparty/ctest.h"

CTEST(keyboard_suite, cpk_test)
{
    Settings tmp;
    VirtualKeyboard temp(&tmp);
    temp.ChangePressedKey(12);
    ASSERT_TRUE(
            temp.GetButtons()[12].GetColor() == sf::Color::Black
            && temp.GetButtons()[12].GetCharacterColor() == sf::Color::White);
}

CTEST(keyboard_suite, crk_test)
{
    Settings tmp;
    VirtualKeyboard temp(&tmp);
    temp.ChangeReleasedKey(12);
    ASSERT_TRUE(
            temp.GetButtons()[12].GetColor() == sf::Color::White
            && temp.GetButtons()[12].GetCharacterColor() == sf::Color::Black);
}