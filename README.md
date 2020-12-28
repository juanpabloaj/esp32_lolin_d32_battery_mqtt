# Battery voltage and MQTT

Before compile, create `configuration.h` file with

    const char *ssid = "";
    const char *password = "";
    const char *mqtt_server = "";

## Solar panel

Connect the solar panel to D32

    + -> USB
    - -> GND

More details in [G6EJD - Solar Power for Projects (Arduino/ESP8266/ESP32)](https://www.youtube.com/watch?v=gcbzdtRmYrM)

## Components

* [Lolin D32](https://www.wemos.cc/en/latest/d32/d32.html)
* [Solar Panel 80x100mm 1W](https://www.seeedstudio.com/1W-Solar-Panel-80X100.html)
* Lithium Ion Battery - 850mAh

## Free public MQTT brokers

* broker.hivemq.com

## References

* [G6EJD - David - Tech Note 130 - Solar Power for Projects (Arduino/ESP8266/ESP32)](https://www.youtube.com/watch?v=gcbzdtRmYrM)
* [ESP32 MQTT – Publish and Subscribe with Arduino IDE](https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/)
* [10 Free Public MQTT Brokers](https://mntolia.com/10-free-public-private-mqtt-brokers-for-testing-prototyping/)
