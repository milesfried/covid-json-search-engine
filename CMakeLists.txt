cmake_minimum_required(VERSION 3.16)
project(su21_srch_eng_miles_and_steve)

set(CMAKE_CXX_STANDARD 17)



foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

include_directories(.)
add_executable(su21_srch_eng_miles_and_steve
        DSVector.h
        main.cpp AVLTree.h DSString.cpp DSString.h parser.cpp parser.h PaperWordEntry.cpp PaperWordEntry.h IndexEntry.cpp IndexEntry.h docudata.cpp docudata.h IndexHandler.cpp IndexHandler.h DSHashtable.h Query.cpp Query.h)
