//
//  Window.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "ExportDefine.h"

class GLFWwindow;

class EXPORT Window
{
public:
    
    Window();
    ~Window();
    
    bool createWindow(const unsigned short width, const unsigned short heigh, const char* title);
    GLFWwindow* getWindow() const;
    
private:
    GLFWwindow* window;
};
#endif /* Window_hpp */
