#include "src/lib/Buttons/ToggleButton.h"
#include "thirdparty/ctest.h"

ButtonColorSet kTBColorSet
        = ButtonColorSet(sf::Color::Black, sf::Color::Black, sf::Color::Black);

CTEST(toggle_button_tests, default_state)
{
    ToggleButton btn(
            0, 0, 100, 100, nullptr, "", "", 1, kTBColorSet, kTBColorSet);
    ASSERT_FALSE(btn.IsEnabled());
}

CTEST(toggle_button_tests, toggle_direct)
{
    ToggleButton btn(
            0, 0, 100, 100, nullptr, "", "", 1, kTBColorSet, kTBColorSet);

    btn.Toggle(true);
    ASSERT_TRUE(btn.IsEnabled());
    btn.Toggle(false);
    ASSERT_FALSE(btn.IsEnabled());
}

CTEST(toggle_button_tests, toggle_by_clicking)
{
    ToggleButton btn(
            0, 0, 100, 100, nullptr, "", "", 1, kTBColorSet, kTBColorSet);

    ASSERT_FALSE(btn.Update(sf::Vector2f(10, 10), false));
    ASSERT_FALSE(btn.Update(sf::Vector2f(10, 10), true));
    ASSERT_TRUE(btn.Update(sf::Vector2f(10, 10), false));
    ASSERT_TRUE(btn.IsEnabled());

    ASSERT_FALSE(btn.Update(sf::Vector2f(10, 10), false));
    ASSERT_FALSE(btn.Update(sf::Vector2f(10, 10), true));
    ASSERT_TRUE(btn.Update(sf::Vector2f(10, 10), false));
    ASSERT_FALSE(btn.IsEnabled());
}
