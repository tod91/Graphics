solution "Delauney"
configurations { "Debug", "Release"}

project "Delauney"
kind "ConsoleApp"
language "C++"
files {"**.hpp", "**.cpp" }

buildoptions { "-std=c++1y" } 

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }