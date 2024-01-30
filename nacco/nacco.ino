#define change 2
#define power 3
#define openSwitchPin 4
#define closeSwitchPin 5
bool flagpressOLong = false;
bool flagpressCLong = false;
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
unsigned long masa = 500;

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
          flagpressC = flagpressOLong= false; // flase kan semua
          delay(50);
        }
  else if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true)
       {
                  OSRelease=millis(); 
                  if(flagpressOLong==false){Serial.println("tekan kejap je Open");}
                  else {Serial.println("open dilepaskan");}
                  flagpressOLong=flagpressO=false;
       }
  // habis progrman open
  // ni untuk close button start
  if (digitalRead(closeSwitchPin) == LOW&&flagpressC==false) 
      {
          Serial.println("Tekan close");
          CSPress = millis(); //simpan masa mula
          flagpressC=true;
          flagpressO = flagpressCLong=false;
          delay(50);
      }
  else if(digitalRead(closeSwitchPin) == HIGH&&flagpressC==true)
      { 
                  CSRelease=millis(); 
                  if(flagpressCLong==false){Serial.println("tekan kejap je Close");}
                  else {Serial.println("open dilepaskan");}
                  flagpressCLong=flagpressC=false;
                  
      }
    // habis progrman close

      if(flagpressO==true && flagpressOLong==false && millis()-OSPress>masa) // nk cek tekan open lama ke cepat
        {
         Serial.println("Open lama");
         flagpressOLong=true;
        }
        // nk cek tekan open lama ke cepat tamat
    
      if(flagpressC==true && flagpressCLong==false && millis()-CSPress>masa) // nk cek tekan close lama ke cepat
        {
         Serial.println("Close lama");
         flagpressCLong=true;
        }
        // nk cek tekan close lama ke cepat tamat


        
                           
  //if (digitalRead(openSwitchPin) == HIGH&&flagpressO==true) {flagpressO=false;OSRelease = millis();}

  //if(millis()-OSPress>pre&&openSwitchPin==LOW){stt();ope();flag5=true;Serial.println("open jalan d tekan");}
  //else if (millis()-OSPress<pre&&openSwitchPin==LOW){stt();ope();flag4=true;Serial.println("jalan terus open");}

  
  //if(flag4==true&&millis()-OSRelease>masa){stp();flag4=false;Serial.println("stop terus open");}
  
}

void stp(){digitalWrite(power, LOW);}
void stt(){digitalWrite(power, HIGH);}
void clo(){digitalWrite(change, HIGH);}
void ope(){digitalWrite(change, LOW);}
