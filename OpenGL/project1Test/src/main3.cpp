#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

using namespace std;

const int screen_width = 640;
const int screen_height = 480;
GLFWwindow * window;
bool init(){
    if(glfwInit() == false){
        cout << "Could not init GLFW" << endl;
        return false;
    }
    cout << "GLFW initialized" << endl;
    

    window = glfwCreateWindow(screen_width, screen_height, "OPENGL - DatNguyen", NULL, NULL);
    if(window == NULL){
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "Couldn't load opengl" << endl;
        glfwTerminate();
        return false;

    }
    return true;
}

void getInfo(){
    const unsigned char *version = glGetString(GL_VERSION);
    const unsigned char *renderer = glGetString(GL_RENDERER);
    const unsigned char *vendor = glGetString(GL_VENDOR);

    cout << "OPENGL Version: " << version  << endl;
    cout << "OPENGL Vendor: " << vendor << endl;
    cout << "OPENGL Renderer: " << renderer << endl;
}

string readShaderSource(string fileName){
    fstream inputFile(fileName); 
  
    // if (!inputFile.is_open()) { 
    //     cout << "Error opening the file!" << endl; 
    //     inputFile.close();
    //     string error = "error";
    //     return error;
    // } 
  
    string line; 
    string code = "";
    cout << "File Content: " << endl; 
    while (getline(inputFile, line)) { 
        code += line + "\n";
    } 
  
    inputFile.close(); 
    return code;
}


int main(){
    if(init() == false){
        return 0;
    }
    getInfo();

    GLfloat vertices[] = {
        // 0.0f, 0.5f, 0.0f,
        // -0.5f, -0.5f, 0.0f,
        // 0.5f, -0.5f, 0.0f

        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        1, 2, 3
    };
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // string vertexSrc = readShaderSource("./shaders/general_vertex_shader.vs");
    // string fragmentSrc = readShaderSource("./shaders/general_fragment_shader.fs");
    string file{__FILE__};
    string directory = file.substr(0, file.rfind("/"));
    string vsPath = "./shaders/general_vertex_shader.vs";
    string fsPath = "./shaders/general_fragment_shader.fs";
    string vS = readShaderSource(vsPath);
    string fS = readShaderSource(fsPath);
    //Shader shader("/home/davidng/Downloads/KhoaCP/28Tech/CPP/Code/GameC++/GameC-/OpenGL/project1Test/shaders/general_vertex_shader.vs", "/home/davidng/Downloads/KhoaCP/28Tech/CPP/Code/GameC++/GameC-/OpenGL/project1Test/shaders/general_fragment_shader.fs");
    cout << vS << endl;
    cout << fS << endl;
    while(!glfwWindowShouldClose(window)){

        glClear(GL_COLOR_BUFFER_BIT);
        glEnableVertexAttribArray(0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    

    return 0;
}