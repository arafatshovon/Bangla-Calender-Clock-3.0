#include <MD_MAX72xx.h>
#include <SPI.h>
#include <RtcDS1302.h>
#include "conv.h"

#include <SoftwareSerial.h>

const byte rxPin = 4;
const byte txPin = 5;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

// RTC CONNECTIONS:
// DS1302 CLK/SCLK --> 7
// DS1302 DAT/IO --> 6
// DS1302 RST/CE --> 8
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

ThreeWire myWire(6,7,8); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

//LED_Matrix SPI Arduino UNO
// CLK Pin  > 13 SCK
// Data Pin > 11 MOSI
#define CS_PIN    3
#define  delay_t  50  // in milliseconds

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 16
// Hardware SPI connection
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//defining Bangla Characters

//byte zero[8] = {0x30,0x78,0xcc,0xcc,0xcc,0xcc,0x78,0x30};
byte zero[8] = {0x30,0x48,0x84,0x84,0x84,0x84,0x48,0x30};
//byte one[8] = {0x40,0x60,0x30,0x18,0x0c,0xcc,0xd8,0x70};
byte one[8] = {0x20,0x10,0x08,0x04,0x04,0x64,0x68,0x30};
byte two[8] = {0x10,0x10,0x08,0x04,0x44,0x38,0x10,0x0c};
//byte three[8] = {0x30,0xb8,0xb4,0x84,0x84,0xc4,0x6c,0x38};
byte three[8] = {0x10,0x38,0xb4,0x84,0x84,0x84,0x48,0x30};
byte four[8] = {0x38,0x44,0x44,0x38,0x44,0x44,0x44,0x38};
byte five[8] = {0x44,0x7c,0x48,0x48,0x4a,0x4c,0x24,0x18};
byte six[8] = {0x10,0x10,0x94,0x94,0x9c,0x84,0xcc,0x78};
byte seven[8] = {0x30,0x78,0xc8,0xc8,0x78,0x08,0x08,0x08};
byte eight[8] = {0xc4,0x44,0x48,0x70,0x58,0x58,0x58,0x70};
byte nine[8] = {0x60,0x30,0x1c,0x04,0x74,0xd4,0x5c,0x10};


byte shoni_0[8]={0x00,0x00,0xdb,0x26,0x52,0x02,0x02,0x02};
byte shoni_1[8]={0x7e,0x80,0xff,0x82,0xba,0xa6,0xb2,0x82};
byte robi_0[8]={0x00,0x00,0xff,0x1c,0x24,0x64,0x14,0x2c};
byte robi_1[8]={0x7f,0x80,0xff,0x8e,0x92,0xb2,0x8a,0x86};
byte shom_0[8]={0xff,0x51,0x89,0x85,0x95,0x9b,0x81,0x61};
byte shom_1[8]={0xff,0x51,0x49,0x45,0x5d,0x5d,0x5b,0x41};
byte mongol_0[8]={0xf9,0x8a,0x4a,0x28,0xe9,0xaa,0xd8,0x08};
byte mongol_1[8]={0x11,0xa1,0xc1,0x95,0xab,0xa1,0x81,0x71};
byte budh_0[8]={0x00,0xff,0x0e,0x12,0x22,0x12,0x0f,0x06};
byte budh_1[8]={0x18,0x20,0x1e,0x34,0x44,0x64,0x14,0x8c};
byte brihoshpoti_0[8]={0xff,0x1c,0x24,0x44,0x34,0x0c,0x10,0x0e};
byte brihoshpoti_1[8]={0xfc,0x70,0x8b,0x8b,0x30,0xc3,0x23,0x18};
byte shukro_0[8]={0x0f,0xa8,0x58,0xa8,0x08,0x08,0x1c,0x1a};
byte shukro_1[8]={0xff,0x1c,0x2a,0x49,0xcb,0x28,0x98,0x78};

