#ifndef player_h
#define player_h

#include "raylib.h"
#include "ball.h"
#include "sprite.h"
#include <iostream>
#include <string>

using namespace std;
class Player : public Sprite // Inherit from Sprite class
{

    int controlsKey[4];
    int kickKey;   // key to kick the ball
    int kickPower; // power of kick

public:
    Player(string type)
    {
        this->type = type;
        Image temp;
        if (type == "blue")
        {
            temp = LoadImage("images/playerBlue.png");
            controlsKey[0] = KEY_W; // up
            controlsKey[1] = KEY_S; // down
            controlsKey[2] = KEY_A; // left
            controlsKey[3] = KEY_D; // right
            kickKey = KEY_SPACE;    // kick key
            direction = {1.0, 0.0}; // default direction is right
        }
        else
        {
            temp = LoadImage("images/playerRed.png");
            controlsKey[0] = KEY_UP;    // up
            controlsKey[1] = KEY_DOWN;  // down
            controlsKey[2] = KEY_LEFT;  // left
            controlsKey[3] = KEY_RIGHT; // right
            kickKey = KEY_ENTER;        // kick key
            direction = {-1.0, 0.0};    // default direction is left
        }

        kickPower = 30; // default kick power
        spriteImage = LoadTextureFromImage(temp);
        position = {0.0, 0.0};
        speed = 0;
        UnloadImage(temp); // Unload the image after loading the texture
    }
    void update(int, int);
    ~Player()
    {
        UnloadTexture(spriteImage);
    }
    friend class Ball; // allow Ball class to access private members of Player class
};
#endif