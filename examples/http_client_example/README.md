## HTTPClient Example

This example demonstrates how to utilize the `http_client` component to control a shelly plug.

## Hardware

* A shelly plug with an IP address in the connected WLAN is needed in this example.

## Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

* Run `. <directory with ESP-IDF version>/export.sh` to set IDF environment
* Run `idf.py set-target esp32xx` to set target chip
* Run `idf.py -p PORT flash monitor` to build, flash and monitor the project

(To exit the serial monitor, type `Ctrl-]` (or on a Mac `Ctrl-Option-6`).

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

## Example Output

If a Shelly Plug is available at the given IP address the end of the log file looks like this:
```
I (10575) WifiManager: Wifi station is connected
I (10575) HTTPClient-Test: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=false
I (10585) wifi:<ba-add>idx:0 (ifx:0, 74:42:7f:fe:b3:ee), tid:0, ssn:0, winSize:64
I (10645) HTTPClient-Test: HTTP GET code: 200
I (10645) HTTPClient-Test: HTTP GET successful.
I (11645) HTTPClient-Test: Response: {"was_on":false}
I (11645) main_task: Returned from app_main()
```

If no Shelly Plug is available at the given IP address the end of the log file looks like this:
```
I (6555) WifiManager: Wifi station is connected
I (6555) HTTPClient-Test: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=false
E (11565) esp-tls: [sock=54] select() timeout
E (11565) transport_base: Failed to open a new connection: 32774
E (11565) HTTP_CLIENT: Connection failed, sock < 0
E (11565) HTTP: Failed to open HTTP connection: ESP_ERR_HTTP_CONNECT
E (11565) HTTP: error(-1): connection refused
E (11575) HTTPClient-Test: HTTP GET failed, error: connection refused
I (11585) main_task: Returned from app_main()
```

Because ESP-IDF component 78/esp-wifi-connect in version 3.1.2 not yet supports ESP-IDF version 6, this example contains a modified version in directory components.