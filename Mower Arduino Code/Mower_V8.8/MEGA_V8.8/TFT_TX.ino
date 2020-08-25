//Transmits Data to the TFT e.g. sensor data from EEPROM

void Send_Data_To_TFT() {
  // Depending on the code received the following data set is sent through the Serial 3 port.

  // Menu Sonar
  if (TFT_Menu_Command == 10) {
    DPRINTLN("TX Sonar to TFT");

    Serial3.print(Sonar_1_Activate);
    Serial3.println("\a");
    delay(200);

    Serial3.print(Sonar_2_Activate);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Sonar_3_Activate);
    Serial3.println("\c");
    delay(200);

    Serial3.print(maxdistancesonar);
    Serial3.println("\d");
    delay(200);

    Serial3.print(Max_Sonar_Hit);
    Serial3.println("\e");
    delay(200);

    DPRINT(F("Sonar 2 Activated = "));
    DPRINTLN(Sonar_2_Activate);
    DPRINT(F("Sonar 1 Activated = "));
    DPRINTLN(Sonar_1_Activate);
    DPRINT(F("Sonar 3 Activated = "));
    DPRINTLN(Sonar_3_Activate);
    DPRINT(F("Sonar Max Distance = "));
    DPRINTLN(maxdistancesonar);
    DPRINT(F("Sonar Sensitivity= "));
    DPRINTLN(Max_Sonar_Hit);
    DPRINTLN(F(" "));
  }


  if (TFT_Menu_Command == 11) {
    DPRINTLN("False Command");

  }

  // Navigation Menu
  if (TFT_Menu_Command == 9) {
    DPRINTLN("TX Nav to TFT");

    Serial3.print(GPS_Enabled);
    Serial3.println("\a");
    delay(200);

    DPRINT(F("GPS Enabled= "));
    DPRINTLN(GPS_Enabled);
  }


  // Menu Battery
  if (TFT_Menu_Command == 26) {
    DPRINTLN("TX Battery to TFT");

    Serial3.print(Battery_Min * 10);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Low_Battery_Instances_Chg);
    Serial3.println("\b");
    delay(200);

    DPRINT(F("Battery Min = "));
    DPRINTLN(Battery_Min);
    DPRINT(F("Battery Sensitivity = "));
    DPRINTLN(Low_Battery_Instances_Chg);
    DPRINTLN(" ");

  }

  // Setup Other
  if (TFT_Menu_Command == 30) {
    DPRINTLN("TX Setup Other");

    Serial3.print(PCB);
    Serial3.println("\a");
    delay(300);

    DPRINT(F("PCB = "));
    if (PCB == 1) DPRINTLN(F("Enabled"));
    if (PCB == 0) DPRINTLN(F("Disabled"));
    DPRINTLN(" ");

  }


  // Menu Sonar
  if (TFT_Menu_Command == 6) {
    DPRINTLN("TX Sensors to TFT");

    Serial3.print(Perimeter_Wire_Enabled);
    Serial3.println("\a");
    delay(200);

    Serial3.print(WIFI_Enabled);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Bumper_Activate_Frnt);
    Serial3.println("\c");
    delay(200);


    DPRINT(F("Wire Module Activated = "));
    DPRINTLN(Perimeter_Wire_Enabled);
    DPRINT(F("WIFI Enabled = "));
    DPRINTLN(WIFI_Enabled);
    DPRINT(F("Bumper Activated = "));
    DPRINTLN(Bumper_Activate_Frnt);
    DPRINTLN(F(" "));
  }


  // Menu Battery
  if (TFT_Menu_Command == 12) {
    DPRINTLN("TX Rain to TFT");

    Serial3.print(Rain_Sensor_Installed);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Rain_Total_Hits_Go_Home);
    Serial3.println("\b");
    delay(200);

    DPRINT(F("Rain Sensor ON/OFF = "));
    DPRINTLN(Rain_Sensor_Installed);
    DPRINT(F("Rain Sensor Sensitivity = "));
    DPRINTLN(Rain_Total_Hits_Go_Home);
    DPRINTLN(F(" "));
  }


  // Wheel Motor Data
  if (TFT_Menu_Command == 14) {
    DPRINTLN("TX Wheel Motor to TFT");

    Serial3.print(PWM_MaxSpeed_LH);
    Serial3.println("\a");
    delay(300);

    Serial3.print(PWM_MaxSpeed_RH);
    Serial3.println("\b");
    delay(200);

    Serial3.print(PWM_Slow_Speed_LH);
    Serial3.println("\c");
    delay(300);

    Serial3.print(PWM_Slow_Speed_RH);
    Serial3.println("\d");
    delay(200);

    Slow_Speed_MAG = Slow_Speed_MAG / 10;
    DPRINTLN("TX:");
    DPRINTLN(Slow_Speed_MAG);
    Serial3.print(Slow_Speed_MAG);
    Serial3.println("\e");
    delay(200);

    DPRINT(F("Wheel Motor PWM LH = "));
    DPRINTLN(PWM_MaxSpeed_LH);
    DPRINT(F("Wheel Motor PWM RH = "));
    DPRINTLN(PWM_MaxSpeed_RH);
    DPRINT(F("Wheel Motor Slow Speed PWM LH = "));
    DPRINTLN(PWM_Slow_Speed_LH);
    DPRINT(F("Wheel Motor Slow Speed PWM RH = "));
    DPRINTLN(PWM_Slow_Speed_RH);
    DPRINT(F("Slow Speed MAG = "));
    DPRINTLN(Slow_Speed_MAG * 10);
    DPRINTLN(F(" "));
  }


  // Blade Motor Data
  if (TFT_Menu_Command == 15) {
    DPRINTLN("TX Blade Motor to TFT");

    Serial3.print(PWM_Blade_Speed);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Cutting_Blades_Activate);
    Serial3.println("\b");
    delay(200);

    DPRINT(F("Blade Motor PWM = "));
    DPRINTLN(PWM_Blade_Speed);
    DPRINT(F("Cutting Blade Activated = "));
    DPRINTLN(Cutting_Blades_Activate);
    DPRINTLN(F(" "));

  }


  // Blade Motor Data
  if (TFT_Menu_Command == 16) {
    DPRINTLN("TX Movement to TFT");

    Serial3.print(Max_Cycles_Straight / 10);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Mower_Turn_Delay_Min / 100);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Mower_Turn_Delay_Max / 100);
    Serial3.println("\c");
    delay(200);

    Serial3.print(Mower_Reverse_Delay / 100);
    Serial3.println("\d");
    delay(200);

    DPRINT(F("Max Mow Length = "));
    DPRINTLN(Max_Cycles_Straight);
    DPRINT(F("Turn Angle Min = "));
    DPRINTLN(Mower_Turn_Delay_Min);
    DPRINT(F("Turn Angle Max = "));
    DPRINTLN(Mower_Turn_Delay_Max);
    DPRINT(F("Reverse Distance = "));
    DPRINTLN(Mower_Reverse_Delay);
    DPRINTLN(F(" "));

  }


  // Tracking to Exit Data
  if (TFT_Menu_Command == 17) {
    DPRINTLN("TX Exit to TFT");

    Serial3.print(Track_Wire_Zone_1_Cycles / 100);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Track_Wire_Zone_2_Cycles / 100);
    Serial3.println("\b");
    delay(200);

    Serial3.print(CCW_Tracking_To_Start);
    Serial3.println("\c");
    delay(200);

    DPRINT("Track Wire Zone 1 = ");
    DPRINTLN(Track_Wire_Zone_1_Cycles);

    DPRINT("Track Wire Zone 2 = ");
    DPRINTLN(Track_Wire_Zone_2_Cycles);

    if (CCW_Tracking_To_Start == 0) {
      CW_Tracking_To_Start = 1;
      CCW_Tracking_To_Charge = 1;
      CW_Tracking_To_Charge = 0;

      DPRINTLN(F("Tracking to Charge = CCW"));
      DPRINTLN(F("Tracking to Start = CW"));
    }

    if (CCW_Tracking_To_Start == 1) {
      CW_Tracking_To_Start = 0;
      CCW_Tracking_To_Charge = 0;
      CW_Tracking_To_Charge = 1;

      DPRINTLN(F("Tracking to Charge = CW"));
      DPRINTLN(F("Tracking to Start = CCW"));

    }
  }


  // Tracking Menu Data
  if (TFT_Menu_Command == 8) {
    DPRINTLN("TX Tracking to TFT");

    Serial3.print(Use_Charging_Station);
    Serial3.println("\a");
    delay(300);

    DPRINT(F("Use Charging Station = "));
    DPRINTLN(Use_Charging_Station);
  }


  // Tracking to Exit Data
  if (TFT_Menu_Command == 18) {
    DPRINTLN("TX Find Wire to TFT");

    Serial3.print(Max_Cycle_Wire_Find / 100);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Max_Cycle_Wire_Find_Back / 10);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Home_Wire_Compass_Heading);
    Serial3.println("\c");
    delay(200);


    DPRINT(F("Wire Find Forwards / cylces = "));
    DPRINTLN(Max_Cycle_Wire_Find);

    DPRINT(F("Wire Find Backwards / cylces = "));
    DPRINTLN(Max_Cycle_Wire_Find_Back);

    DPRINT(F("Home Compass Heading / degrees "));
    DPRINTLN(Home_Wire_Compass_Heading);
  }

  // Tracking PID
  if (TFT_Menu_Command == 19) {
    DPRINTLN("TX Find Wire to TFT");

    Serial3.print(Max_Tracking_Turn_Left / 10);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Max_Tracking_Turn_Right / 10);
    Serial3.println("\b");
    delay(200);

    Serial3.print(P * 100);
    Serial3.println("\c");
    delay(200);

    DPRINT(F("Max Cycles Left Wheel = "));
    DPRINTLN(Max_Tracking_Turn_Left);
    DPRINT(F("Max Cycles Right Wheel = "));
    DPRINTLN(Max_Tracking_Turn_Right);
    DPRINT(F("PID P = "));
    DPRINTLN(P);
    DPRINTLN(F(" "));
  }


  // Compass
  if (TFT_Menu_Command == 27) {
    DPRINTLN("TX Compass to TFT");

    Serial3.print(Compass_Activate);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Compass_Heading_Hold_Enabled);
    Serial3.println("\b");
    delay(300);

    Serial3.print(CPower * 10);
    Serial3.println("\c");
    delay(300);

    Serial3.print(Compass_Setup_Mode);
    Serial3.println("\d");
    delay(200);

    DPRINT(F("Compass Activated = "));
    DPRINTLN(Compass_Activate);
    DPRINT(F("Heading Hold Enabled = "));
    DPRINTLN(Compass_Heading_Hold_Enabled);
    DPRINT(F("Compass Power = "));
    DPRINTLN(CPower);
    DPRINT(F("Compass Setup Mode = "));
    DPRINTLN(Compass_Setup_Mode);
  }


  // GYRO
  if (TFT_Menu_Command == 28) {

    Serial3.print(GYRO_Enabled);
    Serial3.println("\a");
    delay(300);

    Serial3.print(GPower * 10);
    Serial3.println("\b");
    delay(300);

    DPRINT(F("GYRO Enabled= "));
    DPRINTLN(GYRO_Enabled);
    DPRINT(F("GYRO Power = "));
    DPRINTLN(GPower);
  }


  // Wheel Block
  if (TFT_Menu_Command == 29) {

    Serial3.print(Wheel_Amp_Sensor_ON);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Max_Wheel_Amps * 10);
    Serial3.println("\b");
    delay(300);

    DPRINT(F("Wheel Amp ON: "));
    if (Wheel_Amp_Sensor_ON == 1) DPRINTLN("ON");
    if (Wheel_Amp_Sensor_ON == 0) DPRINTLN("OFF");

    DPRINT(F("Wheel Amps Max: "));
    DPRINT(Max_Wheel_Amps);
  }

  // Alarm 1
  if (TFT_Menu_Command == 20) {
    DPRINTLN("TX Alarm1 TFT");

    Serial3.print(Alarm_1_ON);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Alarm_1_Hour);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Alarm_1_Minute);
    Serial3.println("\c");
    delay(200);

    Serial3.print(Alarm_1_Repeat);
    Serial3.println("\d");
    delay(200);

    Serial3.print(Alarm_1_Action);
    Serial3.println("\e");
    delay(200);

    DPRINT(F("Alarm 1 ON = "));
    DPRINTLN(Alarm_1_ON);

    DPRINT(F("Alarm 1 Time = "));
    DPRINT(Alarm_1_Hour);
    DPRINT(F(":"));
    DPRINTLN(Alarm_1_Minute);

    DPRINT(F("Alarm 1 Repeat = "));
    DPRINTLN(Alarm_1_Repeat);

    DPRINT(F("Alarm 1 Action = "));
    DPRINTLN(Alarm_1_Action);
  }


  // Alarm 2
  if (TFT_Menu_Command == 21) {
    DPRINTLN("TX Alarm2 TFT");

    Serial3.print(Alarm_2_ON);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Alarm_2_Hour);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Alarm_2_Minute);
    Serial3.println("\c");
    delay(200);

    Serial3.print(Alarm_2_Repeat);
    Serial3.println("\d");
    delay(200);

    Serial3.print(Alarm_2_Action);
    Serial3.println("\e");
    delay(200);

    DPRINT(F("Alarm 2 ON = "));
    DPRINTLN(Alarm_2_ON);

    DPRINT(F("Alarm 2 Time = "));
    DPRINT(Alarm_2_Hour);
    DPRINT(F(":"));
    DPRINTLN(Alarm_2_Minute);

    DPRINT(F("Alarm 2 Repeat = "));
    DPRINTLN(Alarm_2_Repeat);

    DPRINT(F("Alarm 2 Action = "));
    DPRINTLN(Alarm_2_Action);
  }


  // Alarm 3
  if (TFT_Menu_Command == 22) {
    DPRINTLN("TX Alarm3 TFT");

    Serial3.print(Alarm_3_ON);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Alarm_3_Hour);
    Serial3.println("\b");
    delay(200);

    Serial3.print(Alarm_3_Minute);
    Serial3.println("\c");
    delay(200);

    Serial3.print(Alarm_3_Repeat);
    Serial3.println("\d");
    delay(200);

    Serial3.print(Alarm_3_Action);
    Serial3.println("\e");
    delay(200);

    DPRINT(F("Alarm 3 ON = "));
    DPRINTLN(Alarm_3_ON);

    DPRINT(F("Alarm 3 Time = "));
    DPRINT(Alarm_3_Hour);
    DPRINT(F(":"));
    DPRINTLN(Alarm_3_Minute);

    DPRINT(F("Alarm 3 Repeat = "));
    DPRINTLN(Alarm_3_Repeat);

    DPRINT(F("Alarm 3 Action = "));
    DPRINTLN(Alarm_3_Action);
  }


  // Set Time
  if (TFT_Menu_Command == 23) {
    DPRINTLN("Set Time TFT");
    if (PCB == 0) {
      Time t = rtc.time();
      Time_Hour = t.hr;
      Time_Minute = t.min;
    }
    if (PCB == 1) {
      byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
      Read_DS3231_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                       &year);
      Time_Hour = hour;
      Time_Minute = minute;
      Time_Second = second;
    }

    Serial3.print(Time_Hour);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Time_Minute);
    Serial3.println("\b");
    delay(200);

    DPRINT(F("Time Now = "));
    DPRINT(Time_Hour);
    DPRINT(F(":"));
    DPRINTLN(Time_Minute);
  }



  // Tip Sensor Menu
  if (TFT_Menu_Command == 24) {
    DPRINTLN("TX Tip Sensor to TFT");

    Serial3.print(Angle_Sensor_Enabled);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Tip_Over_Sensor_Enabled);
    Serial3.println("\b");
    delay(200);

    DPRINT(F("Tilt Angle Sensor = "));
    DPRINTLN(Angle_Sensor_Enabled);
    DPRINT(F("Tip Over Sensor = "));
    DPRINTLN(Tip_Over_Sensor_Enabled);
    DPRINTLN(F(" "));

  }


  // Pattern Mow Menu
  if (TFT_Menu_Command == 25) {
    DPRINTLN(F("TX Pattern to TFT"));

    Serial3.print(Pattern_Mow );
    Serial3.println("\a");
    delay(300);

    Serial3.print(Turn_90_Delay_LH / 10);
    Serial3.println("\b");
    delay(300);

    Serial3.print(Turn_90_Delay_RH / 10);
    Serial3.println("\c");
    delay(300);

    Serial3.print(Move_to_next_line_delay / 10);
    Serial3.println("\d");
    delay(300);

    Serial3.print(Line_Length_Cycles);
    Serial3.println("\e");
    delay(300);



    DPRINT(F("Pattern Mow"));
    if (Pattern_Mow == 0) DPRINTLN("OFF");
    if (Pattern_Mow == 1) DPRINTLN("Parallel");
    if (Pattern_Mow == 3) DPRINTLN("Spiral");

    DPRINT(F("Turn 90° LH= "));
    DPRINTLN(Turn_90_Delay_LH);

    DPRINT(F("Turn 90° RH= "));
    DPRINTLN(Turn_90_Delay_RH);

    DPRINT(F("Distance to next row= "));
    DPRINTLN(Move_to_next_line_delay);

    DPRINT(F("Row Length = "));
    DPRINTLN(Line_Length_Cycles);

  }



  // Initial Start Up Values
  if (TFT_Menu_Command == 55) {
    DPRINTLN("TX Start Up Values TFT");

    if (PCB == 0) {
      Time t = rtc.time();
      DPRINTLN("PCB = 0 Time ");
      DPRINT(t.hr);
      DPRINT(":");
      DPRINTLN(t.min);
      Time_Hour = t.hr;
      Time_Minute = t.min;
    }
    if (PCB == 1) {
      byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
      Read_DS3231_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
      Time_Hour = hour;
      Time_Minute = minute;
      Time_Second = second;
    }

    Serial3.print(Alarm_1_ON);
    Serial3.println("\a");
    delay(300);

    Serial3.print(Alarm_2_ON);
    Serial3.println("\b");
    delay(300);

    Serial3.print(Alarm_3_ON);
    Serial3.println("\c");
    delay(300);

    Serial3.print(Time_Hour);
    Serial3.println("\d");         // Sends the time to the Serial Monitor for the TFt to receive
    delay(300);

    Serial3.print(Time_Minute);
    Serial3.println("\e");
    delay(100);

    Serial3.print(GPS_Enabled);
    Serial3.println("\f");
    delay(100);

    Serial3.print(Perimeter_Wire_Enabled);
    Serial3.println("\g");
    delay(100);

    DPRINT(F("Alarm 1 ON = "));
    DPRINTLN(Alarm_1_ON);
    DPRINT(F("Alarm 2 ON = "));
    DPRINTLN(Alarm_2_ON);
    DPRINT(F("Alarm 3 ON = "));
    DPRINTLN(Alarm_3_ON);
    DPRINT(F("|Time:"));
    DPRINT(Time_Hour);
    DPRINT(F(":"));
    if (Time_Minute < 10) DPRINT("0");
    DPRINTLN(Time_Minute);
    DPRINT(F("GPS:"));
    if (GPS_Enabled == 1) DPRINTLN("ON");
    if (GPS_Enabled == 0) DPRINTLN("OFF");
    DPRINT(F("WIRE:"));
    if (Perimeter_Wire_Enabled == 1) DPRINTLN("ON");
    if (Perimeter_Wire_Enabled == 0) DPRINTLN("OFF");

  }



  // Test Wire Sensor
  if (TFT_Menu_Command == 41) {
    DPRINTLN("Test Wire Sensor");

    bool Test_Complete = 0;

    for (int i = 0; i <= 30; i++) {

      if (i > 28) Test_Complete = 1;
      ADCMan.run();
      // ADCMan.setCapture(pinPerimeterLeft, 1, 0);

      if (millis() >= nextTime)  {
        nextTime = millis() + 50;
        if (perimeter.isInside(0) != inside) {
          inside = perimeter.isInside(0);
          counter++;
        }
      }

      Serial3.print((perimeter.isInside(0)));
      Serial3.println("\a");
      delay(300);

      Serial3.print(perimeter.getMagnitude(0));
      Serial3.println("\b");
      delay(200);

      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(200);

      DPRINT(F("IN/Out:"));
      DPRINT(perimeter.isInside(0));
      DPRINT(F("   MAG:"));
      DPRINT(perimeter.getMagnitude(0));
      DPRINT(F("   i:"));
      DPRINTLN(i);
    }
    DPRINTLN(F("Test Completed"));
  }


  // Start Sonar Test
  if (TFT_Menu_Command == 45) {
    DPRINTLN(F("Sonar Test"));
    bool Test_Complete = 0;

    for (int i = 0; i <= 30; i++) {

      if (i > 28) Test_Complete = 1;
      if (Sonar_1_Activate == 1) distance1 = PingSonarY(trigPin1, echoPin1, 1, 1, 1, 5, 0);          //SONAR1
      if (Sonar_1_Activate == 0) distance1 = 999;
      delay(15);
      if (Sonar_2_Activate == 1) distance2 = PingSonarY(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
      if (Sonar_2_Activate == 0) distance1 = 999;
      delay(15);
      if (Sonar_3_Activate == 1) distance3 = PingSonarY(trigPin3, echoPin3, 3, 3, 3, 10, 0);          //SONAR3
      if (Sonar_3_Activate == 0) distance1 = 999;
      delay(15);

      Serial3.print(distance1);
      Serial3.println("\a");
      delay(300);

      Serial3.print(distance2);
      Serial3.println("\b");
      delay(200);

      Serial3.print(distance3);
      Serial3.println("\c");
      delay(200);

      Serial3.print(Test_Complete);
      Serial3.println("\d");
      delay(200);

      DPRINT("Test Complete");
      DPRINTLN(Test_Complete);


    }
    DPRINTLN(F("Sonar Test Complete"));


  }


  // Start Compass Test
  if (TFT_Menu_Command == 48) {
    DPRINTLN(F("Compass Test"));
    bool Test_Complete = 0;

    int Cycles = 40;

    for (int i = 0; i <= Cycles; i++) {

      if (i > (Cycles - 2) ) Test_Complete = 1;
      Get_Compass_Reading();

      int Compass_Degrees_TX = Compass_Heading_Degrees;
      delay(300);

      Serial3.print(Heading * 10);
      Serial3.println("\a");
      delay(300);

      Serial3.print(Compass_Degrees_TX);
      Serial3.println("\b");
      delay(300);

      DPRINT("Heading: ");
      DPRINT(Heading);
      DPRINT("  Degrees: ");
      DPRINTLN(Compass_Degrees_TX);


      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(300);


    }

    DPRINT(F("Compass Test Complete"));
    DPRINTLN(Test_Complete);
  }


  // Start GYRO Test
  if (TFT_Menu_Command == 39) {
    DPRINTLN(F("GYRO Test"));
    bool Test_Complete = 0;

    int Cycles = 60;

    for (int i = 0; i <= Cycles; i++) {

      if (i > (Cycles - 2) ) Test_Complete = 1;
      Get_GYRO_Reading();
      Print_GYRO_Reading();


      Serial3.print(GYRO_Angle_X);
      Serial3.println("\a");
      delay(300);

      Serial3.print(GYRO_Angle_Y);
      Serial3.println("\b");
      delay(300);

      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(300);

      //DPRINT("Angle X: ");
      //DPRINT(GYRO_Angle_X);
      //DPRINT(" Angle Y: ");
      //DPRINTLN(GYRO_Angle_Y);

    }

    DPRINT(F("Compass Test Complete"));
    DPRINTLN(Test_Complete);
  }


  // Start Volt Amp Test
  if (TFT_Menu_Command == 47) {
    DPRINTLN(F("Volt Amp Test"));
    bool Test_Complete = 0;

    for (int i = 0; i <= 30; i++) {

      if (i > 28) Test_Complete = 1;

      Read_Serial1_Nano();
      delay(200);

      int VoltsRX = (Volts * 100) / 2;

      Serial3.print(VoltsRX);
      Serial3.println("\a");
      delay(100);

      Serial3.print(Amps * 100);
      Serial3.println("\b");
      delay(100);

      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(300);

      DPRINT("VoltsRX: ");
      DPRINT(VoltsRX);
      DPRINT("  Volts: ");
      DPRINT(Volts);
      DPRINT("  Amps: ");
      DPRINTLN(Amps);
    }

    DPRINT(F("Volt Amp Test Complete"));
    DPRINTLN(Test_Complete);
  }

  // Start Tilt Test
  if (TFT_Menu_Command == 40) {
    DPRINTLN(F("Tilt Test"));
    bool Test_Complete = 0;
    Setup_Tilt_Tip_Safety();

    for (int i = 0; i <= 30; i++) {

      if (i > 28) Test_Complete = 1;

      Check_Tilt_Tip_Angle();
      delay(200);

      Serial3.print(Tilt_Angle_Sensed);
      Serial3.println("\a");
      delay(100);

      Serial3.print(Tilt_Orientation_Sensed);
      Serial3.println("\b");
      delay(100);

      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(300);

      DPRINT(F("   Data sent"));

      DPRINT(F("  Test Completed "));
      DPRINTLN(Test_Complete);
    }

    DPRINT(F("Tilt Test Complete : "));
    DPRINTLN(Test_Complete);
  }



  // Start Bumper Test
  if (TFT_Menu_Command == 50) {
    DPRINTLN(F("Bumper Bar Test"));
    bool Test_Complete = 0;
    bool Bump_LH;
    bool Bump_RH;

    for (int i = 0; i <= 30; i++) {

      if (i > 28) Test_Complete = 1;

      if (digitalRead(Bumper_Switch_Frnt_LH))  Bump_LH = 0;
      if (!digitalRead(Bumper_Switch_Frnt_LH)) Bump_LH = 1;
      if (digitalRead(Bumper_Switch_Frnt_RH))  Bump_RH = 0;
      if (!digitalRead(Bumper_Switch_Frnt_RH)) Bump_RH = 1;
      delay(200);

      int VoltsRX = (Volts * 100) / 2;

      Serial3.print(Bump_LH);
      Serial3.println("\a");
      delay(100);

      Serial3.print(Bump_RH);
      Serial3.println("\b");
      delay(100);

      Serial3.print(Test_Complete);
      Serial3.println("\c");
      delay(300);

      DPRINT("Bump LH: ");
      DPRINT(Bump_LH);
      DPRINT("  Bump RH: ");
      DPRINTLN(Bump_RH);
    }

    DPRINT(F("Volt Bumper Test Complete"));
    DPRINTLN(Test_Complete);
  }


}

