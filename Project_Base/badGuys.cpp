
#include "badGuys.h"

badGuys::badGuys(){
    speed = 0.01;
    timeinbetween = 20;
    starttime = 0;
    randomT = 20;
    addArman(x);
    x = 0;
}

void badGuys::falling(){
    starttime +=1;
    randomT = (rand()%30)+1;
    //x = float((rand())/float(RAND_MAX) * (1.98)) - 0.99;
    //cout << x<< endl;
    if (starttime > (randomT + 40)){
    
    if (starttime % 2 == 0){
        addArman(x);
    }
    if (starttime % 9 == 0){
        addAngelo(x);
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

void badGuys::addAngelo(float x){
    //cout << x<< endl;
    this ->x = x;
    x = float((rand())/float(RAND_MAX) * (1.8)) - 0.9;
    cout << x<< endl;
    bad.push_back(new Emeny("images/boss.png", x, 0.99, 0.2, 0.22,speed));
    //playerBullets.push_back(new bullet("images/compass.png", xx+0.2/8, 0.9, 0.10, 0.10));
//    for (int i = 0; i < bad.size();i++){
//        bad[i]->shoot();
//    }
}

void badGuys::addArman(float x){
    //cout << x<< endl;
    this ->x = x;
    x = float((rand())/float(RAND_MAX) * (1.8)) - 0.9;
    cout << x<< endl;
    bad.push_back(new Emeny("images/arman.png", x, 0.99, 0.2, 0.22,speed));
    
    //playerBullets.push_back(new bullet("images/compass.png", xx+0.2/8, 0.9, 0.10, 0.10));
}

void badGuys::draw(){
    int count = 0;
    for (int i = 0; i < bad.size();i++){
        bad[i]->draw();
        count++;
        
    }
    cout << "drawtimes count "<<count<<endl;
}

void badGuys::redraw(){
    speed = 0.05;
    timeinbetween = 20;
    starttime = 0;
    randomT = 20;
    x = 0;
}

bool badGuys::contain(float x,float y){
    for (int i = 0; i < bad.size();i++){
        if(bad[i]->contains(x,y))
            return true;
       
    }
    return false;
}



//bullet
void badGuys::bulletdrop(){
    for (int i = 0; i < bad.size();i++){
        bad[i]->drop();
        cout << "drop?"<<endl;
    }
}

void badGuys::bulletshoot(){
    int count = 0;
    for (int i = 0; i < bad.size();i++){
        bad[i]->shoot();
        count ++;
        
    }
    cout << "bullettimes count "<<count<<endl;
    
}

void badGuys::drawbullet(){
    int count = 0;
    for (int i = 0; i < bad.size();i++){
        bad[i]->bulletdraw();
        count++;
    }
    cout << "drawbullettimes count "<<count<<endl;
}

badGuys::~badGuys(){
    bad.clear();
}
