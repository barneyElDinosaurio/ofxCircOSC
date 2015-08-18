//
//  ofxCircOSC.cpp
//
//
//  Created by marioAlzate on 17/ago/15.
//
//

#pragma once
#include "ofMain.h"

class ofxCircOSC{


public:
	bool isOnn = false;
	int X,Y,R,colorR,colorG,colorB,tamano;//Particle variables settings
	string nombre;
	void draw(int x, int y);
	void draw();
	void setup(int colorSetupR,int colorSetupG,int colorSetupB, int tamanoSetup);
	void setup(int tamanoSetup);
	void mouseCool(int xMouse, int yMouse);
	bool isOn(int xMouse, int yMouse);//func for known if the mouse is on the particle
	void isOnPutBig(int xMouse, int yMouse, int tamanoPutBig);//func for put big if the mouse is on the particle
	void isOnParty(int xMouse, int yMouse);//random colors if the mouse is on
	void setInfo(string Nombre);
	void drawInfo();
	void drawInfoIfMoOn(int xMouse,int yMouse);

	ofTrueTypeFont myfont;
};