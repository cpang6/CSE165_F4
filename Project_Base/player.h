#ifndef player_h
#define player_h

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

class player {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    bool animating;
    
public:
    player (const char*, float, float, float, float);
    player (const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();
    
    void animate();
    
    void stop();
        
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    
    bool rising;
    bool movingLeft;
    
    float xinc;
    float yinc;
};

#endif
