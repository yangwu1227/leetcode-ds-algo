# Set Matrix Zeroes

Given an $m \times n$ integer `matrix`, if an element is 0, set its entire row and column to 0's. 

## Explanation 0(1) Space Solution

Initialize:

* `m` as the number of rows
* `n` as the number of columns
* `first_row_zero` as `False`
* `first_col_zero` as `False`

### Check If First Row and Column Contain Any Zero

```
[
  [1, 2, 3],
  [4, 0, 6],
  [7, 8, 9]
]
```

#### First Row

<center>

| `col` | Element | `first_row_zero` |
|-------|---------|------------------|
| 0     | 1       | False            |
| 1     | 2       | False            |
| 2     | 3       | False            |

</center>

#### First Column

<center>

| `row` | Element | `first_col_zero` |
|-------|---------|------------------|
| 0     | 1       | False            |
| 1     | 4       | False            |
| 2     | 7       | False            |

</center>

### Mark Rows and Columns for Zero

```
[
  [1, 2, 3],
  [4, 0, 6],
  [7, 8, 9]
]
```

* For `row = 1`, iterate over the columns starting from the second column:

<center>

| `col` | Element | Is Zero? | Action |
|-------|---------|----------|--------|
| 1     | 0       | True     | * Set `matrix[1][0] = 4` to 0 <br> * Set `matrix[0][1] = 2` to 0 |
| 2     | 6       | False    | No action |

</center>

* For `row = 2`, iterate over the columns starting from the second column:

<center>

| `col` | Element | Is Zero? | Action |
|-------|---------|----------|--------|
| 1     | 8       | False    | No action |
| 2     | 9       | False    | No action |

</center>

After the loop, the matrix is:

```
[
  [1, 0, 3],
  [0, 0, 6],
  [7, 8, 9]
]
```

This effectively marked the rows and columns that need to be set to zero. In this case, the row marked to be zeroed is `[0, 0, 6]` and the column marked to be zeroed is `[0, 0, 8]`.

### Zero Rows and Columns Based on Marks

#### Zero Columns

Fixing `col = 0`, iterate `row` over `1, 2`:

<center>

| `row` | Element | Is Zero? | Action |
|-------|---------|--------|--------|
| 1     | `matrix[1][0] = 0` | Yes | Set `matrix.row(1) = [0, 0, 6]` to all zeros |
| 2     | `matrix[2][0] = 7` | No | No action |

</center>

After zeroing the columns, the matrix is:

```
[
  [1, 0, 3],
  [0, 0, 0],
  [7, 8, 9]
]
```

#### Zero Rows

Fixing `row = 0`, iterate `col` over `1, 2`:

<center>

| `col` | Element | Is Zero? | Action |
|-------|---------|--------|--------|
| 1    | `matrix[0][1] = 0` | Yes | Set `matrix.col(1) = [0, 0, 8]` to all zeros |
| 2    | `matrix[0][2] = 3` | No | No action |

</center>

After zeroing the rows, the matrix is:

```
[
  [1, 0, 3],
  [0, 0, 0],
  [7, 0, 9]
]
```

For this example, this completes the zeroing of the rows and columns.

### Zero First Row and Column If Necessary

Since both `first_row_zero` and `first_col_zero` are `False`, no action is needed in this case. However, if either of them were `True`, the first row or column would be zeroed.

## Time Complexity

### First Two Loops

```c++
for (int col = 0; col < n; col++)
{
    if (matrix(0, col) == 0)
    {
        firstRowZero = true;
        break;
    }
}
for (int row = 0; row < m; row++)
{
    if (matrix(row, 0) == 0)
    {
        firstColZero = true;
        break;
    }
}
```

In the worst case, i.e. no zero elements in the first row and column at all or not until the last elements, these first two loops will run in $O(m + n)$ time.

### Nested Loop

