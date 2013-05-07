/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

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



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See WindowedTask.hpp for more detailed
// documentation about them.




bool WindowedTask::configureHook()
{
    
    if (! type_to_vector::BufferedDataTask::configureHook())
        return false;
    

    

    
    return true;
    
}



bool WindowedTask::startHook()
{
    
    if (! type_to_vector::BufferedDataTask::startHook())
        return false;
    

    

    
    return true;
    
}



void WindowedTask::updateHook()
{
    
    type_to_vector::BufferedDataTask::updateHook();
    

    

    
}



void WindowedTask::errorHook()
{
    
    type_to_vector::BufferedDataTask::errorHook();
    

    

    
}



void WindowedTask::stopHook()
{
    
    type_to_vector::BufferedDataTask::stopHook();
    

    

    
}



void WindowedTask::cleanupHook()
{
    
    type_to_vector::BufferedDataTask::cleanupHook();
    

    

    
}

