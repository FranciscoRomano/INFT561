#pragma once

struct CMesh
{
    CMesh();
    CMesh(const CMesh & n);
    static CMesh Cube();
    static CMesh Prism(int sides, float y);
    static CMesh Sphere(int sides);
    static CMesh Cylinder(int sides);
    void operator=(const CMesh & n);
    
    std::vector<int> indices; 
    std::vector<vec3> vertices;
    std::vector<vec4> vertices4;
};