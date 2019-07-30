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
      drive('B', 0, 0);
    }
    if(turnCounter >= 3){
      drive('B', 15, 15);
      delay(1500);
    }
  }
  
  if(leftSensor && rightSensor && !midSensor){
    drive('F', 15, 15);
  }
  if(!leftSensor && rightSensor && !midSensor){
    if(diffLeftTime >= 800) drive('F', 14, 15);
    else if(800 > diffLeftTime >= 400) drive('F', 10, 15);
    else if(400 > diffLeftTime >= 200) drive('F', 7, 15);
    else if(200 > diffLeftTime >= 50) drive('F', 3, 15);
    else drive('F', 0, 15);
  }
  if(leftSensor && !rightSensor && !midSensor){
    if(diffRightTime >= 800) drive('F', 15, 14);
    else if(800 > diffRightTime >= 400) drive('F', 15, 10);
    else if(400 > diffRightTime >= 200) drive('F', 15, 7);
    else if(200 > diffRightTime >= 50) drive('F', 15, 3);
    else drive('F', 15, 0);
  }
  if(!leftSensor && !rightSensor && !midSensor){
    if(turnCounter < 3){
      drive('F', 8, 15);
      delay(1000);
      turnCounter++;
    }
    else if(turnCounter >= 3){
      drive('F', 15, 8);
      delay(1000);
      turnCounter++;
    }
    else drive('B', 15, 15);
  }
  if(leftSensor && rightSensor && midSensor){
    drive('B', 15, 15); // drive backwards 30cm at the finish line as instructed.
    delay(200);
  }
}
