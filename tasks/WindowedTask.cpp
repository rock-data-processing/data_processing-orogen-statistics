/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include <boost/lexical_cast.hpp>
#include <numeric/Stats.hpp>
#include "WindowedTask.hpp"

using namespace statistics;

WindowedTask::WindowedTask(std::string const& name)
    : WindowedTaskBase(name)
{
}

WindowedTask::WindowedTask(std::string const& name, RTT::ExecutionEngine* engine)
    : WindowedTaskBase(name, engine)
{
}

WindowedTask::~WindowedTask()
{
}

void WindowedTask::process() {

    statistics::Stats stats_data;

    for ( int idx=0; idx < getDataVectorCount(); idx++ ) {

        base::MatrixXd data;
        getDataMatrix(idx, _delay.get(), -1, data);

        numeric::SeriesStats data_stats(data,_ddof.get());

        stats_data.mean = data_stats.mean();
        stats_data.max = data_stats.max();
        stats_data.min = data_stats.min();
        stats_data.n = data_stats.n();
        stats_data.var = data_stats.var();
        stats_data.stddev = data_stats.stdev();


        getTimeMatrix(idx, _delay.get(), -1, data);

        stats_data.time = base::Time::fromSeconds(data.col(0).mean());

        mStatsPorts.at(idx)->write(stats_data);
    }
}




bool WindowedTask::configureHook()
{

    if (! type_to_vector::BufferedDataTask::configureHook())
        return false;

    // create all the output ports for statistics
    for ( int idx=0; idx < getDataVectorCount(); idx++) {

        StatsPortPointer outp = static_cast<StatsPortPointer>(
            createOutputPort("windowed_stats_"+boost::lexical_cast<std::string>(idx),
                "/statistics/Stats") );

        mStatsPorts.push_back(outp);
    }

    return true;
}


void WindowedTask::cleanupHook()
{

    type_to_vector::BufferedDataTask::cleanupHook();

    StatsPorts::iterator it = mStatsPorts.begin();

    for ( ; it != mStatsPorts.end(); it++ )
        ports()->removePort((*it)->getName());

    mStatsPorts.clear();
}

