/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

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



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See CumulativeTask.hpp for more detailed
// documentation about them.




bool CumulativeTask::configureHook()
{
    
    if (! type_to_vector::BaseTask::configureHook())
        return false;
    

    

    
    return true;
    
}



bool CumulativeTask::startHook()
{
    
    if (! type_to_vector::BaseTask::startHook())
        return false;
    

    

    
    return true;
    
}



void CumulativeTask::updateHook()
{
    
    type_to_vector::BaseTask::updateHook();
    

    

    
}



void CumulativeTask::errorHook()
{
    
    type_to_vector::BaseTask::errorHook();
    

    

    
}



void CumulativeTask::stopHook()
{
    
    type_to_vector::BaseTask::stopHook();
    

    

    
}



void CumulativeTask::cleanupHook()
{
    
    type_to_vector::BaseTask::cleanupHook();
    

    

    
}

