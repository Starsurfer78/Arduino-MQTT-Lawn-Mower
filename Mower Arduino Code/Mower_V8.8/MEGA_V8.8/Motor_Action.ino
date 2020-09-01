
void Motor_Action_Go_Mowing_Speed() {

  // No Mag speed adjustment active just go full speed
  if (MAG_Speed_Adjustment == 0) Motor_Action_Go_Full_Speed();

  // Adjust wheel speed according to the MAG level
  if (MAG_Speed_Adjustment == 1) {
    if (MAG_Now >= Slow_Speed_MAG) {
      Motor_Action_Go_Full_Speed();
    }

    if (MAG_Now < Slow_Speed_MAG)  {
      Motor_Action_Go_Slow_Speed();
    }
  }
}

void Motor_Action_Go_Full_Speed()     {
  analogWrite(MotorRight_Rpwm, 0);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, PWM_MaxSpeed_RH);
  analogWrite(MotorLeft_Rpwm, 0);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, PWM_MaxSpeed_LH);
  DPRINT(F("Wheel:FULL|"));
}

void Motor_Action_Go_Slow_Speed()     {
  analogWrite(MotorRight_Rpwm, 0);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, PWM_Slow_Speed_RH);
  analogWrite(MotorLeft_Rpwm, 0);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, PWM_Slow_Speed_LH);
  DPRINT(F("Wheel:SLOW|"));
}

void Motor_Action_GoFullSpeed_Out_Garage()     {
  //Speeds can be changed to give the mower a slight curve when exiting the Garage.

  PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 20;
  if (PWM_MaxSpeed_LH > 255)  PWM_MaxSpeed_LH = 255;
  if (PWM_MaxSpeed_RH > 255)  PWM_MaxSpeed_RH = 255;
  analogWrite(MotorRight_Rpwm, 0);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, PWM_MaxSpeed_RH);
  analogWrite(MotorLeft_Rpwm, 0);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, PWM_MaxSpeed_LH);
  DPRINT(F("Wheel:FULL|"));
}


void SetPins_ToGoForwards()     {                                 // Motor Bridge pins are set for both motors to move forwards.
  analogWrite(MotorRight_Rpwm, PWM_MaxSpeed_RH);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, 0);
  analogWrite(MotorLeft_Rpwm, PWM_MaxSpeed_LH);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, 0);
  DPRINT(F("Wheel:For|"));
}


void SetPins_ToGoBackwards()      {                               // Motor Bridge pins are set for both motors to move Backwards
  analogWrite(MotorRight_Rpwm, 0);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, PWM_MaxSpeed_RH);
  analogWrite(MotorLeft_Rpwm, 0);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, PWM_MaxSpeed_LH);
  DPRINT(F("Wheel:Rev|"));
  delay(20);
}


void Motor_Action_Stop_Motors()  {                                     // Motor Bridge pins are set for both motors to stop
  analogWrite(MotorRight_Rpwm, 0);                                     // Motor 1
  analogWrite(MotorRight_Lpwm, 0);
  analogWrite(MotorLeft_Rpwm, 0);                                     // Motor 2
  analogWrite(MotorLeft_Lpwm, 0);

  DPRINT(F("Wheel:0FF|"));
}


void SetPins_ToTurnLeft()       {                              // Pins are set so that Motors drive in opposite directions
  analogWrite(MotorRight_Rpwm, PWM_MaxSpeed_RH);
  analogWrite(MotorRight_Lpwm, 0);
  analogWrite(MotorLeft_Rpwm, 0);
  analogWrite(MotorLeft_Lpwm, PWM_MaxSpeed_LH);
  DPRINT(F("Wheel:TL_|"));
}


void SetPins_ToTurnRight() {                                    // Pins are set so that Motors drive in opposite directions
  analogWrite(MotorRight_Rpwm, 0);
  analogWrite(MotorRight_Lpwm, PWM_MaxSpeed_LH);
  analogWrite(MotorLeft_Rpwm, PWM_MaxSpeed_RH);
  analogWrite(MotorLeft_Lpwm, 0);
  DPRINT(F("Wheel:R|"));
}


// USed to turn the mower at a set speed.
void Motor_Action_Turn_Speed() {
analogWrite(MotorRight_Rpwm, 0);
  analogWrite(MotorRight_Lpwm, (PWM_MaxSpeed_RH - Turn_Adjust) );                                  // Change the 0 value to 10 or 20 to recuce the speed
  analogWrite(MotorLeft_Rpwm, (PWM_MaxSpeed_LH - Turn_Adjust) );
  analogWrite(MotorLeft_Lpwm, 0);                                 // Change the 0 value to 10 or 20 to recuce the speed
}

//Steers the Mower depending on the PID input from the Algorythm
void Motor_Action_Dynamic_PWM_Steering() {
  analogWrite(MotorRight_Rpwm, PWM_Right);                             // ENA low = Right Swerve   ENB low = Left Swerve
  analogWrite(MotorRight_Lpwm, 0);
  analogWrite(MotorLeft_Rpwm, PWM_Left);
  analogWrite(MotorLeft_Lpwm, 0);
  DPRINT(F("PWM_R:"));
  DPRINT(PWM_Right);
  DPRINT(F("|"));
  DPRINT(F("PWM_L:"));
  DPRINT(PWM_Left);
  DPRINT(F("|"));
}

// Turns the mowing blades on
void Motor_Action_Spin_Blades()  {
  if (Cutting_Blades_Activate == 1) {                                       // Blades are turn ON in settings and will spin!
    delay(20);
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
    delay(20);
    analogWrite(RPWM, PWM_Blade_Speed);
    delay(20);
    DPRINT(F("Blades:ON_|"));
  }

  if (Cutting_Blades_Activate == 0) {                                     // Blades are turn off in settings and will not spin!
    void StopSpinBlades();
  }
}

void Motor_Action_Stop_Spin_Blades()  {
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
  DPRINT(F("Blades:0FF|"));
}
