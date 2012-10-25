#!/bin/sh
case "$1" in
       clearmake)
       	cmake CMakeLists.txt
		make
		rm -r CMakeFiles
		rm CMakeCache.txt
		rm cmake_install.cmake
		rm Makefile
	;;
	clear)
       	rm -r CMakeFiles
		rm CMakeCache.txt
		rm cmake_install.cmake
		rm Makefile
       ;;
       make)
       	cmake CMakeLists.txt
		make
      	;;
      	*)
      		cmake CMakeLists.txt
		make
		rm -r CMakeFiles
		rm CMakeCache.txt
		rm cmake_install.cmake
		rm Makefile
      	;;
esac
