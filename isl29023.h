/******************************************************************************/
/** \file corelightv.h
 *  \brief CoreLight header module for Arduino
 *
 *  This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
 *  Unported License. To view a copy of this license, 
 *  visit http://creativecommons.org/licenses/by-sa/3.0/.
 *
 *  \author Iain Derrington (http://www.kandi-electronics.co.uk)
 *  \version: $RatPacked$
 */
/*******************************************************************************/
#ifndef CORELIGHT_h
#define CORELIGHT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class CoreLight{
public:  
  CoreLight();
  CoreLight(unsigned char);

  void init();         // initialises the device
  void read(float *);  // read light value
private:
  unsigned char dev_address;
};

#endif