```c++
for (int row = 1; row < m; row++)
{
    for (int col = 1; col < n; col++)
    {
        if (matrix(row, col) == 0)
        {
            matrix(row, 0) = 0;
            matrix(0, col) = 0;
        }
    }
}
```

The nested loop starts from the second row and second column, and runs in $O((m-1) \times (n-1))$ time. We can consider this $O(m \times n)$ time.

### Zeroing Rows and Columns

```c++
for (int row = 1; row < m; row++)
{
    if (matrix(row, 0) == 0)
    {
        matrix.row(row).setZero();
    }
}

for (int col = 1; col < n; ++col)
{
    if (matrix(0, col) == 0)
    {
        matrix.col(col).setZero();
    }
}
```

The operations done inside each iteration of these loops, i.e., `matrix.row(row).setZero()` and `matrix.col(col).setZero()`, run in $O(n)$ and $O(m)$ times, respectively. Therefore, the total time complexities for these two loops are:

* $O((m - 1) \times n) = O(m \times n)$ 
* $O(m \times (n - 1)) = O(m \times n)$  

### Zero First Row and Column If Necessary

```c++
if (firstRowZero)
{
    matrix.row(0).setZero();
}
if (firstColZero)
{
    matrix.col(0).setZero();
}
```

These last two loops are not run if `firstRowZero` and `firstColZero` are `False`. If we consider the worst case, i.e., both `firstRowZero` and `firstColZero` are `True`, the time complexity is $O(m + n)$. 

### Total Time Complexity

The total time complexity can be roughly modeled as:

$$
\begin{align*}
O\Big[\big[m + n\big] + \big[(m - 1) \cdot (n - 1)\big] + \big[(m - 1) \cdot n\big] + \big[(n - 1) \cdot m\big] + \big[m + n\big]\Big]&= O(2m + 2n + 3 \cdot (m \times n)) \\
&= O(m + n + m \times n) \\
&= O(m \times n)
\end{align*}
$$

## Space Complexity

The space complexity is $O(1)$ because we are modifying the input matrix in place.

---

# Random Flip Matrix

Given a `m x n` binary grid matrix with all the values set 0 initially. Design an algorithm to randomly pick an index `(i, j)` where `matrix[i][j] == 0` and flips it to 1. After each flip, all the remaining (available) indices `(i, j)` where `matrix[i][j] == 0` should be equally likely to be returned.

## Explanation

Consider a binary matrix of size `m x n` where $m = 3$ and $n = 3$:

```plaintext
[
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]
```

### 1D to 2D Index 

Given a 1D index `index` $\in \{0,..., \text{index}, ..., (m \cdot n) - 1\}$, we can convert it to a 2D index `(i, j)` $\forall i \in \{0, ..., m - 1\}, j \in \{0, ..., n - 1\}$ as follows:

#### C++

```c++
int i = index / n;
int j = index % n;
```

#### Python

```python
i = index // n
j = index % n
```

1. Row Index Calculation (i):

    - Given `index`, when divided by the number of columns $n$, the quotient $i=\text{Floor}[\frac{\text{index}}{n}]$ represents the row index.

    - This works because each complete row contains exactly $n$ elements.

    - Therefore, the row index $i$ is the number of complete rows before reaching `index` $\in \{0,..., \text{index}, ..., m \cdot n\}$.

2. Column Index Calculation $(j)$:

    - Given `index`, the remainder $j=\text{index}$ $\%$ (modulus) $n$ represents the column index.

    - This works because the remainder after dividing `index` by $n$ is the position within the current (incomplete) row.

    - Therefore, the column index $j$ is the position within the row after accounting for all complete rows before `index`.

#### Mapping 1D to 2D Index

Given the matrix and $m = 3$ and $n = 3$:

```plaintext
[
  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8]
]
```

<center>

