#include "quark_client.h"
#include "include/cef_app.h"
#include "include/wrapper/cef_helpers.h"

void QuarkClient::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
    CEF_REQUIRE_UI_THREAD();
    
    CefQuitMessageLoop();
}