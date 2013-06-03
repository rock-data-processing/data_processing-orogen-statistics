#! /usr/bin/env ruby

require 'orocos'
include Orocos

ENV["ORO_LOGLEVEL"] = '3'

Orocos.initialize

Orocos.run 'statistics::WindowedTask' => 'statsTask' do
    
    task = TaskContext.get 'statsTask'

    data_port = Types::TypeToVector::PortConfig.new
    data_port.portname = "rbs1"
    data_port.type = "/base/samples/RigidBodyState"
    data_port.slice = "position"
    data_port.vectorIdx = 0
    data_port.period = 0.1
    data_port.useTimeNow = false

    task.addPort(data_port)

    task.buffer_size = 10

    task.configure
    
    puts
    puts "Task  Type  Orocos_Type"
    puts "--- Input ports ---"
    task.each_input_port do |p|
        puts "#{p.name}  #{p.type_name}  #{p.orocos_type_name}"
    end
    
    puts "\n--- Output ports ---"
    task.each_output_port do |p|
        puts "#{p.name}  #{p.type_name}  #{p.orocos_type_name}"
    end
    puts

    rbs1_w = task.rbs1.writer
    rbs = rbs1_w.new_sample

    stats_r = task.windowed_stats_0.reader

    stop_write = false

    write_t = Thread.new do
        while !stop_write
            rbs.time = Time.now
            rbs.position.x = 1.0
            rbs.position.y = rand
            rbs.position.z = Math.sin(rbs.time.to_f)
            rbs1_w.write(rbs)
            sleep(0.1)
        end
    end

    task.start

    puts "cnt   mean_x   mean_y   mean_z    std_x    std_y    std_z"

    (1..100).each do |idx|

        if s = stats_r.read
            printf "%3d  %8.5f %8.5f %8.5f  %8.5f %8.5f %8.5f\n", s.n, s.mean[0], s.mean[1], s.mean[2], s.stddev[0], s.stddev[1], s.stddev[2]
        end

        sleep(0.1)
    end


    stop_write = true

    write_t.join

end
