/**\file: Point.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class to represent a point in 3D
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *A class to represent point in 3D.
  *The three variables x, y and z reperesent the respective co-ordinates of the point.
  *Various constructors are available to initialize the point in 1, 2 or 3 dimensions.
  *If nothing is provided, the point is assumed to be the origin of 3 dimensional space.
  *If lesses dimensions are provided, the rest are set to zero.
  */
class Point
{
/**
  *\var double x
  *\brief the x co-ordinate of the point.
  *
  *\var double y
  *\brief the y co-ordinate of the point.
  *
  *\var double z
  *\brief the z co-ordinate of the point.
  */
public:
	double x, y, z;

public:
/**
  *\param double x
  *\param double y
  *\param double z
  *
  *\brief A constructor to initialize the point at (x,y,z)
  *
  *It is for initializing the points in 3 dimensions.
  */
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

public:
/**
  *\param double x
  *\param double y
  *
  *\brief A constructor to initialize the point at (x,y,0)
  *
  *It is for initializing the points in 2 dimensions.
  *The third dimension is set to zero.
  *
  */
	Point(double x, double y)
	{
		Point(x, y, 0.0);
	}

public:
/**
  *\param double x
  *
  *\brief A constructor to initialize the point at (x,0,0)
  *
  *It is for initializing the points in 1 dimension.
  *The second and third dimensions are set to zero.
  *
  */
	Point(double x)
	{
		Point(x, 0.0, 0.0);
	}

public:
/**
  *
  *\brief A constructor to initialize the point at (0,0,0)
  *
  *It is for initializing the point without any co-ordinates.
  *It is initialized at x, y and z.
  *
  */
	Point()
	{
		Point(0.0,0.0,0.0);
	}

public:
/**
  *\fn void setX(double x)
  *\param double x
  *
  *\brief A function to set the x co-ordinate of the point.
  *
  */
	void setX(double x)
	{
		this->x = x;
	}

public:
/**
  *\fn void setY(double y)
  *\param double y
  *
  *\brief A function to set the y co-ordinate of the point.
  *
  */
	void setY(double y)
	{
		this->y = y;
	}

public:
/**
  *\fn void setZ(double z)
  *\param double z
  *
  *\brief A function to set the z co-ordinate of the point.
  *
  */
	void setZ(double z)
	{
		this->z = z;
	}

public:
/**
  *\fn double getX(void)
  *\return double x
  *
  *\brief A function to get the x co-ordinate of the point.
  *
  */
	double getX(void)
	{
		return x;
	}

public:
/**
  *\fn double getY(void)
  *\return double y
  *
  *\brief A function to get the y co-ordinate of the point.
  *
  */
	double getY(void)
	{
		return y;
	}

public:
/**
  *\fn double getZ(void)
  *\return double z
  *
  *\brief A function to get the z co-ordinate of the point.
  *
  */
	double getZ(void)
	{
		return z;
	}
};
