/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef STATISTICS_WINDOWEDTASK_TASK_HPP
#define STATISTICS_WINDOWEDTASK_TASK_HPP

#include "statistics/WindowedTaskBase.hpp"

namespace statistics {

    /*! \class WindowedTask */
    class WindowedTask : public WindowedTaskBase
    {
	friend class WindowedTaskBase;
    protected:

        typedef RTT::OutputPort<statistics::Stats>* StatsPortPointer;
        typedef std::vector<StatsPortPointer> StatsPorts;

        StatsPorts mStatsPorts;

    public:
        WindowedTask(std::string const& name = "statistics::WindowedTask");
        WindowedTask(std::string const& name, RTT::ExecutionEngine* engine);
	~WindowedTask();

        virtual void process();

        bool configureHook();

        void cleanupHook();
    };
}

#endif

