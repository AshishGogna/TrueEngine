//
//  Window.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class Window
{
private:
    static int width;
    static int height;
    static string name;
    static GLFWwindow* window;
    
    static void InitGraphics();

public:
    static void CreateWindow(int width = 800, int height = 600, string name = "A Window");
    static void Terminate();
    static void Clear();
    static void SwapBuffers();
    static bool ShouldClose();
    static bool isInitialized();
    static int GetWidth();
    static int GetHeight();
    static GLFWwindow* GetWindow();
};

#endif /* Window_hpp */
