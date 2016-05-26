
/*  Pulse Sensor Amped 1.4    by Joel Murphy and Yury Gitman   http://www.pulsesensor.com

  ----------------------  Notes ----------------------  ----------------------
  This code:
  1) Blinks an LED to User's Live Heartbeat   PIN 13
  2) Fades an LED to User's Live HeartBeat
  3) Determines BPM
  4) Prints All of the Above to Serial

  Read Me:
  https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/README.md
  ----------------------       ----------------------  ----------------------
*/

#include <SoftwareSerial.h>

//  Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin
int button = 6;
boolean pressed = false;
int ledPin = 8;

int bluetoothTx = 10;
int bluetoothRx = 11;
boolean wearing = false;
boolean emergency_low = false;
boolean emergency_high = false;


// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holdsthe incoming raw data
volatile int IPI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  pinMode(blinkPin, OUTPUT);        // pin that will blink to your heartbeat!
  pinMode(fadePin, OUTPUT);         // pin that will fade to your heartbeat!
  pinMode(button, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);             // we agree to talk fast!
  bluetooth.begin(115200);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
  // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE,
  // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
  //   analogReference(EXTERNAL);
}


//  Where the Magic Happens
void loop() {

  serialOutput() ;

  if (QS == true) {    // A Heartbeat Was Found
    // BPM and IPI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat
    fadeRate = 255;         // Makes the LED Fade Effect Happen
    // Set 'fadeRate' Variable to 255 to fade LED with pulse
    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.
    QS = false;                      // reset the Quantified Self flag for next time
  }



  ledFadeToBeat();                      // Makes the LED Fade Effect Happen'
  
  // Detect touchbutton pressed.      
  if (digitalRead(button) == HIGH) {
    if (!pressed) {
      if (wearing == true) {
        wearing = false;
        digitalWrite(ledPin, LOW);

      } else if (wearing == false) {
        wearing = true;
        digitalWrite(ledPin, HIGH);

      }
      pressed = true;
    }
  } else if (digitalRead(button) == LOW && pressed == true) {
    pressed = false;

  }
  Serial.println(wearing);
  Serial.println(pressed);
  checkEmergency();
  delay(20);                             //  take a break
}



void ledFadeToBeat() {
  fadeRate -= 15;                         //  set LED fade value
  fadeRate = constrain(fadeRate, 0, 255); //  keep LED fade value from going into negative numbers!
  analogWrite(fadePin, fadeRate);         //  fade LED
}



