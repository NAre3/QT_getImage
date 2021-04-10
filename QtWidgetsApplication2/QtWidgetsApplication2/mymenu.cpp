#include "mymenu.h"
#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QMessageBox"
#include "QFileDialog"
#include "QDebug"
#include "QListWidget"

mymenu::mymenu(QWidget* parent) :QMainWindow(parent)
{
    createAction();
    createMenu();
    createContentMenu();
    this->resize(300, 400);
}
void mymenu::createAction()
{
    
    fileOpenAction = new QAction(tr("Open File"), this);        //開啟文件
    fileOpenAction->setShortcut(tr("Ctrl+O"));                  //建立開啟文件快捷鍵
    fileOpenAction->setStatusTip("Open File");
    connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
}
void mymenu::createMenu()
{
    menu = this->menuBar()->addMenu(tr("Image"));
    menu->addAction(fileOpenAction);
}

void mymenu::createContentMenu()
{
    this->addAction(fileOpenAction);
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void mymenu::fileOpenActionSlot()
{
    selectFile();
}

void mymenu::selectFile()
{
    QFileDialog* fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Chose Image"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    if (fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
        showImageList();
    }
    for (auto tmp : fileNames)
        qDebug() << tmp << endl;
}

void mymenu::showImageList()
{

    QListWidget* imageList = new QListWidget;           //定義QListWidget
    imageList->resize(365, 400);
    imageList->setViewMode(QListView::IconMode);        //設定QListWidget的顯示方式
    imageList->setIconSize(QSize(150, 150));            //設定圖片大小
    imageList->setSpacing(10);                          //設定圖片間距
    imageList->setResizeMode(QListWidget::Adjust);
    imageList->setMovement(QListWidget::Static);        //設定不能移動圖片
    for(auto tmp : fileNames)
    {
        
        QListWidgetItem* imageItem = new QListWidgetItem;   //定義QListWidgetItem
  
        imageItem->setIcon(QIcon(tmp));                     //設定單元屬性
        imageItem->setSizeHint(QSize(150, 150));            
        imageList->addItem(imageItem);                      //將單元添加到QListWidget中
    }
    imageList->show();                                     //顯示QListWidget
}