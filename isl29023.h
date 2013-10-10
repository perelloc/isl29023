/******************************************************************************
 *  ISL29023 header module for Arduino
 *
 *  This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
 *  Unported License. To view a copy of this license, 
 *  visit http://creativecommons.org/licenses/by-sa/3.0/.
 *
 *  Iain Derrington (http://www.kandi-electronics.co.uk)
*******************************************************************************/
#ifndef ISL29023_h
#define ISL29023_h

class ISL29023 {
public:  
  ISL29023();
  ISL29023(unsigned char);

  void init();         // initialises the device
  float read();        // read light value
private:
  unsigned char dev_address;
};

#endif
