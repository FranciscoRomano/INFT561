#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "classes.h"
#include "graphics.h"
#include "CGraphics.h"

#define C_PI 3.14159265358979323846

int rand_seed = (int)(time(0));
int rand_fast()
{
    rand_seed = (214013 * rand_seed + 2531011);
    return (rand_seed >> 16) & 0x7FFF;
}

int main()
{
    // CCON :: initiate
    int size[2] = { 181, 121 };
    CRenderer context(size[0], size[1]);
    const unsigned int model_size = 10;

    try
    {
        Mesh mesh[2];
        CMesh cmesh1 = CMesh::Prism(8, 0);
        CMesh cmesh2 = CMesh::Cylinder(8);
        mesh[0].indices = cmesh1.indices;
        mesh[1].indices = cmesh2.indices;
        mesh[0].vertices = cmesh1.vertices;
        mesh[1].vertices = cmesh2.vertices;

        int meshID[model_size];
        mat4 modelM4, projectionM4;
        vec3 transform[model_size][3];

        for (unsigned int i = 0; i < model_size; i++)
        {
            for (unsigned int ii = 0; ii < 2; ii++)
            {
                transform[i][2] = vec3(1);
                transform[i][ii] = vec3(
                    (float(rand_fast() % 20) / 4.0f) - 2.50f,
                    (float(rand_fast() % 20) / 4.0f) - 2.50f,
                    0
                );
            }
            meshID[i] = rand_fast() % 2;
        }

        while (true)
        {
            context.clear();

            // MAT4 :: calculate projection matrix
            projectionM4 = maths::perspective(70.0f, float(size[0]) / float(size[1]), 0.1f, 1000.0f) * maths::translate({ 0, 0, 20 });

            const int lineSize = 5;
            const float curTime = clock() / 1000.0f;
            const float sinTime = std::sin(curTime);
            const float cosTime = std::cos(curTime);


            // MESH :: draw multiple meshes
            for (unsigned int i = 0; i < model_size; i++)
            {
                // MAT4 :: calculate model matrix
                modelM4 = mat4(1);
                modelM4 = modelM4 * maths::translate(transform[i][0]);
                modelM4 = modelM4 * (maths::rotate(vec3(1, 0, 0), transform[i][1].x + sinTime) * maths::rotate(vec3(0, 1, 0), transform[i][1].y + cosTime) * maths::rotate(vec3(0, 0, 1), transform[i][1].z + sinTime));
                modelM4 = modelM4 * maths::scale(transform[i][2]);
                // CCON :: draw mesh + matrix
                context.render(mesh[meshID[i]], projectionM4 * modelM4);
            }

            modelM4 = maths::translate(vec3(0.0f, -sinTime, 10.0f));
            // Lines :: draw each line
            for (int i = 0; i < lineSize; i++)
            {
                // Lines :: calculate mat4
                if (i > 0)
                {
                    modelM4 = modelM4 * maths::translate(vec3(1, 0, 0));
                    modelM4 = modelM4 * maths::rotate(vec3(0, 0, 1), (sinTime / lineSize) * float(C_PI));
                }
                // Lines :: calculate vec4
                vec4 vertex1 = projectionM4 * modelM4 * vec4(0, 0, 0, 1);
                vertex1.x /= vertex1.w;
                vertex1.y /= vertex1.w;
                vec4 vertex2 = projectionM4 * modelM4 * vec4(1, 0, 0, 1);
                vertex2.x /= vertex2.w;
                vertex2.y /= vertex2.w;
                // Context :: set vertices/colours
                context.render(ConsoleCanvas::Line{
                    vertex1,
                    vertex2,
                    { 1, 0, 0, 1 },
                    { 0, 0, 1, 1 }
                });
                context.render(ConsoleCanvas::Line{
                    { -vertex1.x, vertex1.y, vertex1.z, vertex1.w },
                    { -vertex2.x, vertex2.y, vertex2.z, vertex2.w },
                    { 1, 0, 0, 1 },
                    { 0, 0, 1, 1 }
                });

                /*context.colour(1, 0, 0);
                context.vertex(vertex1.x, vertex1.y, vertex1.z);
                context.colour(0, 0, 1);
                context.vertex(vertex2.x, vertex2.y, vertex2.z);
                context.colour(1, 0, 0);
                context.vertex(-vertex1.x, vertex1.y, vertex1.z);
                context.colour(0, 0, 1);
                context.vertex(-vertex2.x, vertex2.y, vertex2.z);*/
            }

            context.update();
        }
    }
    catch (const char * message)
    {
        std::cout << message << std::endl;
        system("pause");
    }
    catch (...)
    {
        std::cout << "ERROR :: UNKNOWN EXCEPTION..." << std::endl;
        system("pause");
    }

    return 0;
}