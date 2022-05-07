# LootGenerator-5e
A simple loot generator for DnD 5e

Once all treasure generation is complete I intend to implement a GUI interface in GTK3 or electron, I haven't yet decided.

## Compilation instructions

Clone the repo
Ensure basic dev environment is running and clang is installed, for cross compiliation
install miniGW.

Ubuntu
```
sudo apt install build-essential clang mingw-w64
```

build the project (for both windows and linux targets)
```
make -j 4
```