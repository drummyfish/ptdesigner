# Procedural texture generator project
# Miloslav Ciz, 2012

CC=gcc
CFLAGS=-std=c99 -g -pedantic -Wall -Wextra
SOURCEDIR=sources

test: test.o colorbuffer.o lodepng.o proctextures.o matrix.o colortransition.o kdtree.o general.o linelist.o grammar.0
	$(CC) -lm -o test test.o colorbuffer.o lodepng.o proctextures.o matrix.o colortransition.o kdtree.o general.o linelist.o grammar.o

lodepng.o: $(SOURCEDIR)/lodepng.c $(SOURCEDIR)/lodepng.h
	$(CC) $(CFLAGS) -c -o lodepng.o $(SOURCEDIR)/lodepng.c

grammar.0: $(SOURCEDIR)/grammar.c $(SOURCEDIR)/grammar.h
	$(CC) $(CFLAGS) -c -o grammar.o $(SOURCEDIR)/grammar.c 

test.o: $(SOURCEDIR)/test.c $(SOURCEDIR)/colorbuffer.h $(SOURCEDIR)/general.h
	$(CC) $(CFLAGS) -c -o test.o $(SOURCEDIR)/test.c

colorbuffer.o: $(SOURCEDIR)/colorbuffer.c $(SOURCEDIR)/colorbuffer.h $(SOURCEDIR)/lodepng.h $(SOURCEDIR)/kdtree.h $(SOURCEDIR)/general.h
	$(CC) $(CFLAGS) -c -o colorbuffer.o $(SOURCEDIR)/colorbuffer.c

proctextures.o: $(SOURCEDIR)/proctextures.c $(SOURCEDIR)/proctextures.h $(SOURCEDIR)/colorbuffer.h $(SOURCEDIR)/colortransition.h
	$(CC) $(CFLAGS) -lm -c -o proctextures.o $(SOURCEDIR)/proctextures.c

matrix.o: $(SOURCEDIR)/matrix.h $(SOURCEDIR)/matrix.c
	$(CC) $(CFLAGS) -c -o matrix.o $(SOURCEDIR)/matrix.c

colortransition.o: $(SOURCEDIR)/colortransition.h $(SOURCEDIR)/colortransition.c
	$(CC) $(CFLAGS) -c -o colortransition.o $(SOURCEDIR)/colortransition.c

kdtree.o: $(SOURCEDIR)/kdtree.h $(SOURCEDIR)/kdtree.c $(SOURCEDIR)/general.h
	$(CC) $(CFLAGS) -c -o kdtree.o $(SOURCEDIR)/kdtree.c

general.o: $(SOURCEDIR)/general.h $(SOURCEDIR)/general.c
	$(CC) $(CFLAGS) -c -o general.o $(SOURCEDIR)/general.c

linelist.o: $(SOURCEDIR)/linelist.h $(SOURCEDIR)/linelist.c
	$(CC) $(CFLAGS) -c -o linelist.o $(SOURCEDIR)/linelist.c



