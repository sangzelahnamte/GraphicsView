#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // paper size for A4
    int m_paperWidth = 210 * 4;  // ~ 840 pixels
    int m_paperHeight = 297 * 4; // ~ 1188 pixels

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    //scene->addEllipse(0, 0, 200, 200, QPen(Qt::black), QBrush(Qt::red));

    // canvas area settings to Graphics Rect Item
    QGraphicsRectItem *virtual_canvas = new QGraphicsRectItem(0, 0, m_paperWidth, m_paperHeight); //setting the rectangle
    virtual_canvas->setBrush(Qt::white); //white for blank appearance
    virtual_canvas->setPen(Qt::NoPen); //without border
    scene->addItem(virtual_canvas); //add graphics item to scene

    text_item = new QGraphicsTextItem(virtual_canvas); //adding canvas as parent to text item
    text_item->setPlainText("Start typing here....");
    text_item->setTextInteractionFlags(Qt::TextEditorInteraction); // enables text editing
    text_item->setPos(0, 0); // real x and y position
    //scene->addItem(text_item); no need to add this again

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing); // for smooth graphics rendering
    view->setAlignment(Qt::AlignCenter);
    view->setSceneRect(0, 0, m_paperWidth, m_paperHeight);
    view->setBackgroundBrush(QColor(200, 200, 200));
    this->setCentralWidget(view);
    text_item->setFocus();

    // SIGNALS AND SLOTS
    connect(ui->actionZoom_In, &QAction::triggered, this, &MainWindow::ZoomIn);
    connect(ui->actionZoom_Out, &QAction::triggered, this, &MainWindow::ZoomOut);

    // CUT COPY PASTE SELECT ALL....
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::cut_text);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::copy_text);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::paste_text);
    connect(ui->actionSelect_All, &QAction::triggered, this, &MainWindow::select_all);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ZoomIn()
{
    if(zoomFactor < 3.0)
    {
        zoomFactor *= 1.2;
        view->scale(1.2, 1.2);
    }
}

void MainWindow::ZoomOut()
{
    if (zoomFactor > 0.5)
    {  // Min zoom level
        zoomFactor /= 1.2;
        view->scale(1 / 1.2, 1 / 1.2);
    }
}

void MainWindow::cut_text() // IMPLEMENTATION OF METHOD IS VERY HARD HERE.......!!!!!!!!!!!!!!!!!!!!!!
{
    if(QGraphicsTextItem *text_item = getFocusTextItem())
    {
        // text_item->cut();
    }
}

void MainWindow::copy_text()
{

}

void MainWindow::select_all()
{

}

QGraphicsTextItem *MainWindow::getFocusTextItem()
{
    if(QGraphicsItem *item = ui->graphicsView->scene()->focusItem())
    {
        return dynamic_cast<QGraphicsTextItem*>(item);
    }
    return nullptr;
}

void MainWindow::paste_text()
{

}
