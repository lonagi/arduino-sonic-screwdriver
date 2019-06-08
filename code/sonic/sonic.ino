const int leds = 13;
const int sound = 9;
const int btn1 = 3;
const int btn2 = 6;

int typeS = 0;
bool b_btn1 = false;
int delaka = 0;

const int typesall = 12;
int type1[3] = {1500,1800,2500}; //delay 1 i 3
int type2 = 2000; //delay 100
int type3 = 200; //delay 100
int type4 = 500; //delay 100
int type5 = 1000; //delay 100
int type6[2] = {1471,1575}; //delay 1 i 2
int type7[6] = {139,117,135,124,124,139}; // delay 2 i 2
int type8[6] = {139,117,135,124,124,139}; // delay 1 i 6
int type9[23] = {32, 242, 67, 102, 211, 46, 156, 163, 54, 197, 94, 112, 183, 56, 183, 112, 97, 187, 69, 158, 136, 87}; //delay 1 i 23
int type10[3] = {1500,1800,2500}; //delay 15 i 3
int type11[2] = {1471,1575}; //delay 15 i 2
int type12 = 1000; //delay 5

void setup() {
pinMode(leds,OUTPUT);
pinMode(sound,OUTPUT);
pinMode(btn1,INPUT_PULLUP);
pinMode(btn2,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {

  if(typeS>typesall+1) typeS=1;
  
   if(!digitalRead(btn1))
   {
    Serial.println("Sonic!");
    digitalWrite(leds,HIGH); 
    switch(typeS){
    case 1:
      delaka = 1;
     for (int i = 0; i < 3; i++)
     { 
        tone(sound, type1[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 2:
        delaka = 100;
        tone(sound, type2); 
    break;
     case 3:
        delaka = 100;
        tone(sound, type3); 
    break;
    case 4:
        delaka = 100;
        tone(sound, type4); 
    break;
    case 5:
        delaka = 100;
        tone(sound, type5); 
    break;
    case 6:
      delaka = 1;
     for (int i = 0; i < 2; i++)
     { 
        tone(sound, type6[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 7:
      delaka = 2;
     for (int i = 0; i < 2; i++)
     { 
        tone(sound, type7[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 8:
      delaka = 1;
     for (int i = 0; i < 6; i++)
     { 
        tone(sound, type8[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 9:
      delaka = 1;
     for (int i = 0; i < 23; i++)
     { 
        tone(sound, type9[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 10:
      delaka = 15;
     for (int i = 0; i < 3; i++)
     { 
        tone(sound, type10[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 11:
      delaka = 15;
     for (int i = 0; i < 2; i++)
     { 
        tone(sound, type11[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 12:
        delaka = 5;
        tone(sound, type12); 
    break;
  }
   }
   else
   {
    noTone(sound);
    digitalWrite(leds,LOW);
    Serial.println("No Sonic!");
   }

    if(!digitalRead(btn2) && !b_btn1)
  {
    b_btn1 = true;
    typeS++;
    Serial.println("Schanger "+typeS);
    delay(1500);
    b_btn1 = false;
  }

}
