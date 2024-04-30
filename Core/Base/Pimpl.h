//Pimpl.h

#ifndef START_APP_NAMESPACE_PIMPL_H
#define START_APP_NAMESPACE_PIMPL_H

#include "Exception.h"


namespace START_APP_NAMESPACE
{
    class PimplException : public Exception
    {
    public:
        explicit PimplException(const QString &message) :
            Exception( QString("[PIMPL_EXCEPTION] " + message) )
        {}
        virtual ~PimplException() override
        {}
    };
}

#define DECLARE_PRIVATE(Class)                                                  \
    class Class##Private;                                                       \
    std::unique_ptr<Class##Private> m_Private{nullptr};

#define PRIVATE(Member)                                                         \
    (m_Private->Member)

#define INITIALIZE_PRIVATE(Class)                                               \
    try {                                                                       \
        m_Private.reset( new Class##Private() );                                \
    } catch ( const std::bad_alloc& e ) {                                       \
        throw PimplException(QString("bad_alloc exception in ") + #Class);      \
    } catch ( ... ) {                                                           \
        throw PimplException(QString("other exception in ") + #Class);          \
    }

#endif //START_APP_NAMESPACE_PIMPL_H
