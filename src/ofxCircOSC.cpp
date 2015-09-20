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

void ofxCircOSC::draw(ofColor circleColor){//Overload draw(Random positions)
	ofSetColor(circleColor);
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
    if(ofDist(X,Y,xMouse,yMouse)<tamano)isOnn = true;
}

void ofxCircOSC::isOnParty(int xMouse, int yMouse){//verify mousePos and do a party particle color 
   	//This func need be init in update function, 
	//(i.e. obj.isOnPartu(mouseX,mouseY)) calling to mouse positions;
    if(ofDist(X,Y,xMouse,yMouse)<tamano){//BAD PLAY OVERLOAD OPERATION
    	colorR = ofRandom(0,250);
		colorG = ofRandom(0,250);
		colorB = ofRandom(0,250); 
    }
}

void ofxCircOSC::isOnPutBig(int xMouse, int yMouse, int tamanoPutBig){//verify the if the mouse is on a particule 
   	//This func need be init in update function, 
	//(i.e. obj.isOnPutBig(mouseX,mouseY)) calling to mouse positions;
    if(ofDist(X,Y,xMouse,yMouse)<tamano){//BAD PLAY OVERLOAD OPERATION
    	if(tamano<tamanoPutBig)tamano++;
    }else if(tamano>R)tamano--;
	//This is a dirty play, can be optimized.
}

void ofxCircOSC::setInfo(string Nombre){//init in Setup or update id u change the typeFont or name
	nombre=Nombre;
	myfont.loadFont("arial.ttf", 30);//typeFont and size
}

void ofxCircOSC::drawInfo(int x, int y){//init in Draw
	//Draw the info the x y coordinates
	myfont.drawString(nombre, x,y);//typeFont
}

//Overload func isOnDrawInfo
void ofxCircOSC::isOnDrawInfo(int xMouse,int yMouse){//init in Draw with mousePos values
	//This func shows the an info particle if the mouse is on
	if(ofDist(X,Y,xMouse,yMouse)<tamano)myfont.drawString(nombre, X,Y);
}	

void ofxCircOSC::isOnDrawInfo(int xMouse,int yMouse,int x, int y){//init in Draw with mousePos values
	//This func shows the an info particle if the mouse is on
	if(ofDist(X,Y,xMouse,yMouse)<tamano)myfont.drawString(nombre, x,y);
}	

void ofxCircOSC::setupOSC(string ip,int port){//Setup for OSC sender
		sender.setup(ip, port);
}

void ofxCircOSC::setupResolume(string ipRes,int portRes){//Setup for OSC Resolume sender
		resSender.setup(ipRes, portRes);
}

//OVERLOADS FUNKS sendOSC
void ofxCircOSC::sendOSC(string rutaOSC,int datoOSC){//send data int via OSC
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addIntArg(datoOSC);//data
		sender.sendMessage(m);//send
} 

void ofxCircOSC::sendOSC(string rutaOSC,string datoOSC){//send data string via OSC
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addStringArg(datoOSC);//data
		sender.sendMessage(m);//send
} 

void ofxCircOSC::sendOSC(string rutaOSC,float datoOSC){//send float data via OSC
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addFloatArg(datoOSC);//data
		sender.sendMessage(m);//send
} 

void ofxCircOSC::isOnSendOSC(string rutaOSC,int datoOSC,int xMouse,int yMouse){//send float data via OSC
	//this funk need be initialized in update function
	if(ofDist(X,Y,xMouse,yMouse)<tamano){	
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addIntArg(datoOSC);//data
		sender.sendMessage(m);//send
	}
} 

void ofxCircOSC::isOnSendOSC(string rutaOSC,string datoOSC,int xMouse,int yMouse){//send float data via OSC
	//this funk need be initialized in update function
	if(ofDist(X,Y,xMouse,yMouse)<tamano){	
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addStringArg(datoOSC);//data
		sender.sendMessage(m);//send
	}
} 

void ofxCircOSC::isOnSendOSC(string rutaOSC,float datoOSC,int xMouse,int yMouse){//send float data via OSC
	//this funk need be initialized in update function
	if(ofDist(X,Y,xMouse,yMouse)<tamano){	
		ofxOscMessage m;//create object
		m.setAddress(rutaOSC);//rute
		m.addFloatArg(datoOSC);//data
		sender.sendMessage(m);//send
	}
} 


void ofxCircOSC::rotateVideo(float rotateX,float rotateY,string layer, string clip){
	//Rotate a video clip selected from Resolume in X Y 
		rotateX = ofMap(rotateX,0.0,3.0,0.0,1.0);//Remap values for RESOLUME
		ofxOscMessage mr;
		mr.setAddress("/layer1/video/rotatex/values");
		mr.addFloatArg(rotateX);
		resSender.sendMessage(mr);

		rotateY = ofMap(rotateY,0.0,3.0,0.0,1.0);//Remap values for RESOLUME
		mr.setAddress("/layer1/video/rotatey/values");
		mr.addFloatArg(rotateY);
		resSender.sendMessage(mr);
}

void ofxCircOSC::show(int layer, int clip){
	//Rotate a video clip selected from Resolume in X Y 
		ofxOscMessage mr;
		mr.setAddress("/layer"+ofToString(layer)+"/clip"+ofToString(clip)+"/connect");
		mr.addIntArg(1);//add the clip to the composition
		resSender.sendMessage(mr);

}

