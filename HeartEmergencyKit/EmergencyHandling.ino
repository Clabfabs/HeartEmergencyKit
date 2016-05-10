
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
      bluetooth.println("EMERGENCY! Pulse is too low!");
      bluetooth.print("BPM: ");
      bluetooth.println(BPM);
    }
    else if (BPM > UPPER_THRESHOLD && emergency_high == false) {
      emergency_high = true;
      bluetooth.println("EMERGENCY! Pulse is too high!");
      bluetooth.print("BPM: ");
      bluetooth.println(BPM);
    }
    else if (BPM >= LOWER_THRESHOLD && emergency_low == true) {
      emergency_low = false;
      bluetooth.println("No low emergency anymore");
    }
    else if (BPM <= UPPER_THRESHOLD && emergency_high == true) {
      emergency_high = false;
      bluetooth.println("No high emergency anymore");
    }
  }

}
