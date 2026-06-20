#pragma once
#include "include/cef_client.h"
#include "include/cef_life_span_handler.h"

class QuarkClient : public CefClient, public CefLifeSpanHandler {
public:
    QuarkClient() = default;

    CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
        return this;
    }

    void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

private:
    IMPLEMENT_REFCOUNTING(QuarkClient);
};