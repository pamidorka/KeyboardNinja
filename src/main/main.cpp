#include "lib/Windows/MainWindow.h"

int main() {
    MainWindow* window = new MainWindow;

    window->Show();

    delete window;
    return 0;
}