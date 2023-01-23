#include "Shapes3D.h"

Murk::Shape3D* Murk::CreateCube(float x, float y)
{
    Shape3D* shape = new Shape3D();
    shape->verteces = new Vertex3f[24]
    {
        //bottom
        Vertex3f(-0.5f, -0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(-0.5f, -0.5f, 0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(0.5f, -0.5f, 0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(0.5f, -0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.5f)),
        //top
        Vertex3f(-0.5f, 0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(-0.5f, 0.5f, 0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(0.5f, 0.5f, 0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(0.5f, 0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.5f)),
        //-xConst_size
        Vertex3f(-0.5f, -0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(-0.5f, 0.5f, -0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(-0.5f, 0.5f, 0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(-0.5f, -0.5f, 0.5f, glm::vec3(1.0f, 0.0, 0.5f)),
        //+xConst_size
        Vertex3f(0.5f, -0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(0.5f, 0.5f, -0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(0.5f, 0.5f, 0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(0.5f, -0.5f, 0.5f, glm::vec3(1.0f, 0.0, 0.5f)),
        //-zConst_size
        Vertex3f(-0.5f, -0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(0.5f, -0.5f, -0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(0.5f, 0.5f, -0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(-0.5f, 0.5f, -0.5f, glm::vec3(1.0f, 0.0, 0.5f)),
        //+zConst_size
        Vertex3f(-0.5f, -0.5f, 0.5f, glm::vec3(1.0f, 0.0, 0.0f)),
        Vertex3f(0.5f, -0.5f, 0.5f, glm::vec3(0.0f, 1.0, 0.0f)),
        Vertex3f(0.5f, 0.5f, 0.5f, glm::vec3(0.0f, 0.0, 1.0f)),
        Vertex3f(-0.5f, 0.5f, 0.5f, glm::vec3(1.0f, 0.0, 0.5f)),

    };
    shape->indexCount = 36;
    shape->vertexCount = 24;
    shape->indeces = new unsigned int[36]
    {
        0, 1, 2,
        0, 2, 3,

        4, 5, 6,
        4, 6, 7,

        8, 9, 10,
        8, 10, 11,

        12, 13, 14,
        12, 14, 15,

        16, 17, 18,
        16, 18, 19,

        20, 21, 22,
        20, 22, 23
    };
    return shape;
}
