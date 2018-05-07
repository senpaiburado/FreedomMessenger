#include "settings.h"



Settings::Settings(QObject *parent) : QObject(parent)
{

}

void Settings::setSettingsMap(const QMap<QString, QVariant> &settingsMap)
{
    settings = settingsMap;
}

//template<typename T>
//T Settings::getValue(const QString &key)
//{

//}
