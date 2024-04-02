const int pin_1 = 4;
const int pin_2 = 7;
const int pin_3 = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin_1, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_2, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_3, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pin_2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pin_3, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1000);   // wait for a second
  
  digitalWrite(pin_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(pin_2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(pin_3, LOW);    // turn the LED off by making the voltage LOW

  delay(1000);   // wait for a second
}
