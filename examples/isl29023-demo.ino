#include <isl29023.h>
#include <Wire.h>



ISL29023 isl = ISL29023();

void setup() {
  Serial.begin(9600);
  Wire.begin();
  isl.init(); 
}

void loop() {
    Serial.println(isl.read());
    delay(1000);
}

