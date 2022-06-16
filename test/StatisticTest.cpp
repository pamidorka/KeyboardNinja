#include "src/lib/Statistic.h"
#include "thirdparty/ctest.h"

CTEST(stat_suite_, clock_test)
{
    Settings tmp;
    Statistic temp(&tmp);
    std::string s = temp.ClockFormatString(10);
    ASSERT_STR("00:10", s.c_str());
}

CTEST(stat_suite_, count_test_)
{
    Settings tmp;
    Statistic temp(&tmp);
    temp.Count(12, true);
    ASSERT_EQUAL(1, temp.GetCharCount());
}

CTEST(stat_suite_, error_test_)
{
    Settings tmp;
    Statistic temp(&tmp);
    temp.Count(12, false);
    ASSERT_EQUAL(1, temp.GetErrorCount());
}

CTEST(stat_suite_, test_time)
{
    Settings tmp;
    Statistic temp(&tmp);
    ASSERT_EQUAL(30, temp.GetRemainingTime());
}

CTEST(stat_suite_, accuracy_test)
{
    Settings tmp;
    Statistic temp(&tmp);
    temp.Count(12, true);
    ASSERT_EQUAL(100, temp.GetAccuracy());
}

CTEST(stat_suite_, wpm_test)
{
    Settings tmp;
    Statistic temp(&tmp);
    temp.Count(12, true);
    temp.TimeUpdate();
    ASSERT_EQUAL(0, temp.GetWPM());
}

CTEST(stat_suite_, time_upd_test)
{
    Settings tmp;
    Statistic temp(&tmp);
    temp.TimeUpdate();
    ASSERT_DBL_NEAR(0, temp.GetTime());
}
