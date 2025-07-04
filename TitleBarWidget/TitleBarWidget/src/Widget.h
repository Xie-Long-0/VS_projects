#pragma once

#include <QWidget>
#include "ui_Widget.h"
#include "TitleBar.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::WidgetClass ui;
    XL::TitleBar *m_titleBar = nullptr;
};
