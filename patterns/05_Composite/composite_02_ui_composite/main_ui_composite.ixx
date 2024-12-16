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
        //pWidget->Paint();

        if (auto pFrame = pWidget->GetFrame(); pFrame != nullptr) {
            pWidget->Add(new Button{});
        } else {
            std::cout << "Cannot add a child\n";
        }

        if (auto pFrame = pWidget->GetParent(); pFrame != nullptr) {
            pFrame->Paint();
        } else {
            std::cout << "No parent\n";
        }
    }


    export auto main_ui_composite() -> void {
        Frame *mainWindow = new Frame{};
        Button *btnOk = new Button{};
        mainWindow->Add(btnOk);
        //mainWindow->Paint();


        mainWindow->Remove(btnOk);
        Frame *childWindow = new Frame{};
        Button *btnFind = new Button{};
        childWindow->Add(btnFind);

        mainWindow->Add(childWindow);

        //mainWindow.Paint();

        // std::cout << "Changing visibility\n";
        // mainWindow.SetVisibility(false);
        // mainWindow.Paint();

        std::cout << "Operating on button\n";
        Display(btnOk);

        std::cout << "\n\nOperating on frame\n";
        Display(mainWindow);

        // Delete objects that don't have a parent that would delete it automatically
        delete btnOk;
        delete mainWindow;

        // Would work on windows
        //_CrtDumpMemoryLeaks();
    }
}
