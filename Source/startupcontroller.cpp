#include "startupcontroller.h"

#include <QList>
#include <QString>
#include <QDebug>
#include <QXmlSimpleReader>

StartupResult *StartupController::launch(IQmlEngine *qmlEngine, ISettingsEngine *settingsEngine)
{
    registerQmlTypes(qmlEngine);
    return new StartupResult(QList<int>() << loadFiles(settingsEngine) << loadData(settingsEngine) <<
                             setupLanguage(settingsEngine) << setupSettings(settingsEngine)
                             << setupFonts(qmlEngine));
}

void StartupController::registerQmlTypes(IQmlEngine *qmlEngine)
{

}

int StartupController::loadData(ISettingsEngine *settingsEngine)
{

#ifdef DEBUG_APP
    qDebug() << (settingsEngine->getValue("build_version"));
#endif
    return SUCCESS;
}

int StartupController::setupFonts(IQmlEngine *qmlEngine)
{
    Q_UNUSED(qmlEngine)
    return SUCCESS;
}

int StartupController::setupLanguage(ISettingsEngine *settingsEngine)
{
    Q_UNUSED(settingsEngine)
    return SUCCESS;
}

int StartupController::setupSettings(ISettingsEngine *settingsEngine)
{

    return SUCCESS;
}

int StartupController::loadFiles(ISettingsEngine *settingsEngine)
{
    return SUCCESS;
}
