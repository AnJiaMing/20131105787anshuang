#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include<iostream>
#include<windows.h>
using namespace std;

#ifdef _EiC
#define WIN32
#endif

class Cmain
{
public:
	void capture_frame();
	void onTrackerSlid(int pos);
	int sport( int argc, char** argv )  ;

};