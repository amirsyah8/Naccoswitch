#define change 2
#define power 3
#define openSwitchPin 4
#define closeSwitchPin 5
bool flagpressOLong = false;
bool flagpressCLong = false;
bool flagpressO = false;
bool flagpressC = false;
bool flagJalanO = false;
bool flagJalanC = false;
//bool flagCloseO = false;
unsigned long OSPress = 0;//open switch press
unsigned long OSRelease = 0;//open switch release
unsigned long CSPress = 0;//open switch press
unsigned long CSRelease = 0;//open switch release
unsigned long masaTekanO;
unsigned long masaTekanC;
unsigned long masa = 500;
unsigned long masaRun = 7000;


void setup() {
  Serial.begin(9600);
  Serial.println("Directed by amirshah");
  pinMode(openSwitchPin, INPUT);
  pinMode(closeSwitchPin, INPUT);/// openSwitchPin = LOW = TEKAN, DAH TUKAR

  pinMode(change, OUTPUT); // Define and set change pin as an output CLOSE = LOW, 
  pinMode(power, OUTPUT);  // Define and set power pin as an output
}

void loop() {

  // ni untuk open button start
  if (digitalRead(openSwitchPin) == HIGH&&flagpressO==false) //ASAL SWITH LOW
        {
          Serial.println("Tekan open");
          OSPress = millis(); //simpan masa mula
          flagpressO=true; // tukar status flag open
          flagJalanC=false;
          flagpressC = flagpressOLong= false; // flase kan semua
          delay(100);
        }
  else if (digitalRead(openSwitchPin) == LOW &&flagpressO==true)//ASAL SWITH HIGH
       {
                  OSRelease=millis(); 
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
       }
  // habis progrman open
  // ni untuk close button start
  if (digitalRead(closeSwitchPin) == HIGH&&flagpressC==false) //ASAL SWITH LOW
      {
          Serial.println("Tekan close");
          CSPress = millis(); //simpan masa mula
          flagpressC=true;
          flagJalanO=false;
          flagpressO = flagpressCLong=false;
          delay(100);
      }
  else if(digitalRead(closeSwitchPin) == LOW&&flagpressC==true)//ASAL SWITH HIGH
      { 
                  CSRelease=millis(); 
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

    //kija tekan kali ke 2

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
