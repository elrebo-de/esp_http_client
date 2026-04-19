| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-H21 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | --------- | -------- | --------- | -------- | -------- | -------- |

# HTTPClient

This HTTPClient is a copy of the `HTTPClient` from `sachin42/idfcomponents`.
The first change is that now it is allowed to use method `addHeader` to set header "Authorization".

The second change is an extension in HTTPClient.cpp to enable to use ESP_IDF version 6.0+.

The original code can be found in GitHub: https://github.com/sachin42/idfcomponents.git in directory HTTPClient.
