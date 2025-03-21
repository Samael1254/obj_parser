## OBJ file parser
A simple parser for .obj files.

### Description and purpose
.obj is a file format to store mesh data, in order to process or render meshes.
This program is not useful on its own, it simply parses the .obj file into a mesh structure and prints the result on the standard output.
The code is therefore meant to be used in other programs.
The printing functions contained in the program can also be used to write an .obj file from mesh data, by either redirecting the output to a file or modifying the code to write the data on a file passed as parameter.

### Features
So far, the parser only recognizes the following elements :
- vertices ("v")
- vertex normals ("vn")
- vertex texture coordinates ("vt")
- Faces ("f"), only containing three vertices so far

### Usage
To compile the program, simply type `make` in the repository.
To use the program, pass the file path of the .obj file as an argument like so :
```./obj_parser myfile.obj```
