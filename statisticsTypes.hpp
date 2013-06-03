#ifndef statistics_TYPES_HPP
#define statistics_TYPES_HPP

#include <base/eigen.h>
#include <base/time.h>

namespace statistics {

/** Stores the statistics for data.
 *
 * Data is a number of timeseries. */
struct Stats {

    base::Time time; //!< The time of the latest samples.
    unsigned int n;
    base::VectorXd min;
    base::VectorXd max;
    base::VectorXd mean;
    base::VectorXd stddev;
    base::MatrixXd var; //!< Variance matrix.
};

}

#endif

