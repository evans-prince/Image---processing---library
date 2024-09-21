//
//  Pooling.cpp
//  Image - processing - library
//
//  Created by RAUNIT SINGH on 20/09/24.
//
#include<iostream>
#include<vector>
#include "Pooling.hpp"

using namespace std;

vector<vector<int>> MaxPooling(vector<vector<int>> &matrix,int poolsize,int stride){
    int h=matrix.size();
    int w=matrix[0].size();
    
    //Calculate output dimensions
    int output_h=(h-poolsize)/stride + 1;
    int output_w=(h-poolsize)/stride + 1;
    
    //Initialize output matrix
    vector<vector<int>> pooledOutput(output_h,vector<int>(output_w,0));
    
    //perform max pooling
    for(int i=0;i<=h-poolsize;i+=stride){
        for(int j=0;j<=w-poolsize;j+=stride){
            int maxVal=matrix[i][j];
            for(int x=0;x<poolsize;++x){
                for(int y=0;y<poolsize;++y){
                    maxVal=max(matrix[i+x][j+y],maxVal);
                }
            }
            pooledOutput[i/stride][j/stride]=maxVal;
        }
    }
    return pooledOutput;
    
};


vector<vector<int>> AvgPooling(vector<vector<int>> &matrix,int poolsize,int stride){
    int h=matrix.size();
    int w=matrix[0].size();
    
    //Calculate output dimensions
    int output_h=(h-poolsize)/stride + 1;
    int output_w=(h-poolsize)/stride + 1;
    
    //Initialize output matrix
    vector<vector<int>> pooledOutput(output_h,vector<int>(output_w,0));
    
    //perform average pooling
    for(int i=0;i<=h-poolsize;i+=stride){
        for(int j=0;j<=w-poolsize;j+=stride){
            int sum=0;
            for(int x=0;x<poolsize;++x){
                for(int y=0;y<poolsize;++y){
                    sum=sum+matrix[i+x][j+y];
                }
            }
            pooledOutput[i/stride][j/stride]=sum/(poolsize*poolsize);
        }
    }
    return pooledOutput;
};

