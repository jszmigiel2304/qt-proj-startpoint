//AppException.cpp
#include "AppException.h"

using namespace START_APP_NAMESPACE;

AppException::AppException(const QString &message) :
    Exception( QString("[APP_EXCEPTION] " + message) )
{

}

AppException::~AppException()
{

}
