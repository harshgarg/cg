/**\file: Polygon.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class to reresent a polygon
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *The class stores the entire polygon as a vector.
  *Thus inserting or removing at the end would take O(1) time whereas inserting or removing from middle would take O(n) time.
  *This data structure is preferred as most of the times, last point is the only point of interest.
  *Also vector is a highly ordered dataset which is being exploited here.
  *Another implementation could be using a linked list.
  */
class Polygon
{

private:
/**
  *\var vector<Point> poly
  *\brief A vector to store the points in the ordered fashion.
  *
  *\var bool clockwise
  *\brief A boolean flag set to true if the points are ordered in clockwise.
  *
  */
	vector<Point> poly;			//can get better if linkedlist is used
	bool clockwise;

public:
/**
  *\param bool clockwise
  *
  *\brief A constructor to initalize with the orientation of the polygon.
  *
  *Pass the bool parameter as true if you want to store it in clockwise fashion else false.
  */
	Polygon(bool clockwise)
	{
		this->clockwise = clockwise;
	}

public:
/**
  *\brief A simple constructor,
  *
  *It is assumed that the user would enter the polygon details in anti-clockwise direction.
  *This is done to prevent the code from throwing exceptions when the other constructor is not used.
  */
	Polygon()
	{
		Polygon(false);
	}

public:
/**
  *\fn int getSize(void)
  *\return int size
  *
  *\brief Get the number of elements in the polygons.
  *
  *Returns the number of vertices in the polygon.
  */
	int getSize(void)
	{
		return poly.size();
	}

public:
/**
  *\fn Point getPoint(int index)
  *\param int index
  *\return Point at that index
  *
  *\brief Returns the point stored at the given index.
  *
  *The indexing is done form 1 to n.
  *If wrong index is provided, garbage value can be returned.
  */
	Point getPoint(int index)
	{
		if(index > poly.size())			//check if the index is valid
			return *(new Point());		//else return empty point
		vector<Point>::iterator it = poly.begin();
		return *(it + index);
	}

public:
/**
  *\fn Point getLastPoint(void)
  *\return the last Point
  *
  *\brief Returns the last point inserted in the polygon.
  *
  *
  */
	Point getLastPoint(void)
	{
		return poly.back();
	}

public:
/**
  *\fn void insertPoint(Point p, int index)
  *\param Point p
  *\param int index
  *
  *\brief Inserts p at index index.
  *
  *The indexing is done from 1 to n.
  *If invalid index is given, it would simply drop the point.
  *\warning It cand drop points if indexing is not correct.
  */
	void insertPoint(Point p, int index)
	{
		if(index > poly.size() + 1)		//check if the index is valid
			return;
		vector<Point>::iterator it = poly.begin();
		poly.insert(it + index, p);		//insert
	}

public:
/**
  *\fn void insertAtLast(Point p)
  *\param Point p
  *
  *\brief Inserts p at the end of the polygon.
  *
  *
  */
	void insertAtLast(Point p)
	{
		poly.push_back(p);
	}
};