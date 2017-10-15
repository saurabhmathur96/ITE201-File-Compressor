## ITE201-File-Compressor
Project for ITE201: Object Oriented Programming Concepts

### Build instructions 

```g++ -std=c++11 LZWGlobals.cpp LZWCompressor.cpp LZWDecompressor.cpp LZWCodec.cpp main.cpp -o lzw```

### Usage

```
lzw -flag input_file output_file
```

where `flag` is either `-c` for compress or `-d` for decompress and `input_file` and `output_file` are distinct files

> Made by : Abishek Aditya, Saurabh Mathur & Tushar Bhatia

> data.html taken from http://www.w3.org/2000/07/8378/schemas/xhtml1-sample.xml
