CC := clang++
CFLAGS := -g -O0 --std=c++20

linux-cli: test_loot_generator.o
	${CC} ${CFLAGS} loot.o coinage.o treasure.o lootFactory.o \
	treasureGenerator.o test_loot_generator.o -o linux-cli.bin

test_loot_generator.o: tests/test_loot_generator.cpp treasureGenerator.o
	${CC} ${CFLAGS} -c tests/test_loot_generator.cpp

treasureGenerator.o: treasure.o lootFactory.o treasureGenerator.cpp
	${CC} ${CFLAGS} -c treasureGenerator.cpp

lootFactory.o: loot.o lootFactory.cpp
	${CC} ${CFLAGS} -c lootFactory.cpp

loot.o: loot.cpp
	${CC} ${CFLAGS} -c loot.cpp

coinage.o: coinage.cpp
	${CC} ${CFLAGS} -c coinage.cpp

treasure.o: coinage.o loot.o treasure.cpp
	${CC} ${CFLAGS} -c treasure.cpp

clean:
	rm -f linux-cli.bin
	rm -f *.o