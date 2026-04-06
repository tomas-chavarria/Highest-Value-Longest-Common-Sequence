# Programming Assignment 3
Name: Tomas Chavarria<br>
UFID: 53391675

SOLUTIONS TO THE WRITTEN COMPONENT ARE FOUND IN THE DATA SUBFOLDER IN THE `report.md` FILE.

## Compile / Run Instructions
The program will take in .txt files that are formatted as follows [See `examples` folder for further guidance]:

```
K
x1 v1
x2 v2
...
xK vK
A
B
```

Where:
- $K$ is the number of characters in the alphabet.
- Each of the next $K$ lines contains a character and its value.
- $A$ is the first string.
- $B$ is the second string.

To compile on Linux and MacOS systems, use the build.sh script file found in the build folder. For Windows, use the build.ps1 powershell script file. Each will generate an executable file within the bin folder.

To run the script files, use the following commands:<br>

Windows (Powershell): `powershell -ExecutionPolicy Bypass -File .\build.ps1`<br>
Linux / MacOS: `./build.sh`

After compilation, the user must use the generated executable to parse an input file. The input file MUST be in the run-io directory. The format for this is os-independent, simply run:<br>

```.\hvcls.exe <input file>``` (Where \<input file\> is the name of the input file)

The filename can either be input with the "..\run-io\\" prefix or this can be omitted. However, as specified before, the code will not detect a file if not within the run-io directory. This is intentional behavior to prevent clutter. If attempting to run an example file, please copy it into the run-io directory.


## Assumptions
Input file correctly placed in the `run-io` directory.

`g++` installed as the compiler, and the file format follows that specified in the run instructions

## Known Issues
- No apparent issues
