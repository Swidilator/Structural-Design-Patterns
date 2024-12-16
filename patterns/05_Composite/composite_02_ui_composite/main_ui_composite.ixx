//
// Created by kyle on 2024/09/20.
//

module;
#include <iostream>

export module composite.ui_composite.main;


import composite.ui_composite.Frame;
import composite.ui_composite.Button;
import composite.ui_composite.Widget;

namespace composite::ui_composite {

    void Display(Widget* pWidget) {
        pWidget->Paint();
    }


    export auto main_ui_composite() -> void {
        Frame mainWindow{};
        Button btnOk{};
        mainWindow.Add(&btnOk);
        mainWindow.Paint();

        Frame childWindow{};
        Button btnFind{};
        childWindow.Add(&btnFind);

        mainWindow.Add(&childWindow);

        //mainWindow.Paint();

        // std::cout << "Changing visibility\n";
        // mainWindow.SetVisibility(false);
        // mainWindow.Paint();

        Display(&btnOk);
        Display(&mainWindow);

    }
}
