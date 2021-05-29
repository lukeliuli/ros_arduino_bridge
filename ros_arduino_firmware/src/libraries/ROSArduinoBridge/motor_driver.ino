/***************************************************************
   Motor driver definitions

   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.

   *************************************************************/

#ifdef USE_BASE

#ifdef POLOLU_VNH5019
 
#elif defined POLOLU_MC33926
 

#elif defined L298N_DUAL_HBRIDGE

  boolean directionLeft = false;
  boolean directionRight = false;

  boolean direction(int i){
     if(i == LEFT){
        return directionLeft;
     }else{
        return directionRight;
     }
  }
  void initMotorController() {
  // set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  }

  void setMotorSpeed(int i, int spd) {
    if(spd>MAX_PWM){
      spd=MAX_PWM;
    }
       if(spd<-MAX_PWM){
      spd=-1*MAX_PWM;
    }
    if (i == LEFT){
        if(spd>=0){
            directionLeft = FORWARDS;
            digitalWrite(IN2, HIGH);
            digitalWrite(IN1, LOW);
            analogWrite(ENA, spd);
        }else if(spd < 0){
            directionLeft = BACKWARDS;
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, -spd);
        }
    }
    else {
        if(spd>=0){
            directionRight = FORWARDS;
            digitalWrite(IN4, HIGH);
            digitalWrite(IN3, LOW);
            analogWrite(ENB, spd);
        }else if(spd<0){
            directionRight = BACKWARDS;
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, -spd);
        }
    }
  }

  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif
