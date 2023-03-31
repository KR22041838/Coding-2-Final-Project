
const int PIN_RED   = 5; //red LED
const int PIN_GREEN = 6; //GREEN LED
const int PIN_BLUE  = 7; //BLUE LED

int state = 0; 

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);  // Declare the first LED pin as output
  pinMode(PIN_GREEN, OUTPUT);  // Declare the second LED pin as output
  pinMode(PIN_BLUE, OUTPUT);  // Declare the second LED pin as output
}

void loop() {

static int charCount = 0; // keep track of the number of times '1' is detected
  if (Serial.available()) { // If there is any data available
    char inByte = Serial.read(); // Store the incoming data
   
    switch (state){
    
    case 0:
      digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
      digitalWrite(PIN_RED, 225); // Change the state of the first LED
      digitalWrite(PIN_BLUE, 0); // Change the state of the first LED
 
        // If data recived = 1 turn green LED on   
      if (inByte == 1) {   // Whether the received data is '1'
        // charCount++; // increment the count of '1' detections
        digitalWrite(PIN_BLUE, 0); // Change the state of the first LED
        digitalWrite(PIN_GREEN, 225); // Change the state of the first LED
        digitalWrite(PIN_RED, 0); // Change the state of the first LED 

        state = 1;
      }
      break;

    case 1: 
      digitalWrite(PIN_RED, 0);
      digitalWrite(PIN_GREEN, 225); // Change the state of the first LED
      digitalWrite(PIN_BLUE, 0); // Change the state of the first LED 

      if (inByte == 1) {
        digitalWrite(PIN_RED, 0);
        digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 255); // Change the state of the first LED 

        state = 2;
      }
      break;

    case 2:
      digitalWrite(PIN_RED, 0);
      digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
      digitalWrite(PIN_BLUE, 225); // Change the state of the first LED 

      if (inByte == 1) {
        digitalWrite(PIN_RED, 204);
        digitalWrite(PIN_GREEN, 204); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 0); // Change the state of the first LED 

        state = 3;
      }

      break;
      
      
      case 3: 
    
      digitalWrite(PIN_RED, 204);
        digitalWrite(PIN_GREEN, 204); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 0); // Change the state of the first LED 

      if (inByte == 1) {
        digitalWrite(PIN_RED, 225);
        digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 200); // Change the state of the first LED 
        state = 4;
      }
      break;

       case 4: 
    
        digitalWrite(PIN_RED, 225);
        digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 200); // Change the state of the first LED 

      if (inByte == 1) {
        digitalWrite(PIN_RED, 0);
        digitalWrite(PIN_GREEN, 10); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 225); // Change the state of the first LED
     
        state = 0;
      }
      break;

      

      
      
 default: {
        digitalWrite(PIN_RED, 0);
        digitalWrite(PIN_GREEN, 0); // Change the state of the first LED
        digitalWrite(PIN_BLUE, 0); // Change the state of the first LED 

        }
        break;
      
    }
  }  }  
