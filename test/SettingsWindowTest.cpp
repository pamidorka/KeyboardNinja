#include "src/lib/Windows/SettingsWindow.h"
#include "thirdparty/ctest.h"

CTEST(settings_window_tests, clock_format) {
    ASSERT_STR("00:00", SettingsWindow::ClockFormatString(0).c_str());
	ASSERT_STR("00:05", SettingsWindow::ClockFormatString(5).c_str());
    ASSERT_STR("00:59", SettingsWindow::ClockFormatString(59).c_str());
    ASSERT_STR("01:00", SettingsWindow::ClockFormatString(60).c_str());
    ASSERT_STR("07:30", SettingsWindow::ClockFormatString(450).c_str());
    ASSERT_STR("15:00", SettingsWindow::ClockFormatString(900).c_str());
    ASSERT_STR("90:00", SettingsWindow::ClockFormatString(5400).c_str());
    ASSERT_STR("100:00", SettingsWindow::ClockFormatString(6000).c_str());
}
