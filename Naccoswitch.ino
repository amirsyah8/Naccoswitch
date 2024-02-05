#define change 2
#define power 3
#define openSwitchPin 4
#define closeSwitchPin 5
<<<<<<< HEAD
bool flagpressOLong = false;
bool flagpressCLong = false;
bool flagpressO = false;
bool flagpressC = false;
bool flagJalanO = false;
bool flagJalanC = false;
//bool flagCloseO = false;
=======
bool flagpressE = false;
bool flagpressO = false;
bool flagpressC = false;
bool flag4 = false;
bool flag5 = false;
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
unsigned long OSPress = 0;//open switch press
unsigned long OSRelease = 0;//open switch release
unsigned long CSPress = 0;//open switch press
unsigned long CSRelease = 0;//open switch release
unsigned long masaTekanO;
unsigned long masaTekanC;
<<<<<<< HEAD
unsigned long masa = 500;
unsigned long masaRun = 7000;

=======
unsigned long masa = 700;
unsigned long pre = 700;
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d

void setup() {
  Serial.begin(9600);
  Serial.println("Directed by amirshah");
  pinMode(openSwitchPin, INPUT_PULLUP);
  pinMode(closeSwitchPin, INPUT_PULLUP);/// openSwitchPin = LOW = TEKAN

<<<<<<< HEAD
  pinMode(change, OUTPUT); // Define and set change pin as an output CLOSE = LOW, 
=======
  pinMode(change, OUTPUT); // Define and set change pin as an output
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
  pinMode(power, OUTPUT);  // Define and set power pin as an output
}

void loop() {
<<<<<<< HEAD

=======
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
  // ni untuk open button start
  if (digitalRead(openSwitchPin) == LOW&&flagpressO==false) 
        {
          Serial.println("Tekan open");
          OSPress = millis(); //simpan masa mula
          flagpressO=true; // tukar status flag open
<<<<<<< HEAD
          flagJalanC=false;
          flagpressC = flagpressOLong= false; // flase kan semua
          delay(100);
=======
          flagpressC = flagpressE= false; // flase kan semua
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
        }
  else if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true)
       {
                  OSRelease=millis(); 
<<<<<<< HEAD
                  if(flagpressOLong==false)
                      {
                        Serial.println("tekan kejap je Open");
                        digitalWrite(power, HIGH);
                        digitalWrite(change, HIGH);
                        flagJalanO=true;
                      }
                  else {Serial.println("open dilepaskan");digitalWrite(power, LOW);delay(50);}
                  flagpressOLong=flagpressO=false;
                  delay(100);
=======
                  flagpressO=false;
                  Serial.println("open dilepaskan");
                    if(OSRelease-OSPress>masa) // nk cek tekan lama ke cepat
                        {
                          masaTekanO = OSRelease-OSPress;
                          Serial.print("masa tekan open : ");
                          Serial.println(masaTekanO);
                        }
                       else{Serial.println("tekan kejap je open");}
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
       }
  // habis progrman open
  // ni untuk close button start
  if (digitalRead(closeSwitchPin) == LOW&&flagpressC==false) 
      {
          Serial.println("Tekan close");
          CSPress = millis(); //simpan masa mula
          flagpressC=true;
<<<<<<< HEAD
          flagJalanO=false;
          flagpressO = flagpressCLong=false;
          delay(100);
=======
          flagpressO = flagpressE=false;
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
      }
  else if(digitalRead(closeSwitchPin) == HIGH&&flagpressC==true)
      { 
                  CSRelease=millis(); 
<<<<<<< HEAD
                  if(flagpressCLong==false)
                    {
                      Serial.println("tekan kejap je Close");
                      digitalWrite(power, HIGH);
                      digitalWrite(change, LOW);
                      flagJalanC=true;
                    }
                  else {Serial.println("open dilepaskan");digitalWrite(power, LOW);}
                  flagpressCLong=flagpressC=false;
                  delay(100);
                  
      }
    // habis progrman close

      if(flagpressO==true && flagpressOLong==false && millis()-OSPress>masa) // nk cek tekan open lama ke cepat
        {
         Serial.println("Open lama");
         flagpressOLong=true;
         flagJalanO==false;
           digitalWrite(power, HIGH);
           digitalWrite(change, HIGH);
        }
        // nk cek tekan open lama ke cepat tamat
    
      if(flagpressC==true && flagpressCLong==false && millis()-CSPress>masa) // nk cek tekan close lama ke cepat
        {
         Serial.println("Close lama");
         flagpressCLong=true;
           digitalWrite(power, HIGH);
           digitalWrite(change, LOW);
        }
        // nk cek tekan close lama ke cepat tamat

    //ni nak auto tutup ikut masa
    if(flagJalanO==true && millis()-OSPress>masaRun)
      {
        Serial.println("Auto stop open");
        digitalWrite(power, LOW);
        flagJalanO=false;
      }

    if(flagJalanC==true && millis()-CSPress>masaRun)
      {
        Serial.println("Auto stop close");
        digitalWrite(power, LOW);
        flagJalanC=false;
      } 
      //ni nak auto tutup ikut masa tamat     
  
}
=======
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
>>>>>>> ac1f03c4174674f38de94ffe1c230f92baeae28d
