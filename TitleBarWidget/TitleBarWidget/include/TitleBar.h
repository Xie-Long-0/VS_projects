#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TitleBarClass; };
QT_END_NAMESPACE

namespace XL {


class TitleBar : public QWidget
{
    Q_OBJECT

public:
    enum Flag
    {
        None = 0,
        HideIcon = 0x1,
        HideTitle = 0x2,
        HideMinimizeButton = 0x4,
        HideMaximizeButton = 0x8,
        HideCloseButton = 0x10,
        Moveable = 0x20,
    };
    Q_DECLARE_FLAGS(Flags, Flag);
    Q_FLAG(Flags);

    explicit TitleBar(QWidget *parent = nullptr, Flags flags = Moveable);
    TitleBar(const QString &title, QWidget *parent = nullptr, Flags flags = Moveable);
    ~TitleBar();

public slots:
    void setTitle(const QString &text);
    void setIcon(const QPixmap &img);

    void setFlag(Flag flag, bool on = true)
    {
        m_flags.setFlag(flag, on);
    }

    void setFlags(Flags flags)
    {
        m_flags = flags;
    }

    void setMoveable(bool enabled)
    {
        setFlag(Moveable, enabled);
    }

    void setMinimizeBtnVisible(bool visible)
    {
        setFlag(HideMinimizeButton, !visible);
    }

    void setMaximizeBtnVisible(bool visible)
    {
        setFlag(HideMaximizeButton, !visible);
    }

    void setCloseBtnVisible(bool visible)
    {
        setFlag(HideCloseButton, !visible);
    }

    void onMinimizeBtnClicked();
    void onMaximizeBtnClicked();
    void onCloseBtnClicked();

signals:
    void closeEmit();

protected:
    void paintEvent(QPaintEvent *e) override;
    // 鼠标点击、移动事件
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

private:
    void init();
    Ui::TitleBarClass *ui;
    Flags m_flags;
    QPointF m_pos;
};

}; // namespace XL
