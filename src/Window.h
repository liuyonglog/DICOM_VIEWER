#ifndef WINDOW_H
#define WINDOW_H


#include <string>
#include <sstream>
#include <thread>

#include <QMainWindow>
#include <QTimer>
#include <QScrollArea>
#include <QScrollBar>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QLineEdit>
#include <QUrl>
#include <QMimeData>

#include "ImageOps.h"

#include "FileToolbar.h"
#include "ResizeToolbar.h"
#include "DisplayWidget.h"
#include "ImageWindowingDock.h"
#include "ImageListDock.h"
#include "ImageLayoutControlDock.h"
#include "CanvasWidget.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window();
    ~Window();

private:
    QMenu* m_pFileMenu;
    QMenu* m_pViewMenu;
    FileToolbar* m_pFileToolbar;
    ResizeToolbar* m_pResizeToolbar;
    CanvasWidget* m_pCanvas;

    QScrollArea* m_pScrollArea;
    QTimer* m_pTimer;
    ImageWindowDock* m_pImageWindowingDock;
    ImageListDock* m_pImageListDock;
    ImageLayoutControlDock* m_pImageLayoutDock;

    bool m_bConnected;

private:
    void OpenSlice(QString filename);
    void OpenSeries(QString path);
    void CreateMenus();
    void CreateToolbars();
    void CreateCenterWidgets();
    void CreateDocks();
    void CreateConnections();
    void SetupAnnotation(int index);
    void SetupDisplays();
    void SetupImageWindow(int wc, int ww);
    std::string DateFormat(std::string string);
    std::string TimeFormat(std::string string);

    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);


private slots:
    void OpenDicomImage();
    void OpenDicomSeries();
    void CloseDicomImage();
    void Pan(float scale);
    void UpdateImage();
    void UpdateImage(int index);
    void UpdateActiveSlice(int deltaX, int deltaY);
    void ResetWindow();
    void ZoomIn25Present();
    void ZoomOut25Present();
    void ZoomOriginalSize();
    void ZoomFitToHeight();
    void ZoomComboResize(int index);
    void ZoomCustomSize();
    void UpdateDisplayLayout();

};


#endif
