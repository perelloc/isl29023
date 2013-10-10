#include <Wire.h>
#include <isl29023.h>

#define ISL29023_ADDR 0x44

#define CMD1 0
#define CMD2 1
#define DATALSB 2
#define DATAMSB 3

unsigned char dev_address;

ISL29023::ISL29023(){
  dev_address = ISL29023_ADDR;
}

ISL29023::ISL29023(unsigned char address){
  dev_address = address;
}

void ISL29023::init()
{
  unsigned char i2cdata[2];
  
  i2cdata[0] = CMD1;
  i2cdata[1] = 0b10100000;

  Wire.beginTransmission(dev_address);    // start transmission to device 
  Wire.write(i2cdata[0]);                 // send register address
  Wire.write(i2cdata[1]);                 // send data to write  
  Wire.endTransmission();                 // end transmission


  i2cdata[0] = CMD2;
  i2cdata[1] = 0b00000011;
 
  Wire.beginTransmission(dev_address);    // start transmission to device 
  Wire.write(i2cdata[0]);                 // send register address
  Wire.write(i2cdata[1]);                 // send data to write  
  Wire.endTransmission();                 // end transmission
}

/***********************************************************************/
 *
 * Reads the lux value back from the sensor.
 *              
/**********************************************************************/
float ISL29023::read()
{
  unsigned char  i2cdata[6];
  unsigned int light;    
  float lux;

  i2cdata[0] = DATAMSB;

  Wire.beginTransmission(dev_address);      // start transmission to device 
  Wire.write(i2cdata[0]);                   // send register address
  Wire.endTransmission();                   // end transmission

  Wire.beginTransmission(dev_address);      // start transmission to device 
  Wire.requestFrom((int)dev_address, 1);    // send data n-bytes read/

  while (Wire.available()) {
   i2cdata[0] = Wire.read();                // receive DATA
  }
  Wire.endTransmission();                   // end transmission

  light = ((unsigned int)i2cdata[0])<<8;

  i2cdata[0] = DATALSB;


  Wire.beginTransmission(dev_address);      // start transmission to device 
  Wire.write(i2cdata[0]);                   // send register address
  Wire.endTransmission(); 
  

  Wire.beginTransmission(dev_address);      // start transmission to device 
  Wire.requestFrom((int)dev_address, 1); 

  while (Wire.available()) {
    i2cdata[0] = Wire.read();                // receive DATA
  }
  Wire.endTransmission();                   // end transmission
  
  light |= i2cdata[0];

  // this is a bit lame, ideally use data read back from the device
  // to scale accordingly
  lux = (64000 * (float)light)/65536;
  return lux;
 }
