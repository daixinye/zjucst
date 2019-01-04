TinyApp SmartLED{
Interface:
    TL_Data LIGHT;
Program:
    void setup() {
        TL_Connector.bind(TL_WiFi);
        TL_WiFi.join("inyouzi", "13575756690");
        LIGHT.bind(TL_Light);
    }
    void loop(){
        TL_Light.read();
        TL_Time.delayMillis(1000);
    }
}SL1;

TinyApp ControlPanel@Mobile{
Program:
    TL_Chart C1;
    void setup(){
      C1.bindData(SL1::LIGHT);
      TL_UI.append({C1});
    }
}CP;
