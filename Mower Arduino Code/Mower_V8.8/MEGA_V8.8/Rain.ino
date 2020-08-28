void Check_if_Raining_From_Nano() {

  if (Rain_Sensor_Installed == 1) {

    if ((Rain_Detected == 1) || (Rain_Detected == 0)) {                           // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
      DPRINT(F("Rain:"));
      DPRINT(Rain_Detected);
      DPRINT("|");
      if (Rain_Detected == 1) Rain_Hit_Detected = Rain_Hit_Detected + 1;
      if (Rain_Detected == 0) Rain_Hit_Detected = Rain_Hit_Detected - 1;
      if (Rain_Hit_Detected < 0) Rain_Hit_Detected = 0;
    }
    if ((Rain_Detected != 1) && (Rain_Detected != 0)) {
      DPRINT(F("Rain:"));
      DPRINT(Rain_Detected);
      DPRINT("|");
      Rain_Detected = 0;
      Rain_Hit_Detected = Rain_Hit_Detected + 1;
    }


    else {
      DPRINT(F("Rain:"));
      DPRINT("_|");
      Rain_Detected = 0;
    }

    DPRINT("RHit:");
    DPRINT(Rain_Hit_Detected);
    DPRINT("|");
  }

  if ( (Mower_Running == 1) && (Rain_Hit_Detected == Rain_Total_Hits_Go_Home) ) {
    Motor_Action_Stop_Motors();
    DPRINTLN("");
    DPRINTLN("Rain detected");
    DPRINTLN("");
    delay(2000);
    Manouver_Go_To_Charging_Station();            // If the Mower is running then go to the charge station.
  }

}
