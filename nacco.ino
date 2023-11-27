#define change 4
#define power 5
#define openSwitchPin 2
#define closeSwitchPin 3
bool flagpressE = false;
bool flagpressO = false;
bool flagpressC = false;
bool flag4 = false;
bool flag5 = false;
unsigned long OSPress = 0;//open switch press
unsigned long OSRelease = 0;//open switch release
unsigned long masa = 5500;
unsigned long pre = 700;

void setup() {
  Serial.begin(9600);
  Serial.println("Directed by amirshah");
  pinMode(openSwitchPin, INPUT_PULLUP);
  pinMode(closeSwitchPin, INPUT_PULLUP);/// openSwitchPin = LOW = TEKAN

  pinMode(change, OUTPUT); // Define and set change pin as an output
  pinMode(power, OUTPUT);  // Define and set power pin as an output
}

void loop() {
  if (digitalRead(openSwitchPin) == LOW&&flagpressO==false) {Serial.println("Tekan open");
    OSPress = millis();
    flagpressO=true;
    flagpressC = flagpressE= false;
  }
  else {if(digitalRead(openSwitchPin) == HIGH&&flagpressO==true){OSRelease=millis(); flagpressO=false;Serial.println("open dilepaskan");}}


  if (digitalRead(closeSwitchPin) == LOW&&flagpressC==false) {
    flagpressC=true;
    flagpressO = flagpressE=false;
  }
  else { if(flagpressE==false){flagpressE=true;}}
  
  if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true) {flagpressO=false;OSRelease = millis();}

  if(millis()-OSPress>pre&&openSwitchPin==LOW){stt();ope();flag5=true;Serial.println("open jalan d tekan");}
  else if (millis()-OSPress<pre&&openSwitchPin==LOW){stt();ope();flag4=true;Serial.println("jalan terus open");}

  
  if(flag4==true&&millis()-OSRelease>masa){stp();flag4=false;Serial.println("stop terus open");}
  
}

void stp(){digitalWrite(power, LOW);}
void stt(){digitalWrite(power, HIGH);}
void clo(){digitalWrite(change, HIGH);}
void ope(){digitalWrite(change, LOW);}
