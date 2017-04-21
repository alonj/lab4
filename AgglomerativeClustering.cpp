//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#include <cstdlib>
#include "AgglomerativeClustering.h"
#include <limits>

using std::vector;
using std::string;

const string AgglomerativeClustering::_types[countTypes]={"SingleLink","CompleteLink","AverageLink"};

void AgglomerativeClustering::assignClusters(vector<Point> &points)
{
    for (vector<Point>::size_type i = 0; i< points.size(); i++){
        Cluster cluster(i, points[i]);
        _clusters.push_back(cluster);
    }
}

void AgglomerativeClustering::initDistances(const std::vector<Point> &points)
{
    for (vector<Point>::size_type i = 0; i< (points.size()-1); i++)
    {
        for (vector<Point>::size_type j = i+1; j< points.size(); j++)
        {
            _distances.push_back( PairDistance(i,j, points[i].euclideanDistance(points[j])));
        }
    }
}

bool AgglomerativeClustering::findClosestClusters(PairDistance& psMinimum)
{
    if (_distances.empty()) return false;
    for (vector<PairDistance>::const_iterator cit = _distances.begin();
         cit!=_distances.end(); cit++)
    {
        if (psMinimum > *cit )
        {
            psMinimum=*cit;
        }
    }
    return true;
}

void AgglomerativeClustering::removeDistances(const PairDistance& pdClosest)
{
    //cluster 2 is no longer present - needs to be removed from distances
    for (vector<PairDistance>::size_type i = 0; i!= _distances.size(); )
    {
        if ( (_distances[i].getClusterID1()==pdClosest.getClusterID2()) ||
                  (_distances[i].getClusterID2()==pdClosest.getClusterID2()))
        {
            _distances.erase(_distances.begin()+i);
        }
        else
        {
            i++;
        }
    }
}

void AgglomerativeClustering::updateDistances(const PairDistance& pdClosest)
{
    removeDistances( pdClosest );
//distances to cluster 1 need to be updated
    for (vector<PairDistance>::iterator it = _distances.begin();
         it!=_distances.end(); it++)
    {
         if ( (it->getClusterID1()==pdClosest.getClusterID1()) ||
                  (it->getClusterID2()==pdClosest.getClusterID1()) )
        {
            if (_type==AgglomerativeClustering::SingleLink )
                it->setDistance( Cluster::singleLink(_clusters[it->getClusterID1()],_clusters[it->getClusterID2()]));
       //     else if (_type==AgglomerativeClustering::CompleteLink)
       //         it->setDistance( Cluster::completeLink(_clusters[it->getClusterID1()],_clusters[it->getClusterID2()]));
       //     else if (_type==AgglomerativeClustering::AverageLink)
       //         it->setDistance( Cluster::averageDistance(_clusters[it->getClusterID1()],_clusters[it->getClusterID2()]));
        }
    }
}

size_t AgglomerativeClustering::countValidClusters()
{
    size_t count(0);
    for (vector<Cluster>::size_type i=0; i<_clusters.size(); i++)
    {
        if (_clusters[i].isValid()) count++;
    }
    return count;
}

void AgglomerativeClustering::run(vector<Point> &points, unsigned clustersToStop, AgglomerativeClustering::eType type)
{
    _type=type;
    // at the beginning each point is a cluster
    assignClusters(points);
    initDistances(points);
    while( countValidClusters() > clustersToStop)
    {
        PairDistance pdClosest = _distances[0];
        if (!findClosestClusters(pdClosest)) break;
        size_t clusterID1 = pdClosest.getClusterID1();
        size_t clusterID2 = pdClosest.getClusterID2();
        _clusters[clusterID1].merge(_clusters[clusterID2]);
        updateDistances( pdClosest );
    }
}

void  AgglomerativeClustering::print()
{
    for (vector<Cluster>::size_type i=0; i<_clusters.size(); i++)
    {
        if (_clusters[i].isValid()) _clusters[i].print();
    }
}