byte boishakh_0[8]={0x04,0x06,0x01,0x01,0x02,0x02,0x02,0x01};
byte boishakh_1[8]={0x00,0xfd,0x0c,0x15,0x24,0x44,0x34,0x8c};
byte boishakh_2[8]={0x00,0x5d,0xb5,0x54,0x15,0x15,0x15,0x14};
byte boishakh_3[8]={0x00,0x5c,0xd0,0x50,0xd0,0x10,0x90,0xf0};
byte joishtho_0[8]={0x08,0x07,0x04,0x08,0x0a,0x0a,0x09,0x04};
byte joishtho_1[8]={0x00,0xff,0x30,0x48,0x46,0x74,0x28,0xc8};
byte joishtho_2[8]={0x08,0xe7,0x48,0x8f,0x91,0x5e,0x40,0xc0};
byte joishtho_3[8]={0x00,0xf0,0x80,0x40,0x20,0x90,0x90,0x60};
byte ashar_0[8]={0x3f,0x00,0x01,0x13,0x13,0x10,0x08,0x07};
byte ashar_1[8]={0xff,0x15,0x94,0x54,0x54,0x55,0xf4,0x94};
byte ashar_2[8]={0xff,0x14,0x94,0x54,0xb4,0x14,0x94,0x74};
byte ashar_3[8]={0xfe,0x80,0x90,0xb8,0x98,0x90,0xa0,0xd0};
byte srabon_0[8]={0x1b,0x04,0x0e,0x00,0x10,0x0f,0x00,0x00};
byte srabon_1[8]={0x7f,0xd0,0x51,0x52,0x54,0x56,0xd1,0x00};
byte srabon_2[8]={0xcd,0xd3,0x59,0x59,0x41,0x41,0xc1,0x00};
byte srabon_3[8]={0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte vadro_0[8]={0x03,0x00,0x02,0x02,0x02,0x02,0x01,0x00};
byte vadro_1[8]={0xff,0x20,0x74,0x46,0x3a,0x02,0x04,0xf8};
byte vadro_2[8]={0xff,0x44,0x44,0x45,0x46,0x50,0x4f,0x40};
byte vadro_3[8]={0xf0,0x00,0xc0,0x40,0x40,0x40,0x40,0xc0};
byte ashwin_0[8]={0x00,0x00,0x07,0x14,0x16,0x10,0x1f,0x00};
byte ashwin_1[8]={0x03,0x02,0xaa,0xaa,0xaa,0xea,0xaa,0x2a};
byte ashwin_2[8]={0xf0,0x00,0xb5,0x4c,0xa5,0x0d,0x15,0x1c};
byte ashwin_3[8]={0x00,0x00,0xf8,0x08,0xe8,0x18,0x88,0x08};
byte kartik_0[8]={0x00,0x00,0x07,0x00,0x01,0x02,0x03,0x00};
byte kartik_1[8]={0x00,0x00,0xff,0xf2,0x4a,0x5a,0x42,0xc2};
byte kartik_2[8]={0x7e,0x81,0xff,0x86,0xad,0xa1,0x91,0x8e};
byte kartik_3[8]={0x80,0x00,0xff,0x1e,0x29,0x4b,0x68,0x18};
byte ogrohayon_0[8]={0xfe,0x33,0xba,0x8b,0x8a,0x8b,0x5e,0x22};
byte ogrohayon_1[8]={0xcf,0xa9,0x5b,0xcb,0x08,0x0b,0xe8,0x18};
byte ogrohayon_2[8]={0xff,0x4c,0x2a,0x29,0x4a,0x8c,0x4b,0x2a};
byte ogrohayon_3[8]={0xe1,0x4d,0x53,0x59,0x59,0x41,0x41,0xc1};
byte poush_0[8] = {0x00,0x0f,0x04,0x08,0x08,0x08,0x0e,0x06};
byte poush_1[8] = {0x02,0x77,0x8d,0x95,0xe5,0x05,0x05,0x05};
byte poush_2[8] = {0x00,0xff,0x21,0x11,0x0d,0x13,0x21,0x1f};
byte poush_3[8]{0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00};
byte magh_0[8]={0x00,0x01,0x01,0x00,0x00,0x01,0x01,0x00};
byte magh_1[8]={0xfa,0x0a,0x0a,0x8a,0xca,0xea,0xda,0x00};
byte magh_2[8]={0xfc,0x84,0x84,0x74,0x24,0x44,0x7c,0x00};
byte magh_3[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte falgun_0[8]={0x0f,0x04,0x02,0x02,0x04,0x08,0x06,0x01};
byte falgun_1[8]={0xfc,0x05,0xe4,0x94,0xb5,0x84,0x85,0x84};
byte falgun_2[8]={0xaf,0x58,0x08,0xe8,0x99,0x48,0x9c,0x1a};
byte falgun_3[8]={0xfc,0x08,0x08,0xe8,0x98,0x88,0x08,0x08};
byte choitro_0[8]={0x04,0x03,0x01,0x02,0x02,0x02,0x02,0x01};
byte choitro_1[8]={0x00,0xff,0x40,0x4c,0x74,0x45,0x48,0x70};
byte choitro_2[8]={0x00,0xfe,0x30,0x68,0x68,0x08,0xe8,0x18};
byte choitro_3[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


//fetched data array
byte fetched_time[6]={2,0,3,3,8,7}; //timeformat: hhmmss
int bn_year_arr[4] = {0, 0, 0, 0};
int bn_date_arr[4] = {0,0};
int dayOfTheWeek = 0;
int bn_month = 0;

byte hour_0[8];
byte hour_1[8];
byte mins_0[8];
byte mins_1[8];

byte year_0[8];
byte year_1[8];
byte year_2[8];
byte year_3[8];

byte date_0[8];
byte date_1[8];

byte dayotw_0[8];
byte dayotw_1[8];

byte monthBn_0[8];
byte monthBn_1[8];
byte monthBn_2[8];
byte monthBn_3[8];


// blinking time seperator
int blink_yes = 0;
byte add_dots[8] = {0x00,0x01,0x01,0x00,0x00,0x01,0x01,0x00};


void setup_rtc () 
{
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
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

char c;

int year, month, day, dayOfWeek, hour, min, sec;
int deltaHour=0, deltaMin=0, deltaSec=0;

void updateNTPTime()
{
  mySerial.println("U");
  RtcDateTime now = Rtc.GetDateTime();
  String res = "";
  c = ' ';
  // check if data is available
  int count = 0;

  while (1) {
    if (mySerial.available() > 0) {
      if (mySerial.read() == '#') break;
    }
    if (count > 500) return;
    Serial.println(count);
    count += 1;
  }

  while (c != '\n') {
      if (mySerial.available() > 0) {
        if (c == '.') return;
        c = mySerial.read();
        res += c;
    }
    if (count > 500) return;
    Serial.println(count);
    count += 1;
  }
  sscanf(res.c_str(), "%d %d %d %d %d %d %d", &year, &month, &day, &dayOfWeek, &hour, &min, &sec);
  deltaHour = hour - now.Hour();
  deltaMin = min - now.Minute();
  deltaSec = sec - now.Second();
}

void setup_esp8266()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  updateNTPTime();
}

void setup() {
  // Serial.begin(115200);
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 0);
  mx.clear();
  setup_rtc();
  delay(12000);
  setup_esp8266();
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  updateTime(now);
  updateDate(now);
  updateMonth(now);
  updateYear(now);
  updateDayOfWeek(now);
  setTime();
  drawShape();
}

int myDiv(int a, int b)
{
  if(a<0) return -1;
  else return a/b;
}

void updateTime(const RtcDateTime& dt)
{
  // int sec = (dt.Second() + deltaSec) % 60;
  // int min = (dt.Minute() + deltaMin + (dt.Second() + deltaSec) / 60) % 60;
  // int hour = (dt.Hour() + deltaHour + (dt.Minute() + deltaMin + (dt.Second() + deltaSec) / 60) / 60) % 24;
  
  
  int sec = dt.Second() + deltaSec;
  sec = (sec + 60) % 60;
  int min = dt.Minute() + deltaMin + myDiv(dt.Second() + deltaSec, 60) ;
  min = (min + 60) % 60;
  int hour = dt.Hour() + deltaHour + myDiv(dt.Minute() + deltaMin + myDiv(dt.Second() + deltaSec, 60), 60) ;
  hour = (hour + 24) % 24;


  fetched_time[0] = hour / 10;
  fetched_time[1] = hour % 10;
  fetched_time[2] = min / 10;
  fetched_time[3] = min % 10;
  fetched_time[4] = sec / 10;
  fetched_time[5] = sec % 10;

  blink_yes = fetched_time[5] % 2 ;

  if ((min + sec) == 0) updateNTPTime();
}

void updateDate(const RtcDateTime& dt)
{
  Bdate date = EnglishToBangla(dt.Day(),dt.Month(),dt.Year());
  for (int i=1; i >= 0; i--)
  {
    bn_date_arr[i] = date.banglaDate % 10;
    date.banglaDate = date.banglaDate / 10;
  }
}

void updateMonth(const RtcDateTime& dt)
{
  Bdate date = EnglishToBangla(dt.Day(),dt.Month(),dt.Year());
  bn_month = date.banglaMonthIndex;
}


void updateYear(const RtcDateTime& dt)
{
  int x = EnToBnYear(dt.Year(), dt.Month(), dt.Day());
  for (int i=3; i >= 0; i--)
  {
    bn_year_arr[i] = x % 10;
    x = x / 10;
  }
}

void updateDayOfWeek(const RtcDateTime& dt){
  dayOfTheWeek = dt.DayOfWeek();
}



void setTime(){
  setHour();
  setMinute();
  setDateBn();
  setMonth();
  setYear();
  setDayOTW();
}



void setMonth(){
  
  if(bn_month == 1)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = boishakh_0[i];
      monthBn_1[i] = boishakh_1[i];
      monthBn_2[i] = boishakh_2[i];
      monthBn_3[i] = boishakh_3[i];
  }

  else if(bn_month == 2)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = joishtho_0[i];
      monthBn_1[i] = joishtho_1[i];
      monthBn_2[i] = joishtho_2[i];
      monthBn_3[i] = joishtho_3[i];
     }
  
  else if(bn_month == 3)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = ashar_0[i];
      monthBn_1[i] = ashar_1[i];
      monthBn_2[i] = ashar_2[i];
      monthBn_3[i] = ashar_3[i];
     }
  
  else if(bn_month == 4)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = srabon_0[i];
      monthBn_1[i] = srabon_1[i];
      monthBn_2[i] = srabon_2[i];
      monthBn_3[i] = srabon_3[i];
     }


  else if(bn_month == 5)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = vadro_0[i];
      monthBn_1[i] = vadro_1[i];
      monthBn_2[i] = vadro_2[i];
      monthBn_3[i] = vadro_3[i];
     }
  
  
  else if(bn_month == 6)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = ashwin_0[i];
      monthBn_1[i] = ashwin_1[i];
      monthBn_2[i] = ashwin_2[i];
      monthBn_3[i] = ashwin_3[i];
     }
  
  else if(bn_month == 7)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = kartik_0[i];
      monthBn_1[i] = kartik_1[i];
      monthBn_2[i] = kartik_2[i];
      monthBn_3[i] = kartik_3[i];
     }
  
  else if(bn_month == 9)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = ogrohayon_0[i];
      monthBn_1[i] = ogrohayon_1[i];
      monthBn_2[i] = ogrohayon_2[i];
      monthBn_3[i] = ogrohayon_3[i];
     }
  

  else if(bn_month == 9)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = poush_0[i];
      monthBn_1[i] = poush_1[i];
      monthBn_2[i] = poush_2[i];
      monthBn_3[i] = poush_3[i];
     }
  
  else if(bn_month == 10)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = magh_0[i];
      monthBn_1[i] = magh_1[i];
      monthBn_2[i] = magh_2[i];
      monthBn_3[i] = magh_3[i];
     }
  

  else if(bn_month == 11)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = falgun_0[i];
      monthBn_1[i] = falgun_1[i];
      monthBn_2[i] = falgun_2[i];
      monthBn_3[i] = falgun_3[i];
     }
  

  else if(bn_month == 12)
     for (int i=0; i<=7; i++){
      monthBn_0[i] = choitro_0[i];
      monthBn_1[i] = choitro_1[i];
      monthBn_2[i] = choitro_2[i];
      monthBn_3[i] = choitro_3[i];
     }
  
  else
     for (int i=0; i<=7; i++){
      monthBn_0[i] = zero[i];
      monthBn_1[i] = zero[i];
      monthBn_2[i] = zero[i];
      monthBn_3[i] = zero[i];
     }  
  
}


