#ifndef SEARCH_ENGINE_FILE_MANAGER_H
#define SEARCH_ENGINE_FILE_MANAGER_H

#include <QObject>
#include <QSet>
#include <QHash>
#include <QSharedPointer>

class FileManager : public QObject{

    Q_OBJECT

public:

    FileManager() = default;

    QString getFileText(const QString &file_name);

    //QHash<path, file's text>
    QSharedPointer<QHash<QString, QString>> getDocumentsText();

signals:
    void cantReadFromFile(QString file_name);
    void docsListUpdated(const QSet<QString> &docs_list);

public slots:
    void updateFilesList();
    void clearDocsList();

private:
    QSet<QString> docs;
};

#endif //SEARCH_ENGINE_FILE_MANAGER_H