void Send_Mower_Tracking_Data() {
  Serial3.print(Turn_To_Home);
  Serial3.println("\a");
  delay(100);

  Serial3.print(Find_Wire_Track);
  Serial3.println("\b");
  delay(100);

  Serial3.print(Go_To_Charging_Station);
  Serial3.println("\c");
  delay(300);

  Serial3.print(Mower_Docked);
  Serial3.println("\d");
  delay(300);

  Serial3.print(Mower_Status_Value);
  Serial3.println("\l");
  delay(300);

  Serial3.print(Mower_Error_Value);
  Serial3.println("\f");
  delay(300);


}

void Send_Mower_Error_Data() {

  Serial3.print(Mower_Status_Value);
  Serial3.println("\a");
  delay(300);

  Serial3.print(Mower_Error_Value);
  Serial3.println("\b");
  delay(300);

  DPRINT("Sending Error Data to TFT");

  DPRINT(F("|MS:"));
  DPRINT(Mower_Status_Value);
  DPRINT(F("|ME:"));
  DPRINT(Mower_Error_Value);
}


void Send_Mower_Running_Data() {
  int Delay_running = 200;

  DPRINTLN("|TFT_Data Running Turn Point");

  Serial3.print(Sonar_Status);
  Serial3.println(F("\a"));
  delay(Delay_running);

  Serial3.print(Outside_Wire);
  Serial3.println(F("\b"));
  delay(Delay_running);

  Serial3.print(Bumper_Status);
  Serial3.println("\c");
  delay(Delay_running);

  Serial3.print(Mower_Status_Value);
  Serial3.println("\s");
  delay(Delay_running);

  Serial3.print(Mower_Error_Value);
  Serial3.println("\e");
  delay(Delay_running);

  Serial3.print(Tilt_Angle_Sensed);
  Serial3.println("\f");
  delay(Delay_running);

  // Reformet Volts value for transmission
  float VoltsTX1 = Volts * 100;
  VoltsTX = VoltsTX1;

  Serial3.print(VoltsTX);
  Serial3.println("\g");
  delay(Delay_running);

  Serial3.print(GPS_Inside_Fence);
  Serial3.println("\h");
  delay(Delay_running);

  Serial3.print(GPS_Lock_OK);
  Serial3.println("\i");
  delay(Delay_running);

  Calculate_TFT_Mower_Status_Value();


  DPRINT(F("|S:"));
  DPRINT(Sonar_Status);
  DPRINT(F("|W:"));
  DPRINT(Outside_Wire);
  DPRINT(F("|B:"));
  DPRINT(Bumper_Status);
  DPRINT(F("|MS:"));
  DPRINT(Mower_Status_Value);
  DPRINT(F("|ME:"));
  DPRINT(Mower_Error_Value);
  DPRINT(F("|Tip:"));
  DPRINT(Tilt_Angle_Sensed);
  DPRINT(F("|VTX:"));
  DPRINTLN(VoltsTX);
  DPRINT(F("|GPS Inside Fence:"));
  if (GPS_Inside_Fence == 0) DPRINTLN("OUT");
  if (GPS_Inside_Fence == 1) DPRINTLN("IN");
  DPRINT(F("|GPS Lock:"));
  if (GPS_Lock_OK == 0) DPRINTLN("No lock");
  if (GPS_Lock_OK == 1) DPRINTLN("RTK FIX");
}


