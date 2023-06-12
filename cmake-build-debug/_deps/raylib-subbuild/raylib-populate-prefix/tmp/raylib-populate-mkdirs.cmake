# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-src"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-build"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix/tmp"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix/src"
  "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/radek/Documents/Studia III rok/EPI/Semestr III/Algorytmy/CLion/projekt/cmake-build-debug/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/${subDir}")
endforeach()
