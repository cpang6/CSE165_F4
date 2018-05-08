#include "App.h"
#include <iostream>   // std::cout
#include <string>    


static App* singleton;
static badGuys* pt;
int endScore = 0;

void app_timer(int value){
    if (singleton->game_over){
        singleton->gameOver->advance();
    }
    
    if (singleton->moving){
        singleton->mc->advance();
        pt ->falling();
        pt ->bulletshoot();
        
//        if (pt->contain(singleton->mc->x, singleton->mc->y)||pt->bulletcotaincheck(singleton->mc->x, singleton->mc->y)){
//            singleton->moving = false;
//            singleton->game_over = true;
//            singleton->gameOver->animate();
//        }
        if (pt->contain(singleton->mc->x, singleton->mc->getbullety())){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->mc->shooting = false;
            singleton->gameOver->animate();
        }
    }
    
    if (singleton->up) {
        singleton->mc->moveUp(0.02);
    }
<<<<<<< HEAD
//    singleton->myBullet->advance();
    //singleton->mc->advance();

//    pt->bulletdrop();
//    pt ->bulletshoot();

    //pt ->falling();
    singleton->mc->advance();
    pt ->falling();
    pt ->bulletshoot();
    if (singleton->moving){
//        singleton->mc->advance();
//        pt ->falling();
//        pt ->bulletshoot();
        if (pt->contain(singleton->mc->x, singleton->mc->y)||pt->bulletcotaincheck(singleton->mc->x, singleton->mc->y)){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
        }


        //        // singleton->ball->jump();
        //        float bx = singleton->ball->x + singleton->ball->w/2;
        //        float by = singleton->ball->y - singleton->ball->h + 0.1;
        //        if (singleton->platform->contains(bx, by)){
        //            singleton->ball->rising = true;
        //            singleton->ball->yinc +=0.005;
        //            singleton->ball->xinc = singleton->ball->yinc;
        //            if (singleton->ball->yinc > 0.15){
        //                singleton->ball->yinc = 0.15;
        //            }
        //        }
        //
        //        if (singleton->ball->y - singleton->ball->h < -0.99){
        //            singleton->moving = false;
        //            singleton->game_over = true;
        //            singleton->gameOver->animate();
        //
        //        }
        //    }
        if (singleton->up) {
            singleton->mc->moveUp(0.02);
        }
        if (singleton->down) {
            singleton->mc->moveDown(0.04);
        }
        if (singleton->left) {
            singleton->mc->moveLeft(0.04);
        }
        if (singleton->right) {
            singleton->mc->moveRight(0.04);
        }

        if (singleton->game_over){
=======
    if (singleton->down) {
        singleton->mc->moveDown(0.04);
    }
    if (singleton->left) {
        singleton->mc->moveLeft(0.04);
    }
    if (singleton->right) {
        singleton->mc->moveRight(0.04);
    }
    
    if (singleton->game_over){
        singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    }
    else {
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
            singleton->redraw();
            glutTimerFunc(16, app_timer, value);
        }
    }
}

<<<<<<< HEAD
//void move(int value){
//    singleton->myBullet->advance();
//    if (singleton->up){
//        singleton->mc->moveUp(0.02);
//    }
//    if (singleton->down){
//        singleton->mc->moveDown(0.04);
//    }
//    if (singleton->left){
//        singleton->mc->moveLeft(0.04);
//    }
//    if (singleton->right){
//        singleton->mc->moveRight(0.04);
//    }
//    if (singleton->up || singleton->down || singleton->left || singleton->right){
//        singleton->redraw();
//        glutTimerFunc(32, move, value);
//    }
//}

void App::PrintText(int x, int y, std::string String){
    //(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


=======
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    pt = new badGuys();
    singleton = this;
    mx = 0.0;
    my = 0.0;
<<<<<<< HEAD
    hiScore = new highScore(endScore);


    //    background = new TexRect("images/sky.png", -1, 1, 2, 2);
    // ball = new TexRect("images/mushroom.png", 0, 0.67, 0.2, 0.2);
    // platform = new TexRect("images/board.png", 0, -0.7, 0.6, 0.2);
=======
    
    int score = 0;
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
    
    background = new TexRect("images/background.png", -1, 1, 2, 2);
    mc = new Reimu("images/reimu.png", -0.1, -0.6, 0.15, 0.22);
<<<<<<< HEAD
//    myBullet = new bullet("images/bullet.png", -0.1, -0.55, 0.10, 0.10);
    gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);

=======
    gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
    
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
    up = down = left = right = false;
    
    moving = true;
    game_over = false;
    
    app_timer(1);
    
}

void App::specialKeyPress(int key){
    if (!game_over){
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
        //        if (key == ' '){
        //            singleton->mc->shoot();
        //        }
        //        if (key == ' '){
        ////            myBullet->setFire();
        ////            redraw();
        //    }
        //    move(1);
    }
    
}

void App::specialKeyUp(int key) {
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
    
    //    if (key == ' ') {
    //        myBullet->stopFire();
    //        redraw();
    //    }
    //
}

void App::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    background->draw();

    if (moving){
            endScore = gameTick/8;
            PrintText(560, 580, std::to_string(endScore));
            PrintText(410, 580,hiScore->getScore());
          }
    // platform->draw();
    // ball->draw();
<<<<<<< HEAD

//    myBullet->draw();

//    for (int ii = 0; ii < singleton->mc->playerBullets.size(); ii++) {
//      for (int jj = 0; jj < pt.size(); jj++) {
//        //test
//        if () { //colision detection function
//          //delete enemy[jj]
//          //delete playerBullet[ii]
//          score += 100;
//        }
//
//      }
//    }
    singleton -> mc->bulletdraw();

    pt -> drawbullet();
    pt ->draw();
    mc->draw();
    
    gameOver->draw();
    hiScore->checkScore(endScore);




=======
    
    //    myBullet->draw();
    
    //    for (int ii = 0; ii < singleton->mc->playerBullets.size(); ii++) {
    //      for (int jj = 0; jj < pt.size(); jj++) {
    //        //test
    //        if () { //colision detection function
    //          //delete enemy[jj]
    //          //delete playerBullet[ii]
    //          score += 100;
    //        }
    //
    //      }
    //    }
    
    
    singleton ->mc->bulletdraw();
    
    pt -> drawbullet();
    pt ->draw();
    mc->draw();
    
    gameOver->draw();
    
    
    
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
}

void App::idle(){
    
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        delete singleton;
        delete pt;
        delete gameOver;
        delete background;
        delete mc;
        exit(0);
    }
    
    if (key == ' '){
        singleton->mc->shoot();
<<<<<<< HEAD
    }
    
//    if (key = 'r'){
//        game_over = false;
//        gameOver->stop();
//        moving = true;
//        pt->redraw();
//    }



}

=======
    }
    
//    if (key = 'r'){
//        game_over = false;
//        gameOver->stop();
//        moving = true;
//        mc->draw();
//        pt->draw();
//    }
    
    
}
>>>>>>> b708b75d907185e0692fa9a649c73fa823e0bbe8
