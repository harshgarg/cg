/**\file: Line.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class to represent line in 3D.
  *
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *A class to represent line in 3D.
  *The two variables start and end reperesent the starting point and the end point of the line segement.
  *Various constructors are available to initialize with Point class or just co-ordinates as integers.
  *If nothing is provided, start and end are assumed to be the origin.
  *
  */
class Line
{
public:
/**
  *\var Point start
  *\brief The start point of the line segment.
  *
  *\var Point end
  *\brief The end point of the line segment.
  *
  */
	Point start, end;

/**
  *\param double x1
  *\param double y1
  *\param double z1
  *\param double x2
  *\param double y2
  *\param double z2
  *
  *\brief A constructor for initializing the line in 3D
  *
  *Two new points are created with (x1, y1, z1) and (x2, y2, z2)
  *The first point is set as start point and the second point is set as end point.
  */
	Line(double x1, double y1, double z1, double x2, double y2, double z2)
	{
		//Set the end points
		start.setX(x1);
		start.setY(y1);
		start.setZ(z1);
		end.setX(x2);
		end.setY(y2);
		end.setZ(z2);
	}

/**
  *\param double x1
  *\param double y1
  *\param double x2
  *\param double y2
  *
  *\brief A constructor for initializing the line in 2D
  *
  *Two new points are created with (x1, y1, 0) and (x2, y2, 0)
  *The first point is set as start point and the second point is set as end point.
  */
	Line(double x1, double y1, double x2, double y2)
	{
		//call the constructor overload
		Line(x1, y1, 0.0, x2, y2, 0.0);
	}

/**
  *\param double x1
  *\param double x2
  *
  *\brief A constructor for initializing the line in 1D
  *
  *Two new points are created with (x1, 0, 0) and (x2, 0, 0)
  *The first point is set as start point and the second point is set as end point.
  */
	Line(double x1, double x2)
	{
		//call the constructor overload
		Line(x1, 0.0, 0.0, x2, 0.0, 0.0);
	}

/**
  *\brief A constructor with no arguments
  *
  *Both the start and the end points are set to origin
  */
	Line()
	{
		//call the constructor overload
		Line(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	}

/**
  *\param Point p1
  *\param Point p2
  *
  *\brief A constructor with two points as arguments
  *
  *The first argument is set as start point and the second as end point.
  */
	Line(Point start, Point end)
	{
		//set the points
		this->start = start;
		this->end = end;
	}

/**
  *\fn getStartPoint()
  *\return the start point
  *
  *\brief Returns a Point Class representing the start point.
  *
  */
	Point getStartPoint(void)
	{
		return start;
	}

/**
  *\fn getEndPoint()
  *\return the end point
  *
  *\brief Returns a Point Class representing the end point.
  *
  */
	Point getEndPoint(void)
	{
		return end;
	}

/**
  *\fn setStartPoint(Point p)
  *\param Point p
  *
  *\brief A function to set the start point
  *
  *The argument passed is set as the start point.
  */
	void setStartPoint(Point p)
	{
		start.x = p.x;
		start.y = p.y;
		start.z = p.z;
	}

/**
  *\fn setEndPoint(Point p)
  *\param Point p
  *
  *\brief A function to set the end point
  *
  *The argument passed is set as the end point.
  */
	void setEndPoint(Point p)
	{
		end.x = p.x;
		end.y = p.y;
		end.z = p.z;
	}

/**
  *\fn getLength()
  *\return the length in double
  *
  *\brief Get the length of line segment
  *
  */
	double getLength(void)
	{
		//calulate the euclidian distance between two points and return the distance.
		return pow((pow((end.x - start.x), 2) + pow((end.y - start.y), 2) + pow((end.z - start.z), 2)), .5);
	}
};
