#pragma once
#ifndef core_hpp
#define core_hpp

#include "gobangCore.h"

GOBANGCORE_API int gobangInit(bool order);
GOBANGCORE_API int gobangCoreG(int& x, int& y);
GOBANGCORE_API int gobangCoreS(int& x, int& y);
GOBANGCORE_API int getChessboard(int x, int y);
GOBANGCORE_API int getValueboard(int x, int y);
GOBANGCORE_API int getOrder(void);////////

#endif