/**\file: SphericalPoint.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class to represent a spherical point in 3D
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *\warning: All the angles are measured in degrees.
  *
  *A class to represent spherical point in 3D.
  *The three variables radius, theta and phi reperesent the respective co-ordinates of the point.
  *Various constructors are available to initialize the point in 1, 2 or 3 dimensions.
  *If nothing is provided, the point is assumed to be the origin of 3 dimensional space.
  *If lesses dimensions are provided, the rest are set to zero.
  */
class SphericalPoint
{
public:
/**
  *\var double radius
  *\brief the radius of the point.
  *
  *\var double theta
  *\brief the angle theta of the point in degrees.
  *
  *\var double phi
  *\brief the angle phi of the point in degrees.
  */
	double radius, theta, phi;

public: 
/**
  *\param double radius
  *\param double theta
  *\param double phi
  *
  *\brief A constructor to initialize the point at (radius, theta, phi)
  *
  *It is for initializing the points in 3 dimensions.
  */
	SphericalPoint(double radius, double theta, double phi)
	{
		this->radius = radius;
		this->theta = theta;
		this->phi = phi;
	}

public: 
/**
  *\param double radius
  *\param double theta
  *
  *\brief A constructor to initialize the point at (radius, theta, 0)
  *
  *It is for initializing the points in 2 dimensions.
  *The third dimension is set to zero.
  *
  */
	SphericalPoint(double radius, double theta)
	{
		SphericalPoint(radius, theta, 0.0);
	}

public: 
/**
  *\param double radius
  *
  *\brief A constructor to initialize the point at (radius,0,0)
  *
  *It is for initializing the points in 1 dimension.
  *The second and third dimensions are set to zero.
  *
  */
	SphericalPoint(double radius)
	{
		SphericalPoint(radius, 0.0, 0.0);
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
	SphericalPoint()
	{
		SphericalPoint(0.0,0.0,0.0);
	}

public: 
/**
  *\fn void setRadius(double radius)
  *\param double x
  *
  *\brief A function to set the radius of the point.
  *
  */
	void setRadius(double radius)
	{
		this->radius = radius;
	}

public: 
/**
  *\fn void setTheta(double theta)
  *\param double theta
  *
  *\brief A function to set the theta of the point.
  *
  */
	void setTheta(double theta)
	{
		this->theta = theta;
	}

public: 
/**
  *\fn void setPhi(double phi)
  *\param double phi
  *
  *\brief A function to set the phi of the point.
  *
  */
	void setPhi(double phi)
	{
		this->phi = phi;
	}

public: 
/**
  *\fn double getRadius(void)
  *\return double radius
  *
  *\brief A function to get the radius of the point.
  *
  */
	double getRadius(void)
	{
		return radius;
	}

public: 
/**
  *\fn double getTheta(void)
  *\return double theta
  *
  *\brief A function to get the theta of the point.
  *
  */
	double getTheta(void)
	{
		return theta;
	}

public: 
/**
  *\fn double getPhi(void)
  *\return double phi
  *
  *\brief A function to get the phi of the point.
  *
  */
	double getPhi(void)
	{
		return phi;
	}
};