| 1D Index | 2D Index |
|----------|----------|
| 0        | `(0 // 3, 0 \% 3) = (0, 0)` |
| 1        | `(1 // 3, 1 \% 3) = (0, 1)` |
| 2        | `(2 // 3, 2 \% 3) = (0, 2)` |
| 3        | `(3 // 3, 3 \% 3) = (1, 0)` |
| 4        | `(4 // 3, 4 \% 3) = (1, 1)` |
| 5        | `(5 // 3, 5 \% 3) = (1, 2)` |
| 6        | `(6 // 3, 6 \% 3) = (2, 0)` |
| 7        | `(7 // 3, 7 \% 3) = (2, 1)` |
| 8        | `(8 // 3, 8 \% 3) = (2, 2)` |

</center>

### Algorithm Walkthrough 

* **m** = 3
* **n** = 3
* **total** = 9
* **available indices** = 9
* **map** = {}

<center>

| action | indices pool       | random index | available indices | index to flip | current flipped indices    | 2D index |
|--------|--------------------|--------------|-------------------|---------------|----------------------------|----------|
| flip   | [0, 1, 2, 3, 4, 5, 6, 7, 8] | 1            | 8                 | {}.get(1, 1) = 1             | map[1] = map.get(8, 8) = 8 -> {1: 8} | 1 = [0, 1]   |
| flip   | [0, 1, 2, 3, 4, 5, 6, 7]    | 5            | 7                 | {1: 8}.get(5, 5) = 5         | map[5] = map.get(7, 7) = 7 -> {1: 8, 5: 7} | 5 = [1, 2]   |
| flip   | [0, 1, 2, 3, 4, 5, 6]       | 5            | 6                 | {1: 8, 5: 7}.get(5, 5) = 7   | map[5] = map.get(6, 6) = 6 -> {1: 8, 5: 6} | 7 = [2, 1]   |
| flip   | [0, 1, 2, 3, 4, 5]          | 2            | 5                 | {1: 8, 5: 6}.get(2, 2) = 2   | map[2] = map.get(5, 5) = 6 -> {1: 8, 5: 6, 2: 6} | 2 = [0, 2]   |
| flip   | [0, 1, 2, 3, 4]             | 4            | 4                 | {1: 8, 5: 6, 2: 6}.get(4, 4) = 4 | map[4] = map.get(4, 4) = 4 -> {1: 8, 5: 6, 2: 6, 4: 4} | 4 = [1, 1]   |
| flip   | [0, 1, 2, 3]                | 2            | 3                 | {1: 8, 5: 6, 2: 6, 4: 4}.get(2, 2) = 6 | map[2] = map.get(3, 3) = 3 -> {1: 8, 5: 6, 2: 3, 4: 4} | 6 = [2, 0]   |
| flip   | [0, 1, 2]                   | 2            | 2                 | {1: 8, 5: 6, 2: 3, 4: 4}.get(2, 2) = 3 | map[2] = map.get(2, 2) = 3 -> {1: 8, 5: 6, 2: 3, 4: 4} | 3 = [1, 0]   |
| flip   | [0, 1]                      | 1            | 1                 | {1: 8, 5: 6, 2: 3, 4: 4}.get(1, 1) = 8 | map[1] = map.get(1, 1) = 8 -> {1: 8, 5: 6, 2: 3, 4: 4} | 8 = [2, 2]   |
| flip   | [0]                         | 0            | 0                 | {1: 8, 5: 6, 2: 3, 4: 4}.get(0, 0) = 0 | map[0] = map.get(0, 0) = 0 -> {1: 8, 5: 6, 2: 3, 4: 4, 0: 0} | 0 = [0, 0]   |
| reset  | NA                          | NA           | 9                 | NA            | {}                         | NA       |
| flip   | [0, 1, 2, 3, 4, 5, 6, 7, 8] | 1            | 8                 | {}.get(1, 1) = 1             | map[1] = map.get(8, 8) = 8 -> {1: 8} | 1 = [0, 1]   |

</center>

## Time Complexity

