#ifndef START_APP_NAMESPACE_EXCEPTION_H
#define START_APP_NAMESPACE_EXCEPTION_H

#include <string>

#include <QException>
#include <QString>

namespace START_APP_NAMESPACE
{

    class Exception : public QException
    {
    public:
        explicit Exception(const QString& message);
        explicit Exception(const std::string& message);
        virtual ~Exception();

        void raise() const override;
        Exception *clone() const override;

        virtual const char *what() const noexcept override;
        virtual const QString whatQStr() const final;
        virtual const std::string whatStdStr() const final;

    private:
        const std::string m_message{"DEFAULT_EXCEPTION_MESSAGE"};
    };

}

#endif //START_APP_NAMESPACE_EXCEPTION_H
