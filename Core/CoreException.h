//CoreException.h
#ifndef START_APP_NAMESPACE_COREEXCEPTION_H
#define START_APP_NAMESPACE_COREEXCEPTION_H

#include "Base/Exception.h"

namespace START_APP_NAMESPACE
{
class CoreException : public Exception
{
public:
    explicit CoreException(const QString &message);
    virtual ~CoreException() override;
};
}

#endif //START_APP_NAMESPACE_COREEXCEPTION_H
