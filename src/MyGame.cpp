#include "MyGame.h"

void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
        }
    } else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

MyGame::MyGame(TTF_Font* Font, SDL_Surface* BackgroundImage, Mix_Chunk* WallHit, Mix_Chunk* BallHit) {
    this->Font = Font;
    this->BackgroundImage = BackgroundImage;
    this->BallHit = BallHit;
    this->WallHit = WallHit;


}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
    }
    }


void MyGame::update() {
    player1.y = game_data.player1Y;
    player2.y = game_data.player2Y;
    Ball.x = game_data.ballX;
    Ball.y = game_data.ballY;
}

void MyGame::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player1);
}