The time complexity for each flip is $O(1)$. Regardless of the inputs $m$ and $n$, the same amount of work is done inside the `flip` method or member function to:

1. Generate a random index in $O(1)$

2. Decrement the count of available indices in $O(1)$

3. Look up the random index in the map in $O(1)$

4. Insert (hash) the random index to create a index to index mapping in $O(1)$

5. Convert the 1D index to a 2D index in $O(1)$

## Space Complexity

The space complexity is $O(m \times n)$ to store the mapping of indices. This is because, in the worst case where each generation of random indices is unique, the map will contain all the indices from $0$ to $(m \cdot n) - 1$ as keys.

For examples, given a $3 \times 3$ matrix, the map will contain the following mappings in an arbitrary order:

```plaintext
{8: 0, 5: 3, 0: 8, 7: 1, 4: 4, 2: 6, 6: 2, 1: 7, 3: 5}
```

---

# Sum of Matrix After Queries

Given an integer `n` and a 0-indexed 2D array queries where `queries[i] = [type_i, index_i, val_i]`, design a algorithm that finds the sum of the matrix after applying all `queries`. Initially, all values of the `n x n` matrix are initialized to 0's. For each query:

* If `type_i == 0`, set the values in the row with `index_i` to `val_i`, overwriting any previous values
* If `type_i == 1`, set the values in the column with `index_i` to `val_i`, overwriting any previous values

## Explanation

Given the matrix size `n = 3` and the queries `[[0, 0, 1], [1, 2, 3], [1, 2, 2], [0, 2, 3], [1, 0, 4]]`:

<center>

| **Type** | **Index** | **Value** | **Visited** | **Cells Left to Modify** | **Matrix Sum** |
|----------|-----------|-----------|-------------|--------------------------|----------------|
| NA       | NA        | NA        | - **columns_visited** = {}<br> - **rows_visited** = {} | - **vertical_cells_left_to_modify** = 3<br> - **horizontal_cells_left_to_modify** = 3 | **matrix_sum** = 0 |
| 1        | 0         | 4         | - **columns_visited** = {0}<br> - **rows_visited** = {} | - **vertical_cells_left_to_modify** = 3<br> - **horizontal_cells_left_to_modify** = 2 | **matrix_sum** += (vertical cells = 3) x (val = 4) = 12 |
| 0        | 2         | 3         | - **columns_visited** = {0}<br> - **rows_visited** = {2} | - **vertical_cells_left_to_modify** = 2<br> - **horizontal_cells_left_to_modify** = 2 | **matrix_sum** += (horizontal cells = 2) x (val = 3) = 18 |
| 1        | 2         | 2         | - **columns_visited** = {0, 2}<br> - **rows_visited** = {2} | - **vertical_cells_left_to_modify** = 2<br> - **horizontal_cells_left_to_modify** = 1 | **matrix_sum** += (vertical cells = 2) x (val = 2) = 22 |
| 1        | 2         | 3         | - **columns_visited** = {0, 2}<br> - **rows_visited** = {2} | Skip because column 2 already visited | Skip because column 2 already visited |
| 0        | 0         | 1         | - **columns_visited** = {0, 2}<br> - **rows_visited** = {2, 0} | - **vertical_cells_left_to_modify** = 1<br> - **horizontal_cells_left_to_modify** = 1 | **matrix_sum** += (horizontal cells = 1) x (val = 1) = 23 |

</center>

## Time Complexity

Let $q$ be the number of queries and $n$ be the size of the matrix. The operations done inside each iteration of the queries are as follows:

* Check if `type` is `0` or `1` in $O(1)$

* Look up the row or column index in the visited set in $O(1)$

* Update the `matrix_sum` in $O(1)$

* Decrement the count of cells left to modify in $O(1)$

* Insert (hash) the row or column index in the visited set in $O(1)$

