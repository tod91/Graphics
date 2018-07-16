//
//  Delaunay.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include <stdlib.h>
#include "Sorting.hpp"
#include "Delaunay.hpp"

Delaunay::Delaunay()
: points3D(NULL)
, heights(NULL)
, coords2D(NULL)
, numOfPoints(0)
{
}


Delaunay::~Delaunay()
{
    free(heights);
    free(coords2D);
    
    heights = NULL;
    coords2D = NULL;
}


bool Delaunay::Triangulate(const char* file)
{
    if(GetFileInput(file))
        return false;
    
    if(BottomUpMergeSort(points3D, numOfPoints))
        return false;
    
    //  NOTE:   after splitpoints3DArray() executes, points3D is no longer a valid
    //          pointer and if you try and use it bad things will happen.
    if(SplitPointsArray())
        return false;
    
    InitializeMainTriangle();
    triangulation.AddInitialPoint(coords2D[0]); // tuk ne sum siguren dali ne trqbva da e coords2D[1]
    
    for(unsigned i = 1; i < numOfPoints - 1; ++i)
    {
        triangulation.AddPoint(coords2D[i]);
    }

    LegalizeEdge();
    
    return true;
}


bool Delaunay::LegalizeEdge()
{
    
    return true;
}


bool Delaunay::InitializeMainTriangle()
{
    float upperMostPoint = coords2D[0].y;
    float lowerMostPoint = coords2D[0].y;
    
    for(size_t i = 1; i < numOfPoints; ++i)
    {
        if(upperMostPoint < coords2D[i].y)
           upperMostPoint = coords2D[i].y;
        
        if(lowerMostPoint > coords2D[i].y)
           lowerMostPoint = coords2D[i].y;
    }
    
    float dy = upperMostPoint - lowerMostPoint;
    float dx = coords2D[numOfPoints - 1].x - coords2D[0].x;
    
    //  Main triangles vertices are in order from the leftmost vertex and traveling
    //  counter clockwise.
    //  @NOTE Do we need this? If not remove it and directly assign to triangulation.head->triangle
    coords2D[numOfPoints].x = coords2D[0].x - dy;
    coords2D[numOfPoints].y = lowerMostPoint;
    
    coords2D[numOfPoints + 1].x = coords2D[numOfPoints - 1].x + dy;
    coords2D[numOfPoints + 1].y = lowerMostPoint;
    
    coords2D[numOfPoints + 2].x = coords2D[0].x + dx/2;
    coords2D[numOfPoints + 2].y = upperMostPoint + dx/2;
    
    triangulation.head  = new Node;
    if(!triangulation.head)
    {
        fprintf(stderr, "Error, cannot allocate memory for a Node\n");
        return false;
    }

    
    triangulation.head->triangle.vertex[0] = coords2D[numOfPoints];
    triangulation.head->triangle.vertex[1] = coords2D[numOfPoints + 1];
    triangulation.head->triangle.vertex[2] = coords2D[numOfPoints + 2];
    
    triangulation.head->next = NULL;
    
    return true;
}