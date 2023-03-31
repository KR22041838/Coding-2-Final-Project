#include "ofApp.h"

int sendData = 0; // Variable to send data to Arduino
bool hasMouseBeenPressed = false;
int clickCount = 0;


void ofApp::setup() {
    serialMessage = false; //initialise serialMessage

    serial.listDevices(); //list devices
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    int baud = 9600; //connect to serial port
    serial.setup(0, baud); //open the first device
    
    ofSetBackgroundColor(0); //set background colour
    ofSetCircleResolution(100); // set circle size
    ofSetDepthTest(true);
}

void ofApp::update() {
    if (serialMessage) {
        serialMessage = false;  //
        serial.writeByte(sendData); // sending the data to arduino

        serial.readBytes(receivedData, 5); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
    }
}

void ofApp::draw() {

    ofSetColor(225);	// Text color is white
    

    switch (clickCount % 7) { // rotate through 7 mouse clicks cases
    
    case 0: {  // set inital animation on start up 
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {

            ofSetColor (225);
            ofDrawCircle(ofGetWidth() / 2, (i * 0.001) , 200);
           
        }
    }
        break;
    
    
    case 1: {  //set animation responce to 1 mouse click. 
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
           
            ofSetColor(110 + 117 * sin(i * 1.8 + time), 5* sin(i * 1.8 + time),0);
            ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.02 + time), 270 + i, 50 + 100 * sin(i * 0.004 + time));
            ofDrawCircle(ofGetWidth() / 2 + 200 * sin(i * 0.01 + time), 10 + i, 50 + 140 * sin(i * 0.005 + time));
            ofDrawCircle(ofGetWidth() / 2 + 10 * sin(i * 0.03 + time), 10 + i, 50 + 140 * sin(i * 0.006 + time));

        }
        break;
    }
    case 2: {  //set animation responce to 2 mouse click.
        float time = ofGetElapsedTimef();
        for  (int x = 1; x < 20; x++){
            for (int i = 0; i < 900; i += 5) {

                ofSetColor(127 + 127 * sin(i * 0.04 + time), 100 + 127 * sin(i * 0.05 + time), 7 + 17 * sin(i * 0.012 + time));
                ofDrawCircle(100 * x + 100 * sin(i * 0.1 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));
                ofDrawCircle(100 * x + 100 * sin(i * 0.1 + time), 10 + i, 10 + 8 * sin(i * 0.005 + time));

                ofSetColor(127 + 17 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(100 * x + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));
                ofDrawCircle(100 * x + 100 * sin(i * 0.01 + time), 100 + i, 2 + 1 * sin(i * 0.005 + time));
                ofDrawCircle(100 * x + 170 * sin(i * 0.01 + time), 100 + i, 2 + 1 * sin(i * 0.005 + time));
                ofDrawCircle(100 * x + 100 * sin(i * 0.015 + time), 100 + i, 2 + 1 * sin(i * 0.006 + time));

            }
            
        }
        break;
    }
    case 3: {  //set animation responce to 3 mouse click.
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {

            ofSetColor(107 + 127 * sin(i * 0.8 + time), 127 + 100 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
            ofDrawCircle(ofGetWidth() / 2 + 200 * cos(i * 0.01 + time), 100 + i, 50 + 40 * cos(i * 0.05 + time));
            ofSetColor(1 + 127 * sin(i * 0.8 + time), 127 + 100 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
            ofDrawCircle(ofGetWidth() / 2 + 400 * cos(i * 0.01 + time), 100 + i, 5 + 40 * cos(i * 0.05 + time));
            ofSetColor(1 + 127 * sin(i * 0.8 + time), 1 + 100 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
            ofDrawCircle(ofGetWidth() / 2 + 500 * cos(i * 0.01 + time), 100 + i, 5 + 1 * cos(i * 0.05 + time));
            
        }
        break;
    }
    case 4: {  //set animation responce to 4 mouse click.
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
            for (int i = 0; i < 900; i += 5) {
                ofSetColor(200 + 127 * sin(i * 0.04 + time), 12 + 127 * sin(i * 0.05 + time), 12 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(ofGetWidth() / 2 + 80 * sin(i * 0.1 + time), 100 + i, 50 + 10 * sin(i * 0.05 + time));

                ofSetColor(200 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(ofGetWidth() / 2 + 1000 * sin(i * 0.1 + time), 50 + i, 10 + 40 * sin(i * 0.5 + time));
                

            }

        }
        break;
    }
    case 5: {  //set animation responce to 5 mouse click.
        float time = ofGetElapsedTimef();
        for (int x = 1; x < 20; x++) {
            for (int i = 0; i < 900; i += 5) {
                ofSetColor(127 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                
                ofDrawCircle(50 * x + 100 * tan(i * 0.01 + time + x), 50 + i, 50 + 30 * tan(i * 0.005 + time));
                ofDrawCircle(ofGetWidth() / 2 + 400 * tan(i * 0.001 + time), 100 + i, 5 + 40 * tan(i * 0.005 + time));

            }

        }
        break;
    }
    case 6: {  //set animation responce to 6 mouse click.
        float time = ofGetElapsedTimef();
        for (int x = 1; x < 20; x++) {
            for (int i = 0; i < 900; i += 5) {
               
                ofSetColor(127 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(50 * x + 100 * tan(i * 0.01 + time + x), 50 + i, 50 + 30 * tan(i * 0.005 + time));  
                ofSetColor(127 + 127 * sin(i * 0.8 + time), 127 + 100 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(ofGetWidth() / 2 + 400 * tan(i * 0.001 + time), 100 + i, 5 + 40 * tan(i * 0.005 + time));
                ofDrawCircle(ofGetWidth() / 2 + 400 * tan(i * 0.001 + time), 100 + i, 5 + 40 * tan(i * 0.05 + time));


                ofSetColor(127 + 127 * sin(i * 0.8 + time), 1 + 100 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                ofDrawCircle(ofGetWidth() / 2 + 500 * tan(i * 0.01 + time), 100 + i, 5 + 1 * tan(i * 0.05 + time));
                ofDrawCircle(ofGetWidth() / 2 + 500 * cos(i * 0.01 + time), 100 + i, 5 + 1 * cos(i * 0.05 + time));

            }

        }
        break;
    }

    }

   
    }




void ofApp::mousePressed(int x, int y, int button) {
   
    serialMessage = true; // Send data to Arduino
    sendData = hasMouseBeenPressed ? 1 : 0; // Set the data to be sent to Arduino
    hasMouseBeenPressed = true;
    if (button == OF_MOUSE_BUTTON_LEFT) {
        clickCount++;
    }
   
}
