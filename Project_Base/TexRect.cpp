#include "TexRect.h"


TexRect::TexRect (const char* filename1, const char* filename2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    RgbImage theTexMap1( filename1 );

    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap1.GetNumCols(), theTexMap1.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap1.ImageData() );
    this->texture_id = texture_id;

    // MP4;

    RgbImage theTexMap2( filename2 );

    glGenTextures( 1, &texture_ie );
    glBindTexture( GL_TEXTURE_2D, texture_ie );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap2.GetNumCols(), theTexMap2.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData() );
    this->texture_id = texture_id;
    this->texture_ie = texture_ie;

    this->rows = rows;
    this->cols = cols;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    curr_row = 1;
    curr_col = 1;

    complete = false;
    fire = false;
}


TexRect::TexRect (const char* filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage theTexMap3( filename );
    
    glGenTextures( 1, &texture_if );
    glBindTexture( GL_TEXTURE_2D, texture_if );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap3.GetNumCols(), theTexMap3.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap3.ImageData() );
    
    this->texture_if = texture_if;

    this->rows = rows;
    this->cols = cols;
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1;
    curr_col = 1;
    
    complete = false;

    // Final Project;
    left = right = up = down = false;
    
    
}

// Final Project;
void TexRect::moveUp(float rate){
    y += rate;
}
void TexRect::moveDown(float rate){
    y -= rate;
}
void TexRect::moveLeft(float rate){
    x -= rate;
}
void TexRect::moveRight(float rate){
    x += rate;
}

bool TexRect::done() {
    return complete;
}


void TexRect::draw() {
    
    float xinc = 1.0/cols;
    float yinc = 1.0/rows;
    
    float top = 1 - yinc * (curr_row - 1);
    float bottom = 1 - yinc * curr_row;
    
    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;
    
    if (fire) {
        
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glBegin(GL_QUADS);
        
        glTexCoord2f(left, bottom);
        glVertex2f(x, y - h);
        
        glTexCoord2f(left, top);
        glVertex2f(x, y);
        
        glTexCoord2f(right, top);
        glVertex2f(x+w, y);
        
        glTexCoord2f(right, bottom);
        glVertex2f(x+w, y - h);
        
        glEnd();
        
    }
    
    if (!fire) {
        glBindTexture( GL_TEXTURE_2D, texture_ie );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(0, 0);
        glVertex2f(x, y - h);
        
        glTexCoord2f(0, 1);
        glVertex2f(x, y);
        
        glTexCoord2f(1, 1);
        glVertex2f(x+w, y);
        
        glTexCoord2f(1, 0);
        glVertex2f(x+w, y - h);
        
        glEnd();
        
    }
    glDisable(GL_TEXTURE_2D);

    
}

void TexRect::drawReimu() {
    
    glBindTexture( GL_TEXTURE_2D, texture_if );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    
    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);
    
    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
    
}

void TexRect::incY(){
    y+=0.01;
}

void TexRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}

void TexRect::reset(){
    complete = false;
}

bool TexRect::contains(float x, float y) {
    if (x >= this->x && x <= (this->x + w)
        && y <= this->y && y >= (this->y - h)) {
        return true;
        
    }
    
    else {
        return false;
        
    }
}

void TexRect::setExplode() {
    fire = true;
}

//enemy
void TexRect::falling(){
    
}

