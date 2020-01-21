#pragma once

struct Mesh
{
    std::vector<int> indices;
    std::vector<vec3> normals;
    std::vector<vec3> vertices;
    std::vector<vec2> uvcoords;
    
    // constructor
    Mesh() = default;
    // constructor (copy constructor)
    Mesh(const Mesh & mesh);
    // operator overloading (=, assigment operator)
    void operator=(const Mesh & mesh);
};