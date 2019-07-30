/*
  Program for navidroid car for ELEC1100 course
  By Richard GUERRE 
   & Marvel  GAN
*/

// assign meaningful names to those pins that will be used
#define pinLeftSensor A5      //pin A5
#define pinRightSensor A3     //pin A3
#define pinMidSensor A7       //pin A7
#define pinTopSensor A1       //pin A1

#define pinLQ3 3              //pin D3
#define pinLQ2 4              //pin D4
#define pinLQ1 5              //pin D5
#define pinLQ0 6              //pin D6

#define pinRQ3 7              //pin D7
#define pinRQ2 8              //pin D8
#define pinRQ1 9              //pin D9
#define pinRQ0 10             //pin D10

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

//define variables to be used in script
int leftSensor;
int rightSensor;
int midSensor;
int topSensor;

unsigned long leftTime = 0.0;
unsigned long prevLeftTime = 0.0;
unsigned long diffLeftTime = 0.0;
unsigned long rightTime = 0.0;
unsigned long prevRightTime = 0.0;
unsigned long diffRightTime = 0.0;

int turnCounter;
boolean topCount;

//------------------------------------------------------------------------------------

// the setup function runs once when you press reset or power the board
void setup() {
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMidSensor, INPUT);
  pinMode(pinTopSensor, INPUT);

  pinMode(pinLQ3, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ0, OUTPUT);

  pinMode(pinRQ3, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ0, OUTPUT);

  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);

  turnCounter = 1;
  topCount = false;
  drive('B', 16, 16);
}

//------------------------------------------------------------------------------------

//Function that simplifies the writing of code
void drive(char dir, int spe1, int spe2){
  
  digitalWrite(pinLQ3, bitRead(spe1, 3));
  digitalWrite(pinLQ2, bitRead(spe1, 2));
  digitalWrite(pinLQ1, bitRead(spe1, 1));
  digitalWrite(pinLQ0, bitRead(spe1, 0));
  digitalWrite(pinRQ3, bitRead(spe2, 3));
  digitalWrite(pinRQ2, bitRead(spe2, 2));
  digitalWrite(pinRQ1, bitRead(spe2, 1));
  digitalWrite(pinRQ0, bitRead(spe2, 0));
  
  if(dir == 'F'){
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, HIGH);
  }
  if(dir == 'B'){
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, LOW);
  }
  if(dir == 'L'){
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, HIGH); 
  }
  else if(dir == 'R'){
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, LOW);
  }
  
}


//------------------------------------------------------------------------------------

