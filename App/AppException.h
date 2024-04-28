#ifndef START_APP_NAMESPACE_APPEXCEPTION_H
#define START_APP_NAMESPACE_APPEXCEPTION_H

#include <Base/Exception.h>

namespace START_APP_NAMESPACE
{
    class AppException : public Exception
    {
    public:
        explicit AppException(const QString &message);
        virtual ~AppException() override;
    };
}

#endif //START_APP_NAMESPACE_APPEXCEPTION_H
