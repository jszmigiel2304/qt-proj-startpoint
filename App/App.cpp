#include "App.h"

#include "AppException.h"

using namespace START_APP_NAMESPACE;

App::App(int &argc, char **argv) :
    QGuiApplication(argc, argv),
    LoggingDevice("App.log")
{

}

void App::init()
{
    try {
        m_guiEngine = std::make_unique<Gui>(this);
    } catch (Exception &e) {
        LOGGER->error("[EXCEPTION] {}", e.whatStdStr());
        LOGGER_FLUSH
        throw AppException(e.whatQStr());
    }
}

App::~App()
{

}

void App::run()
{
    m_guiEngine->run();
}
