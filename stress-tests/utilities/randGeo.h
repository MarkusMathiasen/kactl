#pragma once

#include "../../content/geometry/Point.h"

template <class T=double>
Point<T> randIntPt(ll lim) {
    return Point<T>((double)(rand()%(lim*2) - lim), (double)(rand()%(lim*2)-lim));
}
