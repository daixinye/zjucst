TL_MQTT mqtt;

char SERVER_NAME[] = "a1LFDI6H9u4.iot-as-mqtt.cn-shanghai.aliyuncs.com";
char CLIENT_NAME[] = "FESA234FBDS24|securemode=3,signmethod=hmacsha1,timestamp=789|";
char TOPIC_NAME[] = "/sys/a1LFDI6H9u4/tqVcRpUvu3YGdpc8fu52/thing/event/property/post";
char USER_NAME[] = "tqVcRpUvu3YGdpc8fu52&a1LFDI6H9u4";
char PASSWORD[] = "6a408e3e3207d246dff671fbc46528e27fb47c06";
char SSID[] = "EmNets-301";
char PASS[] = "eagle402";
int PORT = 1883;

void setup() {
    TL_WiFi.init();
    mqtt = TL_WiFi.fetchMQTT();
    mqtt.connect(SERVER_NAME, PORT, CLIENT_NAME, USER_NAME, PASSWORD);
    TL_Serial.begin(9600);
}

void loop() {
    TL_Light.read();
    TL_Temperature.read();
    String data = "{\"id\" : \"789\", \"version\":\"1.0\", \"params\" : {";
    data += "\"LightLuxValue\":";
    data += TL_Light.data();
    data += ",\"CurrentTemperature\":";
    data += TL_Temperature.data();
    data += "},\"method\":\"thing.event.property.post\"}";
    TL_Serial.println(data);
    char buf[1000];
    data.toCharArray( buf,1000 );
    int res = mqtt.publish(TOPIC_NAME, buf, strlen(buf),0);
    TL_Serial.println(res);
    TL_Time.delayMillis(1000);
}