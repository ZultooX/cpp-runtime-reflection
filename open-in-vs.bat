@echo off

title Open in vs

setlocal

for %%I in ("%~dp0.") do set "CURRENT_FOLDER=%%~nxI"

echo %CURRENT_FOLDER%

start "" "Library\%CURRENT_FOLDER%.slnx"

endlocal 