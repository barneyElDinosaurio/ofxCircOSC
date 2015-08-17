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
}


void ofxCircOSC::draw(int x, int y){
	ofSetColor(colorR,colorG,colorB);
	ofFill();
	ofCircle(x,y,tamano);
}

