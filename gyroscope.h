#ifndef __GYROSCOPE_H__
#define __GYROSCOPE_H__

#include <Arduino.h>
class Gyroscope
{
  public:
    Gyroscope();

  private:
    const byte WHO_AM_I;      

    const byte CTRL_REG1;     
    const byte CTRL_REG2;     
    const byte CTRL_REG3;     
    const byte CTRL_REG4;     
    const byte CTRL_REG5;     
    const byte REFERENCE;     
    const byte OUT_TEMP;      
    const byte STATUS_REG;    

    const byte OUT_X_L;       
    const byte OUT_X_H;       
    const byte OUT_Y_L;       
    const byte OUT_Y_H;       
    const byte OUT_Z_L;       
    const byte OUT_Z_H;       

    const byte FIFO_CTRL_REG; 
    const byte FIFO_SRC_REG;  

    const byte INT1_CFG;      
    const byte INT1_SRC;      
    const byte INT1_THS_XH;   
    const byte INT1_THS_XL;   
    const byte INT1_THS_YH;   
    const byte INT1_THS_YL;   
    const byte INT1_THS_ZH;   
    const byte INT1_THS_ZL;   
    const byte INT1_DURATION; 
};

#endif