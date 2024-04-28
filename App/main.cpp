#include "App.h"

using namespace START_APP_NAMESPACE;

int main(int argc, char *argv[])
{
    App _app(argc, argv);

    _app.init();
    _app.run();

    return _app.exec();
}
