tex: main.o texture.o
	g++ -o tex ./build/bases3d.o ./build/camera.o ./build/couleurRVB.o ./build/intersection.o ./build/lumiere.o\
	    ./build/main.o ./build/pixelmap.o ./build/plan.o ./build/ppm.o ./build/rayon.o ./build/sphere.o ./build/texture.o

ray: bases3d.o camera.o couleurRVB.o intersection.o lumiere.o main.o pixelmap.o plan.o ppm.o rayon.o sphere.o texture.o
	g++ -o ray ./build/bases3d.o ./build/camera.o ./build/couleurRVB.o ./build/intersection.o ./build/lumiere.o\
	    ./build/main.o ./build/pixelmap.o ./build/plan.o ./build/ppm.o ./build/rayon.o ./build/sphere.o ./build/texture.o

bases3d.o:
	g++ -c -std=c++17 src/bases3d.cpp -o ./build/bases3d.o

camera.o:
	g++ -c -std=c++17 src/camera.cpp -o ./build/camera.o

couleurRVB.o:
	g++ -c -std=c++17 src/couleurRVB.cpp -o ./build/couleurRVB.o

intersection.o:
	g++ -c -std=c++17 src/intersection.cpp -o ./build/intersection.o

lumiere.o:
	g++ -c -std=c++17 src/lumiere.cpp -o ./build/lumiere.o

main.o:
	g++ -c -std=c++17 src/main.cpp -o ./build/main.o

pixelmap.o:
	g++ -c -std=c++17 src/pixelmap.cpp -o ./build/pixelmap.o

plan.o:
	g++ -c -std=c++17 src/plan.cpp -o ./build/plan.o

ppm.o:
	g++ -c -std=c++17 src/ppm.cpp -o ./build/ppm.o

rayon.o:
	g++ -c -std=c++17 src/rayon.cpp -o ./build/rayon.o

sphere.o:
	g++ -c -std=c++17 src/sphere.cpp -o ./build/sphere.o

texture.o:
	g++ -c -std=c++17 src/texture.cpp -o ./build/texture.o



