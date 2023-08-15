#include <MakerKit.h>
#include <ESP32Servo.h>

//#define BLYNK_TEMPLATE_ID           "TMPL64fd_eV-W"
//#define BLYNK_DEVICE_NAME           "IOT"
//#define BLYNK_AUTH_TOKEN            "RokUE6qCyAalm69nITSV8ZdzisbJzhKA"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Miasara";
char pass[] = "haikal236";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff6600);
    pixels.setPixelColor(2, 0xff0000);
    pixels.setPixelColor(3, 0xff6600);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3366ff);
    pixels.setPixelColor(1, 0xcc66cc);
    pixels.setPixelColor(2, 0x3366ff);
    pixels.setPixelColor(3, 0xcc66cc);
    pixels.setPixelColor(4, 0x3366ff);
    pixels.show();
    pixels.show();

  }
}

//BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V7, analogRead(39));
}

BLYNK_WRITE(V10)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,255);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,255);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V12)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,255);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,255);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V11)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,150);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,100);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V13)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,150);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,100);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

Servo servo_23;
BLYNK_WRITE(V14)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(90);

  } else {

  }
}

BLYNK_WRITE(V15)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(0);

  } else {

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  pinMode(39, INPUT);
  Timer1.setInterval(300, Timer1_TimerEvent);

  pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  servo_23.attach(23);
}

void loop() {
  Blynk.run();
  Timer1.run();
}
