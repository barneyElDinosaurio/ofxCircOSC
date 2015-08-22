//
//  ofxCircOSC.cpp
//
//	Things.. Pusgmatrix and popmatrix.
//  Created by marioAlzate on 17/ago/15.
//
//

#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

class ofxCircOSC{
	
public:

	bool isOnn;
	int X,Y,R,colorR,colorG,colorB,tamano,resPort;//Particle variables settings
	string nombre,resIp;
	void draw(int x, int y);//Draw particle in xy pos
	void draw();//Draw particle in Rand pos
	void draw(ofColor colorCircle);//Draw particle in Rand pos with ofColor
	void setup(int colorSetupR,int colorSetupG,int colorSetupB, int tamanoSetup);
	void setup(int tamanoSetup);
	void mouseCool(int xMouse, int yMouse);
	bool isOn(int xMouse, int yMouse);//func for known if the mouse is on the particle
	void isOnPutBig(int xMouse, int yMouse, int tamanoPutBig);//func for put big if the mouse is on the particle
	void isOnParty(int xMouse, int yMouse);//random colors if the mouse is on
	void setInfo(string Nombre);
	void drawInfo(int x, int y);
	void isOnDrawInfo(int xMouse,int yMouse);
	void isOnDrawInfo(int xMouse,int yMouse,int x,int y);

	//OSC FUNKS
	void setupOSC(string ip,int port);
	void sendOSC(string rutaOSC,int datoOSC);
	void sendOSC(string rutaOSC,string datoOSC);
	void sendOSC(string rutaOSC,float datoOSC);
	void isOnSendOSC(string rutaOSC,int datoOSC,int xMouse,int yMouse);
	void isOnSendOSC(string rutaOSC,string datoOSC,int xMouse,int yMouse);
	void isOnSendOSC(string rutaOSC,float datoOSC,int xMouse,int yMouse);

	//RESOLUME FUNKS

	void setupResolume(string ip,int port);
	void show(int layer,int clip);//show a video(COMING)
	void videoOff(int layer, int clip);//COMING
	void rotateVideo(float rotateX,float rotateY,string layer, string clip);//rotate videoclips


	ofTrueTypeFont myfont;//Fonts class
	ofxOscSender sender,resSender;//OSC Sender and Resolume OSC sender


};