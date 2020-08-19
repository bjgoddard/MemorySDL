#pragma once
#include "Dot.h"
#include "Game.h"
#include "TextureManager.h"
#include "Collision.h"

//SDL_Rect& wall;

Dot::Dot()
{
    dotTexture = TextureManager::LoadTexture("assets/dot.bmp");

    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    mCollider.w = DOT_WIDTH;
    mCollider.h = DOT_HEIGHT;


}

void Dot::handleEvent(SDL_Event& e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_w: mVelY -= DOT_VEL; break;
        case SDLK_s: mVelY += DOT_VEL; break;
        case SDLK_a: mVelX -= DOT_VEL; break;
        case SDLK_d: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_w: mVelY += DOT_VEL; break;
        case SDLK_s: mVelY -= DOT_VEL; break;
        case SDLK_a: mVelX += DOT_VEL; break;
        case SDLK_d: mVelX -= DOT_VEL; break;
        }
    }
}



void Dot::move(SDL_Rect& wall)
{
    //Move the dot left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    //If the dot went too far to the left or right
    if ((mPosX < 0) || (mPosX + DOT_WIDTH > Game::SCREEN_WIDTH) || Collision::checkCollision(mCollider, wall))
    {
        //Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
    }

    //Move the dot up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    //If the dot went too far up or down
    if ((mPosY < 0) || (mPosY + DOT_HEIGHT > Game::SCREEN_HEIGHT || Collision::checkCollision(mCollider, wall)))
    {
        //Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}

void Dot::update()
{
    srcRect.h = DOT_HEIGHT;
    srcRect.w = DOT_WIDTH;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = DOT_HEIGHT;
    destRect.w = DOT_WIDTH;
    destRect.x = mPosX;
    destRect.y = mPosY;
}

void Dot::render()
{
    //Show the dot
    /*gDotTexture.render(mPosX, mPosY);*/
    /*dotTexture.render()*/
    SDL_RenderCopy(Game::renderer, dotTexture, &srcRect, &destRect);
}