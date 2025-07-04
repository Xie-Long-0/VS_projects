#include <Windows.h>
#include <QtWidgets/QApplication>
#include "Widget.h"

int main(int argc, char *argv[])
{
    // 设置控制台输出编码为UTF-8
    SetConsoleOutputCP(65001);

    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
