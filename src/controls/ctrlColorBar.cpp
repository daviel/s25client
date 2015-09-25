// $Id: ctrlColorBar.cpp 
//
// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

///////////////////////////////////////////////////////////////////////////////
// Header
#include "defines.h"
#include "ctrlColorBar.h"

#include "ogl/glArchivItem_Font.h"

///////////////////////////////////////////////////////////////////////////////
// Makros / Defines
#if defined _WIN32 && defined _DEBUG && defined _MSC_VER
#define new new(_NORMAL_BLOCK, THIS_FILE, __LINE__)
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

ctrlColorBar::ctrlColorBar(Window* parent,
                         unsigned int id,
                         unsigned short x,
                         unsigned short y,
                         unsigned short width,
                         unsigned short height,
                         TextureColor tc,
                         unsigned int text_color,
                         glArchivItem_Font* font,
                         unsigned int bar_color,
                         const unsigned value, 
                         const unsigned max_value)
    : Window(x, y, id, parent, width, height),
    tc(tc), text_color(text_color), font(font), _value(value), _max_value(max_value), _bar_color(bar_color)
{
}


bool ctrlColorBar::Draw_(void)
{
    unsigned percentage = 0;
    if (_max_value > 0)
        percentage = (100*_value) / _max_value;

    if (percentage > 100)
        percentage = 100;

    // Box zeichnen
    Draw3D(GetX(), GetY(), width_, height_, tc, 2);

    // Fortschritt zeichnen
    DrawRectangle(GetX() + 4, GetY() + 4, (width_ - 8)*percentage / 100, height_ - 8, _bar_color);

    // Text zeichnen
    char caption[256];
    sprintf(caption, "%u", _value);
    font->Draw(GetX() + width_ / 2, GetY() + height_ / 2, caption, glArchivItem_Font::DF_CENTER | glArchivItem_Font::DF_VCENTER, text_color);

    return true;
}