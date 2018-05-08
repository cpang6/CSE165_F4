
#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif
#include <stdio.h>
#include <vector>
#include<iostream>
#include "Emeny.h"
#include "bullet.h"
using namespace std;
class badGuys{
public:
    float speed;
    float timeinbetween;
    int starttime;
    int randomT;
    int x,r;
    int count;
    void redraw();
    
    
    badGuys();
    
    void falling();
    //void interval();
    
    void addAngelo(float x);
    void addArman(float x);
    void allEnemies();
    void draw();
    bool contain(float,float);
    int whatContain(float x,float y);
    void deleteBad(int i);


    
    std::vector <Emeny*> bad;
    std::vector<bullet*> playerBullets;
    
    ~badGuys();
    
    void bulletdrop();
    void bulletshoot();
    void drawbullet();
    bool ishit;
    bool bulletcotaincheck(float, float);
    
    
    
};
