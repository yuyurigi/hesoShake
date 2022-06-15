#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);

    _ShakeCanvas.setup();
    _ShakeCanvas.startShake();
    
    svg.load("usagi.svg");
    for (ofPath p: svg.getPaths()){
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        const vector<ofPolyline>& lines = p.getOutline();
        vector<ofPolyline> outlines;
        for(const ofPolyline & line: lines){
            outlines.push_back(line.getResampledBySpacing(1));
        }
        for (int j = 0; j < outlines.size(); j++) {
            ofPolyline & line = outlines[j];
            for (int k = 0; k < line.size(); k++) {
                if (j==0 && k==0){
                    path.lineTo(line[k]);
                } else if(j>0 && k==0){
                    path.moveTo(line[k]);
                }else if (k > 0) {
                    path.lineTo(line[k]);
                }
            }
            path.close();
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    if( ofGetFrameNum() % 5 == 0)
    {
        _ShakeCanvas.update();
    }

    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(190, 220, 245), ofColor(231, 112, 144), OF_GRADIENT_LINEAR);
    //draw on shake canvae
    ofPushStyle();
    _ShakeCanvas.begin();
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofScale(1/svg.getWidth()*500, 1/svg.getHeight()*500);
        ofTranslate(-svg.getWidth()/2, -svg.getHeight()/2);
        path.setColor(ofColor(255));
        path.setPolyWindingMode(OF_POLY_WINDING_ODD);
        path.draw();
        ofPopMatrix();
    }
    _ShakeCanvas.end();
    ofPopStyle();

    //draw shake canvae
    _ShakeCanvas.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'S' || key == 's') {
            ofImage myImage;
            myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
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
