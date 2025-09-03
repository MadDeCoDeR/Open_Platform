Open Platform Binaries for Users and Developers

This distribution contains both the binary files that are used for your game engine runtime (.dll/.so), 
and linker binaries that can allow your game engine to automatically load the runtime binaries for Windows (.lib),
alongside with a copy of the library's header files.

The library binaries can either be loaded automatically with the help  of the linker binaries, or manually with dllopen.

For Users, the only folder of interest you need is the 'bin' folder that contains the runtime binaries.


Mini FAQ:

Q: Why the library isn't fully static?
A: Because then it would beat the 2 main purposes of the library. 
The library 2 main purposes are either to be an abstraction layer for game store APIs (steam, gog, egs etc) and to allow GNU GPL game engines to use those APIs without violating their license