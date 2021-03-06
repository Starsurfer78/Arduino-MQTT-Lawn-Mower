void Special_Cut_Under_Trampoline_Function() {
  //Enter Code Here
}



// after wire tracking the code to bering the mower to a sensible position away from the wire
// This poart of the code should eb modified to fit your garden needs
void Special_Move_Into_Garden_Zone_X() {
  DPRINTLN(F("start mower code here"));
  Motor_Action_Stop_Motors();                                     // Stop the wheel motors
  if (CCW_Tracking_To_Start == 1) SetPins_ToTurnLeft();           // Turn left
  if (CW_Tracking_To_Start == 1) SetPins_ToTurnRight();           // Turn Right
  Motor_Action_Go_Full_Speed();
  delay(1400);                                                     // Turn left for 0.7seconds
  Motor_Action_Stop_Motors();                                     // Stop the wheel motors.
  SetPins_ToGoForwards();                                         // Get ready to move off
}

void Manouver_Exit_From_Docking_Station() {
  SetPins_ToGoBackwards();                                        // Prepare motors pins to go Backwards
  Motor_Action_GoFullSpeed_Out_Garage();                          // Turn the wheels
  DPRINT(F("Left Wheel PWM:"));
  DPRINT(PWM_MaxSpeed_LH);
  DPRINT("|");
  DPRINT(F("Right Wheel PWM:"));
  DPRINTLN(PWM_MaxSpeed_RH);
  delay (4000);                                             // Backwards time
  Motor_Action_Stop_Motors;                                       // Stop

  if (CCW_Tracking_To_Start == 1) {
    SetPins_ToTurnLeft();                                           // Prepare motors to turn left
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(500);                                                    // Turn time
    Motor_Action_Stop_Motors;                                       // Stop
    SetPins_ToGoBackwards();                                        // Set again to go backwards
    Motor_Action_Go_Full_Speed();                                   // Turn the wheels
    delay (500);                                                    // Backwards Time
    SetPins_ToTurnLeft();                                           // Set to go left
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(200);                                                     // Turning time
    Motor_Action_Stop_Motors();                                     // Stop
  }
  if (CW_Tracking_To_Start == 1) {
    SetPins_ToTurnRight();                                           // Prepare motors to turn left
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(500);                                                    // Turn time
    Motor_Action_Stop_Motors;                                       // Stop
    SetPins_ToGoBackwards();                                        // Set again to go backwards
    Motor_Action_Go_Full_Speed();                                   // Turn the wheels
    delay (500);                                                    // Backwards Time
    SetPins_ToTurnRight();                                           // Set to go left
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(200);                                                     // Turning time
    Motor_Action_Stop_Motors();                                     // Stop
  }
  SetPins_ToGoForwards();                                         // Set to go wheel motor pins to go forwards
  Motor_Action_Stop_Motors();                                     // Stop / Park the mower here
  delay(500);
}



void Specials_Find_Wire_Track()  {

  DPRINTLN("");
  DPRINTLN(F("Lost Mower - find wire Track"));
  Motor_Action_Stop_Spin_Blades();
  delay(5);
  Abort_Wire_Find = 0;
  //No_Wire_Found = 0;
  TestforBoundaryWire();                                                                    // Check to see that the wire is on.

  for (int i = 0; i <= 1; i++) {
    DPRINT(F("Position Try = "));
    DPRINTLN(i);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    PrintBoundaryWireStatus();
    //No_Wire_Found = 0;
    Wire_Find_Attempt = 0;

    // First go backwards if the mower is outside the wire
    if ( inside == false) {                                    // If the mower is outside the wire then run the following code.
      DPRINTLN("Reversing to find the wire");
      ADCMan.run();
      UpdateWireSensor();
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();                                                           // Stop all wheel motion
      delay(1000);
      SetPins_ToGoBackwards();                                                              // Set the mower to back up
      delay(100);

      // While the mower is still outside the boundary wire run this code unless andabort signal from the APP comes or it runs out of tries.
      while (( inside != true) && (Wire_Find_Attempt < 100) ) {
        Motor_Action_Go_Full_Speed();                                                       // Go full speed (in this case backwards)
        UpdateWireSensor();                                                                 // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                                          // Prints of the status of the wire sensor readings.
        DPRINTLN("");
        Wire_Find_Attempt = Wire_Find_Attempt + 1;                                                      // Counts how many loops have passed to find the wire.
        DPRINT(F("No Wire Count Backwards:"));
        DPRINT(Wire_Find_Attempt);
        DPRINT("|");
      }

    }

    Motor_Action_Stop_Motors();
    delay(5);
  }

  Wire_Find_Attempt = 0;
  // Code to go forwards until the mower is outside/ON the wire
  if ( inside == true) {             // If the Mower is situated  the wire then run the following code.
    DPRINTLN(F("Moving Forwards to find the wire"));
    ADCMan.run();
    UpdateWireSensor();
    DPRINTLN(F("CODE POSITION - MOTOR FORWARDS LOOP:  If statements"));
    PrintBoundaryWireStatus();
    Motor_Action_Stop_Motors();
    delay(1000);
    SetPins_ToGoForwards();                                                             // Set the motors to move the mower forwards
    delay(100);                                                                 // resets the cycles
    while (( inside != false) && (Wire_Find_Attempt < 100)) {                               // Move the mower forward until mower is outisde/ON the wire fence or 500 cycles have passed
      Motor_Action_Go_Full_Speed();                                                     // Go full speed (in this case forwards)
      UpdateWireSensor();                                                               // Read the wire sensor and see of the mower is now  or outside the wire
      ADCMan.run();
      PrintBoundaryWireStatus();                                                        // Prints of the status of the wire sensor readings.
      DPRINTLN("");
      Wire_Find_Attempt = Wire_Find_Attempt + 1;                                                    // Counts how many loops have passed to find the wire.
      DPRINT("No Wire Count Forwards:");
      DPRINT(Wire_Find_Attempt);
      DPRINT("|");
    }
  }
  Motor_Action_Stop_Motors();
  delay(5);
}
