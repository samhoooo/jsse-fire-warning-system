// ***** Modify on 5/5
// Consider a building with 3 floors
// You are on the 2nd floor
// The program begins...


boolean no_fire;
int fire_floor[3];   
int temp1;   //Temperature at 1st floor
int temp2;   //Temperature at 2nd floor
int temp3;   //Temperature at 3rd floor
int CO1;     //CO level at 1st floor
int CO2;     //CO level at 2nd floor
int CO3;     //CO level at 3rd floor
int smoke1;  //Smoke level at 1st floor
int smoke2;  //Smoke level at 2nd floor
int smoke3;  //Smoke level at 3rd floor
int floor_no;  //number of floors exist a fire

void setup()
{
   pinMode(11, OUTPUT);      //Output voltages for pin 8-13
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
}

void loop()
{
   //Part1: Initialize 
    digitalWrite(8, LOW);    // switch off all LED
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  no_fire=true;         //Initalize: No floor exist a fire
  floor_no = 0;  //number of floors exist a fire = 0
  for (int x=1 ; x<=3 ; x++)
    {
       fire_floor[x]=0;
    }
   
  randomSeed(analogRead(0));   // Randomize
  
  //Part2: Input data from sensors
   temp1=random(0,5);    // Floor 1: 1 means the value excess the expected range. The probability of alarm is 1/5
   CO1=random(0,5);
   smoke1=random(0,5);
   
   temp2=random(0,5);    // Floor 2: 1 means the value excess the expected range
   CO2=random(0,5);
   smoke2=random(0,5);
   
   temp3=random(0,5);    // Floor 3: 1 means the value excess the expected range
   CO3=random(0,5);
   smoke3=random(0,5);
 
  //Part 3: data analysis (To find out which floor exist a fire)
   if (temp1==1||CO1==1||smoke1==1)
    {
       floor_no = floor_no + 1; 
       fire_floor[floor_no]=1;
       no_fire=false;   //fire occurs
    }
    if (temp2==1||CO2==1||smoke2==1)
    {
       floor_no = floor_no + 1; 
       fire_floor[floor_no]=2;
       no_fire=false;
    }
    if (temp3==1||CO3==1||smoke3==1)
    {
       floor_no = floor_no + 1; 
       fire_floor[floor_no]=3;
       no_fire=false;
    }  
  
  // Part 4: LED indication (Generate output to the LED)
 for (int i=1 ; i<=3 ; i++)
  {
    if (fire_floor[i]==1) 
    {
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(8, HIGH);
    }
    if (fire_floor[i]==2)
    {
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(13, HIGH);
    }
    if (fire_floor[i]==3)
    {
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    } 
  }
  
    if(fire_floor[1]==0 && fire_floor[2]==0 && fire_floor[3]==0)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }

 delay(1000);    //delay 10 seconds before next loop
 
}
 
