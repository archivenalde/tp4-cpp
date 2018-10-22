CC = g++
CCFLAGS= -Wall -pedantic -g -std=c++11
DFLAGS= -Wall -pedantic -ggdb -O0
EXTC = cpp
EXTH = h
EXECUTABLE = tp2.exe
EXECUTABLE_DEBUG = tp2_debug.exe

SRC = $(wildcard *.$(EXTC))
HDR = $(wildcard *.$(EXTH))
OBJ = $(SRC:.$(EXTC)=.o)
DOBJ = $(SRC:.$(EXTC)=.od)

.PHONY: all vars clean debug

all: $(EXECUTABLE)

debug: $(EXECUTABLE_DEBUG)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

$(EXECUTABLE_DEBUG): $(DOBJ)
	$(CC) $(DFLAGS) -o $@ $^

main.o: main.$(EXTC)
	$(CC) $(CCFLAGS) -o $@ -c $<

%.o: %.$(EXTC) %.$(EXTH)
	$(CC) $(CCFLAGS) -o $@ -c $<

main.od: main.$(EXTC)
	$(CC) $(DFLAGS) -g -o $@ -c $<

%.od: %.$(EXTC) %.$(EXTH)
	$(CC) $(DFLAGS) -g -o $@ -c $<

%.od: %.$(EXTC)
	$(CC) $(DFLAGS) -g -o $@ -c $<

vars:
	echo $(SRC)
	echo $(HDR)
	echo $(OBJ)
	echo $(DOBJ)

clean:
	rm -rf *.o
	rm -rf *.od
	rm -f $(EXECUTABLE)
	rm -f $(EXECUTABLE_DEBUG)
