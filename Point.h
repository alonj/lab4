//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H

#include <iostream>
#include <vector>
#include <string>


class Point
{
private:
    size_t _idPoint;
    std::vector<double> _values;
    std::string _name;

public:
    Point(size_t id_point, const std::vector<double>& values, const std::string& name = "");

    size_t getID() const { return _idPoint; }

    double euclideanDistance( const Point &other_point ) const;

    void print() const;

};


#endif
