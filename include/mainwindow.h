#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include "include/file_manager.h"
#include "include/inverted_index.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void show_files(const QSet<QString> &docs_list);

private:
    Ui::MainWindow *ui;
    FileManager *file_manager;
};
#endif // MAINWINDOW_H