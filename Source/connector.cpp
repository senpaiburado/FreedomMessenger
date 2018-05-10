#include "connector.h"

#include <QObjectUserData>

Connector::Connector(QObject *parent) : QObject(parent)
{
    socket = new QWebSocket;
    connect(socket, &QWebSocket::textMessageReceived, this, &Connector::readMessage);
}

bool Connector::connectToServer(const QString &hostAddr, int port)
{
    socket->open(QUrl("ws://127.0.0.1:12345"));
    return true;
}

void Connector::sendRequest(const QByteArray &request)
{
    socket->sendTextMessage(request);
}

QString Connector::getError() const
{
    return socket->errorString();
}

void Connector::readMessage(const QString &message)
{
    qDebug() << message;
}