As can be seen, all operations are independent of the matrix dimensions $n \times n$. Therefore, the overall time complexity linear, $O(q)$, with respect to the number of queries.

## Space Complexity

Considering only the most significant memory usage (i.e., ignoring the use of integer variables), we use $O(2n) = O(n)$ space to store the visited rows and columns sets; this is becuase, in the worst case, all rows and columns are visited at least once.

---

# Sparse Matrix Multiplication

Given two sparse matrices `A` and `B` in their dense representations, design an algorithm to efficiently multiply them. The result should be returned in the dense representation. 

In Python, the sparse matrices are represented as lists of lists:

```python
A = [[1, 0, 0],
     [-1, 0, 3]]

B = [[7, 0, 0],
     [0, 0, 0],
     [0, 0, 1]]
```

In C++, the sparse matrices are represented as vectors of vectors:

```c++
std::vector<std::vector<double>> A = {{1.0, 0.23, 0.43},
                                      {-1.45, 0.3, 3.0}};

std::vector<std::vector<double>> B = {{7.0, 0.0, 0.0},
                                      {0.0, 0.0, 0.0},
                                      {0.0, 0.0, 1.0}};
```

## Explanation

When two matrices, `A` ($m \times k$) and `B` ($k \times n$), are multiplied, the result is a matrix `C` ($m \times n$). Each element $c_{ij}$ of `C` is computed as the dot product of the $i$-th row of `A` and the $j$-th column of `B`:

$$
\begin{align*}
C[i][j] = \sum_{t=0}^{k-1} A[i][t] \times B[t][j]
\end{align*}
$$

Note that $t$ is the dimension of the row space of `A` and the column space of `B`.

### Dictionary of Keys (DOK) Format

To handle sparse matrices, we can optimize the multiplication by skipping multiplication and addition operations for elements $c_{ij}$ that would be zeros anyways. This can be done by first converting the dense matrices `A` and `B` to dictionary of keys (DOK) format. In DOK format, we store the indices $(i, j)$ of non-zero elements as keys and their cell values as values of a dictionary.

To check our implementation, we compare our output matrix against those of the reference implementations in Python and C++.

#### Python

In Python, the `scipy.sparse.dok_matrix` class, which is a subclass of the `dict` class, implements the DOK format.

#### C++

The `Eigen::SparseMatrix` class in C++ can be used to represent sparse matrices; however, the underlying implementation of `Eigen::SparseMatrix` is actually a versatile variant of the widely-used compressed column (or row) storage scheme.

### Algorithm Walkthrough

Given the matrices `A` and `B`:

```python   
A = [[1, 0, 0],
     [-1, 0, 3]]

B = [[7, 0, 0],
     [0, 0, 0],
     [0, 0, 1]]
```

The sparse matrices `A` and `B` in DOK format are:

```python
A = {(0, 0): 1, (1, 0): -1, (1, 2): 3}
B = {(0, 0): 7, (2, 2): 1}
```

#### First Non-Zero Element of `A`

* Initialize `row_idx = 0`
* Initialize `common_idx = 0`
* Initialize `value = 1`

Given the row index `row_idx = 0`, the question is: what are the relevant cell values in `B` that need to be multiplied with this non-zero element in `A[row_idx, common_idx]`? 

Because each row in `A` is dotted with each column in `B`, with the element from `A` being fixed, the cell value `A[0, 0] = 1` contributes to three different dot products:

1. Row 0 of `A` dotted with column 0 of `B` to compute the element at `C[0, 0]`:

$$
\begin{bmatrix}
\textcolor{red}{1} \\
0 \\
0
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{7} \\
0 \\
0
\end{bmatrix} = 1 \times 7 = 7
$$

2. Row 0 of `A` dotted with column 1 of `B` to compute the element at `C[0, 1]`:

$$
\begin{bmatrix}
\textcolor{red}{1} \\
0 \\
0
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{0} \\
0 \\
0
\end{bmatrix} = 1 \times 0 = 0
$$

