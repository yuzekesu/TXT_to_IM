# How to Use
1. Create .txt file.
2. Write the coordinate of the vertex **each ROW** as float (the x, y and z), seperate by spaces. You can add comment at the same row if you want, but put it after the coordinate.
3. Put an empty space or anything that contain no numbers.
4. Write the indices, add any comment you want with spaces between nearby indices. The program will check if the index is within the range or not.
5. Drag the .txt onto the .exe OR open the .txt with the .exe to create the .im file.
6. When reading/using the generated .im, make sure your own program read the .im with the following data structure in mind.

# Data Structure of the .im file
* Header
  1. number of the vertices : uint64_t
  2. number of the indices : uint64_t
* Body
  1. array of the coordinate : {float x,y,z;} as vertices
  2. array of the indices : uint32_t as indices

# Example of a .txt file
```
1.0 2.0 3.f hi I am the comment
1.0 2.f 1.0          or like this
3.f 2.0 1.0  // or like this
5 5 5
LineBreak

The indices starts here haha
1 2 haha 
3
```
