#include "src/lib/Textbox.h"
#include "thirdparty/ctest.h"

CTEST(model_suite, list_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    temp.LoadList();
    ASSERT_EQUAL(5, temp.GetList().size());
}

CTEST(model_suite, used_str_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    temp.LoadList();
    temp.NewWord();
    ASSERT_TRUE(temp.GetUsedStr().size() > 0);
}

CTEST(model_suite, mp_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    temp.MovePointer(12, false);
    ASSERT_EQUAL(1, temp.GetPointer());
}

CTEST(model_suite, check_cc_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    ASSERT_FALSE(temp.CheckCharCorrect(12, false));
}

CTEST(model_suite, change_cc_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    temp.LoadList();
    temp.NewWord();
    temp.ChangeCharColor(sf::Color(120, 120, 120));
    ASSERT_TRUE(temp.GetUsedStr()[0].color == sf::Color(120, 120, 120));
}

CTEST(model_suite, choose_cc_test)
{
    Settings tmp;
    TextboxModel temp(&tmp);
    temp.LoadList();
    temp.NewWord();
    temp.ChooseCharColor(12, true);
    ASSERT_TRUE(temp.GetUsedStr()[0].color == sf::Color::Red);
}