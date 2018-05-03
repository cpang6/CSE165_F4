#include "App.h"

static App* singleton;

//void explode(int value){
//    if (!singleton->painting->done()){
//        singleton->painting->advance();
//        singleton->redraw();
//        glutTimerFunc(32, explode, value);
//    }
//}


void move(int value){
    //enemy - self dropping? 
    if (singleton->gamestart){
        //singleton->enemy->jump();
        float bx = singleton->enemy->x + singleton->enemy->w/2;
        float by = singleton->enemy->y - singleton->enemy->h + 0.1;
        
    }
    //
    
    if (singleton->up){
        singleton->painting->moveUp(0.05);
    }
    if (singleton->down){
        singleton->painting->moveDown(0.05);
    }
    if (singleton->left){
        singleton->painting->moveLeft(0.05);
    }
    if (singleton->right){
        singleton->painting->moveRight(0.05);
    }
    if (singleton->up || singleton->down || singleton->left || singleton->right){
        singleton->redraw();
        glutTimerFunc(32, move, value);
    }
}

void App::specialKeyPress(int key){
    if (key == 100){
        left = true;
    }
    if (key == 101){
        up = true;
    }
    if (key == 102){
        right = true;
    }
    if (key == 103){
        down = true;
    }
    move(1);
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
    }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
//    char* wall_file, painting_file;
    
    
    //painting = new TexRect("fireball.bmp", "mushroom.bmp", 6, 6, 0, 0.67, 0.5, 0.5);
    //painting = new TexRect("fireball.bmp", "angelo1.bmp", 6, 6, 0, 0.67, 0.5, 0.5);
    painting = new TexRect("r1.bmp", 1, 1, 0, -0.8, 0.1, 0.15);
    
    enemy = new TexRect("r1.bmp", 1, 1, 0, 0.8, -0.1, 0.15);
    
    up = down = left = right = false;
    moving = false;
    
    gamestart = true;
    move(1);

}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    enemy -> drawReimu();
    
    painting->drawReimu();
    
    
    glDisable(GL_TEXTURE_2D);
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
//    if (painting->contains(x, y)) {
//        painting->setExplode();
//        explode(0);
//        redraw();
//    }
    
    // Redraw the scene
    // redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::idle(){
//    painting->advance();
    redraw();
}

void App::keyUp(unsigned char key) {

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        //delete background;
        delete painting;
        // delete mushroom;
        
        exit(0);
    }
//    else if (key == ' '){
//        painting->reset();
//        explode(0);
//    }
    
    
}
