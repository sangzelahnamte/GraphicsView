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
}

MainWindow::~MainWindow()
{
    delete ui;
}
