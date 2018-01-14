#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(20); // brigthness of background
    ofSetVerticalSync(true);
    
    bFill       = false;
    bWireframe  = false;
    
    cam.setDistance(1000);
    
    gui.setup(); //panel
    gui.add(width.setup("width",ofGetWidth()*0.5,0,600));
    gui.add(height.setup("heigth",ofGetHeight()*0.5,0,600));
    gui.add(depth.setup("depth",ofGetHeight()*0.5,0,600));

    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    ofSetSphereResolution(24);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);
    
    pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
                            );
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    
    // draw the outer sphere
    material.begin();
    ofNoFill();
    ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth());
    material.end();
    gui.draw();
    if(!bFill && bWireframe){
        // if we are only drawing the wireframe, use
        // the material to draw it, otherwise the material
        // will be bound and unbound for every geometry
        // and the wireframe will be drawn in black
        material.begin();
    }

    
    //box.setPosition(ofGetWidth()*0.5,ofGetHeight()*0.5, 0);
    box.setWidth(width);
    box.setHeight(height);
    box.setDepth(depth);
    cam.begin();
    //box.rotate(rotY, 0, 1.0, 0.0);
    box.draw();
    ofFill();
    cam.end();
    if(bFill) {
        material.begin();
        ofFill();
        box.draw();
        material.end();
    }
    
    if(bWireframe) {
        ofNoFill();
        ofSetColor(0, 0, 0);
        box.setScale(1.01f);
        box.drawWireframe();
        box.setScale(1.f);
    }

  

    //ofSetColor(red, green, blue);
    if(!bFill && bWireframe){
        material.end();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            bFill = !bFill;
            break;
        case 'w':
            bWireframe = !bWireframe;
            break;
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
