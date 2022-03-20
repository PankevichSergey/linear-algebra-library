# linear algebra library



Mat class supports basic operations with matrices: concatenation, multiplication, addition, fast raising to a power, gaussian elimination, finding an inverse, a characteristic polynomial, determinant and trace. 

Matrices consist of Vectors that use Num class which is an implementation of a rational fraction, so any operations inside rational numbers field are done without loss of precision. 

Perm class supports permutations product, fast raising to power, finding sign of a permutation and its decomposition into cycles.

Poly class provides an interface that allows to multiply, add, read, write and compare polynomials.
