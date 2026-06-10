@echo off

title Generating C++ Project

echo ===============================
echo ==     GENERATING CMAKE     ===
echo ===============================

cmake -G "Visual Studio 18 2026"    ^
    -T host=x64                     ^
    -S .                            ^
    -B Library                      ^
    -DTESTING_SUITE="loop"

if %errorlevel% neq 0 (
    echo [FAILED] Generating Cmake Failed.
    pause
)

pause