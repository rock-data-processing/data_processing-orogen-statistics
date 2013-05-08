/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef STATISTICS_CUMULATIVETASK_TASK_HPP
#define STATISTICS_CUMULATIVETASK_TASK_HPP

#include <vector>
#include <rtt/InputPort.hpp>
#include <numeric/Stats.hpp>
#include "statistics/CumulativeTaskBase.hpp"

namespace statistics {

    /*! \class CumulativeTask */
    class CumulativeTask : public CumulativeTaskBase
    {
	friend class CumulativeTaskBase;
    protected:

        typedef RTT::OutputPort<statistics::Stats>* StatsPortPointer;
        typedef std::vector<StatsPortPointer> StatsPorts;

        StatsPorts mStatsPorts;

        typedef base::Stats<base::VectorXd> VectorStats;
        typedef std::vector<VectorStats> StatsVector;

        StatsVector mStatistics;

    public:
        CumulativeTask(std::string const& name = "statistics::CumulativeTask");

        CumulativeTask(std::string const& name, RTT::ExecutionEngine* engine);

	~CumulativeTask();

        virtual void process();

        bool configureHook();

        void cleanupHook();
    };
}

#endif

