#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QTcpSocket>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = nullptr);

private:
    QTcpSocket *socket;

    void sendMessage(const QByteArray &data);
signals:

public slots:
    void readMessage();
};

#endif // CONNECTOR_H