void setDayOTW(){
  if(dayOfTheWeek == 6){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = shoni_0[i];
      dayotw_1[i] = shoni_1[i];
    }
  }
  if(dayOfTheWeek == 0){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = robi_0[i];
      dayotw_1[i] = robi_1[i];
    }
  }
   if(dayOfTheWeek == 1){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = shom_0[i];
      dayotw_1[i] = shom_1[i];
    }
  }
   if(dayOfTheWeek == 2){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = mongol_0[i];
      dayotw_1[i] = mongol_1[i];
    }
  }
   if(dayOfTheWeek == 3){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = budh_0[i];
      dayotw_1[i] = budh_1[i];
    }
  }
   if(dayOfTheWeek == 4){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = brihoshpoti_0[i];
      dayotw_1[i] = brihoshpoti_1[i];
    }
  }
   if(dayOfTheWeek == 5){
    for (int i=0; i<=7; i++){ 
      dayotw_0[i] = shukro_0[i];
      dayotw_1[i] = shukro_1[i];
    }
  }
    
 
  

  
}

void setDateBn(){
  // first digit of date
  if (bn_date_arr[0] == 0){

    for (int i=0; i<=7; i++){
      
      date_0[i] = zero[i];

    }      
  }

  if (bn_date_arr[0] == 1){

    for (int i=0; i<=7; i++){
      
      date_0[i] = one[i];

    }      
  }

  if (bn_date_arr[0] == 2){

    for (int i=0; i<=7; i++){
      
      date_0[i] = two[i];

    }      
  }
  if (bn_date_arr[0] == 3){

    for (int i=0; i<=7; i++){
      
      date_0[i] = three[i];

    }      
  }

  if (bn_date_arr[0] == 4){

    for (int i=0; i<=7; i++){
      
      date_0[i] = four[i];

    }      
  }
  if (bn_date_arr[0] == 5){

    for (int i=0; i<=7; i++){
      
      date_0[i] = five[i];

    }      
  }
  if (bn_date_arr[0] == 6){

    for (int i=0; i<=7; i++){
      
      date_0[i] = six[i];

    }      
  }
  if (bn_date_arr[0] == 7){

    for (int i=0; i<=7; i++){
      
      date_0[i] = seven[i];

    }      
  }
  if (bn_date_arr[0] == 8){

    for (int i=0; i<=7; i++){
      
      date_0[i] = eight[i];

    }      
  }
  if (bn_date_arr[0] == 9){

    for (int i=0; i<=7; i++){
      
      date_0[i] = nine[i];

    }      
  }

  // 2nd digit date

  if (bn_date_arr[1] == 0){

    for (int i=0; i<=7; i++){
      
      date_1[i] = zero[i];

    }      
  }

  if (bn_date_arr[1] == 1){

    for (int i=0; i<=7; i++){
      
      date_1[i] = one[i];

    }      
  }

  if (bn_date_arr[1] == 2){

    for (int i=0; i<=7; i++){
      
      date_1[i] = two[i];

    }      
  }
  if (bn_date_arr[1] == 3){

    for (int i=0; i<=7; i++){
      
      date_1[i] = three[i];

    }      
  }

  if (bn_date_arr[1] == 4){

    for (int i=0; i<=7; i++){
      
      date_1[i] = four[i];

    }      
  }
  if (bn_date_arr[1] == 5){

    for (int i=0; i<=7; i++){
      
      date_1[i] = five[i];

    }      
  }
  if (bn_date_arr[1] == 6){

    for (int i=0; i<=7; i++){
      
      date_1[i] = six[i];

    }      
  }
  if (bn_date_arr[1] == 7){

    for (int i=0; i<=7; i++){
      
      date_1[i] = seven[i];

    }      
  }
  if (bn_date_arr[1] == 8){

    for (int i=0; i<=7; i++){
      
      date_1[i] = eight[i];

    }      
  }
  if (bn_date_arr[1] == 9){

    for (int i=0; i<=7; i++){
      
      date_1[i] = nine[i];

    }      
  }


}



