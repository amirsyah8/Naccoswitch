#define change 2
#define power 3
#define openSwitchPin 4
#define closeSwitchPin 5
bool flagpressE = false;
bool flagpressO = false;
bool flagpressC = false;
bool flag4 = false;
bool flag5 = false;
unsigned long OSPress = 0;//open switch press
unsigned long OSRelease = 0;//open switch release
unsigned long CSPress = 0;//open switch press
unsigned long CSRelease = 0;//open switch release
unsigned long masaTekanO;
unsigned long masaTekanC;
unsigned long masa = 700;
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
  // ni untuk open button start
  if (digitalRead(openSwitchPin) == LOW&&flagpressO==false) 
        {
          Serial.println("Tekan open");
          OSPress = millis(); //simpan masa mula
          flagpressO=true; // tukar status flag open
          flagpressC = flagpressE= false; // flase kan semua
        }
  else if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true)
       {
                  OSRelease=millis(); 
                  flagpressO=false;
                  Serial.println("open dilepaskan");
                    if(OSRelease-OSPress>masa) // nk cek tekan lama ke cepat
                        {
                          masaTekanO = OSRelease-OSPress;
                          Serial.print("masa tekan open : ");
                          Serial.println(masaTekanO);
                        }
                       else{Serial.println("tekan kejap je open");}
       }
  // habis progrman open
  // ni untuk close button start
  if (digitalRead(closeSwitchPin) == LOW&&flagpressC==false) 
      {
          Serial.println("Tekan close");
          CSPress = millis(); //simpan masa mula
          flagpressC=true;
          flagpressO = flagpressE=false;
      }
  else if(digitalRead(closeSwitchPin) == HIGH&&flagpressC==true)
      { 
                  CSRelease=millis(); 
                  flagpressC=false;
                  Serial.println("open dilepaskan");
                       if(CSRelease-CSPress>masa) // nk cek tekan lama ke cepat
                            {
                              masaTekanC = CSRelease-CSPress;
                              Serial.print("masa tekan Close : ");
                              Serial.println(masaTekanC);
                            }
                           else{Serial.println("tekan kejap je Close");}
      }
    // habis progrman close

  //if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true) {flagpressO=false;OSRelease = millis();}

  //if(millis()-OSPress>pre&&openSwitchPin==LOW){stt();ope();flag5=true;Serial.println("open jalan d tekan");}
  //else if (millis()-OSPress<pre&&openSwitchPin==LOW){stt();ope();flag4=true;Serial.println("jalan terus open");}

  
  //if(flag4==true&&millis()-OSRelease>masa){stp();flag4=false;Serial.println("stop terus open");}
  
}

void stp(){digitalWrite(power, LOW);}
void stt(){digitalWrite(power, HIGH);}
void clo(){digitalWrite(change, HIGH);}
void ope(){digitalWrite(change, LOW);}
