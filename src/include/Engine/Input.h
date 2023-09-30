#pragma once
#include <SDL2/SDL.h>

class Input
{
public:
    static void update();
    static bool getKey(SDL_Scancode code);
    static bool getKeyDown(SDL_Scancode code);

private:
    static const Uint8 *keyStates;
    static bool prevKeyStates[SDL_NUM_SCANCODES];
    static bool keyPressedThisFrame[SDL_NUM_SCANCODES];
};