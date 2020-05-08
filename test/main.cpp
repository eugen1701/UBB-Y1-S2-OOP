#include "Repository.h"
#include "UI.h"
#include <iostream>

int main() {
    Repository repo{};
    UI ui{repo};
    ui.run();
    return 0;
}
