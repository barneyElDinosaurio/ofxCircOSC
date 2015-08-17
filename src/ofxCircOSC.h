//
//  ofxMilib.cpp
//
//
//  Created by marioAlzate on 1/10/14.
//
//

#pragma once
#include "ofMain.h"

class ofxCircOSC{


public:
	int X,Y,R,colorR,colorG,colorB,tamano;
	void draw(int x, int y);
	void draw();
	void setup(int colorSetupR,int colorSetupG,int colorSetupB, int tamanoSetup);
	void setup(int tamanoSetup);
	void move2MouseCute(int xMouse, int yMouse);
	void mouseCool(int xMouse, int yMouse);


};