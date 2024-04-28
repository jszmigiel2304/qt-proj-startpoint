#include "Exception.h"

using namespace START_APP_NAMESPACE;


Exception::Exception(const QString &message) :
    QException(),
    m_message{message.toStdString()}
{
}

Exception::Exception(const std::string &message) :
    QException(),
    m_message{message}
{

}

Exception::~Exception()
{
}

void Exception::raise() const
{
    throw *this;
}

Exception *Exception::clone() const
{
    return new Exception(*this);
}

const char *Exception::what() const noexcept
{
    return m_message.c_str();
}

const QString Exception::whatQStr() const
{
    return QString::fromStdString(m_message);
}

const std::string Exception::whatStdStr() const
{
    return m_message;
}
