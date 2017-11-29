//
//  Particle.cpp
//  myFlockingSim
//
//  Created by Danielle Beecham on 11/15/17.
//

#include "Particle.hpp"

void Particle::reset() {
    //Initializing position, velocity, and drag and reseting the force to zero
    
    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    
    velocity.x = ofRandom(-3.9, 3.9);
    velocity.y = ofRandom(-3.9, 3.9);
    
    drag = ofRandom (0.95, 0.998);
    
    //force comes from moving the mouse which is why we need to reset it to zero each time
    force = ofPoint(0,0);
}

void Particle::update(){
    if (isAttracting) {ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());
    
    force = attractPoint - position;
    force.normalize();
    
    velocity *= drag;
    velocity += force *.6;
    
    position += velocity;
    
    }else {
        ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());
        force = attractPoint - position;
        float distance = force.length();
        force.normalize();
        
        if (distance < 150) {
            velocity -= force * 0.6;
        }
        position += velocity;
    }
}


void Particle::draw() {
    if (isAttracting){
    ofSetColor(244, 209, 66);
    ofDrawCircle(position.x, position.y, 2.0);
    } else {
        ofSetColor(2226, 15, 40);
    }
    ofDrawCircle(position.x, position.y, 2.0);
}


void Particle::toggleMode() {
    isAttracting = !isAttracting;
    reset();
}
