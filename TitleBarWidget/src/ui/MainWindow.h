#pragma once

#include "xWidgets.h"
#include "ui_MainWindow.h"

class MainWindow : public xWidgets
{
    Q_OBJECT
public:
    explicit MainWindow();

protected:

private:
    Ui::MainWindowClass ui;
};
