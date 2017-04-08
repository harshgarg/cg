/**\file: JarvisMarch.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: Get convex hull of a given set of points with Gift Wrapping Algorithm (Jarvis' March)
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *
  *The class provides a static function to get a convex hull of given set of points.
  *Gift Wrapping Algorithm (Jarvis' March) is used to find the convex hull.
  *The user can also export the function to .ch format, as required by the assignment.
  *This format is in-house developed at BITS Pilani Hyderabad Campus.
  *The time complexity of the algorithm is O(nh) where h is no of points in convex hull.
  *It is an output sensitive algorithm.
  *For indepth description, plese see the individual function description.
  */

class JarvisMarch
{

/**
  *\fn static Polygon convexHullJarvis(vector<Point> points)
  *\param vector<Point> points
  *\return Polygon which is the convex hull of the given set of points
  *
  *\brief A function to get convex hull with Gift Wrapping Algorithm
  *
  *It gets a convex hull of the given set of points with Jarvis' March.
  *The time complexity is O(nh) where h is no of points in CH.
  *It is a outpout senstive algorithm. Worst case is O(n^2).
  *It returns a Polygon class. Refer to documentation of the class for details.
  *
  */
public:
	static Polygon convexHullJarvis(vector<Point> points)
	{
		pair<vector<int>, vector<Point>> p = JarvisAlgo(points);
		Polygon result;									//create a polygon
		for(int i : p.first)
			result.insertAtLast(p.second[i]);			//pass the points on convex hull to the polygon
		return result;
	}

/**
  *\fn static void convexHullJarvisToCH(vector<Point> points, string filepath)
  *\param vector<Point> points
  *\param string filepath
  *\return void
  *
  *\brief A function to get .ch file of Convex hull
  *
  *The function takes a vector of points and a file path as parameters.
  *The convex hull of given set of points is calculated and saved as .ch file at the given filepath.
  *Jarvis' March is used for finding the convex hull.
  *For details on .ch file, contact Dr. T Ray from BITS Pilani University.
  *
  */
public:
	static void convexHullJarvisToCH(vector<Point> points, string filepath)
	{
		pair<vector<int>, vector<Point>> p = JarvisAlgo(points);
		ExportToCH::write(p.second, p.first, filepath);
	}

/**
  *\fn pair<vector<int>, vector<Point>> JarvisAlgo(vector<Point> points)
  *\param vector<Point> points
  *\return pair<vector<int>, vector<Point>>
  *
  *\brief A private function with implementation of Jarvis' for finding convex hull
  *
  *The function takes a set of points as input.
  *It applies Jarvis' March on it to find the convex hull.
  *CH is found by recursively analyzing the direction of three consicutive points, convex hull is generated.
  *Wrapper pulbic classes to provide proper output formats are present.
  *Look at them if you intend to call it from outside.
  *
  */
private:
	static pair<vector<int>, vector<Point>> JarvisAlgo(vector<Point> points)
	{
		/**
		  *\var Point pivot (local)
		  *\brief The point located outside the ch for initializing the algorithm
		  *
		  *\var int pivotindex (local)
		  *\brief the index of the point which is currently set as pivot
		  *
		  *\var Point minpoint (local)
		  *\brief The point with minimum angle encountered till the current loop
		  *
		  *\var int minindex (local)
		  *\brief The index of the minpoint
		  *
		  *\var vector<int> result (local)
		  *\brief The vector to store the resultant convex hull indices
		  */
		//initialization of various required variables
		int iter;
		Point pivot;
		pivot.setX(getXMin(points) - 1);		//for initializing it outside the ch
		pivot.setY(getYMin(points) - 1);
		pivot.setZ(0);
		int pivotindex = -1;					//the index of the point outside convex hull
		vector<int> result;						//vector to store the result

		Point minpoint;							//the point with minimum angle
		int minindex;							//the index of that point
		do
		{
			minpoint = points[0];				//assume that the point is the first point
			minindex = 0;
			iter = 1;
			if(pivotindex == 0)					//if first point the pivot
			{
				minpoint = points[1];
				minindex = 1;
				iter = 2;
			}
			for(; iter < points.size(); iter++)	//validate our assumption or correct the minpoint
			{
				if(iter == pivotindex)
					continue;
				if(checkDirection(pivot, minpoint, points[iter]))
				{
					minpoint = points[iter];
					minindex = iter;
				}
			}
			result.push_back(minindex);			//insert the point in result
			pivot = minpoint;
			pivotindex = minindex;
		}
		while(result.size() < 2 || result[0] != pivotindex); 		//till you encounter the start point
		result.pop_back();						//last point is repeated twice
		return {result, points};
	} 

/**
  *\fn getXMin(vector<Point> points)
  *\param vector<Point> points
  *\return the least x co-ordinate
  *
  *\brief finds the least x co-ordinate and returns it as int
  *
  *
  */
private:
	static int getXMin(vector<Point> points)
	{
		int xmin = points[0].x;
		for(Point p : points)
		{
			if(p.x < xmin)
				xmin = p.x;
		}
		return xmin;
	}

/**
  *\fn get&Min(vector<Point> points)
  *\param vector<Point> points
  *\return the least y co-ordinate
  *
  *\brief finds the least y co-ordinate and returns it as int
  *
  *
  */
private:
	static int getYMin(vector<Point> points)
	{
		int ymin = points[0].y;
		for(Point p : points)
		{
			if(p.y < ymin)
				ymin = p.y;
		}
		return ymin;
	}

/**
  *\fn checkDirection(Point a, Point b, Point c)
  *\param Point a
  *\param Point b
  *\param Point c
  *\return a boolean indicating the sign of area
  *
  *\brief Check the sign of area
  *
  *Returns true if the signed area of the triangle abc is positive
  *else returns false.
  */
private:
	static bool checkDirection(Point a, Point b, Point c)
	{
		//compute area * 2
		double area = a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y;
		if(area > 0.0)
			return true;
		return false;
	}
	
};