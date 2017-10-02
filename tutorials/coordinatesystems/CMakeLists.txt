INCLUDE(tutorial)
ADD_TUTORIAL(coordinatesystems)

# copy res
FILE(COPY 
	../shaders/coordinatesystems.vert 
	../shaders/coordinatesystems.frag 
	DESTINATION 
	${CMAKE_CURRENT_BINARY_DIR}/
	)
FILE(COPY 
	${PROJECT_SOURCE_DIR}/resource/totoro.png
	${PROJECT_SOURCE_DIR}/resource/wuliannan.png
	DESTINATION 
	${CMAKE_CURRENT_BINARY_DIR}/
	)