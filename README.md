## OBJ file parser library
A simple C library to parse .obj files.

### Description and purpose
.obj is a file format to store mesh data, in order to process or render meshes.
This library provides functions to parse, load, print or save .obj files thanks to a common mesh structure.

### Features
So far, the parser only recognizes the following elements :
- vertices ("v")
- vertex normals ("vn")
- vertex texture coordinates ("vt")
- Faces ("f"), only containing three vertices so far
All the other elements are ignored

### Usage
To use the library, you can either build it from source with `make`, or download the precompiled archive.
You then have to link it to your program when compiling with the `-lobjParser` flag.
More information on how to use static libraries in your C programs [here](https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b).

### FUTURE IMPROVEMENTS
- Triangulate polygons
- Parse .mtl files
- Handle negative indices
- Handle groups ("g")
- Handle objects ("o")
