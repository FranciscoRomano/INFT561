// ** Dependencies *********************************************************************************

    #include "classes.h"

// *************************************************************************************************
// ** Definitions **********************************************************************************

    Mesh::Mesh(const Mesh & mesh)
    {
        this->operator=(mesh);
    }
    void Mesh::operator=(const Mesh & mesh)
    {
        this->indices = mesh.indices;
        this->normals = mesh.normals;
        this->vertices = mesh.vertices;
        this->uvcoords = mesh.uvcoords;
    }


// *************************************************************************************************