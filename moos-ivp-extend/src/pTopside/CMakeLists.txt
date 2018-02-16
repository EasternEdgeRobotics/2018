#--------------------------------------------------------
# The CMakeLists.txt for:                       pTopside
# Author(s):                              eer
#--------------------------------------------------------

SET(SRC
  Topside.cpp
  Topside_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pTopside ${SRC})

TARGET_LINK_LIBRARIES(pTopside
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

