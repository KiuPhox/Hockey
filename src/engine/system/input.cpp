#include "Engine/Input.h"

#include <iostream>

const Uint8 *Input::keyStates;
bool Input::prevKeyStates[SDL_NUM_SCANCODES] = {false};
bool Input::keyPressedThisFrame[SDL_NUM_SCANCODES] = {false};

void Input::update()
{
    keyStates = SDL_GetKeyboardState(NULL);

    for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
    {
        bool isPressed = keyStates[i];
        keyPressedThisFrame[i] = isPressed && !prevKeyStates[i];
        prevKeyStates[i] = isPressed;
    }
};

bool Input::getKey(SDL_Scancode code)
{
    return keyStates[code];
}

bool Input::getKeyDown(SDL_Scancode code)
{
    return keyPressedThisFrame[code];
}
