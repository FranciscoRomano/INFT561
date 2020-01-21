// ** Dependencies *********************************************************************************
    
    #include "default.h"
    #include "classes.h"
    #include "graphics.h"
    
// *************************************************************************************************
// ** Definitions **********************************************************************************
    
    CRenderer::CRenderer(int width, int height) : ConsoleCanvas(width, height) {}

    void CRenderer::render(Line line)
    {
        ConsoleCanvas::render(line);
    }

    void CRenderer::render(Mesh mesh, mat4 matrix)
    {
        // mesh data
        vec4 vertex[3];
        vec4 colour[3];
        static ConsoleCanvas::Triangle triangle;
        // iterate throught each triangle
        for (unsigned int i = 0; i < mesh.indices.size(); i += 3)
        {
            // calculate vertex data
            triangle.c1 = vec4(mesh.vertices[mesh.indices[i + 0]], 1);
            triangle.c2 = vec4(mesh.vertices[mesh.indices[i + 1]], 1);
            triangle.c3 = vec4(mesh.vertices[mesh.indices[i + 2]], 1);
            triangle.v1 = matrix * triangle.c1;
            triangle.v2 = matrix * triangle.c2;
            triangle.v3 = matrix * triangle.c3;
            triangle.c1 = triangle.c1 + 0.5f;
            triangle.c2 = triangle.c2 + 0.5f;
            triangle.c3 = triangle.c3 + 0.5f;

            triangle.v1.x /= triangle.v1.w;
            triangle.v1.y /= triangle.v1.w;

            triangle.v2.x /= triangle.v2.w;
            triangle.v2.y /= triangle.v2.w;

            triangle.v3.x /= triangle.v3.w;
            triangle.v3.y /= triangle.v3.w;

            ConsoleCanvas::render(triangle);
        }
    }

    void CRenderer::update()
    {
        ConsoleCanvas::render();
    }

// *************************************************************************************************