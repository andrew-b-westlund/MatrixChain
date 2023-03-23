# MatrixChain
Software that will optimize the order of the multiplication of matrices.

In this program's main file, the dimensions of the matrices are set in an array, with the number of rows in the first matrix being the first array value, the number of columns in the first matrix (which will be inferred to be the number of rows in the second matrix) will be the second value of the array, and so on until the final value of the array is the number of columns in the final matrix. The program will compute which order of matrix multiplication would be optimal and prints out the order, i.e. (A1(A2A3)A4). It also calculates how many multiplications would be needed for that order of multiplication.

Input: None, the array of dimensions is set in the main. Future versions are planned to be set by the user.

Output: The order of the correct optimization of the matrix multiplication; The minimum total operations needed.

Compile: g++ newMatrixChainm.cpp -O2 -o mc

Execute: ./mc
