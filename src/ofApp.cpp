#include "ofApp.h"
////bool isBackgroundGreen = false; // Variable to keep track of the background color
int sendData = 0; // Variable to send data to Arduino
//ofTrueTypeFont font; // Declare a font object
bool hasMouseBeenPressed = false;
int clickCount = 0;


void ofApp::setup() {
    serialMessage = false;

    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    //font.load("Helvetica", 18);


    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    //serial.setup("COM10", baud); // windows example
    //serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
    //serial.setup("/dev/ttyUSB0", baud); //linux example
    
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetDepthTest(true);
}

void ofApp::update() {
    if (serialMessage) {
        serialMessage = false;
        serial.writeByte(sendData); // sending the data to arduino

        serial.readBytes(receivedData, 5); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
    }
}

void ofApp::draw() {

    /* can combine DrawCircle animations by just having stacking them one after the other
    Video used:
    https://www.youtube.com/watch?v=kYejiSrzFzs&list=PLWPxkLdNmFwOVBCvwLh3tiKc4G74iUe03&index=3
    

    */

    ofSetColor(225);	// Text color is white
    

    switch (clickCount % 7) {
    
    case 0: {
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {

            ofSetColor (225);
            ofDrawCircle(ofGetWidth() / 2, (i * 0.001) , 200);
            //ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time), 5 + i, 10 + 4 * sin(i * 0.005 + time));
        }
    }
        break;
    
    
    case 1: {
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
           
            ofSetColor(110 + 117 * sin(i * 1.8 + time), 5* sin(i * 1.8 + time),0);
            ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.02 + time), 270 + i, 50 + 100 * sin(i * 0.004 + time));
            ofDrawCircle(ofGetWidth() / 2 + 200 * sin(i * 0.01 + time), 10 + i, 50 + 140 * sin(i * 0.005 + time));
            ofDrawCircle(ofGetWidth() / 2 + 10 * sin(i * 0.03 + time), 10 + i, 50 + 140 * sin(i * 0.006 + time));

        }
        break;
    }
    case 2: {
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
    case 3: {
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
    case 4: {
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
    case 5: {
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
    case 6: {
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

   // string msg;
   // msg += "Click to change background color\n";
   // msg += receivedData;
   
    
   // ofDrawBitmapString(msg, 200, 300); // Write the data on the output window
   // font.drawString(msg, 400, 600);


void ofApp::mousePressed(int x, int y, int button) {
    //isBackgroundGreen = !isBackgroundGreen; // Toggle the background color
    serialMessage = true; // Send data to Arduino
    //sendData = isBackgroundBlue ? 1 : 0; // Set the data to be sent to Arduino
    sendData = hasMouseBeenPressed ? 1 : 0; // Set the data to be sent to Arduino
    hasMouseBeenPressed = true;
    if (button == OF_MOUSE_BUTTON_LEFT) {
        clickCount++;
    }
   
}
