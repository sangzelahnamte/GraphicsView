#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ZoomIn();
    void ZoomOut();

    // cut copy paste select all text
    void cut_text();
    void copy_text();
    void paste_text();
    void select_all();

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsTextItem *text_item;

    qreal zoomFactor = 1.0;

    QGraphicsTextItem *getFocusTextItem();
};
#endif // MAINWINDOW_H
