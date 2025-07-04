#include "TitleBar.h"
#include "ui_TitleBar.h"
#include <QStyleOption>
#include <QPainter>


XL::TitleBar::TitleBar(QWidget *parent, Flags flags)
    : QWidget(parent)
    , m_flags(flags)
    , ui(new Ui::TitleBarClass())
{
    ui->setupUi(this);
    init();
}

XL::TitleBar::TitleBar(const QString &title, QWidget *parent, Flags flags)
    : QWidget(parent)
    , m_flags(flags)
    , ui(new Ui::TitleBarClass())
{
    ui->setupUi(this);
    init();

    setTitle(title);
}

XL::TitleBar::~TitleBar()
{
    delete ui;
}

void XL::TitleBar::init()
{
    if (window()->isMaximized())
        ui->maximize_button->setObjectName("restore_button");
    else
        ui->maximize_button->setObjectName("maximize_button");

    connect(ui->minimize_button, &QPushButton::clicked, this, &TitleBar::onMinimizeBtnClicked);
    connect(ui->maximize_button, &QPushButton::clicked, this, &TitleBar::onMaximizeBtnClicked);
    connect(ui->close_button, &QPushButton::clicked, this, &TitleBar::onCloseBtnClicked);
}

void XL::TitleBar::setIcon(const QPixmap &img)
{
    ui->icon_label->setPixmap(img);
}

void XL::TitleBar::onMinimizeBtnClicked()
{
    window()->showMinimized();
}

void XL::TitleBar::onMaximizeBtnClicked()
{
    if (window()->isMaximized())
    {
        window()->showNormal();
        ui->maximize_button->setObjectName("maximize_button");
    }
    else
    {
        window()->showMaximized();
        ui->maximize_button->setObjectName("restore_button");
    }
}

void XL::TitleBar::onCloseBtnClicked()
{
    emit closeEmit();
}

void XL::TitleBar::setTitle(const QString &text)
{
    ui->title_label->setText(text);
}

void XL::TitleBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void XL::TitleBar::mousePressEvent(QMouseEvent *e)
{
}

void XL::TitleBar::mouseReleaseEvent(QMouseEvent *e)
{
}

void XL::TitleBar::mouseMoveEvent(QMouseEvent *e)
{
}
