# Generated from orogen/lib/orogen/templates/tasks/CMakeLists.txt

include(statisticsTaskLib)
ADD_LIBRARY(${STATISTICS_TASKLIB_NAME} SHARED 
    ${STATISTICS_TASKLIB_SOURCES})

add_dependencies(${STATISTICS_TASKLIB_NAME}
    regen-typekit)


TARGET_LINK_LIBRARIES(${STATISTICS_TASKLIB_NAME}
    ${OrocosRTT_LIBRARIES}
    ${STATISTICS_TASKLIB_DEPENDENT_LIBRARIES})
SET_TARGET_PROPERTIES(${STATISTICS_TASKLIB_NAME}
    PROPERTIES LINK_INTERFACE_LIBRARIES "${STATISTICS_TASKLIB_INTERFACE_LIBRARIES}")

INSTALL(TARGETS ${STATISTICS_TASKLIB_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/orocos)

INSTALL(FILES ${STATISTICS_TASKLIB_HEADERS}
    DESTINATION include/orocos/statistics)

