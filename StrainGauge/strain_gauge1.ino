#include <SPI.h>
#include <SD.h>

//Sensor Variables----------------------
int sensor1 = A0;
int sensor1Value = 0;


int sensor2 = A1;
int sensor2Value = 0;

int sensor3 = A2;
int sensor3Value = 0;

int sensor4 = A3;
int sensor4Value = 0;

int sensor5 = A4;
int sensor5Value = 0;

int sensor6 = A5;
int sensor6Value = 0;
//-------------------------------------

unsigned long time;
File test;
const int chipSelect = 10;
const int readingCount = 180; 
int readings[readingCount];

void setup()
{
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(10, OUTPUT);
  
  time = millis();
  
  //SD.begin(chipSelect);

  if(!SD.begin()){
    Serial.println("initialization failed!");
    while(1);
  }

  test = SD.open("BKBR.txt", FILE_WRITE);

}

void loop()
{ 	
  
  


  if(test ){
     for(int i = 0; i < readingCount; i += 6){
       	readings[i] = analogRead(A0);
  		readings[i+1] = analogRead(A1);
  		readings[i+2] = analogRead(A2);
  		readings[i+3] = analogRead(A3);
  		readings[i+4] = analogRead(A4);
  		readings[i+5] = analogRead(A5);
     } 
  
  	 for(int i = 0; i < readingCount; i += 6){
       time = millis();
       test.print(time);
       test.print(",");
       test.print(readings[i]);
       test.print(",");
       test.print(readings[i+1]);
       test.print(",");
       test.print(readings[i+2]);
       test.print(",");
       test.print(readings[i+3]);
       test.print(",");
       test.print(readings[i+4]);
       test.print(",");
       test.print(readings[i+5]);
       test.print("\n");
     }

     test.flush();
  }
  else{
    Serial.println("error opening file");
  }
}