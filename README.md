# ls-js-value
A javascript/ecmascript implementation of native types: undefined, null, NaN, Infinity, boolean, number, string, array and object

To get/build/etc...:

1. `git clone` or download/unzip this project
2. `cd` to this project base directory
3. type `cmake .` -- don't forget the dot/period/full stop, you need that
4. type `make`

You can also cd to the test or sample directory and `cmake .; make` as well.

The samples directory has some basic usage examples, while the test directory has a gauntlet of tests to make sure the code functions correctly, it uses the library code statically and builds single applications with no library dependencies.

The code is without any documents or commenting, but the variable names are fairly destriptive so it is somewhat self-documenting.  I do have plans to comment the code in the near future.  It is well.. my excuse is that I wrote the code in a hurry.  however so that I do not have to reverse engineer my own code later I will documetn / comment it (I promise.)

Anyway, if you find it useful give a "hey yeah" or a "Thanks"

TODO:

1. [DONE] seperate out the header from the source
2. [DONE] add istream support
3. [DONE] finish casting for arrays and objects
4. implement json stringify and parse
5. add symbols
6. impliment iff file read and write support
7. add documentation and api reference
8. add jekyl site with examples and how to support this mini project


 
