#include "GuiException.h"

using namespace START_APP_NAMESPACE;

GuiException::GuiException(const QString &message) :
    Exception( QString("[GUI_EXCEPTION] " + message) )
{

}

GuiException::~GuiException()
{

}
