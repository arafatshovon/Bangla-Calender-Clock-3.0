
// CONNECTIONS:
// DS1302 CLK/SCLK --> 7
// DS1302 DAT/IO --> 6
// DS1302 RST/CE --> 8
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <RtcDS1302.h>
#include "conv.h"

ThreeWire myWire(6,7,8); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup () 
{
    Serial.begin(57600);

    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) 
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled) 
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}

void loop () 
{
    RtcDateTime now = Rtc.GetDateTime();


    Serial.print(now.Hour());
    Serial.print(":");
    Serial.print(now.Minute());
    Serial.print(":");
    Serial.print(now.Second());
    Serial.println();


    if (!now.IsValid())
    {
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(10000); // ten seconds
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
    char datestring[26];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
    Serial.print(" : Date");


    
}



void printDateTimeBn(const RtcDateTime& dt)
{
    char datestring[26];
    struct Bdate date;
    date = EnglishToBangla(dt.Day(),dt.Month(),dt.Year());
    
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            date.banglaMonthIndex,
            date.banglaDate,
            date.banglaYear,
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
    Serial.print(" :Bangla Date");


    
}
