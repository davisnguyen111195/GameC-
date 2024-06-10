#ifndef DEF_SHADER
#define DEF_SHADER
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
public:
    const char* m_vs;
    const char* m_fs;
    unsigned int ID;

    Shader(const char* vertexPath, const char* framentPath);

};

#endif