int red = 4; // the red LED is connected to Pin 0 of the Arduino
int yellow = 5; // the yellow LED is connected to Pin 1 of the Arduino
int green = 6; // the green LED is connected to Pin 2 of the Arduino

void on(int color)
{
  digitalWrite(color, HIGH);   
}

void off(int color)
{
  digitalWrite(color, LOW);   
}

void wait(int sek)
{
  delay(sek*1000);   
}
        
void setup() {
  //set up serial port
  Serial.begin(9600);
    
  // set up all the LEDs as OUTPUT
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
 
}

void loop() {
 
  //Første stadie - RØD
  Serial.println("Rødt");
  on(red); 
  off(yellow);
  off(green);
  
  // Vent 15 sek til det bliver rødt
  wait(15);
    
  //Nu bliver det grønt  
  on(yellow);  //rød + gul sammen
  Serial.println("Gult");

  wait(2);     //vent 1 sek
  off(red);    //sluk gul og rød og tønd grøn
  off(yellow); //
  on(green);   //
  Serial.println("Grønt");
  
  //Vent 15 sek på at det bliver rødt
  wait(15);
  
  //Nu bliver det rødt igen. Først skifter vi til gul og slukker for grøn. 
  // Sådan er det når det bliver rødt, så står gul alene - Det er et signal til den der kører bilen.
   on(yellow);
   off(green);
   Serial.println("Gult");  

    //venter 1 sek
    wait(2);

   //  Tænd for rød og sluk for gul (grøn er allerede slukket).
  on(red);
  off(yellow);
  
 //og så tilbage til start - Det kører bare rundt og rundt.
  wait(2);        
}
