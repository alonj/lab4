//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#include "Point.h"
#include "Cluster.h"
#include <cmath>

using std::vector;
using std::string;
using std::cout;
using std::endl;

Point::Point(size_t id_point, const std::vector<double> &values, const std::string &name):_idPoint(id_point),
                                                                                          _values(values),
                                                                                          _name(name){     }


double Point::euclideanDistance(const Point &other_point) const{
    double sum = 0.0;
    for(  vector<double>::size_type i = 0; i < _values.size(); i++)
    {
        sum += pow( _values[i] - other_point._values[i], 2.0);
    }

    return sqrt(sum);
}

void Point::print() const
{
    for(vector<double>::size_type i = 0; i < _values.size(); i++)
        cout << _values[i] << " ";

    if ( !_name.empty())
        cout << " - " << _name;

    cout << endl;

}