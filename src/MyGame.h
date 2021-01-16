#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
} game_data;



class MyGame {

    private:
        SDL_Rect player1 = { 0, 0, 20, 60 };
        SDL_Rect player2 = { 300, 0, 20, 60 };

        SDL_Surface* BackgroundImage;
        Mix_Chunk* BallHit;
        Mix_Chunk* WallHit;
        TTF_Font* Font;

        SDL_Rect Ball = { 0, 0, 30, 30 };

    public:
        std::vector<std::string> messages;

        void on_receive(std::string message, std::vector<std::string>& args);
        MyGame(TTF_Font* Font, SDL_Surface* BackgroundImage, Mix_Chunk* WallHit, Mix_Chunk* BallHit);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
};

#endif