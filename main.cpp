// Implementation of the KMeans Algorithm
// reference: http://mnemstudio.org/clustering-k-means-example-1.htm

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "AgglomerativeClustering.h"

using std::vector;

void readInput(const std::string& filename, vector<Point>& points )
{
    std::ifstream file;
    file.open( filename.c_str(), std::ifstream::in);

    std::string line;
    // read data from file
    size_t pointID = 0;

    while (getline(file, line))
    {
        vector<double> values;
        std::istringstream iss(line);
        std::string point_name;
        iss >> point_name;
        while (iss.good())
        {
            double dval(0.0);
            iss >> dval;
            values.push_back(dval);
        }
        Point p( pointID, values, point_name);
        points.push_back(p);
        pointID++;
    }

    file.close();
}

int main(int argc, char *argv[]){

    std::string fileName(argv[1]);
    unsigned clustersToStop=(unsigned)atoi(argv[2]);
    std::string type(argv[3]);

    vector<Point> points;
    std::cout << fileName << std::endl;
    readInput(fileName, points);
    if ( (clustersToStop < 1)||(clustersToStop > points.size()) ) return 1;

    AgglomerativeClustering aclustering;
    if (type==AgglomerativeClustering::_types[AgglomerativeClustering::SingleLink])
        aclustering.run(points, clustersToStop, AgglomerativeClustering::SingleLink);
    else if (type==AgglomerativeClustering::_types[AgglomerativeClustering::AverageLink])
        aclustering.run(points, clustersToStop, AgglomerativeClustering::AverageLink);
    else if (type==AgglomerativeClustering::_types[AgglomerativeClustering::CompleteLink])
        aclustering.run(points, clustersToStop, AgglomerativeClustering::CompleteLink);
    aclustering.print();
    return 0;
}
