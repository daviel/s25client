SET(Boost_COMPILER "-mgw44")

# disable rsp files to allow ccache to work
SET(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
SET(CMAKE_C_USE_RESPONSE_FILE_FOR_OBJECTS OFF)
SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS OFF)
