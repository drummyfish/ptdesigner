#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <iostream>

int main(int argc, char *argv[])

{
  setlocale(LC_NUMERIC,"en_US");
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
