
SET(TARGET_SRC example.cpp)
ADD_EXECUTABLE(example ${TARGET_SRC})

IF(MSVC)
	TARGET_LINK_LIBRARIES(example 
				      debug ${OUTPUT_LIBDIR}/KLog${CMAKE_DEBUG_POSTFIX}.lib optimized ${OUTPUT_LIBDIR}/KLog.lib)
ELSE(MSVC)
	TARGET_LINK_LIBRARIES(example
				      debug KLog${CMAKE_DEBUG_POSTFIX} optimized KLog )
ENDIF(MSVC)
	
ADD_DEPENDENCIES(example KLog)