3. Row 0 of `A` dotted with column 2 of `B` to compute the element at `C[0, 2]`:

$$
\begin{bmatrix}
\textcolor{red}{1} \\
0 \\
0
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{0} \\
0 \\
1
\end{bmatrix} = 1 \times 0 = 0
$$

<center>

| col_idx | B[common_idx, col_idx] | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[0, 0] = 7$                 | Yes       | - $A[0, 0] \times B[0, 0] = 1 \times 7 = 7$ <br> - Update $C[0, 0] = 7$ |
| 1               | $B[0, 1] = 0$                 | No        | Skip multiplication |
| 2               | $B[0, 2] = 0$                 | No        | Skip multiplication |

</center>

#### Second Non-Zero Element of `A`

* Initialize `row_idx = 1`
* Initialize `common_idx = 0`
* Initialize `value = -1`

The second non-zero element in `A` is $A[1, 0] = -1$. This element contributes to the following dot products:

1. Row 1 of `A` dotted with column 0 of `B` to compute the element at `C[1, 0]`:

$$
\begin{bmatrix}
\textcolor{red}{-1} \\
0 \\
3
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{7} \\
0 \\
0
\end{bmatrix} = -1 \times 7 = -7
$$

2. Row 1 of `A` dotted with column 1 of `B` to compute the element at `C[1, 1]`:

$$
\begin{bmatrix}
\textcolor{red}{-1} \\
0 \\
3
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{0} \\
0 \\
0
\end{bmatrix} = -1 \times 0 = 0
$$

3. Row 1 of `A` dotted with column 2 of `B` to compute the element at `C[1, 2]`:

$$
\begin{bmatrix}
\textcolor{red}{-1} \\
0 \\
3
\end{bmatrix} \cdot
\begin{bmatrix}
\textcolor{red}{0} \\
0 \\
1
\end{bmatrix} = -1 \times 1 = -1
$$

<center>

| col_idx | B[common_idx, other_col_idx] | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[0, 0] = 7$                | Yes       | - $A[1, 0] \times B[0, 0] = -1 \times 7 = -7$ <br> - Update $C[1, 0] = -7$ |
| 1               | $B[0, 1] = 0$                 | No        | Skip multiplication |
| 2               | $B[0, 2] = 0$                | No        | Skip multiplication |

</center>

#### Third Non-Zero Element of `A`

* Initialize `row_idx = 1`
* Initialize `common_idx = 2`
* Initialize `value = 3`

The third non-zero element in `A` is $A[1, 2] = 3$. This element contributes to the following dot products:

1. Row 1 of `A` dotted with column 0 of `B` to compute the element at `C[1, 0]`:

$$
\begin{bmatrix}
-1 \\
0 \\
\textcolor{red}{3}
\end{bmatrix} \cdot
\begin{bmatrix}
7 \\
0 \\
\textcolor{red}{0}
\end{bmatrix} = 3 \times 0 = 0
$$

2. Row 1 of `A` dotted with column 1 of `B` to compute the element at `C[1, 1]`:

$$
\begin{bmatrix}
-1 \\
0 \\
\textcolor{red}{3}
\end{bmatrix} \cdot
\begin{bmatrix}
0 \\
0 \\
\textcolor{red}{0}
\end{bmatrix} = 3 \times 0 = 0
$$

3. Row 1 of `A` dotted with column 2 of `B` to compute the element at `C[1, 2]`:

$$
\begin{bmatrix}
-1 \\
0 \\
\textcolor{red}{3}
\end{bmatrix} \cdot
\begin{bmatrix}
0 \\
0 \\
\textcolor{red}{1}
\end{bmatrix} = 3 \times 1 = 3
$$

<center>

