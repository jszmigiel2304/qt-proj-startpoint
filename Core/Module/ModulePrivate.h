// ModulePrivate.h

#ifndef START_APP_NAMESPACE_MODULEPRIVATE_H
#define START_APP_NAMESPACE_MODULEPRIVATE_H

#include <QThread>

#include "Module.h"

namespace START_APP_NAMESPACE
{
    class Module::ModulePrivate : public QObject
    {
        Module::ThreadingBehavior m_threadingBehavior;
        QThread m_thread;

        friend class Module;
    };
}

#endif //START_APP_NAMESPACE_MODULEPRIVATE_H