void setYear(){
  // first digit of year
  if (bn_year_arr[0] == 0){

    for (int i=0; i<=7; i++){
      
      year_0[i] = zero[i];

    }      
  }

  if (bn_year_arr[0] == 1){

    for (int i=0; i<=7; i++){
      
      year_0[i] = one[i];

    }      
  }

  if (bn_year_arr[0] == 2){

    for (int i=0; i<=7; i++){
      
      year_0[i] = two[i];

    }      
  }
  if (bn_year_arr[0] == 3){

    for (int i=0; i<=7; i++){
      
      year_0[i] = three[i];

    }      
  }

  if (bn_year_arr[0] == 4){

    for (int i=0; i<=7; i++){
      
      year_0[i] = four[i];

    }      
  }
  if (bn_year_arr[0] == 5){

    for (int i=0; i<=7; i++){
      
      year_0[i] = five[i];

    }      
  }
  if (bn_year_arr[0] == 6){

    for (int i=0; i<=7; i++){
      
      year_0[i] = six[i];

    }      
  }
  if (bn_year_arr[0] == 7){

    for (int i=0; i<=7; i++){
      
      year_0[i] = seven[i];

    }      
  }
  if (bn_year_arr[0] == 8){

    for (int i=0; i<=7; i++){
      
      year_0[i] = eight[i];

    }      
  }
  if (bn_year_arr[0] == 9){

    for (int i=0; i<=7; i++){
      
      year_0[i] = nine[i];

    }      
  }

  // 2nd digit year

  if (bn_year_arr[1] == 0){

    for (int i=0; i<=7; i++){
      
      year_1[i] = zero[i];

    }      
  }

  if (bn_year_arr[1] == 1){

    for (int i=0; i<=7; i++){
      
      year_1[i] = one[i];

    }      
  }

  if (bn_year_arr[1] == 2){

    for (int i=0; i<=7; i++){
      
      year_1[i] = two[i];

    }      
  }
  if (bn_year_arr[1] == 3){

    for (int i=0; i<=7; i++){
      
      year_1[i] = three[i];

    }      
  }

  if (bn_year_arr[1] == 4){

    for (int i=0; i<=7; i++){
      
      year_1[i] = four[i];

    }      
  }
  if (bn_year_arr[1] == 5){

    for (int i=0; i<=7; i++){
      
      year_1[i] = five[i];

    }      
  }
  if (bn_year_arr[1] == 6){

    for (int i=0; i<=7; i++){
      
      year_1[i] = six[i];

    }      
  }
  if (bn_year_arr[1] == 7){

    for (int i=0; i<=7; i++){
      
      year_1[i] = seven[i];

    }      
  }
  if (bn_year_arr[1] == 8){

    for (int i=0; i<=7; i++){
      
      year_1[i] = eight[i];

    }      
  }
  if (bn_year_arr[1] == 9){

    for (int i=0; i<=7; i++){
      
      year_1[i] = nine[i];

    }      
  }

  //3rd digit

  if (bn_year_arr[2] == 0){

    for (int i=0; i<=7; i++){
      
      year_2[i] = zero[i];

    }      
  }

  if (bn_year_arr[2] == 1){

    for (int i=0; i<=7; i++){
      
      year_2[i] = one[i];

    }      
  }

  if (bn_year_arr[2] == 2){

    for (int i=0; i<=7; i++){
      
      year_2[i] = two[i];

    }      
  }
  if (bn_year_arr[2] == 3){

    for (int i=0; i<=7; i++){
      
      year_2[i] = three[i];

    }      
  }

  if (bn_year_arr[2] == 4){

    for (int i=0; i<=7; i++){
      
      year_2[i] = four[i];

    }      
  }
  if (bn_year_arr[2] == 5){

    for (int i=0; i<=7; i++){
      
      year_2[i] = five[i];

    }      
  }
  if (bn_year_arr[2] == 6){

    for (int i=0; i<=7; i++){
      
      year_2[i] = six[i];

    }      
  }
  if (bn_year_arr[2] == 7){

    for (int i=0; i<=7; i++){
      
      year_2[i] = seven[i];

    }      
  }
  if (bn_year_arr[2] == 8){

    for (int i=0; i<=7; i++){
      
      year_2[i] = eight[i];

    }      
  }
  if (bn_year_arr[2] == 9){

    for (int i=0; i<=7; i++){
      
      year_2[i] = nine[i];

    }      
  }

  // 4th digit

  if (bn_year_arr[3] == 0){

    for (int i=0; i<=7; i++){
      
      year_3[i] = zero[i];

    }      
  }

  if (bn_year_arr[3] == 1){

    for (int i=0; i<=7; i++){
      
      year_3[i] = one[i];

    }      
  }

  if (bn_year_arr[3] == 2){

    for (int i=0; i<=7; i++){
      
      year_3[i] = two[i];

    }      
  }
  if (bn_year_arr[3] == 3){

    for (int i=0; i<=7; i++){
      
      year_3[i] = three[i];

    }      
  }

  if (bn_year_arr[3] == 4){

    for (int i=0; i<=7; i++){
      
      year_3[i] = four[i];

    }      
  }
  if (bn_year_arr[3] == 5){

    for (int i=0; i<=7; i++){
      
      year_3[i] = five[i];

    }      
  }
  if (bn_year_arr[3] == 6){

    for (int i=0; i<=7; i++){
      
      year_3[i] = six[i];

    }      
  }
  if (bn_year_arr[3] == 7){

    for (int i=0; i<=7; i++){
      
      year_3[i] = seven[i];

    }      
  }
  if (bn_year_arr[3] == 8){

    for (int i=0; i<=7; i++){
      
      year_3[i] = eight[i];

    }      
  }
  if (bn_year_arr[3] == 9){

    for (int i=0; i<=7; i++){
      
      year_3[i] = nine[i];

    }      
  }
  
}

