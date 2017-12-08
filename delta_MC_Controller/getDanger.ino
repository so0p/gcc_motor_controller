//Globals
//***********************
bool dangerFront = false;
bool dangerBack = false;

uint16_t currentM1 = 0;
uint16_t currentM2 = 0;
uint16_t currentM3 = 0;
uint16_t currentM4 = 0;
uint16_t currentM5 = 0;
uint16_t currentM6 = 0;

bool dangerOverride = false;

bool dangerM1 = false;
bool dangerM2 = false;
bool dangerM3 = false;
bool dangerM4 = false;
bool dangerM5 = false;
bool dangerM6 = false;   

bool FrontRight = false;
bool FrontLeft = false;
bool BackRight = false;
bool BackLeft = false;
//***********************

int M1_thresh = 1;
int M2_thresh = 2;
int M3_thresh = 3;
int M4_thresh = 4;
int M5_thresh = 5;
int M6_thresh = 6;              // undertermined values; requires testing

int BUTTON_PIN_FRONT_R = 43;
int BUTTON_PIN_FRONT_L = 41;
int BUTTON_PIN_BACK_R = 47;
int BUTTON_PIN_BACK_L = 45;     // arbitrary pin locations

int buttonStateFront_R = 0;
int buttonStateFront_L = 0;
int buttonStateBack_R = 0;
int buttonStateBack_L = 0;

void setup() 
{
  pinMode(BUTTON_PIN_FRONT_R, INPUT);
  pinMode(BUTTON_PIN_FRONT_L, INPUT);
  pinMode(BUTTON_PIN_BACK_R, INPUT);
  pinMode(BUTTON_PIN_BACK_L, INPUT);
}

void loop() {

  if( dangerOverride = true){
    bool dangerM1 = false;
    bool dangerM2 = false;
    bool dangerM3 = false;
    bool dangerM4 = false;
    bool dangerM5 = false;
    bool dangerM6 = false;   

    bool dangerFront = false;
    bool dangerBack = false;
  }

  else {

  if( mode = MODE_ROVER){

        buttonStateFront_R = digitalRead(BUTTON_PIN_FRONT_R);
        buttonStateBack_R = digitalRead(BUTTON_PIN_BACK_R);
        buttonStateFront_L = digitalRead(BUTTON_PIN_FRONT_L);
        buttonStateBack_L = digitalRead(BUTTON_PIN_BACK_L);         

        if (buttonStateFront_R || buttonStateFront_L == HIGH){
          dangerFront = true;
        }
        else {
          dangerFront = false;
        }
  
        if (buttonStateBack_R || buttonStateBack_L == HIGH){
          dangerBack = true;
        }

        else{
          dangerBack = false;
        }
  }
  else if( mode = MODE_ARM){

    int counter = 0;
      
    if( counter = 50){
      
     roboclaw1.ReadCurrents(address, &currentM1, &currentM2);
     roboclaw2.ReadCurrents(address, &currentM3, &currentM4);
     roboclaw3.ReadCurrents(address, &currentM5, &currentM6);
      
        if(currentM1 > M1_thresh){
          dangerM1 = true;
        }

        else if(currentM2 > M2_thresh){
          dangerM2 = true;
        }

        else if(currentM3 > M3_thresh){
          dangerM3 = true;
        }

        else if(currentM4 > M4_thresh){
          dangerM4 = true;
        }

        else if(currentM5 > M5_thresh){
          dangerM5 = true;
        }

        else if(currentM6 > M6_thresh){
          dangerM6 = true;
        }
    }
 
    counter++;        
        
      
    }
  }
}
