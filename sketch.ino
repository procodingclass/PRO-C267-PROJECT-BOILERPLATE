#include<ezButton.h>
#include "pitches.h"

byte clk = 2;
byte dt = 3;
byte sw = 4;

//  counting rotations
int counter = 0;

//  to avoid repetition
int flag = 1 , prev_counter = -1;

//  buzzer pin
const byte buzzer_pin = 5;

//  button object
ezButton button(sw);

void setup(){

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(clk) , encoder , FALLING);
  pinMode(buzzer_pin, OUTPUT);
  button.setDebounceTime(25);
}

void loop(){

  button.loop();
  if (button.isPressed()){
    select_mode();
  }

  choose_mode();

  //  for better working of simulator
  delay(10);
}

void encoder(){

  prev_counter = counter;

  if (digitalRead(dt)  ==  HIGH)counter++;
  else counter--;

  counter = constrain(counter , 0 , 1);
  flag = 1;
}

void choose_mode(){

  if (flag  ==  1  &&  prev_counter  !=  counter){
    if (counter  ==  0)Serial.println("Play Mario");
    else if (counter  ==  1)Serial.println("Coffin Dance");

    flag = 0;
  }
}

void select_mode(){
  if (counter  ==  0)mario();
  else if (counter  ==  1)coffin_dance();
}

void coffin_dance(){

  int melody[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  };
  
  for (int thisNote = 0; thisNote < 112; thisNote++) {   

    int noteDuration = 750 / noteDurations[thisNote];
    tone(buzzer_pin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(buzzer_pin);
  }
}

void mario(){

  tone(buzzer_pin,660,100);
  delay(150);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,510,100);
  delay(100);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,770,100);
  delay(550);
  tone(buzzer_pin,380,100);
  delay(575);

  tone(buzzer_pin,510,100);
  delay(450);
  tone(buzzer_pin,380,100);
  delay(400);
  tone(buzzer_pin,320,100);
  delay(500);
  tone(buzzer_pin,440,100);
  delay(300);
  tone(buzzer_pin,480,80);
  delay(330);
  tone(buzzer_pin,450,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(200);
  tone(buzzer_pin,660,80);
  delay(200);
  tone(buzzer_pin,760,50);
  delay(150);
  tone(buzzer_pin,860,100);
  delay(300);
  tone(buzzer_pin,700,80);
  delay(150);
  tone(buzzer_pin,760,50);
  delay(350);
  tone(buzzer_pin,660,80);
  delay(300);
  tone(buzzer_pin,520,80);
  delay(150);
  tone(buzzer_pin,580,80);
  delay(150);
  tone(buzzer_pin,480,80);
  delay(500);

  tone(buzzer_pin,510,100);
  delay(450);
  tone(buzzer_pin,380,100);
  delay(400);
  tone(buzzer_pin,320,100);
  delay(500);
  tone(buzzer_pin,440,100);
  delay(300);
  tone(buzzer_pin,480,80);
  delay(330);
  tone(buzzer_pin,450,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(200);
  tone(buzzer_pin,660,80);
  delay(200);
  tone(buzzer_pin,760,50);
  delay(150);
  tone(buzzer_pin,860,100);
  delay(300);
  tone(buzzer_pin,700,80);
  delay(150);
  tone(buzzer_pin,760,50);
  delay(350);
  tone(buzzer_pin,660,80);
  delay(300);
  tone(buzzer_pin,520,80);
  delay(150);
  tone(buzzer_pin,580,80);
  delay(150);
  tone(buzzer_pin,480,80);
  delay(500);

  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,150);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(150);

  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,430,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(100);
  tone(buzzer_pin,570,100);
  delay(220);

  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,200);
  delay(300);

  tone(buzzer_pin,1020,80);
  delay(300);
  tone(buzzer_pin,1020,80);
  delay(150);
  tone(buzzer_pin,1020,80);
  delay(300);

  tone(buzzer_pin,380,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,150);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(150);

  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,430,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(100);
  tone(buzzer_pin,570,100);
  delay(420);

  tone(buzzer_pin,585,100);
  delay(450);

  tone(buzzer_pin,550,100);
  delay(420);

  tone(buzzer_pin,500,100);
  delay(360);

  tone(buzzer_pin,380,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,150);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(150);

  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,430,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(100);
  tone(buzzer_pin,570,100);
  delay(220);

  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,200);
  delay(300);

  tone(buzzer_pin,1020,80);
  delay(300);
  tone(buzzer_pin,1020,80);
  delay(150);
  tone(buzzer_pin,1020,80);
  delay(300);

  tone(buzzer_pin,380,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,760,100);
  delay(100);
  tone(buzzer_pin,720,100);
  delay(150);
  tone(buzzer_pin,680,100);
  delay(150);
  tone(buzzer_pin,620,150);
  delay(300);

  tone(buzzer_pin,650,150);
  delay(300);
  tone(buzzer_pin,380,100);
  delay(150);
  tone(buzzer_pin,430,100);
  delay(150);

  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,430,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(100);
  tone(buzzer_pin,570,100);
  delay(420);

  tone(buzzer_pin,585,100);
  delay(450);

  tone(buzzer_pin,550,100);
  delay(420);

  tone(buzzer_pin,500,100);
  delay(360);

  tone(buzzer_pin,380,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(300);
  tone(buzzer_pin,500,100);
  delay(150);
  tone(buzzer_pin,500,100);
  delay(300);

  tone(buzzer_pin,500,60);
  delay(150);
  tone(buzzer_pin,500,80);
  delay(300);
  tone(buzzer_pin,500,60);
  delay(350);
  tone(buzzer_pin,500,80);
  delay(150);
  tone(buzzer_pin,580,80);
  delay(350);
  tone(buzzer_pin,660,80);
  delay(150);
  tone(buzzer_pin,500,80);
  delay(300);
  tone(buzzer_pin,430,80);
  delay(150);
  tone(buzzer_pin,380,80);
  delay(600);

  tone(buzzer_pin,500,60);
  delay(150);
  tone(buzzer_pin,500,80);
  delay(300);
  tone(buzzer_pin,500,60);
  delay(350);
  tone(buzzer_pin,500,80);
  delay(150);
  tone(buzzer_pin,580,80);
  delay(150);
  tone(buzzer_pin,660,80);
  delay(550);

  tone(buzzer_pin,870,80);
  delay(325);
  tone(buzzer_pin,760,80);
  delay(600);

  tone(buzzer_pin,500,60);
  delay(150);
  tone(buzzer_pin,500,80);
  delay(300);
  tone(buzzer_pin,500,60);
  delay(350);
  tone(buzzer_pin,500,80);
  delay(150);
  tone(buzzer_pin,580,80);
  delay(350);
  tone(buzzer_pin,660,80);
  delay(150);
  tone(buzzer_pin,500,80);
  delay(300);
  tone(buzzer_pin,430,80);
  delay(150);
  tone(buzzer_pin,380,80);
  delay(600);

  tone(buzzer_pin,660,100);
  delay(150);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,510,100);
  delay(100);
  tone(buzzer_pin,660,100);
  delay(300);
  tone(buzzer_pin,770,100);
  delay(550);
  tone(buzzer_pin,380,100);
  delay(575);
}