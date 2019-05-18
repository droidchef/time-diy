#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

SoftwareSerial bluetoothDevice(10, 11); // RX, TX
#define baud_rate 9600
#define LED 13

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(baud_rate);
  while(!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("We are ready!");
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2500);
  display.clearDisplay();
  // set the data rate for the SoftwareSerial port
  bluetoothDevice.begin(baud_rate);
  bluetoothDevice.println("We are ready");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetoothDevice.available()) {
    String input = bluetoothDevice.readString();
//    if (input == '1') {
//      testDrawText();
//    } else if (input == '0') {
//      testDrawTextZERO();
//    }
    writeText(input);
    Serial.print(input);
    
  }
  if (Serial.available()) {
    bluetoothDevice.write(Serial.read());
  }
  delay(60);
}

void writeText(const String& thisIsAString) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(thisIsAString);
  display.display();
}


void testDrawText(void){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(F("ONE"));
  display.display();
}

void testDrawTextZERO(void){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(F("ZERO"));
  display.display();
}
