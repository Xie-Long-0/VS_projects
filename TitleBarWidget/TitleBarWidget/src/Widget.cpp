#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);

    m_titleBar = new XL::TitleBar(tr("标题"), this);
    m_titleBar->setFixedHeight(32);
    ui.titlebarLayout->addWidget(m_titleBar);
    connect(m_titleBar, &XL::TitleBar::closeEmit, this, &Widget::close);
}

Widget::~Widget()
{
}