void setHour(){
  
  // setting first digit
  if (fetched_time[0] == 0){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = zero[i];

    }      
  }

  if (fetched_time[0] == 1){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = one[i];

    }      
  }

  if (fetched_time[0] == 2){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = two[i];

    }      
  }
  if (fetched_time[0] == 3){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = three[i];

    }      
  }

  if (fetched_time[0] == 4){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = four[i];

    }      
  }
  if (fetched_time[0] == 5){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = five[i];

    }      
  }
  if (fetched_time[0] == 6){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = six[i];

    }      
  }
  if (fetched_time[0] == 7){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = seven[i];

    }      
  }
  if (fetched_time[0] == 8){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = eight[i];

    }      
  }
  if (fetched_time[0] == 9){

    for (int i=0; i<=7; i++){
      
      hour_0[i] = nine[i];

    }      
  }

  // 2nd digit hour

  if (fetched_time[1] == 0){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  zero[i];

    }      
  }

  if (fetched_time[1] == 1){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  one[i];

    }      
  }

  if (fetched_time[1] == 2){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  two[i];

    }      
  }
  if (fetched_time[1] == 3){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  three[i];

    }      
  }

  if (fetched_time[1] == 4){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  four[i];

    }      
  }
  if (fetched_time[1] == 5){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  five[i];

    }      
  }
  if (fetched_time[1] == 6){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  six[i];

    }      
  }
  if (fetched_time[1] == 7){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  seven[i];

    }      
  }
  if (fetched_time[1] == 8){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  eight[i];

    }      
  }
  if (fetched_time[1] == 9){

    for (int i=0; i<=7; i++){
      
      hour_1[i] =  nine[i];

    }      
  }
  
  
    if (blink_yes == 1){
       for (int i=0; i<=7; i++){
      
        hour_1[i] = hour_1[i] + add_dots[i];

      }

    }  
  
  //Serial.println("Hour printed");
}