// Sends Wheel Amp Data during Test
void Send_Wheel_Amp_Data() {
  Serial3.print(Wheel_Blocked);
  Serial3.println("\a");
  delay(300);


  DPRINT(F("Wheel Status: "));
  if (Wheel_Blocked == 4) DPRINTLN("Blocked");
  if (Wheel_Blocked == 0) DPRINTLN("- - - -");
}



// Transfers the values to the TFT in Docked Mode.
void Send_Mower_Docked_Data()  {

  Calculate_TFT_Mower_Status_Value();
  // Reformet Volts value for transmission
  float VoltsTX1 = Volts * 100;
  VoltsTX = VoltsTX1;

  Serial3.print(VoltsTX);
  Serial3.println("\a");
  delay(300);

  Serial3.print(Mower_Status_Value);
  Serial3.println("\w");
  delay(300);

  Serial3.print(Mower_Error_Value);
  Serial3.println("\c");
  delay(300);

  Serial3.print(Charging);
  Serial3.println("\d");
  delay(300);

  int GPS_Lock_OK_Docked_TX;
  if (GPS_Lock_OK == 0) GPS_Lock_OK_Docked_TX = 2;
  if (GPS_Lock_OK == 1) GPS_Lock_OK_Docked_TX = 5;
  Serial3.print(GPS_Lock_OK_Docked_TX);
  Serial3.println("\e");
  delay(300);

  DPRINT(F("|VTX:"));
  DPRINT(VoltsTX);
  DPRINT(F("|MS:"));
  DPRINT(Mower_Status_Value);
  DPRINT(F("|ME:"));
  DPRINT(Mower_Error_Value);
  DPRINT(F("|C:"));
  DPRINT(Charging);
  DPRINT(F("|LOCK:"));
  DPRINT(GPS_Lock_OK);

}

