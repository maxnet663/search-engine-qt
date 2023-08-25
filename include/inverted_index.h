#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <QObject>
#include <QHash>
#include <QSharedPointer>

struct Entry {
    QString file_name;
    size_t count;
};

class InvertedIndex {

    Q_OBJECT

private:

    QList<Entry> getWordFreq(const QString &word);

    void extractUniqueWords(const QString &text);

public:

    void updateDocumentBase(QSharedPointer<QHash<QString, QString>> &input_docs);

    QList<Entry> getWordCount(const QString &word);

private:

    QHash<QString, QList<Entry>> freq_dictionary;

    //QHash<path, text>
    QSharedPointer<QHash<QString, QString>> docs;
};

#endif //INVERTED_INDEX_H