void setMinute(){
  
  //setting third digit
  if (fetched_time[2] == 0){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = zero[i];

    }      
  }

  if (fetched_time[2] == 1){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = one[i];

    }      
  }

  if (fetched_time[2] == 2){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = two[i];

    }      
  }
  if (fetched_time[2] == 3){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = three[i];

    }      
  }

  if (fetched_time[2] == 4){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = four[i];

    }      
  }
  if (fetched_time[2] == 5){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = five[i];

    }      
  }
  if (fetched_time[2] == 6){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = six[i];

    }      
  }
  if (fetched_time[2] == 7){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = seven[i];

    }      
  }
  if (fetched_time[2] == 8){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = eight[i];

    }      
  }
  if (fetched_time[2] == 9){

    for (int i=0; i<=7; i++){
      
      mins_0[i] = nine[i];

    }      
  }

  //setting fourth digit

    if (fetched_time[3] == 0){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = zero[i];

    }      
  }

  if (fetched_time[3] == 1){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = one[i];

    }      
  }

  if (fetched_time[3] == 2){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = two[i];

    }      
  }
  if (fetched_time[3] == 3){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = three[i];

    }      
  }

  if (fetched_time[3] == 4){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = four[i];

    }      
  }
  if (fetched_time[3] == 5){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = five[i];

    }      
  }
  if (fetched_time[3] == 6){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = six[i];

    }      
  }
  if (fetched_time[3] == 7){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = seven[i];

    }      
  }
  if (fetched_time[3] == 8){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = eight[i];

    }      
  }
  if (fetched_time[3] == 9){

    for (int i=0; i<=7; i++){
      
      mins_1[i] = nine[i];

    }      
  }
  //Serial.println("Mins printed");
}


