@echo off
cls
color 09
@echo === Game Clearing Script ===
ping -n 2 localhost >nul
color 0c
@echo === Clearing ===
@call del /S /Q "CMakeFiles"
@call del /S /Q "cmake_install.cmake"
@call del /S /Q "CMakeCache.txt"
@call del /S /Q "Makefile"
color 09
@echo === Cleared ===
@echo Press any Key to build the game...
@pause >nul
@call make.bat