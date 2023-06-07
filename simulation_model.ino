//Led pins
const int upPin[4]={0,13,9,5};
const int downPin[4]={0,12,8,4};
const int greenPin[4]={0,11,7,3};
const int redPin[4]={0,10,6,2};
//***

//AnalogRead pins (for detecting button pressing)
const int firePinG=1;       //Ground floor  
const int firePin1=2;     //first floor
const int firePin2=3;     //second floor
const int firePin3=4;     //third floor
const int resetPin=0;     //Reset


//variables for storing AnalogRead values
int fireG = 0;            //Ground floor  
int fire1 = 0;          //first floor
int fire2 = 0;          //second floor
int fire3 = 0;          //third floor
int reset = 0;          //reset
int LOOP = 10;          // LOOP times

//Multi-fire part: storing fire signal
boolean is_fireG = false;
boolean is_fire1 = false;
boolean is_fire2 = false;
boolean is_fire3 = false;

void setup()
{
  for (int x = 1; x <= 3 ; x++)
  {
  pinMode(upPin[x], OUTPUT);
  pinMode(downPin[x], OUTPUT);
  pinMode(greenPin[x], OUTPUT);
  pinMode(redPin[x], OUTPUT);         
  }
  Serial.begin(9600); 
  pinMode(firePinG, INPUT); 
  pinMode(firePin1, INPUT);
  pinMode(firePin2, INPUT);
  pinMode(firePin3, INPUT);
  pinMode(resetPin, INPUT);
}