void Calculate_TFT_Mower_Status_Value() {

  Mower_Status_Value = 0;

  if ((Wire_Detected == 1) && (Tilt_Orientation_Sensed == 0)) {
    Mower_Error = 0;
    if ((Mower_Docked == 1) || (Mower_Parked == 1)) {
      Mower_Error_Value = 0;
    }
  }



  if (Wire_Detected == 0) {

    // If the mower is running and no wire is detected then the full error screen is displayed
    if (Mower_Running == 1) {
      Mower_Error = 1;
      Mower_Error_Value = 1;     // 1 = No Wire Detected
    }
    // If the mower is docked then the Wire Off message is displayed on the docked screen.
    if ((Mower_Docked == 1) || (Mower_Parked == 1)) {
      Mower_Error_Value = 1;
    }
  }


  if (Mower_Docked == 1)           Mower_Status_Value = 1;
  if (Mower_Parked == 1)           Mower_Status_Value = 2;

  if (Mower_Parked_Low_Batt == 1)  {
    Mower_Status_Value = 4;  // Error Mode
    Mower_Error_Value = 2;   // 2 = Low Battery
  }

  if (Mower_Error == 1)                                    Mower_Status_Value = 4;  // Error
  if (Mower_Error == 3) {
    Mower_Status_Value = 4;  // Error
    Mower_Error_Value = 3;
  }
  if (Mower_Running == 1)                                  Mower_Status_Value = 5;
  if (Manuel_Mode == 1)                                    Mower_Status_Value = 6;
  if (Tracking_Wire == 1)                                  Mower_Status_Value = 7;
  if (Rain_Hit_Detected == 1)                              Mower_Status_Value = 8;
  if (Exiting_Dock == 1)                                   Mower_Status_Value = 9;

}
