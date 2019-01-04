TinyApp SmartLED{
Interface:
    TL_Data LIGHT;
    // TL_Data TEMP;
    // TL_Data HUMI;
Program:
    void setup() {
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
    // TL_Chart C2;
    // TL_Chart C3;
    void setup(){
      C1.bindData(SL1::LIGHT);
    //   C2.bindData(SL1::TEMP);
    //   C3.bindData(SL1::HUMI);
      TL_UI.append({C1});
    }
}CP;
