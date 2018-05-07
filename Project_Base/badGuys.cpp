
#include "badGuys.h"

badGuys::badGuys(){
    speed = 0.01;
    timeinbetween = 20;
    starttime = 0;
    randomT = 20;
    addArman();
    x = 0;
}

void badGuys::falling(){
    starttime +=1;
    randomT = (rand()%30)+1;
    x = float((rand())/float(RAND_MAX) * (2)) - 1;
    cout << x<< endl;
    if (starttime > (randomT + 40)){
    
    if (starttime % 2 == 0){
        addArman();
    }
    if (starttime % 10 == 0){
        addAngelo();
    }
    starttime = 0;
    }
    
    for (int i = 0; i < bad.size();i++){
                if(bad[i]->y<-2){
                    bad.erase(bad.begin()+i-1);
                }
        bad[i]->jump();
    }
    
}

void badGuys::addAngelo(){
    //cout << x<< endl;
    bad.push_back(new Emeny("images/boss.png", (float((rand())/float(RAND_MAX) * (2)) - 1), 0.99, 0.2, 0.22,speed));
    
}

void badGuys::addArman(){
    //cout << x<< endl;
    bad.push_back(new Emeny("images/arman.png", (float((rand())/float(RAND_MAX) * (2)) - 1), 0.99, 0.2, 0.22,speed));
}

void badGuys::draw(){
    for (int i = 0; i < bad.size();i++){
        bad[i]->draw();
    }
}

void badGuys::redraw(){
    speed = 0.05;
    timeinbetween = 20;
    starttime = 0;
    randomT = 20;
    x = 0;
}

badGuys::~badGuys(){
    bad.clear();
}
