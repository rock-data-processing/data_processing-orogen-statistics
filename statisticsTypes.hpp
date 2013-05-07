#ifndef statistics_TYPES_HPP
#define statistics_TYPES_HPP

#include <base/eigen.h>

namespace statistics {

/** Stores the statistics for data.
 *
 * Data is a number of timeseries. */
struct Stats {

    unsigned int n;
    base::VectorXd mean;
    base::VectorXd stddev;
    base::VectorXd max;
    base::VectorXd min;
    base::MatrixXd cov;
};

}

#endif

