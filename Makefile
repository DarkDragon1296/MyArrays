CC = g++
CFLAGS = -c
LDFLAGS = -lwinmm
TARGET_FILE = SolveSquare.exe
TARGET_DIR = ./build/

all: setup

setup: main.o Menu.o StandArr.o OtherOperations.o TorusArr.o
	$(CC) $(TARGET_DIR)main.o $(TARGET_DIR)Menu.o $(TARGET_DIR)StandArr.o $(TARGET_DIR)OtherOperations.o $(TARGET_DIR)TorusArr.o -o $(TARGET_FILE)
	mv $(TARGET_FILE) $(TARGET_DIR)

main.o: main.cpp Menu.h StandArr.h TorusArr.h OtherOperations.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) main.cpp
	mv main.o $(TARGET_DIR)

Menu.o: Menu.cpp Menu.h OtherOperations.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) Menu.cpp
	mv Menu.o $(TARGET_DIR)

StandArr.o: StandArr.cpp StandArr.h OtherOperations.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) StandArr.cpp
	mv StandArr.o $(TARGET_DIR)

OtherOperations.o: OtherOperations.cpp OtherOperations.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) OtherOperations.cpp
	mv OtherOperations.o $(TARGET_DIR)

TorusArr.o: TorusArr.cpp TorusArr.h OtherOperations.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) TorusArr.cpp
	mv TorusArr.o $(TARGET_DIR)

run:
	$(TARGET_DIR)$(TARGET_FILE)

clean:
	rm -f $(TARGET_DIR)*.o $(TARGET_DIR)$(TARGET_FILE)

.PHONY: clean all setup