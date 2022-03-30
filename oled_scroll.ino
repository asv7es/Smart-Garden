#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

char message[] = "M1 = 16%, M2 = 90%, M3 = 50%, M4 = 20%";
int x, minX;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(2);          // text size
  display.setTextColor(WHITE);     // text color
  display.setTextWrap(false);
  x = display.width();
  minX = -12*strlen(message);
  Serial.println(display.width());
  Serial.println(display.height());
}

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(x,10);
  display.print(message);
  display.display();
  x=x-4;
  if(x<minX)
  x=display.width();
  
}
