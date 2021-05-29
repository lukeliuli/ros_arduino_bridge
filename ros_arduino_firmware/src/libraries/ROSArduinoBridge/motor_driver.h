/***********************************************************************
   Motor driver function definitions - by James Nugen and Chaoyang Liu
   ***********************************************************************/

  void initMotorController();
  void setMotorSpeed(int i, int spd);
  void setMotorSpeeds(int leftSpeed, int rightSpeed);
  #ifdef L298N_DUAL_HBRIDGE
    // motor one
    #define ENA 5
    #define IN1 7 //注意方向，有可能电机和电机驱动的方向不匹配，所以要IN1,IN2对调，或者编码其输出正负反转.这里采用改变编码器输出正负
    #define IN2 8
    // motor two
    #define ENB 6
    #define IN3 9
    #define IN4 10
  #endif
