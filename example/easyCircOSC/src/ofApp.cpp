#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(250);//fondo

	miObj.setup(30);//configura el tamaño
	miObj.setInfo("elPrimero");
	miObj.setupOSC("127.0.0.1",1234);
	miObj.setupResolume("127.0.0.1",7777);
}

//--------------------------------------------------------------
void ofApp::update(){
	mx=mouseX;//mouseX
	my=mouseY;//mouseY

	//miObj.mouseCool(mouseX,mouseY);//move particle with the mouse
	miObj.isOnParty(mx,my);
	miObj.isOnPutBig(mx,my,100);
	miObj.isOnSendOSC("/miPrueba",mx*2,mx,my);//Send OSC
}

//--------------------------------------------------------------
void ofApp::draw(){
	miObj.draw();//dibuja mi particula
	miObj.isOnDrawInfo(mx,my);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
