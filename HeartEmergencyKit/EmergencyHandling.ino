
//////////
/////////  All Serial Handling Code,
/////////  It's Changeable with the 'serialVisual' variable
/////////  Set it to 'true' or 'false' when it's declared at start of code.
/////////

int LOWER_THRESHHOLD = 60;
int UPPER_THRESHHOLD = 80;

void checkEmergency() {
  if (wearing) {
    if (BPM < LOWER_THRESHHOLD) {
      bluetooth.println("EMERGENCY! Pulse is too low!");
      bluetooth.print("BPM: ");
      bluetooth.println(BPM);
    }
    if (BPM > UPPER_THRESHHOLD) {
      bluetooth.println("EMERGENCY! Pulse is too high!");
      bluetooth.print("BPM: ");
      bluetooth.println(BPM);
    }
 }

}
