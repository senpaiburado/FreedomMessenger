#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QVariant>
#include <QDebug>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);

    void setSettingsMap(const QMap<QString, QVariant> &settingsMap);

    template<typename T = QString>
    T getValue(const QString &key) {
        QVariant item = settings[key];
        if (item.isNull()) {
            qDebug() << "There is not any settings for key " << key;
            return QVariant().value<T>();
        }
        return item.value<T>();
    }

private:
    QMap<QString, QVariant> settings;
signals:

public slots:
};

#endif // SETTINGS_H
