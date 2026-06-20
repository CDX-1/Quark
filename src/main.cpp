#include <windows.h>
#include "include/cef_app.h"
#include "quark_app.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    
    CefMainArgs main_args(hInstance);

    CefRefPtr<QuarkApp> app(new QuarkApp);
    
    int exit_code = CefExecuteProcess(main_args, app, nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }

    CefSettings settings;
    settings.no_sandbox = true; 
    
    CefInitialize(main_args, settings, app.get(), nullptr);
    
    CefRunMessageLoop();

    CefShutdown();

    return 0;
}