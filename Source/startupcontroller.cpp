#include "startupcontroller.h"

#include <QList>

#define SUCCESS 0 // This value defines successful executing of function
#define WARNING 1 // This value defines executing of function with insignificant problems
#define ERROR -1 // // This value defines executing of function with critical problems

StartupResult *StartupController::launch(IQmlEngine *qmlEngine, ISettingsEngine *settingsEngine)
{
    registerQmlTypes(qmlEngine);
    return new StartupResult(QList<int>() << loadData(settingsEngine) <<
                             setupLanguage(settingsEngine) << setupSettings(settingsEngine)
                             << setupFonts(qmlEngine));
}

void StartupController::registerQmlTypes(IQmlEngine *qmlEngine)
{

}

int StartupController::loadData(ISettingsEngine *settingsEngine)
{

    return SUCCESS;
}

int StartupController::setupFonts(IQmlEngine *qmlEngine)
{

    return SUCCESS;
}

int StartupController::setupLanguage(ISettingsEngine *settingsEngine)
{

    return SUCCESS;
}

int StartupController::setupSettings(ISettingsEngine *settingsEngine)
{

    return SUCCESS;
}
