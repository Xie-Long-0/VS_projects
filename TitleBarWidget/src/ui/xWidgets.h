#pragma once

#include <qwidget.h>
#include "ui_xWidgets.h"

/**
 * @brief 注意：继承此窗口后在子类构造函数的UI初始化代码部分需要将
 * ui.setupUi(this); 修改为ui.setupUi(m_centralWidget);
*/
class xWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit xWidgets();
    ~xWidgets();

    void onMin();
    void onMaxOrNormal();
    void onClose();

    bool isResizeable() const
    {
        return m_bResizeable;
    }
    void setResizeable(bool on)
    {
        m_bResizeable = on;
    }

protected:
    QWidget *m_centralWidget = nullptr;

    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
    void changeEvent(QEvent *e) override;

private:
    void initUI();
    void onLogicalDotsPerInchChanged(qreal dpi);
    void setWidgetBorderless();

private:
    Ui::xWidgetsClass ui;
    float m_dpiScale = 1.0f;
    bool m_bResizeable = true;
};
