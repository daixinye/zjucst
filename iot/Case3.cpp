TinyApp SmartDoor
{
Interface:
    TL_Event Ev({"Open", "Close"});
    bool TurnOnLED();
    bool TurnOffLED();
Program:
    double gyro_z[5] = {0.0};
    int i = 0;
    void setup()
    {
        TL_Connector.bind(TL_WiFi);
        TL_WiFi.join("onelink", "onelinktest");
    }
    void loop()
    {
        TL_Gyro.read();
        gyro_z[i] = TL_Gyro.data_z();
        i++;
        if (i == 5)
        {
            i = 0;
        }
        double sum = 0.0;
        double average = 0.0;
        for (int j = 0; j < 5; j++)
        {
            sum += gyro_z[j];
        }
        average = sum / 5;
        if (average < -10 && sum < -150)
        {
            Ev.trigger("Open");
            TurnOnLED();
            TL_Time.delayMillis(1000);
            for (int j = 0; j < 5; j++)
            {
                gyro_z[j] = 0;
            }
        }
        else if (average > 10 && sum > 150)
        {
            Ev.trigger("Close");
            TurnOffLED();
            TL_Time.delayMillis(1000);
            for (int j = 0; j < 5; j++)
            {
                gyro_z[j] = 0;
            }
        }
        TL_Time.delayMillis(100);
    }
    bool TurnOnLED()
    {
        TL_Bulb.turnOn();
        return true;
    }
    bool TurnOffLED()
    {
        TL_Bulb.turnOff();
        return true;
    }
}
SD;

TinyApp SmartLED
{
Interface:
    TL_Data LIGHT;
    bool TurnOnLED();
    bool TurnOffLED();
Program:
    void setup()
    {
        TL_Connector.bind(TL_WiFi);
        TL_WiFi.join("onelink", "onelinktest");
        LIGHT.bind(TL_Light);
    }
    bool TurnOnLED()
    {
        TL_Bulb.turnOn();
        return true;
    }
    bool TurnOffLED()
    {
        TL_Bulb.turnOff();
        return true;
    }
}
SL1, SL2;

TinyApp ControlPanel @Mobile
{
Program:
    TL_Button B1, B2;
    TL_Chart C1;
    TL_Text T1;
    void setup()
    {
        B1.setText("SL1 board LED Turn On!");
        B2.setText("SL1 board Turn Off!");
        C1.bindData(SL1::LIGHT);
        T1.bindData(SD::Ev);
        TL_UI.append({B1, B2, T1, C1});
    }
    void B1.isPressed()
    {
        SL1::TurnOnLED();
    }
    void B2.isPressed()
    {
        SL1::TurnOffLED();
    }
}
CP;

Policy IfNeedLED
{
Rule:
    If(SD::Ev.isTriggered("Open") && SL1::LIGHT.last() < 100)
    {
        For(L In{SL1, SL2})
        {
            L::TurnOnLED();
        }
    }
    If(SD::Ev.isTriggered("Close") && SL1::LIGHT.last() > 100)
    {
        For(L In{SL1, SL2})
        {
            L::TurnOffLED();
        }
    }
}
INL;