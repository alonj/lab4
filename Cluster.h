//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#ifndef LAB3_KMEANS_CLUSTER_H
#define LAB3_KMEANS_CLUSTER_H

#include "Point.h"

class Cluster
{
    friend void calcAllInterPointDistances(const Cluster cluster1,const Cluster cluster2,std::vector<double> distances);
private:
    int _idCluster;
    std::vector<Point> _points;
public:
    static double singleLink(const Cluster& cluster1, const Cluster& cluster2);

    void merge(Cluster& cluster2);
    bool isValid(){ return _idCluster!=_invalid; }
public:
    Cluster(int id_cluster, const Point &point);
    void print( ) const;
private:
    static const int _invalid;
};

#endif
