//
//  badGuys.cpp
//  glutapp
//
//  Created by Test on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "badGuys.h"

badGuys::badGuys(){
    speed = 0.05;
    timeinbetween = 20;
    starttime = 0;
    randomT = 20;
    x = 0;
}

void badGuys::falling(){
    starttime +=1;
    randomT = (rand()%20)+1;
    x = float((rand())/float(RAND_MAX) * (2)) - 1;
    //if (starttime > (randomT + 10)){
    
    //if (starttime % 2 == 0){
    addArman();
    //}
    if (starttime % 5 == 0){
        addAngelo();
    }
    starttime = 0;
    // }
    
    for (int i = 0; i < bad.size();i++){
        //        if(bad[i]->y<-2){
        //            bad.erase(bad.begin()+i-1);
        //        }
        bad[i]->jump();
    }
    
}

void badGuys::addAngelo(){
    bad.push_back(new Emeny("images/boss.png", 0, 0.99, 0.2, 0.22,speed));
    
}

void badGuys::addArman(){
    bad.push_back(new Emeny("images/mushroom.png", 0, 0.99, 0.2, 0.22,speed));
}

void badGuys::draw(){
    for (int i = 0; i < bad.size();i++){
        bad[i]->draw();
    }
}

badGuys::~badGuys(){
    bad.clear();
}
