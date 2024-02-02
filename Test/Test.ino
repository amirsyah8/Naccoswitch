#define change 3
#define power 2
#define openSwitchPin 4
#define closeSwitchPin 5

void setup() {
    pinMode(openSwitchPin, INPUT_PULLUP);
  pinMode(closeSwitchPin, INPUT_PULLUP);/// openSwitchPin = LOW = TEKAN                                       
  pinMode(change, OUTPUT); // Define and set change pin as an output
  pinMode(power, OUTPUT);  // Define and set power pin as an output

}

void loop() {
  // put your main code here, to run repeatedly:

  if(openSwitchPin==LOW)
    {
      digitalWrite(power, HIGH);
      digitalWrite(change, LOW);
    }
 if(closeSwitchPin==LOW)
    {
      digitalWrite(power, LOW);
      digitalWrite(change, HIGH);
    }
}
