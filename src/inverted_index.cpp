#include "include/inverted_index.h"
#include <QTextStream>

static size_t countOccurrences(const QString &text, const QString &word) {
    size_t walk = 0;
    size_t occur_counter = 0;

    while (walk <= text.length() - word.length()) {
        auto occur_begin = text.indexOf(word);
        if (occur_begin == -1) {
            return occur_counter;
        }
        auto occur_end = occur_begin + word.length();

        if ( (occur_begin == 0 || text[occur_begin - 1] == ' ')
            && occur_end == ' ' || occur_end == text.length() ) {
            occur_counter++;
        }
        walk = occur_end;
    }
    return occur_counter;
};

QList<Entry> InvertedIndex::getWordFreq(const QString &word) {
    QList<Entry> result;
    for (auto it = docs->cbegin(); it != docs->cend(); ++it) {
        auto count = countOccurrences(it.value(), word);
        result.push_back({it.key(), count});
    }
    return result;
}

void InvertedIndex::extractUniqueWords(const QString &text) {
    QTextStream data(&const_cast<QString&>(text), QIODevice::ReadOnly);
    QString word;
    //todo your thread may be here
    while(!data.atEnd()) {
        data >> word;
        if (!freq_dictionary.contains(word)) {
            auto &target = freq_dictionary[word];
            auto freq = getWordFreq(word);
            target = qMove(freq);
        }
    }
}

QList<Entry> InvertedIndex::getWordCount(const QString &word) {
    return freq_dictionary[word];
}

void InvertedIndex::updateDocumentBase(QSharedPointer<QHash<QString, QString>> &input_docs) {
    if (!docs->empty()) {
        docs.clear();
    }
    if (!freq_dictionary.empty()) {
        freq_dictionary.clear();
    }

    for (const auto &text : *input_docs) {
        extractUniqueWords(text);
    }

}
