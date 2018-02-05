//
//  Matrix4.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Matrix4.hpp"
#include <math.h>

Matrix4::Matrix4()
{
    float m[4][4] = {0};
    SetMat(m);
}

Matrix4::Matrix4(float m[4][4])
{
    SetMat(m);
}

void Matrix4::SetMat(float m[4][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            mat[i][j] = m[i][j];
        }
    }
}

Matrix4 Matrix4::Identity()
{
    mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0;   mat[0][3] = 0;
    mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0;   mat[1][3] = 0;
    mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1;   mat[2][3] = 0;
    mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0;   mat[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::TranslationMatrix(Vector3 by)
{
    mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0;   mat[0][3] = by.x;
    mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0;   mat[1][3] = by.y;
    mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1;   mat[2][3] = by.z;
    mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0;   mat[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::RotationMatrix(Vector3 by)
{
    Matrix4 rX = Matrix4();
    Matrix4 rY = Matrix4();
    Matrix4 rZ = Matrix4();
    
    //Degrees to Randians
    by.x = by.x * (M_PI/180);
    by.y = by.y * (M_PI/180);
    by.z = by.z * (M_PI/180);
    
    rZ.mat[0][0] = cosf(by.z); rZ.mat[0][1] = -sinf(by.z); rZ.mat[0][2] = 0; rZ.mat[0][3] = 0;
    rZ.mat[1][0] = sinf(by.z); rZ.mat[1][1] =  cosf(by.z); rZ.mat[1][2] = 0; rZ.mat[1][3] = 0;
    rZ.mat[2][0] = 0;          rZ.mat[2][1] = 0;           rZ.mat[2][2] = 1; rZ.mat[2][3] = 0;
    rZ.mat[3][0] = 0;          rZ.mat[3][1] = 0;           rZ.mat[3][2] = 0; rZ.mat[3][3] = 1;
    
    rX.mat[0][0] = 1; rX.mat[0][1] = 0;          rX.mat[0][2] = 0;           rX.mat[0][3] = 0;
    rX.mat[1][0] = 0; rX.mat[1][1] = cosf(by.x); rX.mat[1][2] = -sinf(by.x); rX.mat[1][3] = 0;
    rX.mat[2][0] = 0; rX.mat[2][1] = sinf(by.x); rX.mat[2][2] = cosf(by.x);  rX.mat[2][3] = 0;
    rX.mat[3][0] = 0; rX.mat[3][1] = 0;          rX.mat[3][2] = 0;           rX.mat[3][3] = 1;
    
    rY.mat[0][0] = cosf(by.y); rY.mat[0][1] = 0; rY.mat[0][2] = -sinf(by.y); rY.mat[0][3] = 0;
    rY.mat[1][0] = 0;          rY.mat[1][1] = 1; rY.mat[1][2] = 0;           rY.mat[1][3] = 0;
    rY.mat[2][0] = sinf(by.y); rY.mat[2][1] = 0; rY.mat[2][2] = cosf(by.y);  rY.mat[2][3] = 0;
    rY.mat[3][0] = 0;          rY.mat[3][1] = 0; rY.mat[3][2] = 0;           rY.mat[3][3] = 1;
    
    SetMat((rZ * rY * rX).mat);
    return *this;
}

Matrix4 Matrix4::ScaleMatrix(Vector3 by)
{
    mat[0][0] = by.x; mat[0][1] = 0;    mat[0][2] = 0;    mat[0][3] = 0;
    mat[1][0] = 0;    mat[1][1] = by.y; mat[1][2] = 0;    mat[1][3] = 0;
    mat[2][0] = 0;    mat[2][1] = 0;    mat[2][2] = by.z; mat[2][3] = 0;
    mat[3][0] = 0;    mat[3][1] = 0;    mat[3][2] = 0;    mat[3][3] = 1;

    return *this;
}

Matrix4 Matrix4::operator*(Matrix4 m)
{
    Matrix4 res = Matrix4();
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            res.mat[i][j] = mat[i][0] * m.mat[0][j] +
                            mat[i][1] * m.mat[1][j] +
                            mat[i][2] * m.mat[2][j] +
                            mat[i][3] * m.mat[3][j];
        }
    }
    
    return res;
}

string Matrix4::ToString()
{
    string s;
    
    s += to_string(mat[0][0]) + "\t" + to_string(mat[0][1]) + "\t" + to_string(mat[0][2]) + "\t" + to_string(mat[0][3]) +"\n";
    
    s += to_string(mat[1][0]) + "\t" + to_string(mat[1][1]) + "\t" + to_string(mat[1][2]) + "\t" + to_string(mat[1][3]) +"\n";
    
    s += to_string(mat[2][0]) + "\t" + to_string(mat[2][1]) + "\t" + to_string(mat[2][2]) + "\t" + to_string(mat[2][3]) +"\n";
    
    s += to_string(mat[3][0]) + "\t" + to_string(mat[3][1]) + "\t" + to_string(mat[3][2]) + "\t" + to_string(mat[3][3]);
    
    return s;
}