// the loop function runs over and over again forever
void loop() {

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  midSensor = digitalRead(pinMidSensor);
  topSensor = digitalRead(pinTopSensor);

  if(!leftSensor){
    leftTime = millis();
    diffLeftTime = leftTime - prevLeftTime;
    prevLeftTime = leftTime;
  }
  if(!rightSensor){
    rightTime = millis();
    diffLeftTime = rightTime - prevRightTime;
    prevRightTime = rightTime;
  }

  if(!topSensor){
    if(turnCounter == 1){
      topCount = true;
    }
    if(turnCounter >= 3){
      drive('B', 15, 15);
      delay(500);
    }
  }

  if(topCount){
  if(leftSensor && rightSensor && !midSensor){
    if(turnCounter < 3) drive('F', 15, 15);
    else if(turnCounter == 4) drive('F', 10, 10);
    else drive('F', 10, 10);
  }
  
  if(!leftSensor && rightSensor && !midSensor){
    if(turnCounter > 3){
      drive('F', 15, 8);
      delay(100);
    }
    else{
    if(diffLeftTime >= 400) drive('F', 12, 15);
    else if(400 > diffLeftTime >= 200) drive('F', 8, 15);
    else if(200 > diffLeftTime >= 100) drive('F', 4, 15);
    else if(100 > diffLeftTime >= 50) drive('F', 0, 15);
    else drive('L', 5, 10);
    }
  }
  if(leftSensor && !rightSensor && !midSensor){
    if(turnCounter > 3){
      drive('F', 8, 15);
      delay(100);
    }
    else{
    if(diffRightTime >= 400) drive('F', 15, 12);
    else if(400 > diffRightTime >= 200) drive('F', 1/*
  Program for navidroid car for ELEC1100 course
  By Richard GUERRE 
   & Marvel  GAN
*/

// assign meaningful names to those pins that will be used
#define pinLeftSensor A5      //pin A5
#define pinRightSensor A3     //pin A3
#define pinMidSensor A7       //pin A7
#define pinTopSensor A1       //pin A1

#define pinLQ3 3              //pin D3
#define pinLQ2 4              //pin D4
#define pinLQ1 5              //pin D5
#define pinLQ0 6              //pin D6

#define pinRQ3 7              //pin D7
#define pinRQ2 8              //pin D8
#define pinRQ1 9              //pin D9
#define pinRQ0 10             //pin D10

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

//define variables to be used in script
int leftSensor;
int rightSensor;
int midSensor;
int topSensor;

unsigned long leftTime = 0.0;
unsigned long prevLeftTime = 0.0;
unsigned long diffLeftTime = 0.0;
unsigned long rightTime = 0.0;
unsigned long prevRightTime = 0.0;
unsigned long diffRightTime = 0.0;

int turnCounter;
boolean topCount;
boolean wiggle;

//------------------------------------------------------------------------------------

// the setup function runs once when you press reset or power the board
void setup() {
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMidSensor, INPUT);
  pinMode(pinTopSensor, INPUT);

  pinMode(pinLQ3, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ0, OUTPUT);

  pinMode(pinRQ3, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ0, OUTPUT);

  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);

  turnCounter = 1;
  topCount = false;
  boolean
  drive('B', 16, 16);
}

//------------------------------------------------------------------------------------

//Function that simplifies the writing of code
void drive(char dir, int spe1, int spe2){
  
  digitalWrite(pinLQ3, bitRead(spe1, 3));
  digitalWrite(pinLQ2, bitRead(spe1, 2));
  digitalWrite(pinLQ1, bitRead(spe1, 1));
  digitalWrite(pinLQ0, bitRead(spe1, 0));
  digitalWrite(pinRQ3, bitRead(spe2, 3));
  digitalWrite(pinRQ2, bitRead(spe2, 2));
  digitalWrite(pinRQ1, bitRead(spe2, 1));
  digitalWrite(pinRQ0, bitRead(spe2, 0));
  
  if(dir == 'F'){
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, HIGH);
  }
  if(dir == 'B'){
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, LOW);
  }
  if(dir == 'L'){
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, HIGH); 
  }
  else if(dir == 'R'){
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, LOW);
  }
  
}


//------------------------------------------------------------------------------------

// the loop function runs over and over again forever
void loop() {

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  midSensor = digitalRead(pinMidSensor);
  topSensor = digitalRead(pinTopSensor);

  if(!topSensor){
    if(turnCounter == 1){
      topCount = true;
    }
    if(turnCounter >= 3){
      drive('B', 15, 15);
      delay(500);
      drive('B', 0, 0);
      delay(10000);
    }
  }

  if(topCount){
  if(leftSensor && rightSensor && !midSensor){
    if(turnCounter < 3) drive('F', 15, 15);
    else if(turnCounter >= 4) drive('F', 13, 13);
    else drive('F', 10, 10);
  }
  
  if(!leftSensor && rightSensor && !midSensor){
      drive('L', 5, 10);
  }
  if(leftSensor && !rightSensor && !midSensor){
      drive('R', 10, 5);
  }
  if(!leftSensor && !rightSensor && !midSensor){
    if(turnCounter < 3){
      drive('L', 3, 15);
      delay(300);
      turnCounter++;
    }
    else if(turnCounter == 3){
      drive('R', 13, 3);
      delay(300);
      turnCounter++;
     
    }
    else if(wiggle){
      drive('B', 15, 5);
      delay(100);
      wiggle = false;
    }
    else if(!wiggle){
      drive('B', 5, 10);
      delay(100);
      wiggle = true;
    }
  }
  if(leftSensor && rightSensor && midSensor){
    drive('B', 15, 15);
  }
  }
}
5, 8);
    else if(200 > diffRightTime >= 100) drive('F', 15, 4);
    else if(100 > diffRightTime >= 50) drive('F', 15, 0);
    else drive('R', 10, 5);
    }
  }
  if(!leftSensor && !rightSensor && !midSensor){
    if(turnCounter < 3){
      drive('L', 3, 15);
      delay(300);
      //drive('F', 0, 0);
      //delay(5000);
      turnCounter++;
    }
    else if(turnCounter == 3){
      drive('R', 13, 3);
      delay(300);
      //drive('F', 0, 0);
      //delay(5000);
      turnCounter++;
    }
  }
  if(leftSensor && rightSensor && midSensor){
    drive('B', 15, 15); // drive back 30cm at the finish line as instructed
  }
  }
}
