#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QWebSocket>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = nullptr);

    bool connectToServer(const QString &hostAddr, int port = 19283);
    Q_INVOKABLE void sendRequest(const QByteArray &request);
    QString getError() const;

private:
    QWebSocket *socket;

public slots:
    void readMessage(const QString &message);
};

#endif // CONNECTOR_H
