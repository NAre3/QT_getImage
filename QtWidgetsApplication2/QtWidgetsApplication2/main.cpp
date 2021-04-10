#include "mymenu.h"
#include <QApplication>
#include <QProcess>
#include <QMessageBox>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    mymenu m_menu;
    m_menu.show();
    return a.exec();
}