#include "src/lib/Buttons/ToggleButton.h"
#include "thirdparty/ctest.h"

ButtonColorSet kDefaultColorSet = ButtonColorSet(Color::Black, Color::Black, Color::Black);

CTEST(stat_suite_, clock_test) {
	ToggleButton btn(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet);
    ASSERT_FALSE(btn.IsEnabled());
}

CTEST(stat_suite_, clock_test) {
	ToggleButton btn(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet);

    btn.Toggle(true);
    ASSERT_TRUE(btn.IsEnabled())
    btn.Toggle(false);
    ASSERT_FALSE(btn.IsEnabled())
}

CTEST(stat_suite_, clock_test) {
	ToggleButton btn(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet);

    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.Update(Vector2f(10, 10), false));
    ASSERT_TRUE(btn.IsEnabled());

    ASSERT_FALSE(btn.Update(Vector2f(10, 10), false));
    ASSERT_FALSE(btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(btn.Update(Vector2f(10, 10), false));
    ASSERT_FALSE(btn.IsEnabled());
}
