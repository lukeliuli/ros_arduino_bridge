/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */



#ifdef ARDUINO_MY_COUNTER
  #define LEFT_ENC_A 2
  #define LEFT_ENC_B 4
  #define RIGHT_ENC_A 3
  #define RIGHT_ENC_B 11
  void initEncoders();
  void leftEncoderEvent();
  void rightEncoderEvent();
#endif

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
