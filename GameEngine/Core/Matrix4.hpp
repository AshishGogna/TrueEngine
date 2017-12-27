//
//  Matrix4.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Matrix4_hpp
#define Matrix4_hpp

#include <stdio.h>
#include <iostream>

#endif /* Matrix4_hpp */

using namespace std;

class Matrix4
{
private:
    void SetMatrix(float m[4][4]);
    
public:
    float matrix[4][4];

    Matrix4();
    Matrix4(float m[4][4]);
    Matrix4 InitIdentity();
    
    Matrix4 Multiply(Matrix4 m);
    
    string ToString();
};
