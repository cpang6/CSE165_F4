
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
#include "Emeny.h"
class badGuys{
public:
    float speed;
    float timeinbetween;
    int starttime;
    int randomT;
    int x;
    void redraw();
    
    badGuys();
    
    void falling();
    //void interval();
    
    void addAngelo();
    void addArman();
    void allEnemies();
    void draw();
    
    std::vector <Emeny*> bad;
    
    ~badGuys();
    
    
    
};
