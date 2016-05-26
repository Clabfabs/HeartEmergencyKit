
//////////
/////////  All Emergency Handling Code
/////////

int LOWER_THRESHOLD = 40;
int UPPER_THRESHOLD = 120;

void checkEmergency() {
  if (wearing) {
    if (BPM < LOWER_THRESHOLD && emergency_low == false) {
      emergency_low = true;
      sendBluetoothData('L', BPM );
    }
    else if (BPM > UPPER_THRESHOLD && emergency_high == false) {
      emergency_high = true;
      sendBluetoothData('H', BPM );
    }
    else if (BPM >= LOWER_THRESHOLD && emergency_low == true) {
      emergency_low = false;
      sendBluetoothData('X', BPM );
    }
    else if (BPM <= UPPER_THRESHOLD && emergency_high == true) {
      emergency_high = false;
      sendBluetoothData('Y', BPM );
    }
  }
}
