/**\file: Andrew.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: Get convex hull of a given set of points with Andrew's Algorithm
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *The class provides a static function to get a convex hull of given set of points.
  *Andrew's Algorithm is used in finding the convex hull.
  *The user can also export the function to .ch format, as required by the assignment.
  *This format is in-house developed at BITS Pilani Hyderabad Campus.
  *The time complexity of the algorithm is O(nlogn).
  *It might increase to O(n^2) if c++98 compiler is used.
  *For indepth description, plese see the individual function description.
  *
  */
class Andrew
{
/**
  *\fn static Polygon convexHullAndrew(vector<Point> points)
  *\param vector<Point> points
  *\return Polygon which is the convex hull of the given set of points
  *
  *\brief A function to get convex hull with Andrew's Algorithm
  *
  *It gets a convex hull of the given set of points with Andrew's Algorithm
  *Ideally takes O(nlogn) time complexity.
  *But it depends on the sort implemention in std namespace.
  *It returns a Polygon class. Refer to documentation of the class for details.
  *
  */
public:
	static Polygon convexHullAndrew(vector<Point> points)
	{
		pair<vector<int>, vector<Point>> p = AndrewAlgo(points);
		Polygon result;									//create a polygon
		for(int i : p.first)
			result.insertAtLast(p.second[i]);			//pass the points on convex hull to the polygon
		return result;
	}

/**
  *\fn static void convexHullAndrewToCH(vector<Point> points, string filepath)
  *\param vector<Point> points
  *\param string filepath
  *\return void
  *
  *\brief A function to get .ch file of Convex hull
  *
  *The function takes a vector of points and a file path as parameters.
  *The convex hull of given set of points is calculated and saved as .ch file at the given filepath.
  *Andrew's Algorithm is used for finding the convex hull.
  *For details on .ch file, contact Dr. T Ray from BITS Pilani University.
  *
  */
public:
	static void convexHullAndrewToCH(vector<Point> points, string filepath)
	{
		pair<vector<int>, vector<Point>> p = AndrewAlgo(points);
		ExportToCH::write(p.second, p.first, filepath);
	}

/**
  *\fn static pair<vector <int>, vector <Point>> AndrewAlgo(vector<Point> points)
  *\param vector<Point> points
  *\return pair<vector <int>, vector <Point>>
  *
  *\brief a private function to get convex hull
  *
  *The public functions to call this are also present.
  *Please refer to their documentation if you intend to use this function.
  *This function is to avoid redundancy in the code.
  *The public functions would call this function and provide output in the required format.
  *This function returns a pair with a integer vector and a Point class vector.
  *The Point class vector is the set of points whose CH is calculated.
  *The integer vector contains the index of all the points in Point class vectors who are present in covex hull.
  */
private:
	static pair<vector <int>, vector <Point>> AndrewAlgo(vector<Point> points)
	{
		/**
		  *\var vector<Point> upper (local)
		  *\brief This variable acts as a list of points on upper hull.
		  *
		  *\var vector<Point> upper (local)
		  *\brief This variable acts as a list of points on lower hull.
		  *
		  *\var vector<int> result (local)
		  *\brief The vector to store the resultant convex hull indices
		  *
		  */
		int iter, temp;
		static vector<int> result;

		//if points are less than or equal to three, include all in convex hull.
		if(points.size() <= 3)
		{
			for(iter = 0; iter < points.size(); iter++)
				result.push_back(iter);
			return {result, points};
		}

		sort(points.begin(), points.end(), [](Point const& A, Point const& B) {
			return (A.x < B.x)? true:(A.x > B.x)? false:(A.y < B.y)? true:false;
		});
		
		vector<Point> upper;
		for(iter = 0; iter < points.size(); iter++)
		{
			temp = upper.size();
			while(temp > 1 && checkDirection(upper[temp - 2], upper[temp - 1], points[iter]))
			{
				upper.pop_back();
				result.pop_back();
				temp--;
			}
			result.push_back(iter);
			upper.push_back(points[iter]);
		}
		result.pop_back();

		vector<Point> lower;
		for(iter = points.size() - 1; iter >= 0; iter--)
		{
			temp = lower.size();
			while(temp > 1 && checkDirection(lower[temp - 2], lower[temp - 1], points[iter]))
			{
				lower.pop_back();
				result.pop_back();
				temp--;
			}
			lower.push_back(points[iter]);
			result.push_back(iter);
		}
		result.pop_back();
		return {result, points};
	}

/**
  *\fn static bool checkDirection(Point a, Point b, Point c)
  *\param Point a
  *\param Point b
  *\param Point c
  *\return a boolean stating the sign of area
  *
  *\brief returns true if area is greater else false
  *
  *The function calculates the signed area of all the three points.
  *Returns true if the area is positive.
  *Else false.
  */
private:
	static bool checkDirection(Point a, Point b, Point c)
	{
		double area = a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y;
		if(area > 0)
			return true;
		return false;
	}
};