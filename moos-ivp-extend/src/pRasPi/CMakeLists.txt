#--------------------------------------------------------
# The CMakeLists.txt for:                       pRasPi
# Author(s):                              eer
#--------------------------------------------------------

SET(SRC
  RasPi.cpp
  RasPi_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pRasPi ${SRC})

TARGET_LINK_LIBRARIES(pRasPi
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

