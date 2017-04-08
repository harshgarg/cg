/**\file: ExportToCH.cpp
  *\author: Parth Kundaliya
  *\author: Gurleen Cheema
  *
  *\brief: A class to export a set of points and its convex hull to .ch.
  * 
  *\warning: compile it with c++11 or later version for best results
  *\warning: It refers to some other files which are not referenced here. Use the CGeoExtension.cpp for compilation
  *
  *
  *The class is under consideration for severe changes and multiple export options are planned.
  *Please check for updates if you want to use such features.
  *The main idea is to take the input in the class constructor itself and allow it to be exported in any format the user wants.
  *The current static functions would no longer be static.
  */
class ExportToCH
{
/**
  *\fn static void write(vector<Point> points, vector<int> ch, string filepath)
  *\param vector<Point> points
  *\param vector<int> ch
  *\param string filepath
  *
  *\brief a function to convert set of points and its convex hull to a .ch file.
  *
  *Pass the vector of points, a vector containing index of points and a filepath to store the data.
  *It would create a new file, overwrite an existing file if it is the case and fill the data.
  *Though the function is currently static, changes are planned.
  *.ch is a file format to represent a set of points and its convex hull.
  *It has been developed at BITS Pilani University.
  *For more details on the file format, contact Dr. T Ray.
  *
  */
public:
	static void write(vector<Point> points, vector<int> ch, string filepath)
	{
		ofstream file;
		file.open(filepath);			//open the file
		file << "CH\n" << points.size() << " " << ch.size() << "\n";
		for(Point p : points)
			file << p.x << " " << p.y << " " << p.z << "\n";		//enter all the points
		for(int i : ch)
			file << i << " ";							//enter indices of points on convex hull
	}
};