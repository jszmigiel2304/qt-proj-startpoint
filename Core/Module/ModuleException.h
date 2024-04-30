#ifndef START_APP_NAMESPACE_MODULEEXCEPTION_H
#define START_APP_NAMESPACE_MODULEEXCEPTION_H

#include "../Base/Exception.h"

namespace START_APP_NAMESPACE
{
    class ModuleException : public Exception
    {
    public:
        explicit ModuleException(const QString &message);
        virtual ~ModuleException() override;
    };
}

#endif //START_APP_NAMESPACE_MODULEEXCEPTION_H
