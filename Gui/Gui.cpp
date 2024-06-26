#include "Gui.h"

#include <QStringLiteral>

#include "GuiException.h"

using namespace START_APP_NAMESPACE;

Gui::Gui(QObject *parent ) :
    QObject(parent)
{
    QObject::connect(
        &m_engine,
        &QQmlApplicationEngine::objectCreationFailed,
        this,
        []() {
            GuiException _exception( QString("Gui engine object creation FAILED.") );
            _exception.raise();
            //QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
}

Gui::~Gui()
{

}

void Gui::run()
{
    const QUrl _url( QStringLiteral("../Gui/Qml/Main.qml") );
    m_engine.load(_url);
}
