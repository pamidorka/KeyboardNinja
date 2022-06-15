#include "src/lib/Settings.h"
#include "thirdparty/ctest.h"

CTEST(stat_suite_, clock_test) {
	Settings s;
}

CTEST(stat_suite_, count_test_) {
	Settings s;
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Easy.txt"));
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Normal.txt"));
	ASSERT_TRUE(s.LoadVocabularyFromCSV("Hard.txt"));
}

CTEST(stat_suite_, error_test_) {
	Settings s;
    ASSERT_TRUE(s.LoadFont("Roboto-Regular.ttf"));
    ASSERT_TRUE(s.LoadFont("OpenSans-Regular.ttf"));
    ASSERT_TRUE(s.LoadFont("times.ttf"));
}

CTEST(stat_suite_, test_time) {
	Settings s;
	ASSERT_EQUAL((size_t)200, s.GetVocabularySize());
}

CTEST(stat_suite_, accuracy_test) {
	Settings s;
    ASSERT_STR("the", s.GetWordAt(0).c_str());
    ASSERT_STR("line", s.GetWordAt(199).c_str());
}

CTEST(stat_suite_, wpm_test) {
	Settings s;
    s.SetTextSize(20);
    ASSERT_EQUAL(20u, s.GetTextSize());
	s.SetTextSize(58);
	ASSERT_EQUAL(58u, s.GetTextSize());
}

CTEST(stat_suite_, wpm_test) {
	Settings s;
    s.SetTestLengthInSeconds(15);
    ASSERT_EQUAL(15, s.GetTestLengthInSeconds());
	s.SetTestLengthInSeconds(60);
    ASSERT_EQUAL(60, s.GetTestLengthInSeconds());
}

CTEST(stat_suite_, wpm_test) {
	Settings s;
    s.SetDifficultySettingsId(1);
    ASSERT_EQUAL(1, s.GetDifficultySettingsId());
    s.SetDifficultySettingsId(2);
    ASSERT_EQUAL(2, s.GetDifficultySettingsId());
}

CTEST(stat_suite_, wpm_test) {
	Settings s;
    s.SetFontSettingsId(1);
    ASSERT_EQUAL(1, s.GetFontSettingsId());
    s.SetFontSettingsId(2);
    ASSERT_EQUAL(2, s.GetFontSettingsId());
}

CTEST(stat_suite_, wpm_test) {
	Settings s;
    s.SetFontSizeSettingsVal(true);
    ASSERT_TRUE(s.GetFontSizeSettingsVal());
}