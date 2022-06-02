CC := clang++
CFLAGS := -g -O0 --std=c++20
# WCC := x86_64-w64-mingw32-g++-win32
# WFLAGS := --static
INCLUDE := -I src/include

# all: linux-cli win-cli

linux-cli: test_loot_generator.o
	${CC} ${CFLAGS} loot.o coinage.o treasure.o lootFactory.o \
	treasureGenerator.o test_loot_generator.o dice.o \
	-o bin/lootGen-cli.bin

# win-cli: test_loot_generator-win.o
# 	${WCC} ${CFLAGS} ${WFLAGS} loot-win.o coinage-win.o treasure-win.o \
# 	lootFactory-win.o treasureGenerator-win.o test_loot_generator-win.o \
# 	dice-win.o -o bin/lootGen-cli.exe

test_loot_generator.o: tests/test_loot_generator.cpp \
                           treasureGenerator.o
	${CC} ${CFLAGS} -c tests/test_loot_generator.cpp ${INCLUDE}

treasureGenerator.o: treasure.o lootFactory.o dice.o src/treasureGenerator.cpp
	${CC} ${CFLAGS} -c src/treasureGenerator.cpp ${INCLUDE}

lootFactory.o: loot.o dice.o coin.o src/lootFactory.cpp
	${CC} ${CFLAGS} -c src/lootFactory.cpp ${INCLUDE}

loot.o: src/loot.cpp
	${CC} ${CFLAGS} -c src/loot.cpp ${INCLUDE}

coin.o: loot.o src/coin.cpp
	${CC} ${CFLAGS} -c src/coin.cpp ${INCLUDE}

gemstone.o: loot.o src/gemstone.cpp
	${CC} ${CFLAGS} -c src/gemstone.cpp ${INCLUDE}

art.o: loot.o src/art.cpp
	${CC} ${CFLAGS} -c src/art.cpp ${INCLUDE}

coinage.o: coin.o src/coinage.cpp
	${CC} ${CFLAGS} -c src/coinage.cpp ${INCLUDE}

treasure.o: coinage.o loot.o src/treasure.cpp
	${CC} ${CFLAGS} -c src/treasure.cpp ${INCLUDE}

dice.o: src/dice.cpp
	${CC} ${CFLAGS} -c src/dice.cpp ${INCLUDE}


# test_loot_generator-win.o: tests/test_loot_generator.cpp \
#                            treasureGenerator-win.o
# 	${WCC} ${CFLAGS} ${WFLAGS} -c tests/test_loot_generator.cpp \
# 	-o test_loot_generator-win.o

# treasureGenerator-win.o: treasure-win.o lootFactory-win.o dice-win.o \
#                          src/treasureGenerator.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/treasureGenerator.cpp \
# 	-o treasureGenerator-win.o

# lootFactory-win.o: loot-win.o dice-win.o src/lootFactory.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/lootFactory.cpp \
# 	-o lootFactory-win.o

# loot-win.o: src/loot.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/loot.cpp -o loot-win.o

# coinage-win.o: src/coinage.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/coinage.cpp -o coinage-win.o

# treasure-win.o: coinage-win.o loot-win.o src/treasure.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/treasure.cpp -o treasure-win.o

# dice-win.o: src/dice.cpp
# 	${WCC} ${CFLAGS} ${WFLAGS} -c src/dice.cpp -o dice-win.o

clean:
	rm -f *.o