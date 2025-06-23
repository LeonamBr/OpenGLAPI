#include "application/Application.h"
#include "core/log.h"

extern Application* CreateApplication();

int main() {

    Log::Init();
    auto* app = CreateApplication();
    Application::Set(app);
    app->Run();
    delete app;
    return 0;
}