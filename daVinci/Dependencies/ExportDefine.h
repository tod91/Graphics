//
//  ExportDefine.h
//  daVinci
//
//  Created by Todor Ivanov on 6/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef ExportDefine_h
#define ExportDefine_h

#ifdef __APPLE__
#define EXPORT __attribute__((visibility("default")))

#elif _WIN32
#define EXPORT __declspec(dllexport)
#endif

#endif /* ExportDefine_h */
