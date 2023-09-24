#include "Engine/Text.h"

Text::Text(GameObject *obj, std::string text, TTF_Font *font, SDL_Color color, Align align) : Component(obj)
{
    this->text = text;
    this->color = color;
    this->font = font;
    this->align = align;
}