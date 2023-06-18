/*
Pet temperature and humidity monitor Sys
*/

#include <SimpleDHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 13

int pinDHT11_1 = 15; // GPIO15
int pinDHT11_2 = 16; // GPIO2
int pinDHT11_3 = 4; // GPIO4

// Call library: SimpleDHT11
SimpleDHT11 dht11_1(pinDHT11_1);
SimpleDHT11 dht11_2(pinDHT11_2);
SimpleDHT11 dht11_3(pinDHT11_3);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // display tempeture forever
  for(;;){
    displayTempeture1();
    displayTempeture2();
    displayTempeture3();
  }
}

void loop(){

}

void displayTempeture1(void){
  display.clearDisplay();

  //display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // top left

  // read without samples.
  byte temperature1 = 0;
  byte humidity1 = 0;

  int err = SimpleDHTErrSuccess;

  if ((err = dht11_1.read(&temperature1, &humidity1, NULL)) != SimpleDHTErrSuccess) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0); // top left
    display.print("Read DHT11_1 failed, err="); display.print(SimpleDHTErrCode(err));
    display.print(","); display.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
    display.setTextSize(2);
    display.println("tankA:" );
    display.println();

    display.setTextSize(4); 
    display.print((int)temperature1); 
    
    display.setTextSize(2);
    display.print("H"); 

    display.setTextSize(4);
    display.print((int)humidity1); 
    
    display.setTextSize(2);
    display.println("C");

    display.display();
    delay(2000);
}

void displayTempeture2(void){
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // top left

  // read without samples.
  byte temperature2 = 0;
  byte humidity2 = 0;
  int err = SimpleDHTErrSuccess;

  if ((err = dht11_2.read(&temperature2, &humidity2, NULL)) != SimpleDHTErrSuccess) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0); // top left
    display.print("Read DHT11_2 failed, err="); display.print(SimpleDHTErrCode(err));
    display.print(","); display.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
    display.setTextSize(2);
    display.println("tankB:" );
    display.println();

    display.setTextSize(4); 
    display.print((int)temperature2);
    
    display.setTextSize(2);
    display.print("H"); 

    display.setTextSize(4); 
    display.print((int)humidity2);

    display.setTextSize(2);
    display.print("C"); 

  // DHT11 sampling rate is 1HZ.
  display.display();

  delay(2000);
}


void displayTempeture3(void){
  display.clearDisplay();

  //display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // top left

  // read without samples.
  byte temperature3 = 0;
  byte humidity3 = 0;

  int err = SimpleDHTErrSuccess;

  if ((err = dht11_3.read(&temperature3, &humidity3, NULL)) != SimpleDHTErrSuccess) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0); // top left
    display.print("Read DHT11_3 failed, err="); display.print(SimpleDHTErrCode(err));
    display.print(","); display.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
    display.setTextSize(2);
    display.println("tankC:" );
    display.println();

    display.setTextSize(4); 
    display.print((int)temperature3); 
    
    display.setTextSize(2);
    display.print("H"); 

    display.setTextSize(4);
    display.print((int)humidity3); 
    
    display.setTextSize(2);
    display.println("C");

    display.display();
    delay(2000);
}