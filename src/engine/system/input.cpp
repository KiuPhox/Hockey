#include <Engine/Input.h>
#include <iostream>

const Uint8 *Input::keyStates;

void Input::update()
{
    keyStates = SDL_GetKeyboardState(NULL);
};

bool Input::getKey(SDL_Scancode code)
{
    return keyStates[code];
}