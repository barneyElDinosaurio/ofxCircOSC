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
	R = tamanoSetup;

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
   	//This func need be init in update function, 
	//(i.e. obj.mouseCool(mouseX,mouseY)) calling to mouse positions;
    X += ( xMouse - X )*0.1;
    Y += ( yMouse - Y )*0.1;
}

bool ofxCircOSC::isOn(int xMouse, int yMouse){//verify the if the mouse is on a particule 
   	//This func need be init in update function, 
	//(i.e. obj.isOn(mouseX,mouseY)) calling to mouse positions;
    if(ofDist(X,Y,xMouse,yMouse)<tamano){
    	isOnn = true;
    }

}

void ofxCircOSC::isOnParty(int xMouse, int yMouse){//verify mousePos and do a party particle color 
   	//This func need be init in update function, 
	//(i.e. obj.isOnPartu(mouseX,mouseY)) calling to mouse positions;
    if(ofDist(X,Y,xMouse,yMouse)<tamano){
    	colorR = ofRandom(0,250);
		colorG = ofRandom(0,250);
		colorB = ofRandom(0,250); 
    }

}

void ofxCircOSC::isOnPutBig(int xMouse, int yMouse, int tamanoPutBig){//verify the if the mouse is on a particule 
   	//This func need be init in update function, 
	//(i.e. obj.isOnPutBig(mouseX,mouseY)) calling to mouse positions;
    if(ofDist(X,Y,xMouse,yMouse)<tamano){
    	if(tamano<tamanoPutBig)tamano++;
    }else if(tamano>R)tamano--;
//This is a dirty play, can be optimized.
}