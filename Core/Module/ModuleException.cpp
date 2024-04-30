#include "ModuleException.h"

using namespace START_APP_NAMESPACE;

ModuleException::ModuleException(const QString &message) :
    Exception( QString("[MODULE_EXCEPTION] " + message) )
{

}

ModuleException::~ModuleException()
{

}