| `other_col_idx` | `B[common_idx, other_col_idx]` | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[2, 0] = 0$                 | No        | Skip multiplication |
| 1               | $B[2, 1] = 0$              | No        | Skip multiplication |
| 2               | $B[2, 2] = 1$                 | Yes       | - $A[1, 2] \times B[2, 2] = 3 \times 1 = 3$ <br> - Update $C[1, 2] = 3$ |

</center>

The output sparse matrix `C` is:

```python
C = {(0, 0): 7, (1, 0): -7, (1, 2): 3}
```

The dense representation of the output matrix `C` is:

```python
C = [[7, 0, 0],
     [-7, 0, 3]]
```

## Time Complexity

If $A$ has $a$ non-zero elements and $B$ has $b$ non-zero elements, the time complexity of the sparse matrix multiplication is $O(a \times d)$, where $d$ is the average number of non-zero elements per column in $B$. 

This is because, for each non-zero element in $A$, we iterate over the columns of $B$, carying out, on average, $d$ multiplication and addition operations per column.

Note that is much more efficient than the $O(m \times n \times k)$ time complexity of the naive matrix multiplication algorithm, which is derived as follows:

1. For each element in the resulting $m \times n$ matrix, a dot product of a row from $A$ and a column from $B$ is computed. 

2. Each dot product involves $k$ multiplications and $k-1$ additions, which can be considered as $O(k + (k-1)) = O(k)$.

Therefore, for each element in the resulting matrix $C_{ij}$, the number of operations is $O(k)$. Since there are $m \times n$ elements in the resulting matrix, the total time complexity is $O(m \times n \times k)$.

## Space Complexity

The space complexity of the output matrix $C$ depends on the number of non-zero elements in the resultant matrix, which is typically proportional to the sparsity of A and B. That is, if $a$ and $b$ are the number of non-zero elements in $A$ and $B$, respectively, the space complexity of the output matrix $C$ is $O(a + b)$ in the worst case where $a = m \times k$ and $b = k \times n$.

---

# Match Alphanumerical Pattern in Matrix I 

Given two inputs:

* 2D integer matrix `matrix` where $0 \le \text{matrix}[i][j] \le 9$

* 2D character matrix `pattern` where each element is either a digit or a a lowercase english letter

Find the indices $(i, j)$, which is the top-left corner of the submatrix in `matrix` that matches the pattern in `pattern`. The pattern is considered matched if the submatrix in `matrix` has the same dimensions as `pattern` and the elements in the submatrix match the corresponding elements in `pattern`.
If there are multiple matches, return the top-left corner of the submatrix with the smallest row index. If there are still multiple matches, return the top-left corner of the submatrix with the smallest column index. If there are no matches, return `[-1, -1]`.

## Examples

### Example 1

* board = [[1, 2, 2], [2, 2, 3], [2, 3, 3]]

