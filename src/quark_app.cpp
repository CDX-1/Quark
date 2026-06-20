#include "quark_app.h"
#include "quark_client.h"
#include "include/cef_browser.h"
#include "include/wrapper/cef_helpers.h"

void QuarkApp::OnContextInitialized() {
    CEF_REQUIRE_UI_THREAD();

    CefRefPtr<QuarkClient> client(new QuarkClient());

    CefWindowInfo window_info;
    
    CefBrowserSettings browser_settings;
    std::string url = "https://www.google.com";

    CefBrowserHost::CreateBrowser(
        window_info, 
        client, 
        url, 
        browser_settings, 
        nullptr, 
        nullptr
    );
}