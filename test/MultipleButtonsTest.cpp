#include "src/lib/Buttons/MultipleButtons.h"
#include "thirdparty/ctest.h"

ButtonColorSet kDefaultColorSet = ButtonColorSet(Color::Black, Color::Black, Color::Black);

CTEST(stat_suite_, clock_test) {
	ToggleButton btn0(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
	ToggleButton btn1(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
	MultipleButtons mul_btn;
	mul_btn.AddButton(btn0);
	mul_btn.AddButton(btn1);

    for (size_t i = 0; i < mul_btn.ButtonCount(); i++) {
        ASSERT_FALSE(mul_btn.GetButton(i).IsEnabled());
	}
}

CTEST(stat_suite_, clock_test) {
	ToggleButton btn0(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
	ToggleButton btn1(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
	MultipleButtons mul_btn;
	mul_btn.AddButton(btn0);
	mul_btn.AddButton(btn1);

    for (size_t i = 0; i < mul_btn.ButtonCount(); i++) {
        mul_btn.SetActiveButtonId((int)i);
        ASSERT_EQUAL((int)i, mul_btn.GetActiveButtonId());
        for (size_t j = 0; j < mul_btn.ButtonCount(); j++) {
            ASSERT_EQUAL(i == j, mul_btn.GetButton(j).IsEnabled());
        }
    }
}

CTEST(stat_suite_, clock_test) {
	ToggleButton btn0(0, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
    ToggleButton btn1(200, 0, 100, 100, nullptr, "", "", 1, kDefaultColorSet, kDefaultColorSet, false);
    MultipleButtons mul_btn;
    mul_btn.AddButton(btn0);
    mul_btn.AddButton(btn1);

    ASSERT_FALSE(mul_btn.Update(Vector2f(10, 10), false));
    ASSERT_FALSE(mul_btn.Update(Vector2f(10, 10), true));
    ASSERT_TRUE(mul_btn.Update(Vector2f(10, 10), false));
    ASSERT_EQUAL(0, mul_btn.GetActiveButtonId());

    ASSERT_FALSE(mul_btn.Update(Vector2f(260, 10), false));
    ASSERT_FALSE(mul_btn.Update(Vector2f(260, 10), true));
    ASSERT_TRUE(mul_btn.Update(Vector2f(260, 10), false));
    ASSERT_EQUAL(1, mul_btn.GetActiveButtonId());
}
