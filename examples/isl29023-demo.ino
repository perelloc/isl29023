#include <isl29023.h>
#include <Wire.h>



Isl29023 isl = ISL29023();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  cl.init(); 
}

void loop() {
  float light;
  // put your main code here, to run repeatedly: 
  for(;;){
    isl.read(&light);
    Serial.println(light);
  }
}

