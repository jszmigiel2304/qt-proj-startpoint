//CoreException.cpp
#include "CoreException.h"

using namespace START_APP_NAMESPACE;

CoreException::CoreException(const QString &message) :
    Exception( QString("[CORE_EXCEPTION] " + message) )
{

}

CoreException::~CoreException()
{

}
