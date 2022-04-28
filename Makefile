CC := clang++
CFLAGS := -g -O0 --std=c++20
WCC := x86_64-w64-mingw32-g++-win32
WFLAGS := --static

all: test_loot_generator.o test_loot_generator-win.o

linux-cli: test_loot_generator.o
	${CC} ${CFLAGS} loot.o coinage.o treasure.o lootFactory.o \
	treasureGenerator.o test_loot_generator.o dice.o \
	-o lootGen-linux-cli.bin

win-cli: test_loot_generator-win.o
	${WCC} ${CFLAGS} ${WFLAGS} loot-win.o coinage-win.o treasure-win.o \
	lootFactory-win.o treasureGenerator-win.o test_loot_generator-win.o \
	dice-win.o -o lootGen-win-cli.exe

test_loot_generator.o: tests/test_loot_generator.cpp \
                           treasureGenerator.o
	${CC} ${CFLAGS} -c tests/test_loot_generator.cpp

treasureGenerator.o: treasure.o lootFactory.o dice.o treasureGenerator.cpp
	${CC} ${CFLAGS} -c treasureGenerator.cpp

lootFactory.o: loot.o dice.o lootFactory.cpp
	${CC} ${CFLAGS} -c lootFactory.cpp

loot.o: loot.cpp
	${CC} ${CFLAGS} -c loot.cpp

coinage.o: coinage.cpp
	${CC} ${CFLAGS} -c coinage.cpp

treasure.o: coinage.o loot.o treasure.cpp
	${CC} ${CFLAGS} -c treasure.cpp

dice.o: dice.cpp
	${CC} ${CFLAGS} -c dice.cpp

test_loot_generator-win.o: tests/test_loot_generator.cpp \
                           treasureGenerator-win.o
	${WCC} ${CFLAGS} ${WFLAGS} -c tests/test_loot_generator.cpp \
	-o test_loot_generator-win.o

treasureGenerator-win.o: treasure-win.o lootFactory-win.o dice-win.o \
                         treasureGenerator.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c treasureGenerator.cpp \
	-o treasureGenerator-win.o

lootFactory-win.o: loot-win.o dice-win.o lootFactory.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c lootFactory.cpp \
	-o lootFactory-win.o

loot-win.o: loot.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c loot.cpp -o loot-win.o

coinage-win.o: coinage.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c coinage.cpp -o coinage-win.o

treasure-win.o: coinage-win.o loot-win.o treasure.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c treasure.cpp -o treasure-win.o

dice-win.o: dice.cpp
	${WCC} ${CFLAGS} ${WFLAGS} -c dice.cpp -o dice-win.o

clean:
	rm -f *.o