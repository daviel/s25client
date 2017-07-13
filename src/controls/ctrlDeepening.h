// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
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
#ifndef CTRLDEEPENING_H_INCLUDED
#define CTRLDEEPENING_H_INCLUDED

#pragma once

#include "Window.h"
#include "DrawPoint.h"
#include "controls/ctrlBaseText.h"
#include "controls/ctrlBaseColor.h"

class glArchivItem_Font;

/// Control with a "deepened" look by a 3D border
class ctrlDeepening: public Window
{
public:
    ctrlDeepening(Window* parent, unsigned id, DrawPoint position, unsigned short width, unsigned short height,
        TextureColor tc);

protected:
    void Draw_() override;
    /// Derived classes have to draw the content
    virtual void DrawContent() const = 0;

private:
    TextureColor tc;
};

/// Deepening with text
class ctrlTextDeepening: public ctrlDeepening, public ctrlBaseText
{
public:
    ctrlTextDeepening(Window* parent, unsigned id, DrawPoint position, unsigned short width, unsigned short height,
        TextureColor tc, const std::string& text, glArchivItem_Font* font, unsigned color);

    Rect GetBoundaryRect() const override;
protected:
    void DrawContent() const override;


};

/// Colored Deepening
class ctrlColorDeepening : public ctrlDeepening, public ctrlBaseColor
{
    public:
        ctrlColorDeepening(Window* parent, unsigned int id, DrawPoint position, unsigned short width, unsigned short height,
            TextureColor tc, unsigned fillColor);

    protected:
        void DrawContent() const override;

};

#endif // !CTRLDEEPENING_H_INCLUDED

