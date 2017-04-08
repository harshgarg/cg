/**\file: 
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class for fetching points as input
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *The class has static methods to fetch function from input.
  *Currently it only suppports input from standard input.
  *If required in the project, functions would be developed to take input from files as well.
  *Equivalent classes to fetch lines or polygons can also be developed
  */
class GetPoints
{
/**
  *\fn static vector<Point> getInput(void)
  *\return set of points entered
  *
  *\brief Returns a vector of points entered by the user
  *
  *The function requests user to enter the x, y and z co-ordinates of the points.
  *It stores it in an vector of Point class.
  *Returns it after all the points are entered.
  */
public:
	static vector<Point> getInput(void)
	{
		vector<Point> input;
		int n;
		double x, y, z;
		Point *p;
		cout<<"Please enter the number of points : ";
		scanf("%d", &n);
		for(int iter = 0; iter < n; iter++)
		{
			cout<<"Please enter x ,y and z co-ordinates sepreated by a space for point " << iter << " : ";
			scanf("%lf %lf %lf", &x, &y, &z);
			p = new Point(x, y, z);
			input.push_back(*p);
		}
		return input;
	}
};

