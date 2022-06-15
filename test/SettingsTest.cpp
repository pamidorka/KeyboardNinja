#include "src/lib/Settings.h"
#include "thirdparty/ctest.h"

CTEST(settings_tests, default_constructor) {
	Settings s;
}

CTEST(settings_tests, check_all_three_difficulties) {
	Settings s;
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Easy.txt"));
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Normal.txt"));
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Hard.txt"));
}

CTEST(settings_tests, check_all_three_fonts) {
	Settings s;
    ASSERT_TRUE(s.LoadFont("Roboto-Regular.ttf"));
    ASSERT_TRUE(s.LoadFont("OpenSans-Regular.ttf"));
    ASSERT_TRUE(s.LoadFont("times.ttf"));
}

CTEST(settings_tests, check_default_vocabulary_size) {
	Settings s;
	ASSERT_EQUAL((size_t)200, s.GetVocabularySize());
}

CTEST(settings_tests, check_default_vocabulary_words) {
	Settings s;
    ASSERT_STR("the", s.GetWordAt(0).c_str());
    ASSERT_STR("line", s.GetWordAt(199).c_str());
}

CTEST(settings_tests, change_text_size) {
	Settings s;
    s.SetTextSize(20);
    ASSERT_EQUAL(20u, s.GetTextSize());
	s.SetTextSize(58);
	ASSERT_EQUAL(58u, s.GetTextSize());
}

CTEST(settings_tests, change_test_length) {
	Settings s;
    s.SetTestLengthInSeconds(15);
    ASSERT_EQUAL(15, s.GetTestLengthInSeconds());
	s.SetTestLengthInSeconds(60);
    ASSERT_EQUAL(60, s.GetTestLengthInSeconds());
}

CTEST(settings_tests, change_difficulty_settings_id) {
	Settings s;
    s.SetDifficultySettingsId(1);
    ASSERT_EQUAL(1, s.GetDifficultySettingsId());
    s.SetDifficultySettingsId(2);
    ASSERT_EQUAL(2, s.GetDifficultySettingsId());
}

CTEST(settings_tests, change_font_settings_id) {
	Settings s;
    s.SetFontSettingsId(1);
    ASSERT_EQUAL(1, s.GetFontSettingsId());
    s.SetFontSettingsId(2);
    ASSERT_EQUAL(2, s.GetFontSettingsId());
}

CTEST(settings_tests, change_font_size_settings_val) {
	Settings s;
    s.SetFontSizeSettingsVal(true);
    ASSERT_TRUE(s.GetFontSizeSettingsVal());
}