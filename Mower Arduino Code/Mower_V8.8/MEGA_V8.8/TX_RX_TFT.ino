// Listens to the serial 3 port if a menu command has been executed.
void Check_TFT_Serial_Input() {

  String Serial3_RX_Value  = "";
  int Number_Received;

  while (Serial3.available() > 0) {
    char recieved = Serial3.read();
    if ( recieved != '\g' ) {
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;
    }
    else if (recieved == '\g') {
      TFT_Menu_Command  = Serial3_RX_Value.toInt();
      Serial3_RX_Value  = ""; // changed to string
      DPRINT("TFT Menu Command: ");
      DPRINT(TFT_Menu_Command );
      DPRINT(" = ");
      Confirm_TX_or_RX_Action();                          // Prints the Menu Selected
      delay(100);

      Confirm_RX();            // Confirms the transmition is received unless 57 (Docked Info)

      if ((Mower_Docked == 1) || (Mower_Parked == 1)) delay(500);
      Send_Data_To_TFT();                                   // Send data to TFT - depends on menu code received
      Receive_Data_From_TFT();                              // Receive Data from TFT - depends on menu code received
    }

    else DPRINT(F("No Data Received|"));
  }

}



void Activate_TFT_Menu() {

  DPRINTLN();
  DPRINTLN(F("TFT Menu Activated"));
  Menu_Complete_TFT = false;                                // Menu complete will return to the normal loop
  delay(500);
  DPRINTLN("waiting for command");

  while (Menu_Complete_TFT == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
    Check_TFT_Serial_Input();
    delay(200);
    if (TFT_Menu_Command == 1) Menu_Complete_TFT = true;
  }

}


void Confirm_RX() {
  // confirms to the TFT that a request for data transfer has been received.
  Serial3.print(TFT_Menu_Command * 3);
  Serial3.println("\h");
  delay(200);
  DPRINT("Confirmstion Code Sent : ");
  DPRINTLN(TFT_Menu_Command * 3);
}




// Based on the code received this menu confirms the menu item to be used.
void Confirm_TX_or_RX_Action() {

  if (TFT_Menu_Command == 1)  DPRINTLN(F("Main Menu"));
  if (TFT_Menu_Command == 2)  DPRINTLN(F("Quick Start Menu"));
  if (TFT_Menu_Command == 3)  DPRINTLN(F("Exit Dock Menu"));
  if (TFT_Menu_Command == 4)  DPRINTLN(F("Options Menu"));
  if (TFT_Menu_Command == 5)  DPRINTLN(F("Time Menu"));
  if (TFT_Menu_Command == 6)  DPRINTLN(F("Sensors Menu"));
  if (TFT_Menu_Command == 7)  DPRINTLN(F("Motion Menu"));
  if (TFT_Menu_Command == 8)  DPRINTLN(F("Tracking Menu"));
  if (TFT_Menu_Command == 9)  DPRINTLN(F("Navigation Menu"));
  if (TFT_Menu_Command == 10) DPRINTLN(F("Sonar Menu"));
  //  Leave 11 Free.
  if (TFT_Menu_Command == 12) DPRINTLN(F("Rain Sensor Menu"));
  if (TFT_Menu_Command == 13) DPRINTLN(F("Stop Menu"));
  if (TFT_Menu_Command == 14) DPRINTLN(F("Wheel Motor Menu"));
  if (TFT_Menu_Command == 15) DPRINTLN(F("Blade Motor Menu"));
  if (TFT_Menu_Command == 16) DPRINTLN(F("Movement Menu"));
  if (TFT_Menu_Command == 17) DPRINTLN(F("Tracking Exit Points"));
  if (TFT_Menu_Command == 18) DPRINTLN(F("Find Wire"));
  if (TFT_Menu_Command == 19) DPRINTLN(F("Track PID"));
  if (TFT_Menu_Command == 20) DPRINTLN(F("Set Alarm 1"));
  if (TFT_Menu_Command == 21) DPRINTLN(F("Set Alarm 2"));
  if (TFT_Menu_Command == 22) DPRINTLN(F("Set Alarm 3"));
  if (TFT_Menu_Command == 23) DPRINTLN(F("Set Time"));
  if (TFT_Menu_Command == 24) DPRINTLN(F("Tip Sensor Menu"));
  if (TFT_Menu_Command == 25) DPRINTLN(F("Pattern Menu"));
  if (TFT_Menu_Command == 26) DPRINTLN(F("Battery Menu"));
  if (TFT_Menu_Command == 27) DPRINTLN(F("Compass Menu"));
  if (TFT_Menu_Command == 28) DPRINTLN(F("GYRO Menu"));
  if (TFT_Menu_Command == 29) DPRINTLN(F("Wheel Block Amps Menu"));
  if (TFT_Menu_Command == 30) DPRINTLN(F("Setup Other Menu"));

  if (TFT_Menu_Command == 38) DPRINTLN(F("Wheel Amp Test"));
  if (TFT_Menu_Command == 39) DPRINTLN(F("GYRO Test"));
  if (TFT_Menu_Command == 40) DPRINTLN(F("Tilt Test"));
  if (TFT_Menu_Command == 41) DPRINTLN(F("Wire Test"));
  if (TFT_Menu_Command == 42) DPRINTLN(F("Relay Test"));
  if (TFT_Menu_Command == 43) DPRINTLN(F("Wheel Test"));
  if (TFT_Menu_Command == 44) DPRINTLN(F("Blade Test"));
  if (TFT_Menu_Command == 45) DPRINTLN(F("Sonar Test"));
  if (TFT_Menu_Command == 46) DPRINTLN(F("Turn Test"));
  if (TFT_Menu_Command == 47) DPRINTLN(F("Volt Amp Test"));
  if (TFT_Menu_Command == 48) DPRINTLN(F("Compass Test"));
  if (TFT_Menu_Command == 49) DPRINTLN(F("Go Home Test"));
  if (TFT_Menu_Command == 50) DPRINTLN(F("Bumper Bar"));
  if (TFT_Menu_Command == 55) DPRINTLN(F("Start-Up Value"));
  if (TFT_Menu_Command == 57) DPRINTLN(F("TX Docked Info"));
  if (TFT_Menu_Command == 58) DPRINTLN(F("Mower Running"));


}
