#pragma once

#include "ConsoleCanvas.h"

struct CRenderer : public ConsoleCanvas
{
    // constructor
    CRenderer(int width, int height);
    // render
    void render(Line line);
    // render a mesh
    void render(Mesh mesh, mat4 matrix);
    // update the renderer
    void update();
};