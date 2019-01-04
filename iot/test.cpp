String url("http://192.168.31.221/test?");
TL_HTTP http_client;

void setup() {
    TL_Serial.begin(9600);
    bool a = TL_WiFi.init();
    if(a) {
        TL_Serial.println("WiFi module initialization succeeds");
    }
    else {
        TL_Serial.println("WiFi module initialization fails");
    }
    bool b = TL_WiFi.join("inyouzi", "13575756690");
    if(b) {
        TL_Serial.println("Joining the Wifi networks succeeds");
    }
    else {
        TL_Serial.println("Joining the Wifi networks fails");
    }
    http_client = TL_WiFi.fetchHTTP();
}

void loop() {
    TL_Light.read();
    TL_Serial.print("Light data is ");
    TL_Serial.println(TL_Light.data());

    TL_Temperature.read();
    TL_Serial.print("Temperature data is ");
    TL_Serial.println(TL_Temperature.data());

 TL_Humidity.read();
    TL_Serial.print("Humidity data is ");
    TL_Serial.println(TL_Humidity.data());

    TL_PM25.read();
    TL_Serial.print("PM25 data is ");
    TL_Serial.println(TL_PM25.data());

    bool result = http_client.get(url + "light=" + TL_Light.data() + "&temp=" + TL_Temperature.data() + "&humi=" + TL_Humidity.data() + "&pm25=" + TL_PM25.data());
    TL_Serial.println(result);

    TL_Time.delayMillis(1000);


}