void drawShape() {

      /*setRow(startDev, endDev, r, value)
      startDev – from which division you want to display the character.
      endDev – at which division you want to stop.
      r – no of the row which is to be set.
      value – bit map of that row.
    */

  // time showing display 
  for (int i = 0; i <= 7; i++) {
    //mx.setRow(3, 3, i, hour_0[i]);
    mx.setRow(3, 3, i, hour_0[i]);
    
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, hour_1[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, mins_0[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, mins_1[i]);
  }
  delay(delay_t);

  // day,date showing display 
  for (int i = 0; i <= 7; i++) {
    
    mx.setRow(15, 15, i, dayotw_0[i]);
    
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(14, 14, i, dayotw_1[i]);
  }
  delay(delay_t);
  
  for (int i = 0; i <= 7; i++) {
    mx.setRow(13, 13, i, date_0[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(12, 12, i, date_1[i]);
  }
  delay(delay_t);

  // month showing display 
  for (int i = 0; i <= 7; i++) {
    
    mx.setRow(11, 11, i, monthBn_0[i]);
    
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(10, 10, i, monthBn_1[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(9, 9, i, monthBn_2[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(8, 8, i, monthBn_3[i]);
  }
  delay(delay_t);



//Year Showing Display

  for (int i = 0; i <= 7; i++) {
    //mx.setRow(3, 3, i, hour_0[i]);
    mx.setRow(7, 7, i, year_0[i]);
    
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, year_1[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, year_2[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, year_3[i]);
  }
  delay(delay_t);

}
  
  
