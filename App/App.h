#ifndef START_APP_NAMESPACE_APP_H
#define START_APP_NAMESPACE_APP_H

#include <memory.h>

#include <QGuiApplication>

#include <Base/Exception.h>
#include <Gui.h>

#include <Log/LoggingDevice.h>

namespace START_APP_NAMESPACE
{
class App : public QGuiApplication, public LoggingDevice
    {
        //Q_OBJECT

    public:
        typedef std::unique_ptr<App> UnqPtr;
        typedef std::shared_ptr<App> ShrPtr;

        explicit App(int &argc, char **argv);
        virtual ~App() override;

        void init();
        void run();

    private:
        Gui::UnqPtr m_guiEngine;
    };
}

#endif //START_APP_NAMESPACE_APP_H
