//
// Created by anna on 4/16/2017.
//

#ifndef LAB4_ANNA_PAIRSIMILARITY_H
#define LAB4_ANNA_PAIRSIMILARITY_H

#include <stdlib.h>

class PairDistance
{
private:
    size_t _clusterID1;
    size_t _clusterID2;
    double _distance;
public:
    PairDistance(size_t clusterID1, size_t clusterID2, double distance): _clusterID1(clusterID1),
                                                                         _clusterID2(clusterID2),
                                                                         _distance(distance) { }
    double setDistance(double distance) { _distance=distance; }
    size_t getClusterID1() const { return _clusterID1; }
    size_t getClusterID2() const { return _clusterID2; }

    bool operator > (const PairDistance& ps) const
    {
        if ( _distance > ps._distance ) return true;
        return false;
    }
};



#endif //LAB4_ANNA_PAIRSIMILARITY_H
