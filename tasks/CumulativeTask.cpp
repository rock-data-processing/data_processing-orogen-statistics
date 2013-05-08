/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include <boost/lexical_cast.hpp>
#include "CumulativeTask.hpp"

using namespace statistics;

CumulativeTask::CumulativeTask(std::string const& name)
    : CumulativeTaskBase(name)
{
}

CumulativeTask::CumulativeTask(std::string const& name, RTT::ExecutionEngine* engine)
    : CumulativeTaskBase(name, engine)
{
}

CumulativeTask::~CumulativeTask()
{
}

void CumulativeTask::process() {
        
    base::VectorXd vec;
    statistics::Stats stats_data;
        
    for ( int idx=0; idx < getDataVectorCount(); idx++ ) {

        VectorStats& stats = mStatistics.at(idx);

        getVector(idx,vec);
        stats.update(vec);
        getTimeVector(idx,vec);

        stats_data.time = base::Time::fromSeconds(vec.mean());
        stats_data.n = stats.n();
        stats_data.mean = stats.mean();
        stats_data.max = stats.max();
        stats_data.min = stats.min();
        stats_data.stddev = stats.stdev();
        stats_data.cov = stats.var();

        mStatsPorts.at(idx)->write(stats_data);        
    }
}


bool CumulativeTask::configureHook()
{
    
    if (! type_to_vector::BaseTask::configureHook())
        return false;
    
    // create all the output ports
    for ( int idx=0; idx < getDataVectorCount(); idx++) {
        
        StatsPortPointer outp = static_cast<StatsPortPointer>(
            createOutputPort("stats_"+boost::lexical_cast<std::string>(idx),
                "/statistics/Stats") );

        mStatsPorts.push_back(outp);
    }

    mStatistics.resize(getDataVectorCount());

    return true;
}


void CumulativeTask::cleanupHook()
{
    
    type_to_vector::BaseTask::cleanupHook();
    
    StatsPorts::iterator it = mStatsPorts.begin();

    for ( ; it != mStatsPorts.end(); it++ )
        ports()->removePort((*it)->getName());
    
    mStatsPorts.clear();
    mStatistics.clear();
}