void loop()
{   
  fire1 = 0;
  fireG = 0;
  fire2 = 0;
  fire3 = 0;
  reset = 0;
  for(int x=0; x<= LOOP; x++)
  {
  fireG = fireG + analogRead(firePinG);
  fire1 = fire1 + analogRead(firePin1);
  fire2 = fire2 + analogRead(firePin2);
  fire3 = fire3 + analogRead(firePin3);
  reset = reset + analogRead(resetPin);
  }
  fireG = fireG/LOOP;
  fire1 = fire1/LOOP;
  fire2 = fire2/LOOP;
  fire3 = fire3/LOOP;
  reset = reset/LOOP;
  
  if (fireG>512)  //If button G is pressed
  {  
  //initialize LEDs
  for (int x = 1; x <= 3 ; x++)
  {
  digitalWrite(upPin[x], LOW);
  digitalWrite(downPin[x], LOW);
  digitalWrite(greenPin[x], LOW);
  digitalWrite(redPin[x], LOW);         
  }
    
    digitalWrite(upPin[1],HIGH);
    digitalWrite(upPin[2],HIGH);
    digitalWrite(upPin[3],HIGH);
    digitalWrite(greenPin[1],HIGH);   
    digitalWrite(greenPin[2],HIGH);   
    analogWrite(greenPin[3],1023);   
    
   if (is_fire1 == true)
   {
     digitalWrite(redPin[1],HIGH); 
     digitalWrite(greenPin[1],LOW); 
     digitalWrite(upPin[1],LOW);
   }
   
   if (is_fire2 == true)
  {
    digitalWrite(redPin[1],HIGH); 
    digitalWrite(greenPin[1],LOW); 
    digitalWrite(upPin[1],LOW);
    digitalWrite(redPin[2],HIGH); 
    digitalWrite(greenPin[2],LOW); 
    digitalWrite(upPin[2],LOW);
  }
  
  if (is_fire3 == true)
  {
    digitalWrite(redPin[1],HIGH); 
    digitalWrite(greenPin[1],LOW); 
    digitalWrite(upPin[1],LOW);
    digitalWrite(redPin[2],HIGH); 
    digitalWrite(greenPin[2],LOW); 
    digitalWrite(upPin[2],LOW);
    digitalWrite(redPin[3],HIGH); 
    digitalWrite(greenPin[3],LOW); 
    digitalWrite(upPin[3],LOW);
  }
    
    is_fireG= true;
  }
  
        if (fire1>512)   //If button 1 is pressed
            {  
                      //initialize LEDs
                for (int x = 1; x <= 3 ; x++)
                    {
                        digitalWrite(upPin[x], LOW);
                        digitalWrite(downPin[x], LOW);
                        digitalWrite(greenPin[x], LOW);
                        digitalWrite(redPin[x], LOW);         
                     }
  
              digitalWrite(upPin[2],HIGH);
              digitalWrite(upPin[3],HIGH);
              digitalWrite(greenPin[2],HIGH);  
              analogWrite(greenPin[3],1023);   
              digitalWrite(redPin[1], HIGH);
              
              if (is_fire2 == true)
              {
                   digitalWrite(redPin[1],HIGH); 
                   digitalWrite(greenPin[1],LOW); 
                   digitalWrite(upPin[1],LOW);
                   digitalWrite(redPin[2],HIGH); 
                   digitalWrite(greenPin[2],LOW); 
                   digitalWrite(upPin[2],LOW);
              }
              
              if (is_fire3 == true)
              {
                  digitalWrite(redPin[1],HIGH); 
                  digitalWrite(greenPin[1],LOW); 
                  digitalWrite(upPin[1],LOW);
                  digitalWrite(redPin[2],HIGH); 
                  digitalWrite(greenPin[2],LOW); 
                  digitalWrite(upPin[2],LOW);
                  digitalWrite(redPin[3],HIGH); 
                  digitalWrite(greenPin[3],LOW); 
                  digitalWrite(upPin[3],LOW);
              }
             is_fire1=true;
            }
            
       
        if (fire2>512)  //If button 2 is pressed
            {  
                      //initialize LEDs
                for (int x = 1; x <= 3 ; x++)
                    {
                        digitalWrite(upPin[x], LOW);
                        digitalWrite(downPin[x], LOW);
                        digitalWrite(greenPin[x], LOW);
                        digitalWrite(redPin[x], LOW);         
                     }
  
              digitalWrite(upPin[3],HIGH);
              digitalWrite(downPin[1],HIGH);
              analogWrite(greenPin[3],1023);   
              digitalWrite(greenPin[1],HIGH);   
              digitalWrite(redPin[2], HIGH);
              
                if (is_fire1 == true)
                {
                  digitalWrite(redPin[1],HIGH); 
                  digitalWrite(greenPin[1],LOW); 
                  digitalWrite(upPin[1],LOW);
                 }
                 
                 if (is_fire3 == true)
              {
                  digitalWrite(redPin[1],HIGH); 
                  digitalWrite(greenPin[1],LOW); 
                  digitalWrite(upPin[1],LOW);
                  digitalWrite(redPin[2],HIGH); 
                  digitalWrite(greenPin[2],LOW); 
                  digitalWrite(upPin[2],LOW);
                  digitalWrite(redPin[3],HIGH); 
                  digitalWrite(greenPin[3],LOW); 
                  digitalWrite(upPin[3],LOW);
              }
              
                 if (is_fireG ==true)
                 {
                  digitalWrite(redPin[1],HIGH); 
                  digitalWrite(greenPin[1],LOW); 
                  digitalWrite(upPin[1],LOW);
                  digitalWrite(redPin[2],HIGH); 
                  digitalWrite(greenPin[2],LOW); 
                  digitalWrite(upPin[2],LOW);
                  digitalWrite(redPin[3],HIGH); 
                  digitalWrite(greenPin[3],LOW); 
                  digitalWrite(upPin[3],LOW);
                 }
              
                 
              is_fire2=true;
            }
         
        if (fire3>512)
            {  
                      //initialize LEDs
                for (int x = 1; x <= 3 ; x++)
                    {
                        digitalWrite(upPin[x], LOW);
                        digitalWrite(downPin[x], LOW);
                        digitalWrite(greenPin[x], LOW);
                        digitalWrite(redPin[x], LOW);         
                     }
                     
               digitalWrite(downPin[2],HIGH);
              digitalWrite(downPin[1],HIGH);
              analogWrite(greenPin[2],1023);   
              digitalWrite(greenPin[1],HIGH);   
              analogWrite(redPin[3], 1023);
              is_fire3=true;    
             }   
            
         if (reset>512)
            {  
                      //initialize LEDs
                for (int x = 1; x <= 3 ; x++)
                    {
                        digitalWrite(upPin[x], LOW);
                        digitalWrite(downPin[x], LOW);
                        digitalWrite(greenPin[x], LOW);
                        digitalWrite(redPin[x], LOW);         
                     }
                     
                     //Delete all multi-fire records
                     boolean is_fireG = false;
                     boolean is_fire1 = false;
                     boolean is_fire2 = false;
                     boolean is_fire3 = false;
            }   
            
  Serial.print(fireG);
  Serial.print(" & ");
  Serial.println(fire1);            
}