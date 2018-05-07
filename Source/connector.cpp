#include "connector.h"

Connector::Connector(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(parent);
    connect(socket, &QTcpSocket::readyRead, this, &Connector::readMessage);

    socket->connectToHost(QString("127.0.0.1"), 19283);
}

void Connector::sendMessage(const QByteArray &data)
{

}

void Connector::readMessage()
{
    QString answer = socket->readAll();
    qDebug().noquote() << answer;
}
