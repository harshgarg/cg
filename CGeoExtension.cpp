/**\file: CGeoExtension.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: THe file containing references to all the files in the API.
  * 
  *\warning: compile it with c++11 or later version for best results
  *
  *Include this file on the top and call any of the functions provided in the documentation you want.
  *Enjoy!!
  */
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include "src\Geometry\Point.cpp"
#include "src\Geometry\SphericalPoint.cpp"
#include "src\Geometry\Line.cpp"
#include "src\Geometry\Polygon.cpp"
#include "src\Geometry\PlanarToSpherical.cpp"

#include "src\IO\GetPoints.cpp"
#include "src\IO\ExportToCH.cpp"

#include "src\ConvexHull\Andrew.cpp"
#include "src\ConvexHull\GrahamScan.cpp"
#include "src\ConvexHull\JarvisMarch.cpp"
