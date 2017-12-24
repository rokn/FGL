#include <FloatingNetwork.h>
#include "Application.h"

int main() {
    Config config;
    config.windowWidth = 1000;
    config.windowHeight = 800;
    config.appName = "FGL";
    config.antialiasLevel = 4;

    Application *application = new Application(config);

    sf::Rect<int> area(0, 0, config.windowWidth, config.windowHeight);
    FloatingNetwork *network = new FloatingNetwork(area, 69, 1200);

    application->registerHandler(network);

    int exitCode = application->run();


    delete network;
    delete application;

    return exitCode;
}
