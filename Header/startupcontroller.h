#ifndef STARTUPCONTROLLER_H
#define STARTUPCONTROLLER_H

// Root files
#include <QObject>
#include <QQmlApplicationEngine>

// Own files
#include "settings.h"

using IQmlEngine = QQmlApplicationEngine; // Qml engine interface
using ISettingsEngine = Settings; // Settings engine interface

// Data of startup process
struct StartupResult;

// Class with methods to control startup of application
class StartupController
{
public:
    // This method calls other methods to startup application and gets result
    static StartupResult *launch(IQmlEngine *qmlEngine, ISettingsEngine *settingsEngine);

private:
    // Use to register own types (classes, enums, structures etc.) in QML
    static void registerQmlTypes(IQmlEngine *qmlEngine);
    // Use to load settings into application's memory from file
    static int loadData(ISettingsEngine *settingsEngine);
    // Use to load fonts for GUI (QML)
    static int setupFonts(IQmlEngine *qmlEngine);
    // Use to set language in GUI (QML)
    static int setupLanguage(ISettingsEngine *settingsEngine);
    // Use to control loaded settings
    static int setupSettings(ISettingsEngine *settingsEngine);
};

struct StartupResult {
    StartupResult(const QList<int> &data) {
        for (QList<int>::const_iterator it = data.begin(); it != data.end(); it++) {
            switch ((*it)) {
            case 0:
                successful++;
                break;
            case 1:
                warnings++;
                break;
            case -1:
                errors++;
                break;
            default:
                throw std::runtime_error("Startup result type error! Crash!");
            }
        }
    }
    int successful = 0;
    int warnings = 0;
    int errors = 0;
};

#endif // STARTUPCONTROLLER_H
