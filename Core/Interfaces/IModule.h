#ifndef IMODULE_H
#define IMODULE_H


namespace START_APP_NAMESPACE
{
    class IModule {
    public:
        virtual ~IModule() {}

        // Initialize the module
        virtual void init() = 0;

        // Start the module
        virtual void start() = 0;

        // Stop the module
        virtual void stop() = 0;
    };
}

#endif // IMODULE_H
