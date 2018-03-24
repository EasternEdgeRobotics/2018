# Install script for directory: /home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include;/usr/local/include;/usr/local/include;/usr/local/include;/usr/local/include;/usr/local/include;/usr/local/include;/usr/local/include")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE DIRECTORY FILES
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/App/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/Comms/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/DB/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/Utils/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/Thirdparty/PocoBits/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/Thirdparty/getpot/include"
    "/home/nick/eer/moos-ivp/MOOS/MOOSCore/Core/libMOOS/Thirdparty/AppCasting/include"
    FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.hxx$")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/nick/eer/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/nick/eer/moos-ivp/build/MOOS/MOOSCore/Core/libMOOS/testing/cmake_install.cmake")

endif()

