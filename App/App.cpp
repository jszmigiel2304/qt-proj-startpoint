#include "App.h"

#include "AppException.h"

using namespace START_APP_NAMESPACE;

App::App(int &argc, char **argv) :
    QGuiApplication(argc, argv)
{

}

void App::init()
{
    try {
        m_guiEngine = std::make_unique<Gui>(this);
    } catch (Exception &e) {
        qDebug() << e.whatQStr();
        throw;
    }
}

App::~App()
{

}

void App::run()
{
    m_guiEngine->run();
}
