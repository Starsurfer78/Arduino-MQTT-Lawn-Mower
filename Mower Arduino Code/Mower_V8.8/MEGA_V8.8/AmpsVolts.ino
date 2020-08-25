


void Process_Volt_Information()   {
  //  Logic for how the battery readings should be handled

  if (Volts < Battery_Min) {
    Low_Battery_Detected = (Low_Battery_Detected + 1);
    DPRINT(F("VLow:"));
    DPRINT(Low_Battery_Detected);
    DPRINT(F("|"));
    if (Low_Battery_Detected > Low_Battery_Instances_Chg) {
      DPRINTLN(F("Low Battery Detected"));
      if (Use_Charging_Station == 1) {
        // need to add a low batt code... to TFT
        Manouver_Go_To_Charging_Station();                       // Stops the mowing and sends the mower back to the charging station via the permieter wire
      }
      if (Use_Charging_Station == 0) Manouver_Park_The_Mower_Low_Batt();                      // Parks the mower with a low battery warning
    }
  }

  if (Volts >= Battery_Min) {
    DPRINT(F("VLow:"));
    DPRINT(Low_Battery_Detected);
    DPRINT(F("|"));
    Low_Battery_Detected = 0;
  }
}



// checks to see if the mower is on the charging station
void Check_if_Charging() {


  if (Charging == 4)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
    DPRINT(F("Charging:"));
    DPRINT(Charging);
    DPRINT(F("|"));
    Charge_Detected_MEGA = 1;
    Print_Charging_LCD();
    DPRINT(F("MEGA = 1|"));
  }
  if (Charging == 0)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
    DPRINT(F("Charging:"));
    DPRINT(Charging);
    DPRINT(F("|"));
    Charge_Detected_MEGA = 0;
    Print_Charging_LCD();
  }
  if ((Charging != 4) && (Charging != 0)) {
    DPRINT(F("Charging:"));
    DPRINT(Charging);
    DPRINT(F("|"));
    Charge_Detected_MEGA = 0;
    Print_Charging_LCD();
  }



  //  else {
  //    DPRINT("Charging:");
  //   // DPRINT("_|");
  //   DPRINT(Charging);
  //   Charge_Detected_MEGA = 0;
  //   DPRINT("**|");
  //    }
}



void Check_if_Docked() {

  if (Charge_Detected_MEGA == 1) {                                    // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
    Motor_Action_Stop_Motors();
    DPRINTLN(F("Charging Current detected"));
    DPRINTLN(F("Mower Docked"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Docked in"));
    lcd.setCursor(0, 1);
    lcd.print(F("Charging Station"));                                // Prints info to LCD display
    delay(2000);
    Mower_Docked = 1;
    // Update the TFT Screen
    if (TFT_Screen_Menu == 1) {
      //Send_Mower_Docking_Data();
      Turn_To_Home = 0;
      Find_Wire_Track = 0;
      Go_To_Charging_Station = 0;
    }
    Manouver_Dock_The_Mower();                                    // Shuts down the Mower ready for charging and mowing again.
    lcd.clear();
  }
  DPRINTLN("");
}

void Calculate_Volt_Amp_Charge() {

  if (Show_TX_Data == 1) {
    DPRINT(F("Amp:"));
    DPRINT(RawValueAmp);
    DPRINT(F("|"));
    DPRINT(F("Volt:"));
    DPRINT(RawValueVolt);
    DPRINT(F("|"));
    DPRINT(F("Rain:"));
    DPRINT(Rain_Detected);
    DPRINT(F("|"));
    if (Wheel_Amp_Sensor_ON == 1) {
      DPRINT(F("WBlock:"));
      DPRINT(Wheel_Blocked);
      DPRINT(F("|"));
    }
  }

  // Calculate Amps from NANO RX Data
  int mVperAmp = 185;
  int ACSoffset = 2500;
  double VoltageAmp = 0;
  double Amps_Now = 0;
  VoltageAmp = (RawValueAmp / 1024.0) * 5000; // Gets you mV
  Amps_Now =  ((VoltageAmp - ACSoffset) / mVperAmp);
  Amps = Amps_Now;

  DPRINT(F("A:"));
  DPRINT(Amps);
  DPRINT(F("|"));


  // Calculate Voltage from NANO RX Data

  if (RawValueVolt > 100)  {
    float vout = 0.0;
    float R1 = 30000;      // Mower 330 = 30000    Mower LAM = 30000
    //float R2 = 7000;       // Mower 330 = 7000
    float R2 = 7300;       // Mower LAM = 6500
    vout = (RawValueVolt * 5.0) / 1024.0; // see text
    Volts = vout / (R2 / (R1 + R2));
    Volts_Last = Volts;
    Zero_Volts = 0;
  }

  else {
    Volts = Volts_Last;
    Zero_Volts = Zero_Volts + 1;
    if (Zero_Volts > 5) Volts = 0;

  }

  DPRINT(F("V:"));
  DPRINT(Volts);
  DPRINT(F("|"));

  if (Amps < 0.4) Charging = 0;
  if (Amps > 0.4) Charging = 4;
  //DPRINT("Charging = ");
  //DPRINT(Charging);
  //DPRINT("|");

}
