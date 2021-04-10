
#ifndef MYMENU_H
#define MYMENU_H

#include "QMainWindow"
class mymenu : public QMainWindow
{
    Q_OBJECT
public:
    explicit mymenu(QWidget* parent = 0);

private slots:
    void fileOpenActionSlot();
private:
    void createAction();     
    void createMenu();      
    void createContentMenu();
private:
    void selectFile();       //選擇文件
    void showImageList();    //顯示圖片
private:
    QAction* fileOpenAction; //建立QAction指標，打開文件
    QMenu* menu;             //建立Qmenu指標
private:
    QStringList fileNames;
};

#endif // MYMENU_H