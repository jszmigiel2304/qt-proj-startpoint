// Module.cpp

#include "Module.h"

#include "ModulePrivate.h"

using namespace START_APP_NAMESPACE;

Module::Module(ThreadingBehavior threadingBehavior, QObject *parent) :
    QObject(parent)
{
    INITIALIZE_PRIVATE(Module)
}

void Module::init()
{
    // Initialization logic
}

void Module::start()
{
    if (PRIVATE(m_threadingBehavior) == RunInNewThread) {
        PRIVATE(m_thread).start();
    } else {
        run();
    }
}

void Module::stop()
{
    if (PRIVATE(m_threadingBehavior) == RunInNewThread) {
        PRIVATE(m_thread).quit();
        PRIVATE(m_thread).wait();
    }
}

Module::~Module()
{
    stop();
}
