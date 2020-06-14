# MinimalType

Will hopefully become a full on languge running on it's own mtvm byte code.


Instalation
===========

To install mt in your home directory run:
```
cd 
git clone https://github.com/ramsaycarslaw/minimaltype.git
```

then:
```
cd minimaltype
```

Finally, build with:
```
make
```

You can remove all of the .o files and the executable with:
```
make clean
```

To distribute the compiler everywhere on your system copy the executable `mtc` to `usr/local/bin`



Compiling
=========

To compile the mtvm assembley/byte code use:
```
./mtc build path/to/file
```
This will result in the creation of an `out.mtc` file which is the binary data. To see it's contents on a UNIX system run
```
xxd out.mtc
```

This will hex dump the contents of the file to the command line.







