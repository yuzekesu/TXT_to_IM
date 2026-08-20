# How to Use
1. Create .txt file.
2. Write the coordinate of the vertex **each ROW** as float, seperate by spaces. You can add comment at the same row if you want, but put it after the coordinate.
3. Put an empty space or anything that contain no numbers.
4. Write the indices, add any comment you want with spaces between nearby indices. The program will check if the index is within the range or not.

# Data Structure
* Header
  1. number of vertices : uint64_t
  2. number of indices : uint64_t
* Body
  1. array of cordinate : {float x,y,z;} as vertices
  2. array of indices : uint32_t as indices
