#ifndef START_APP_NAMESPACE_GUI_H
#define START_APP_NAMESPACE_GUI_H

#include <memory>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace START_APP_NAMESPACE
{
    class Gui : public QObject
    {
        //Q_OBJECT

    public:
        typedef std::unique_ptr<Gui> UnqPtr;
        typedef std::shared_ptr<Gui> ShrPtr;

        explicit Gui(QObject *parent = nullptr);
        virtual ~Gui() override;

        void run();

    private:
        QQmlApplicationEngine m_engine;
    };
}

#endif //START_APP_NAMESPACE_GUI_H
