@echo off

REM Check if we need to create the bootstrap directory
IF EXIST "./bootstrap" (
    echo Found existing bootstrap directory
) ELSE (
    echo Creating the bootstrap directory
    mkdir bootstrap
)

REM Change to the boostrap directory
cd bootstrap

REM Check if vcpkg is already clones to the bootstrap directory
IF EXIST "./vcpkg" (
    echo Found existing vcpkg installation
    echo Checking for vcpkg update
    cd vcpkg

    REM Pull the repo to check for updates
    git pull
) ELSE (
    echo Cloning vcpkg

    REM Clone the repo into the bootstrap directory
    git clone https://github.com/microsoft/vcpkg vcpkg
    cd vcpkg
)

REM Run the vcpkg bootstrap script to ensure it's up to date
echo Ensuring vcpkg is update to date
call bootstrap-vcpkg.bat

REM Add vcpkg command to the local path
SET PATH=%PATH%;%CD%
REM Set the vcpkg root to the boostrap directory for the rest of the script
set VCPKG_ROOT=%CD%

REM Move back to the boostrap directory
cd ..

REM Move back to the repository directory
cd ..


REM Install the vcpkg dependencies
echo Installing vcpkg dependencies

call dependencies.bat

echo Done installing packages!

echo Finished bootstraping project!
