/**\file: GrahamScan.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: Get convex hull of a given set of points with Graham Scan Algorithm
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *The class provides a static function to get a convex hull of given set of points.
  *Graham Scan Algorithm is used to find the convex hull.
  *The user can also export the function to .ch format, as required by the assignment.
  *This format is in-house developed at BITS Pilani Hyderabad Campus.
  *The time complexity of the algorithm is O(nlogn).
  *It might increase to O(n^2) if c++98 compiler is used.
  *For indepth description, plese see the individual function description.
  */
class GrahamScan
{
/**
  *\fn static Polygon convexHullGraham(vector<Point> points)
  *\param vector<Point> points
  *\return Polygon which is the convex hull of the given set of points
  *
  *\brief A function to get convex hull with Graham Scan Algorithm
  *
  *It gets a convex hull of the given set of points with Graham Scan Algorithm
  *Ideally takes O(nlogn) time complexity.
  *But it depends on the sort implemention in std namespace.
  *It returns a Polygon class. Refer to documentation of the class for details.
  *
  */
public:
	static Polygon convexHullGraham(vector<Point> points)
	{
		pair<vector<int>, vector<Point>> p = GrahamScanAlgo(points);
		Polygon result;									//create a polygon
		for(int i : p.first)
			result.insertAtLast(p.second[i]);			//pass the points on convex hull to the polygon
		return result;
	}

/**
  *\fn static void convexHullGrahamToCH(vector<Point> points, string filepath)
  *\param vector<Point> points
  *\param string filepath
  *\return void
  *
  *\brief A function to get .ch file of Convex hull
  *
  *The function takes a vector of points and a file path as parameters.
  *The convex hull of given set of points is calculated and saved as .ch file at the given filepath.
  *Graham Scan Algorithm is used for finding the convex hull.
  *For details on .ch file, contact Dr. T Ray from BITS Pilani University.
  *
  */
  	static void convexHullGrahamToCH(vector<Point> points, string filepath)
	{
		pair<vector<int>, vector<Point>> p = GrahamScanAlgo(points);
		ExportToCH::write(p.second, p.first, filepath);
	}

/**
  *\fn pair<vector<int>, vector<Point>> GrahamScanAlgo(vector<Point> points)
  *\param vector<Point> points
  *\return pair<vector<int>, vector<Point>>
  *
  *\brief A private function with implementation of Graham Scan Algorithm for finding convex hull
  *
  *The function takes a set of points as input.
  *It applies Graham Scan Algorithm on it to find the convex hull.
  *The points are converted into spherical co-ordinates, and sorted.
  *Then by recursively analyzing the direction of three consicutive points, convex hull is generated.
  *Wrapper pulbic classes to provide proper output formats are present.
  *Look at them if you intend to call it from outside.
  *
  */
private:
	static pair<vector<int>, vector<Point>> GrahamScanAlgo(vector<Point> points)
	{
		/**
		  *\var Line direction (local)
		  *\brief The direction along which all points are to be converted to polar co-ordinates
		  *
		  *\var vector<SphericalPoint>  polar (local)
		  *\brief The vector containing all the points in polar co-ordinates
		  *
		  *\var vector<pair<SphericalPoint, int>> sortedpoints (local)
		  *\brief The Vector containing original index and sphreical points sorted in increasing theta
		  *
		  *\var vector<int> result (local)
		  *\brief The vector to store the resultant convex hull indices
		  *
		  *\var vector<pair<SphericalPoint, int>> temp (local)
		  *\brief The vector required in the algorithm. This is used instead of stack required in the implementation.
		  */


		//Initialization of all the required variables

		Line direction;
		direction.start = getInteriorPoint(points);			//get an interior point for origin
		direction.end = rightMost(points);					//get the rightmost point for direction
		vector<SphericalPoint> polar = PlanarToSpherical::convert(points, direction.start, direction);		//convert to polar co-ordinates
		vector<int> result;
		vector<pair<SphericalPoint, int>> temp;
		int iter;

		//If the points are less than or equal to three, all of them are in convex hull.
		if(points.size() <= 3)
		{
			for(iter = 0; iter < points.size(); iter++)
				result.push_back(iter);
			return {result, points};
		}

		vector<pair<SphericalPoint, int>> sortedpoints;
		for(iter = 0; iter < polar.size(); iter++)
			sortedpoints.push_back({polar[iter], iter});		//enter the index and point in sortedpoints
		//sort the vector with inbuilt function and passing lambda function to compare
		sort(sortedpoints.begin(), sortedpoints.end(), [](pair<SphericalPoint, int> const& A, pair<SphericalPoint, int> const& B) {
			return (A.first.theta < B.first.theta)? true:false;
		});	//end of lambda function

		//for the initialization of the temp.
		//we insert the last point, the first point and the second point.
		temp.push_back(sortedpoints[sortedpoints.size() - 1]);
		temp.push_back(sortedpoints[0]);
		temp.push_back(sortedpoints[1]);
		result.push_back(sortedpoints[1].second);

		iter = 2;
		
		
		while(iter <= sortedpoints.size())					//a loop to insert points in result
		{
			temp.push_back(sortedpoints[iter++ % sortedpoints.size()]);
			result.push_back(temp.back().second);
			while(checkDirection(points[temp[temp.size() - 1].second], points[temp[temp.size() - 2].second], points[temp[temp.size() - 3].second]))
			{
				temp.erase(temp.end() - 2);				//If the middle point gets inside the two end of last three points, it is deleted.
				result.erase(result.end() - 2);
			}				//Else a new point is added in temp in the start of loop
		}

		return {result, points};
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
		double area = a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y;	//area of the triangle * 2
		if(area > 0)
			return true;
		return false;
	}

/**
  *\fn getInteriorPoint(vector<Point> points)
  *\param vector<Point> points
  *\return a interior point
  *
  *\brief get a point inside the convex hull of given points
  *
  *The function finds the arethmatic mean of all the poits and returns it.
  *It is ensured to be inside the CH.
  */
private:
	static Point getInteriorPoint(vector<Point> points)
	{
		double x = 0, y = 0;
		for(Point p : points)					//sum up x and y
		{
			x += p.x;
			y += p.y;
		}

		x = x / points.size();					//divide by size of points to get the average
		y = y / points.size();

		Point in;								//return it in a point

		in.x = x;
		in.y = y;

		in.z = 0;

		return in;
	}

/**
  *\fn rightMost(vector<Point> points)
  *\param vector<Point> points
  *\return the rightmost point
  *
  *\brief a simple function to find the rightmost point in a vector of points
  *
  *
  */
private:
	static Point rightMost(vector<Point> points)
	{
		Point result = points[0];
		for(Point p : points)
		{
			if(p.x > result.x || (p.x == result.x && p.y > result.y))			//check if the point is rightmost
				result = p;
		}
		return result;
	}
};