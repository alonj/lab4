//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//
#include "Cluster.h"
#include <cstdlib>
#include <limits>
#include <afxres.h>

using std::vector;
using std::cout;
using std::endl;

const int Cluster::_invalid=-1;

Cluster::Cluster(int idCluster, const Point& point) : _idCluster(idCluster)
{
    _points.push_back(point);
}


void Cluster::print() const
{
    cout << "Cluster " << _idCluster + 1 << endl;
    for(vector<Point>::size_type j = 0; j < _points.size(); j++)
    {
        cout << "Point " << _points[j].getID() + 1 << ": ";
        _points[j].print();
    }
}

void calcAllInterPointDistances(const Cluster cluster1,const Cluster cluster2,vector<double> distances)
{
    for(vector<Point>::const_iterator cit=cluster1._points.begin(); cit!=cluster1._points.end();cit++)
    {
        double minimalDist=std::numeric_limits<double>::max();
        for(vector<Point>::const_iterator citt=cluster2._points.begin();citt!=cluster2._points.end();citt++)
        {
            if(minimalDist > cluster1(*cit).euclideanDistance(cluster2(*citt)))
                minimalDist=cluster1(*cit).euclideanDistance(cluster2(*citt))
        }
        distances.push_back(minimalDist);
    }
}

double Cluster::singleLink(const Cluster& cluster1, const Cluster& cluster2)
{
    std::vector<double> distances;
    calcAllInterPointDistances(cluster1, cluster2, distances);
    double min = std::numeric_limits<double>::max();
    for (vector<double>::const_iterator cit=distances.begin();
            cit!=distances.end(); cit++)
    {
        if (min>*cit) min=*cit;
    }
    return min;
}


void Cluster::merge( Cluster& cluster2)
{
    _points.insert(_points.end(),cluster2._points.begin(),cluster2._points.end());
    cluster2._idCluster=Cluster::_invalid;
}