#include "xWidgets.h"
#include <QDebug>
#include <QScreen>
#include <QWindow>

#ifdef Q_OS_WIN
#include <dwmapi.h>     // Dwmapi.lib
#include <windows.h>
#include <windowsx.h>
#endif

xWidgets::xWidgets()
{
    setAttribute(Qt::WA_StyledBackground, true);
    setWidgetBorderless();
    ui.setupUi(this);

    initUI();

    QScreen *screen = qApp->primaryScreen();
    connect(screen, &QScreen::logicalDotsPerInchChanged, this, &xWidgets::onLogicalDotsPerInchChanged);
}

xWidgets::~xWidgets()
{}

void xWidgets::onMin()
{
    if (windowState() != Qt::WindowMinimized)
    {
        showMinimized();
    }
}

void xWidgets::onMaxOrNormal()
{
    if (windowState() == Qt::WindowMaximized)
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
}

void xWidgets::onClose()
{
    close();
}

bool xWidgets::nativeEvent(const QByteArray & eventType, void *message, long *result)
{
#ifdef Q_OS_WIN
    if (eventType != "windows_generic_MSG")
        return QWidget::nativeEvent(eventType, message, result);

    MSG *msg = static_cast<MSG *>(message);
    QWidget *widget = QWidget::find(reinterpret_cast<WId>(msg->hwnd));
    if (!widget)
        return QWidget::nativeEvent(eventType, message, result);

    switch (msg->message)
    {

    case WM_NCCALCSIZE:
    {
        *result = 0;
        return true;
    }

    case WM_NCHITTEST:
    {
        auto winrect = geometry();

        int x = GET_X_LPARAM(msg->lParam);
        int y = GET_Y_LPARAM(msg->lParam);

        QScreen *screen = windowHandle()->screen();

        m_dpiScale = screen->devicePixelRatio();

        if (windowState() == Qt::WindowFullScreen)
        {
            *result = HTCLIENT;
            return true;
        }

        const LONG border_width = 5;

        if (m_bResizeable)
        {
            bool resizeWidth = minimumWidth() != maximumWidth();
            bool resizeHeight = minimumHeight() != maximumHeight();

            if (resizeWidth)
            {
                //left border
                if (x >= winrect.left() && x < winrect.left() + border_width)
                {
                    *result = HTLEFT;
                }
                //right border
                else if (x < winrect.right() && x >= winrect.right() - border_width)
                {
                    *result = HTRIGHT;
                }
            }
            if (resizeHeight)
            {
                //bottom border
                if (y < winrect.bottom() && y >= winrect.bottom() - border_width)
                {
                    *result = HTBOTTOM;
                }
                //top border
                else if (y >= winrect.top() && y < winrect.top() + border_width)
                {
                    *result = HTTOP;
                }
            }
            if (resizeWidth && resizeHeight)
            {
                //bottom left corner
                if (x >= winrect.left() && x < winrect.left() + border_width &&
                    y < winrect.bottom() && y >= winrect.bottom() - border_width)
                {
                    *result = HTBOTTOMLEFT;
                }
                //bottom right corner
                else if (x < winrect.right() && x >= winrect.right() - border_width &&
                    y < winrect.bottom() && y >= winrect.bottom() - border_width)
                {
                    *result = HTBOTTOMRIGHT;
                }
                //top left corner
                else if (x >= winrect.left() && x < winrect.left() + border_width &&
                    y >= winrect.top() && y < winrect.top() + border_width)
                {
                    *result = HTTOPLEFT;
                }
                //top right corner
                else if (x < winrect.right() && x >= winrect.right() - border_width &&
                    y >= winrect.top() && y < winrect.top() + border_width)
                {
                    *result = HTTOPRIGHT;
                }
            }
        }
        if (0 != *result)
            return true;

        *result = HTCLIENT;
        double dpr = m_dpiScale; // this->devicePixelRatioF();
        auto ax = (x - winrect.left()) / dpr;
        auto ay = (y - winrect.top()) / dpr;
        QPoint pos(ax, ay);

        //判断点击标题栏
        if (ui.titleBarWidget->geometry().contains(pos))
        {
            *result = HTCAPTION;
            return true;
        }

        break;
    }

    case WM_GETMINMAXINFO:
    {
        if (::IsZoomed(msg->hwnd))
        {
            RECT frame = { 0, 0, 0, 0 };
            AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
            frame.left = abs(frame.left);
            frame.top = abs(frame.bottom);
            widget->setContentsMargins(int(frame.left / m_dpiScale), int(frame.top / m_dpiScale), int(frame.right / m_dpiScale), int(frame.bottom / m_dpiScale));
        }
        else
        {
            widget->setContentsMargins(0, 0, 0, 0);
        }

        *result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
        return true;
    }
    break;

    default:
        break;
    }

#endif

    return QWidget::nativeEvent(eventType, message, result);
}

void xWidgets::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::WindowStateChange)
    {
        if (windowState() != Qt::WindowMaximized)
        {
            //ui.max_button->setStyleSheet("background-image: url(:/res/svg/maximize.svg);");
            ui.max_button->setToolTip(tr("Maximize"));
        }
        else if (windowState() == Qt::WindowMaximized)
        {
            //ui.max_button->setStyleSheet("background-image: url(:/res/svg/maximize2.svg);");
            ui.max_button->setToolTip(tr("Restore"));
        }
    }
}

void xWidgets::initUI()
{
    ui.min_button->setToolTip(tr("Minimize"));
    if (windowState() == Qt::WindowMaximized)
    {
        ui.max_button->setToolTip(tr("Restore"));
    }
    else
    {
        ui.max_button->setToolTip(tr("Maximize"));
    }
    ui.close_button->setToolTip(tr("Close"));

    connect(ui.min_button, &QAbstractButton::clicked, this, &xWidgets::onMin);
    connect(ui.max_button, &QAbstractButton::clicked, this, &xWidgets::onMaxOrNormal);
    connect(ui.close_button, &QAbstractButton::clicked, this, &xWidgets::onClose);

    m_centralWidget = ui.centralWidget;
}

void xWidgets::onLogicalDotsPerInchChanged(qreal dpi)
{
    resize(size() - QSize(1, 1));
    resize(size() + QSize(1, 1));
}

void xWidgets::setWidgetBorderless()
{
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);

#ifdef Q_OS_WIN
    DwmEnableComposition(DWM_EC_ENABLECOMPOSITION); // windows7 need disable.
    HWND hwnd = reinterpret_cast<HWND>(winId());
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);

    // add window shadow.
    const MARGINS shadow = { 1, 1, 1, 1 };
    DwmExtendFrameIntoClientArea(HWND(winId()), &shadow);
#endif
}
