@echo off
cls
color 09
@echo === Game Compiler Script ===
ping -n 2 localhost >nul
color 0b
@echo === Generating makefile ===
set Path=H:\cpp\MinGW\bin
set Path=%Path%;H:\cpp\cmake\bin
set Path=%Path%;%SystemRoot%\System32
set PATH=H:\cpp\MinGW\bin
set PATH=%PATH%;H:\cpp\cmake\bin
set PATH=%PATH%;%SystemRoot%\System32
@call cmake.exe -G "MinGW Makefiles" CMakeLists.txt
color 0a
@echo === Building The Game ===
ping -n 1 localhost >nul
@call mingw32-make.exe
color 0e
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
@call copy winlib\libgcc_s_dw2-1.dll "libgcc_s_dw2-1.dll"
@call copy "winlib\libstdc++-6.dll" "libstdc++-6.dll"
color 09
@echo === Finished ===
@echo Press any Key to clear the cache...
@pause >nul
@call clear.bat