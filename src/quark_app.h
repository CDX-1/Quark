#pragma once
#include "include/cef_app.h"

class QuarkApp : public CefApp, public CefBrowserProcessHandler {
public:
    QuarkApp() = default;

    CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
        return this;
    }

    void OnContextInitialized() override;

private:
    IMPLEMENT_REFCOUNTING(QuarkApp);
};