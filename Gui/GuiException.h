#ifndef START_APP_NAMESPACE_GUIEXCEPTION_H
#define START_APP_NAMESPACE_GUIEXCEPTION_H

#include <Base/Exception.h>

namespace START_APP_NAMESPACE
{
    class GuiException : public Exception
    {
    public:
        explicit GuiException(const QString &message);
        virtual ~GuiException() override;
    };
}

#endif //START_APP_NAMESPACE_GUIEXCEPTION_H
