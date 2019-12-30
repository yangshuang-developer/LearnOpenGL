# propagate menu links up
SET(CPACK_NSIS_MENU_LINKS ${CPACK_NSIS_MENU_LINKS} PARENT_SCOPE)

#config libs
#GLAD
ADD_SUBDIRECTORY(glad)

#GLFW
SET(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "Build the GLFW example programs" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target" FORCE)
SET(GLFW_VULKAN_STATIC OFF CACHE BOOL "Use the Vulkan loader statically linked into application" FORCE)

ADD_SUBDIRECTORY(glfw)

#GLM
ADD_SUBDIRECTORY(glm)


