MACRO (ADD_TUTORIAL TUTORIAL_NAME)
  ADD_EXECUTABLE(${TUTORIAL_NAME} ${TUTORIAL_NAME}.h ${TUTORIAL_NAME}.cpp)
  TARGET_LINK_LIBRARIES(${TUTORIAL_NAME} core glad glfw opengl32 ${ADDITIONAL_LIBRARIES})
  SET_PROPERTY(TARGET ${TUTORIAL_NAME} PROPERTY FOLDER Tutorials)
ENDMACRO ()
