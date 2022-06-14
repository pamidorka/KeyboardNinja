#include "lib/Windows/MainWindow.h"

int main() {
    srand(time(NULL));
    MainWindow* window = new MainWindow;

    window->Show();

    delete window;
    return 0;
}