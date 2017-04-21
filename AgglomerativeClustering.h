//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#ifndef LAB4_H
#define LAB4_H
#include "AgglomerativeClustering.h"
#include "Point.h"
#include "Cluster.h"
#include "PairDistance.h"

class AgglomerativeClustering
{
public:
    enum eType{SingleLink=0, CompleteLink, AverageLink, countTypes};
    static const std::string _types[countTypes];
    void run(std::vector<Point> &points, unsigned clustersToStop, eType type);
    void print();

private:
    std::vector<Cluster> _clusters;
    //we keep vector of distances between each pair of clusters in this vector
    std::vector<PairDistance> _distances;
    eType _type;

private:
    void assignClusters(std::vector<Point> & points);
    void initDistances(const std::vector<Point> &points);
    bool findClosestClusters(PairDistance& psMinimum);
    void updateDistances(const PairDistance& pdClosest);
    size_t countValidClusters();
    void removeDistances(const PairDistance& pdClosest);
};


#endif
