// Print the times the timer expires in a interval of 1s up to 10
int i = 0;
void callback()
{
    TL_Temperature.read();
    TL_Serial.print("Temperature data is ");
    TL_Serial.println(TL_Temperature.data());
    TL_Time.delayMillis(1000);

    TL_Light.read();
    TL_Serial.print("Light data is ");
    TL_Serial.println(TL_Light.data());
    TL_Time.delayMillis(1000);
}
void setup()
{
    TL_Serial.begin(9600);
    // Set the period and the type of the timer
    TL_Timer.setPeriod(1000, TIMER_PERIODIC);
    // Attach the callback function to the timer. When the timer expires, the callback function will be excuted
    TL_Timer.attachInterrupt(callback);
    // Start the timer
    TL_Timer.start();
    TL_Time.delayMillis(10000);
    //Stop the timer
    TL_Timer.stop();
}

void loop()
{
}