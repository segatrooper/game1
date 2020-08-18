
#include "Character.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Character::Character(SDL_Texture* p_text) {
    this->text = p_text;
    // std::cout << this->text << p_text << std::endl;
    // this->*position;
    this->goN = false;
    this->goS = false;
    this->goW = false;
    this->goE = false;
}

void Character::rcopy(SDL_Renderer* rend) {
    SDL_Rect src;
    switch(facing) {
        case 0:
            //North
            src.y = 3;
            break;
        case 1:
            //South
            src.y = 0;
            break;
        case 2:
            //East
            src.y = 2;
            break;
        case 3:
            //West
            src.y = 1;
            break;
    }
    
        if (animation) {
            this->frame = (int)(SDL_GetTicks() * this->vel/ (300)) % 4;
            if (this->frame == 3) {
                this->frame = 1;
            }
        } else {
            this->frame = 1;
        }
        src.x = this->frame;
        src.w = 32;
        src.h = 64;
        src.x = src.x * 32;
        src.y = src.y * 64;
        SDL_Rect dst;
        dst.x = (int)this->x;
        dst.y = (int)this->y;
        dst.w = 32;
        dst.h = 64;
        // std::cout << this->position << std::endl;
        SDL_RenderCopy(rend, this->text, &src, &dst);
        //debug
        // std::cout << this->position->x << " " << this->position->y << std::endl;
        std::cout << this->x << std::endl;
        std::cout << this->y << std::endl;
        // std::cout << goE << std::endl;
        // std::cout << goW << std::endl;

}
void Character::setFacing(int i) {
    if (!(goN || goS || goW || goE)){
        this->animation = false;
        // std::cout << "animation set to false" << std::endl;
    }
}


void Character::moving() {
    if (this->goN == true) {
        std::cout << "Going North\n";
        this->y -= this->vel;
    }
    if (this->goS == true) {
        std::cout << "Going South\n";
        this->y += this->vel;
    }
    if (this->goE == true) {
        std::cout << "Going East\n";
        this->x += this->vel;
    }
    if (this->goW == true) {
        std::cout << "Going West\n";
        this->x -= this->vel;
    }
}

void Character::going(int i ) {
    switch(i) {
        case 0:
            this->goN = true;
            this->facing = 0;
            break;
        case 1:
            this->goS = true;
            this->facing = 1;
            break;
        case 2:
            this->goE = true;
            this->facing = 2;
            break;
        case 3:
            this->goW = true;
            this->facing = 3;
            break;
    }
    this->animation = true;
}


void Character::notgoing(int i ) {
    switch(i) {
        case 0:
            this->goN = false;
            break;
        case 1:
            this->goS = false;
            break;
        case 2:
            this->goE = false;
            break;
        case 3:
            this->goW = false;
            break;
}
}
