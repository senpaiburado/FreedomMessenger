#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>
#include <QFile>
#include <QXmlStreamReader>

class XmlReader : public QObject
{
    Q_OBJECT
public:
    explicit XmlReader(QObject *parent = nullptr);



signals:

public slots:
};

#endif // XMLREADER_H
