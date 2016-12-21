CPP=g++ --std=c++11 -Wall

all: Projet


Projet: Main.cpp Jeu.hpp Plateau.hpp Plateau.hpp QuaranteHuit.cpp QuaranteHuitimpaire.cpp Taquin.cpp
	$(CPP) -o $@ $^

clean: 
	rm -rf Projet
