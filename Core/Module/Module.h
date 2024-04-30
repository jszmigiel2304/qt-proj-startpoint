// Module.h
#ifndef START_APP_NAMESPACE_MODULE_H
#define START_APP_NAMESPACE_MODULE_H

//#include <memory>

#include <QObject>

#include "../Interfaces/IModule.h"
#include "../Base/Pimpl.h"
#include "../Base/Definitions.h"

namespace START_APP_NAMESPACE
{
    class Module : public QObject, public IModule {
        Q_OBJECT
        DECLARE_PRIVATE(Module)

    public:
        enum ThreadingBehavior : EnumT {
            RunInCurrentThread,
            RunInNewThread
        };
        Q_ENUM(ThreadingBehavior)

        Module(ThreadingBehavior threadingBehavior = RunInCurrentThread, QObject *parent = nullptr);
        virtual ~Module();

        void init() override;
        void start() override;
        void stop() final;

    protected:

        virtual void run() = 0;
    };

} // namespace START_APP_NAMESPACE

#endif // START_APP_NAMESPACE_MODULE_H
