CC := clang++
CFLAGS := -g -O0 --std=c++20
# WCC := x86_64-w64-mingw32-g++-win32
# WFLAGS := --static
INCLUDE := -I src/include

# all: linux-cli win-cli

linux-cli: main.o
	${CC} ${CFLAGS} loot.o coinage.o treasure.o lootFactory.o \
	treasureGenerator.o main.o dice.o \
	art.o gemstone.o magicItem.o coin.o \
	-o bin/lootGen-cli.bin ${INCLUDE}

main.o: src/main.cpp treasureGenerator.o
	${CC} ${CFLAGS} -c src/main.cpp ${INCLUDE}

treasureGenerator.o: treasure.o lootFactory.o dice.o gemstone.o art.o magicItem.o \
                     src/treasureGenerator.cpp
	${CC} ${CFLAGS} -c src/treasureGenerator.cpp ${INCLUDE}

lootFactory.o: loot.o dice.o coin.o gemstone.o art.o magicItem.o src/lootFactory.cpp
	${CC} ${CFLAGS} -c src/lootFactory.cpp ${INCLUDE}

loot.o: src/loot.cpp
	${CC} ${CFLAGS} -c src/loot.cpp ${INCLUDE}

coin.o: loot.o src/coin.cpp
	${CC} ${CFLAGS} -c src/coin.cpp ${INCLUDE}

gemstone.o: loot.o src/gemstone.cpp
	${CC} ${CFLAGS} -c src/gemstone.cpp ${INCLUDE}

art.o: loot.o src/art.cpp
	${CC} ${CFLAGS} -c src/art.cpp ${INCLUDE}

magicItem.o: loot.o src/magicItem.cpp
	${CC} ${CFLAGS} -c src/magicItem.cpp ${INCLUDE}

coinage.o: coin.o src/coinage.cpp
	${CC} ${CFLAGS} -c src/coinage.cpp ${INCLUDE}

treasure.o: coinage.o loot.o art.o gemstone.o magicItem.o src/treasure.cpp
	${CC} ${CFLAGS} -c src/treasure.cpp ${INCLUDE}

dice.o: src/dice.cpp
	${CC} ${CFLAGS} -c src/dice.cpp ${INCLUDE}

clean:
	rm -f *.o