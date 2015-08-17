#include "ofxCircOSC.h"

void ofxCircOSC::setup(int colorSetupR,int colorSetupG,int colorSetupB, int tamanoSetup){////Overload Setup(Color,Rad)
	colorR = colorSetupR;
	colorG = colorSetupG;
	colorB = colorSetupB;
	tamano = tamanoSetup;
}

void ofxCircOSC::setup(int tamanoSetup){//Overload Setup(Rad)
	colorR = ofRandom(0,250) ;
	colorG = ofRandom(0,250) ;
	colorB = ofRandom(0,250) ;
	tamano = tamanoSetup;
	//Just one time per particle
	X = ofRandom(0,ofGetWidth());
	Y = ofRandom(0,ofGetHeight());
}


void ofxCircOSC::draw(int x, int y){//Overload draw(x,y positions)
	X = x;
	Y = y;
	ofSetColor(colorR,colorG,colorB);
	ofFill();
	ofCircle(X,Y,tamano);
}

void ofxCircOSC::draw(){//Overload draw(Random positions)
	ofSetColor(colorR,colorG,colorB);
	ofFill();
	ofCircle(X,Y,tamano);
}

void ofxCircOSC::mouseCool(int xMouse, int yMouse){//movement cool with mousePositions
    X += ( xMouse - X )*0.1;
    Y += ( yMouse - Y )*0.1;
}