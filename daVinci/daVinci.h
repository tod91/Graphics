//
//  daVinci.h
//  daVinci
//
//  Created by Todor Ivanov on 5/9/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef daVinci_h
#define daVinci_h

class Renderer;

extern "C" Renderer *NewRenderer(const unsigned short windowWidth, const unsigned short windowHeight);

extern "C" void DeleteRenderer(Renderer *person);

#endif /* daVinci_h */
