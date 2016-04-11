
//////////
/////////  All Serial Handling Code,
/////////  It's Changeable with the 'serialVisual' variable
/////////  Set it to 'true' or 'false' when it's declared at start of code.
/////////

int LOWER_THRESHOLD = 40;
int UPPER_THRESHOLD = 100;

void checkEmergency() {
  if (wearing) {
    if (BPM < LOWER_THRESHOLD && emergency_low == false) {
      emergency_low = true;
      Serial.println("EMERGENCY! Pulse is too low!");
      Serial.print("BPM: ");
      Serial.println(BPM);
    }
    else if (BPM > UPPER_THRESHOLD && emergency_high == false) {
      emergency_high = true;
      Serial.println("EMERGENCY! Pulse is too high!");
      Serial.print("BPM: ");
      Serial.println(BPM);
    }
    else if (BPM >= LOWER_THRESHOLD && emergency_low == true) {
      emergency_low = false;
      Serial.println("No low emergency anymore");
    }
    else if (BPM <= UPPER_THRESHOLD && emergency_high == true) {
      emergency_high = false;
      Serial.println("No high emergency anymore");
    }
  }

}
