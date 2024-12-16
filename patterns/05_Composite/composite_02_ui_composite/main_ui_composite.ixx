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
    void Display(Widget *pWidget) {
        pWidget->Paint();

        auto pFrame = pWidget->GetFrame();
        if (pFrame) {
            pWidget->Add(new Button{});
        } else {
            std::cout << "Cannot add a child\n";
        }
    }


    export auto main_ui_composite() -> void {
        Frame *mainWindow = new Frame{};
        Button *btnOk = new Button{};
        mainWindow->Add(btnOk);
        mainWindow->Paint();

        Frame *childWindow = new Frame{};
        Button *btnFind = new Button{};
        childWindow->Add(btnFind);

        mainWindow->Add(childWindow);

        //mainWindow.Paint();

        // std::cout << "Changing visibility\n";
        // mainWindow.SetVisibility(false);
        // mainWindow.Paint();

        Display(btnOk);
        Display(mainWindow);

        delete mainWindow;

        // Would work on windows
        //_CrtDumpMemoryLeaks();
    }
}
