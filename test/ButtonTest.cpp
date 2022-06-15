#include "src/lib/Buttons/Button.h"
#include "thirdparty/ctest.h"

ButtonColorSet kDefaultColorSet = ButtonColorSet(Color::Black, Color::Black, Color::Black);

CTEST(stat_suite_, clock_test) {
    Button btn(30, 30, 20, 20, nullptr, "", 1, kDefaultColorSet);

    ASSERT_TRUE(btn.IsMouseHover(Vector2f(40, 40)));
    ASSERT_TRUE(btn.IsMouseHover(Vector2f(48, 32)));
    ASSERT_FALSE(btn.IsMouseHover(Vector2f(15, 40)))
    ASSERT_FALSE(btn.IsMouseHover(Vector2f(35, 5)))
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);

    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonIdle);
    ASSERT_FALSE(btn.Update(Vector2f(500, 500), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonIdle);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
    ASSERT_FALSE(btn.Update(Vector2f(500, 500), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonIdle);
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);

    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHoverActive);
    ASSERT_TRUE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);

    ASSERT_FALSE(btn.Update(Vector2f(500, 500), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonIdle);
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);
    
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHoverInactive);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);
    
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHoverActive);
    ASSERT_FALSE(btn.Update(Vector2f(500, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonUnhoverActive);
    ASSERT_FALSE(btn.Update(Vector2f(500, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonIdle);
}

CTEST(stat_suite_, clock_test) {
	Button btn(0, 0, 100, 100, nullptr, "", 1, kDefaultColorSet);
    
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHover);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHoverActive);
    ASSERT_FALSE(btn.Update(Vector2f(500, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonUnhoverActive);
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.GetButtonState() == ButtonStates::ButtonHoverActive);
}
