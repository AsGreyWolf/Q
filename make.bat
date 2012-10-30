@echo off
@echo === Game Compiler Script ===
ping -n 2 localhost >nul
color 0a
@echo === Generating makefile ===
set Path=C:\путьдоmingw\bin
set Path=%PATH%;C:\путьдоcmake\bin
set Path=%PATH%;%SystemRoot%\System32
@call C:\путьдоcmake\bin\cmake.exe -G "MinGW Makefiles" CMakeLists.txt
@echo === Building The Game ===
ping -n 1 localhost >nul
@call mingw32-make.exe
@echo === Copying dlls ===
ping -n 1 localhost >nul
@call copy winlib\libFLAC-8.dll "libFLAC-8.dll"
@call copy winlib\libfreetype-6.dll "libfreetype-6.dll"
@call copy winlib\libjpeg-8.dll "libjpeg-8.dll"
@call copy winlib\libmikmod-2.dll "libmikmod-2.dll"
@call copy winlib\libogg-0.dll "libogg-0.dll"
@call copy winlib\libpng15-15.dll "libpng15-15.dll"
@call copy winlib\libtiff-5.dll "libtiff-5.dll"
@call copy winlib\libvorbis-0.dll "libvorbis-0.dll"
@call copy winlib\libvorbisfile-3.dll "libvorbisfile-3.dll"
@call copy winlib\libwebp-2.dll "libwebp-2.dll"
@call copy winlib\smpeg.dll "smpeg.dll"
@call copy winlib\zlib1.dll "zlib1.dll"
@call copy winlib\SDL.dll "SDL.dll"
@call copy winlib\SDL_image.dll "SDL_image.dll"
@call copy winlib\SDL_mixer.dll "SDL_mixer.dll"
@call copy winlib\SDL_ttf.dll "SDL_ttf.dll"
@echo === Finished ===
