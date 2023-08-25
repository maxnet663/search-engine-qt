#include "include/mainwindow.h"
#include "interface/ui_engine.h"

#include <QFileDialog>
#include <qglobal.h>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
        , file_manager(new FileManager)
{
    ui->setupUi(this);
    connect(ui->add_file_button, &QPushButton::clicked
            , file_manager, &FileManager::updateFilesList);
    connect(ui->clear_button, &QPushButton::clicked
            , file_manager, &FileManager::clearDocsList);
    connect(file_manager, &FileManager::docsListUpdated, this, &MainWindow::show_files);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file_manager;
}

void MainWindow::show_files(const QSet<QString> &docs_list) {
    ui->files_list->clear();
    for (const auto &doc : docs_list) {
        ui->files_list->addItem(doc);
    }
}
