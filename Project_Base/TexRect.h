#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
//    float x;
//    float y;
//    float w;
//    float h;
    GLuint texture_id;
    GLuint texture_ie;
    GLuint texture_if;
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    
    // MP4;
    bool fire;
    
    // Final Project;
    bool left, right, up, down;
    
public:
    float x;
    float y;
    float w;
    float h;
    TexRect (const char*, const char*, int, int, float, float, float, float);
    TexRect (const char*, int, int, float, float, float, float);

    
    bool done();
    
    void draw();
    
    // MP4;
    bool contains(float, float);
    void setExplode();
    
    // Final Project;
    void drawReimu();
    
    void moveUp(float rate = 0.01);
    void moveDown(float rate = 0.01);
    void moveLeft(float rate = 0.01);
    void moveRight(float rate = 0.01);
    
    void advance();
    
    void incY();
    
    void reset();
    
    //enemy
    void falling();
};

#endif
