#version 410

in vec3 vertexColor;

out vec4 pixelColor;

void  main(){
    pixelColor = vec4(vertexColor, 1.0);
}