#include "include/file_manager.h"

#include <QFile>
#include <QFileDialog>
#include <QRegExp>

QString FileManager::getFileText(const QString &file_name) {
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit cantReadFromFile(file_name);
        return {};
    }
    auto text =  file.readAll();
    file.close();
    return text;
}

QSharedPointer<QHash<QString, QString>> FileManager::getDocumentsText() {
    QSharedPointer<QHash<QString, QString>> all_texts;
    all_texts->reserve(docs.size());
    for (const auto &doc_name : docs) {
        // todo here may be thread
        // with validation of already added texts
        auto text = getFileText(doc_name);
        text.remove(QRegExp("[?!,.;:`'\"/\\<>*$#@()]"));
        text = text.toLower();
        all_texts->insert(doc_name, text);
    }
    return all_texts;
}

void FileManager::clearDocsList() {
    docs.clear();
    emit docsListUpdated(docs);
}

void FileManager::updateFilesList() {
    auto files = QFileDialog::getOpenFileNames(
            nullptr
            , "Choose files to index"
            , PROJECT_PATH
            , "Text files (*.txt)");
    // todo fix case when user open invalid file, directory for example
    for (auto &path : files) {
        docs.insert(qMove(path));
    }
    emit docsListUpdated(docs);
}
