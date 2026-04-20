/*
 * Example program to use a Shelly Plug with elrebo-de/http_client
 * (unless it would be better to use elrebo-de/shelly_plug for this task)
 */

#include <string>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "wifi_manager.hpp"
#include "HTTPClient.h"

static const char *tag = "HTTPClient-Test";

extern "C" void app_main(void)
{
    Wifi wifi( std::string("WifiManager"), // tag for ESP_LOGx
               std::string("ESP32"),       // ssid_prefix for configuration access point
               std::string("de-DE")        // language for configuration access point
             );

    /* Configure the ShellyPlug */
    std::string ipAddr = std::string("192.168.178.102");

    // initialize ShellyPlug HTTPClient
    HTTPClient *shellyPlug = new HTTPClient();

    // switch off shelly plug
    std::string command = "http://";
    command += ipAddr;
    command += "/rpc/Switch.Set?id=0&on=false";

    ESP_LOGI(tag, "ShellyPlug Command: %s", command.c_str());

    shellyPlug->begin(command.c_str());
    int httpCode = shellyPlug->GET();
    if (httpCode > 0)
    {
        ESP_LOGI(tag, "HTTP GET code: %d", httpCode);
        if (httpCode == HTTP_CODE_OK)
        {
            ESP_LOGI(tag, "HTTP GET successful.");

            // read response from GET
            std::string payload = "";
            if (shellyPlug->available() > 0 || shellyPlug->connected())
            {
                payload = std::string(shellyPlug->readString().c_str());
            }
            ESP_LOGI(tag, "Response: %s", payload.c_str()); // ReadString needs 1000 msec
        }
    }
    else
    {
        ESP_LOGE(tag, "HTTP GET failed, error: %s", HTTPClient::errorToString(httpCode).c_str());
    }
}
