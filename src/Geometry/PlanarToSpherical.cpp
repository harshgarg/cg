/**\file: PlanarToSpherical.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class having functions to convert set of points from planar to spherical co-ordinates.
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *\warning: All the angles would be stored in degrees.
  *
  *The class contains a few static functions to convert a vector of points in planar co-ordinates to spherical co-ordinates.
  *The user has options to provide the new origin and the direction.
  *The point has to be provided as a Point class and the direction as Line class.
  *
  */
class PlanarToSpherical
{
public:
/**
  *\fn static vector<SphericalPoint> convert(vector<Point> input, Point origin, Line direction)
  *\param vector<Point> input
  *\param Point origin
  *\param Line direction
  *\return a vector of SphericalPoint
  *
  *\brief A function to convert a vector of planar points to spherical points at a given origin and direction of 0 degree angle
  *
  *All the angles would be stored in degree.
  *Time complexity is O(n)
  *Returns a new vector with spherical points stored in it.
  *Order is maintained.
  *
  */
	static vector<SphericalPoint> convert(vector<Point> input, Point origin, Line direction)
	{
		vector<SphericalPoint> result;			//create a vector to store the result
		double radius, theta, phi;
		for(Point p : input)					//iterate over all the points
		{
			radius = pow(pow(p.x - origin.x, 2) + pow(p.y - origin.y, 2), .5);		//set the radius as distance
			theta = getAngle(origin, direction, p);		//theta as the angle
			SphericalPoint sp;					//create an instance of spherical point
			sp.radius = radius;					//set the values
			sp.theta = theta;
			result.push_back(sp);				//push it in the vector
		}
		return result;
	}

public:
/**
  *\fn static vector<SphericalPoint> convert(vector<Point> input, Point origin)
  *\param vector<Point> input
  *\param Point origin
  *\return a vector of SphericalPoint
  *
  *\brief A function to convert a vector of planar points to spherical points at a given origin.
  *
  *The direction for 0degree is assumed to be along x axis.
  *All the angles would be stored in degree.
  *Time complexity is O(n)
  *Returns a new vector with spherical points stored in it.
  *Order is maintained.
  *
  */
	static vector<SphericalPoint> convert(vector<Point> input, Point origin)
	{
		return convert(input, origin, *(new Line(0,0,0,1,0,0)));
	}

public:
/**
  *\fn static vector<SphericalPoint> convert(vector<Point> input)
  *\param vector<Point> input
  *\return a vector of SphericalPoint
  *
  *\brief A function to convert a vector of planar points to spherical points.
  *
  *The origin is assumed to be at the planar origin.
  *The direction for 0degree is assumed to be along x axis.
  *All the angles would be stored in degree.
  *Time complexity is O(n)
  *Returns a new vector with spherical points stored in it.
  *Order is maintained.
  *
  */
	static vector<SphericalPoint> convert(vector<Point> input)
	{
		return convert(input, *(new Point(0,0,0)), *(new Line(0,0,0,1,0,0)));
	}

private:
/**
  *\fn static double getAngle(Point pivot, Line direction, Point p)
  *\param Point pivot
  *\param Line direction
  *\param Point p
  *\return double angle
  *
  *\brief Get a angle of a point from a given line at a given point.
  *
  *The angle would be measure in degrees.
  *The value would lie in between 0degree to 360degrees.
  */
	static double getAngle(Point pivot, Line direction, Point p)
	{
		//first move the direction vector to origin
		if(direction.start.x != pivot.x || direction.start.y != pivot.y)
		{
			direction.end.x -= (direction.start.x - pivot.x);
			direction.end.y -= (direction.start.y - pivot.y);
			direction.start.x = pivot.x;
			direction.start.y = pivot.y;
		}

		double angle1 = atan2(direction.end.y - pivot.y, direction.end.x - pivot.x);	//slop of direction vector
    	double angle2 = atan2(p.y - pivot.y, p.x - pivot.x);		//slope of origin and point
    	double angle = angle1 - angle2;
    	angle = angle * -1;							//required
    	angle = angle * 180 / 3.14159265;			//for conversion to degrees
    	if(angle < 0)
    		angle = angle + 360;					//to ensure angle is positive
    	return angle;
	}
};