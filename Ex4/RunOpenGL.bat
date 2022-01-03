
REM
echo "Running \m"
g++ -c -o main.o 4a.cpp -I\"C:\msys64\mingw64\include"
cls
echo "Compiling Graphic"
g++ -o main.exe  main.o -L\"C:\msys64\mingw64\lib\x64 -lopengl32 -lglu32 -lfreeglut
cls
echo "App Running"
main.exe