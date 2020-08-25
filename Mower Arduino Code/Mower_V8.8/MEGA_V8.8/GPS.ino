// GPS Module Code

// The ESP32 sends send 3.3V on the output pin when the mower is inside the GPS fence.
// when the mower leaves the GPS fence the pin is at 0 volts.
// The pin A7 is read by the adcman feature as analog.read cat be used anymore.

void Check_GPS_In_Out() {

// Run the ADCman to get the pin values as per the settings
ADCMan.run();
GPS_Fence_Signal = ADCMan.read(GPS_Fence_Signal_Pin);    // Read GPS in out status
GPS_Lock_Signal  = ADCMan.read(GPS_Lock_Pin);            // Read GPS Fixed status

// Print the value to the serial monitor
DPRINT("|GPS:");
DPRINT(GPS_Fence_Signal);
DPRINT("/");

if (GPS_Fence_Signal < 100) GPS_Inside_Fence = 0;   // Mower is Outside the GPS Fence
if (GPS_Fence_Signal > 100) GPS_Inside_Fence = 1;   // Mower is Inside the GPS Fence

    if (GPS_Inside_Fence == 0) DPRINT(":OUT");
    if (GPS_Inside_Fence == 1) DPRINT(":IN");

//DPRINT("|Lock:");
//DPRINT(GPS_Lock_Signal);
//DPRINT("/");

if (GPS_Lock_Signal < 100)  GPS_Lock_OK = 0;   // Mower is Outside the GPS Fence
if (GPS_Lock_Signal > 100)  GPS_Lock_OK = 1;   // Mower is Inside the GPS Fence

   if (GPS_Lock_OK == 0) DPRINT(":NoLOCK");
   if (GPS_Lock_OK == 1) DPRINT(":RTKFIX");

        // if there is no GPS Lock and the mower is running then keep within the whiole loop
        // until a GPS RTK lock is found.
        while ((GPS_Lock_OK == 0) && (Mower_Running == 1)) {
          Motor_Action_Stop_Motors();                               // Stop Wheels
          Motor_Action_Stop_Spin_Blades();                          // Stop Blade
          DPRINTLN("");
          DPRINT(F("- Checking for GPS Lock "));
          DPRINT(F("| Lock:"));
          ADCMan.run();
          GPS_Lock_Signal = ADCMan.read(GPS_Lock_Pin);
          DPRINTLN(GPS_Lock_Signal);
          delay(100);
          if (GPS_Lock_Signal < 50)  GPS_Lock_OK = 0;   // Mower is Outside the GPS Fence
          if (GPS_Lock_Signal > 50)  GPS_Lock_OK = 1;   // Mower is Inside the GPS Fence
          Send_Mower_Running_Data();
          delay(1000);
          }


    DPRINT("|");

}