* pattern = ["ab", "bb]:

$$
\text{board} = \begin{bmatrix}
\textcolor{red}{1} & \textcolor{red}{2} & 2 \\
\textcolor{red}{2} & \textcolor{red}{2} & 3 \\
2 & 3 & 3
\end{bmatrix}
\;\;
\text{pattern} = \begin{bmatrix}
a & b \\
b & b
\end{bmatrix}
$$

The submatrix in `board` that matches the pattern in `pattern` has the top-left corner at $(0, 0)$.

### Example 2

* board = [[1, 2], [2, 1]]

* pattern = ["xx"]

$$
\text{board} = \begin{bmatrix}
1 & 2 \\
2 & 1
\end{bmatrix}
\;\;
\text{pattern} = \begin{bmatrix}
x & x
\end{bmatrix}
$$

There are no submatrices in `board` that match the pattern in `pattern`.

### Example 3

* board = [[1, 1, 2], [3, 3, 4], [6, 6, 6]]

* pattern = ["ab", "66"]

$$
\text{board} = \begin{bmatrix}
1 & 1 & 2 \\
3 & \textcolor{red}{3} & \textcolor{red}{4} \\
6 & \textcolor{red}{6} & \textcolor{red}{6}
\end{bmatrix}
\;\;
\text{pattern} = \begin{bmatrix}
a & b \\
6 & 6
\end{bmatrix}
$$

The submatrix in `board` that matches the pattern in `pattern` has the top-left corner at $(1, 1)$.

## Explanation

The algorithm iterates over all possible submatrices in `matrix` that have the same dimensions as `pattern`, starting from the top-left corner of each submatrix.

For each submatrix with top-left corner at $(i, j)$, the algorithm checks if the elements in the submatrix match the corresponding elements in `pattern`. If a match is found, the algorithm returns the top-left corner $(i, j)$.

The logic for checking if a submatrix matches the pattern is as follows:

* Initializes two dictionaries: `board_int_to_pattern_str` and `pattern_str_to_board_int` to maintain a bidirectional mapping between board integers and pattern strings.

* Iterates over each element in the pattern matrix and the corresponding element in the board submatrix starting at $(i, j)$.

    - If the element in the pattern matrix is a digit, the algorithm checks if the corresponding element in the board submatrix matches the digit. If not, the submatrix does not match the pattern, and the algorithm returns `False` to move on to the next submatrix.

    - If the element in the pattern matrix is a lowercase letter, the algorithm makes two checks:

        1. If the element in the board submatrix is already mapped to a different letter in `board_int_to_pattern_str`, the submatrix does not match the pattern, and the algorithm returns `False`.

        2. If the element in the pattern matrix is already mapped to by a different integer in `pattern_str_to_board_int`, the submatrix does not match the pattern, and the algorithm returns `False`.

        3. Otherwise, the algorithm updates the mappings in `board_int_to_pattern_str` and `pattern_str_to_board_int` and continues to the next element in the pattern matrix.

* If all elements in the pattern matrix match the corresponding elements in the board submatrix, the algorithm returns `True` to indicate that the submatrix matches the pattern.

## Time Complexity

Let $m$ and $n$ be the number of rows and columns in the `matrix`, respectively, and $p$ and $q$ be the number of rows and columns in the `pattern`, respectively.

There can be at most $(m - p + 1) \times (n - q + 1)$ submatrices in the `matrix` that have the same dimensions as the `pattern`. 

For each submatrix, the algorithm iterates over all elements in the `pattern`. For each element in the `pattern`, the algorithm performs the following operations:

* Check if the element in `pattern` is a digit in $O(1)$

  - If the element in `pattern` is a digit, the algorithm checks if the corresponding element in the submatrix matches the digit in $O(1)$.

* If the element in `pattern` is a lowercase letter:

  - One lookup and one comparisons both costing $O(1)$.

  - Another lookup and another comparison both costing $O(1)$.

  - Two updates to the mappings both costing $O(1)$.

For each submatrix, we can consider the time complexity to be $O(p \times q)$.

In the wrost case, i.e., no submatrix matches the pattern, the time complexity can be modeled as:

$$
\begin{align*}
O\Big[(m - p + 1) \times (n - q + 1) \times p \times q\Big]
\end{align*}
$$

## Space Complexity

The components contributing to the space complexity are:

1. **Hash Maps**:

    - Two hash maps, `board_int_to_pattern_str` and `pattern_str_to_board_int`, are used.

    - **Keys for `board_int_to_pattern_str`**: Limited to integers from 0 to 9 (10 possible keys).

    - **Keys for `pattern_str_to_board_int`**: Limited to 26 lowercase letters (26 possible keys).

    - Total possible unique mappings: $36 (10 + 26)$.

2. **Space per Submatrix**:

    - For each submatrix, the space required to store mappings in the worst case is $O(36) = O(1)$.

3. **Total Space for All Submatrices**:

    - There are $(m - p + 1) \times (n - q + 1)$ possible submatrices

    - Even if all submatrices match the pattern and mappings are stored for each, the total space remains $O(1)$ for each submatrix.

