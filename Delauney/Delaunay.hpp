//
//  Delaunay.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Delaunay_hpp
#define Delaunay_hpp

#include "TriangulationContainer.hpp"
#include "Types.hpp"
#include <stdio.h>

class Delaunay
{
public:
    
    Delaunay();
    ~Delaunay();
    
    bool Triangulate(const char* file);
    
private:// Methods
    
    // Dissable cpy ctor & assignment operator
    Delaunay(const Delaunay&);
    Delaunay& operator=(const Delaunay&);
    
    bool GetFileInput(const char* file);
    bool SplitPointsArray();
    bool InitializeMainTriangle();
    bool LegalizeEdge();
    
private: // Data
    Vertex3D*              points3D;
    Vertex2D*              coords2D;
    float*                 heights;
    unsigned               numOfPoints;
    TriangulationContainer triangulation;
};

#endif /* Delaunay_hpp */