INCLUDE(tutorial)
ADD_TUTORIAL(textures)

# # add special lib
# TARGET_LINK_LIBRARIES(textures glm ${ADDITIONAL_LIBRARIES})

# copy res
FILE(COPY 
	../shaders/textures.vert 
	../shaders/textures.frag 
	DESTINATION 
	${CMAKE_CURRENT_BINARY_DIR}/
	)
FILE(COPY 
	${PROJECT_SOURCE_DIR}/resource/totoro.png
	${PROJECT_SOURCE_DIR}/resource/wuliannan.png
	DESTINATION 
	${CMAKE_CURRENT_BINARY_DIR}/
	)