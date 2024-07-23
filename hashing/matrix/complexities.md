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

Given two sparse matrices `A` and `B` (in their dense representations), design an algorithm to multiply them and return the result as a dense matrix. 

In Python, the sparse matrices are represented as lists of lists. For example, the matrix:

```python
A = [[1, 0, 0],
     [-1, 0, 3]]

B = [[7, 0, 0],
     [0, 0, 0],
     [0, 0, 1]]
```

In C++, the sparse matrices are represented as vectors of vectors. For example, the matrix:

```c++
std::vector<std::vector<double>> A = {{1.0, 0.23, 0.43},
                                      {-1.45, 0.3, 3.0}};

std::vector<std::vector<double>> B = {{7.0, 0.0, 0.0},
                                      {0.0, 0.0, 0.0},
                                      {0.0, 0.0, 1.0}};
```

## Explanation

To multiply two matrices, `A` ($m \times k$) and `B` ($k \times n$), the result is a matrix `C` ($m \times n$). Each element of `C` is computed as the dot product of the corresponding row of `A` and the column of `B`. Specifically:

$$
\begin{align*}
C[i][j] = \sum_{t=0}^{k-1} A[i][t] \times B[t][j]
\end{align*}
$$

where $t$ must be a common dimension between `A` and `B`, i.e., the number of columns in `A` must be equal to the number of rows in `B`.

### Dictionary of Keys (DOK) Format

To handle sparse matrices, we can optimize the multiplication by skipping the multiplication and addition operations for elements that are zero. This can be done by converting the dense matrices `A` and `B` to dictionary of keys (DOK) format. In DOK format, we store the indices of non-zero elements as keys and their values as values.

#### Python

In Python, the `scipy.sparse.dok_matrix` class, which is a subclass of the `dict` class, implements the DOK format.

#### C++

The `Eigen::SparseMatrix` class in C++ can be used to represent sparse matrices; however, the underlying implementation is a versatile variant of the widely-used Compressed Column (or Row) Storage scheme.

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

* Initialize `a_row_idx = 0`
* Initialize `common_idx = 0`
* Initialize `a_value = 1`

<center>

| `other_col_idx` | `B[common_idx, other_col_idx]` | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[0, 0] = 7$                 | Yes       | - $A[0, 0] x B[0, 0] = 1 \times 7 = 7$ <br> - Update $C[0, 0] = 7$ |
| 1               | $B[0, 1] = 0$                 | No        | Skip multiplication |
| 2               | $B[0, 2] = 0$                 | No        | Skip multiplication |

</center>

#### Second Non-Zero Element of `A`

* Initialize `a_row_idx = 1`
* Initialize `common_idx = 0`
* Initialize `a_value = -1`

<center>

| `other_col_idx` | `B[common_idx, other_col_idx]` | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[0, 0] = 7$                | Yes       | - $A[1, 0] x B[0, 0] = -1 \times 7 = -7$ <br> - Update $C[1, 0] = -7$ |
| 1               | $B[0, 1] = 0$                 | No        | Skip multiplication |
| 2               | $B[0, 2] = 0$                | No        | Skip multiplication |

</center>

#### Third Non-Zero Element of `A`

* Initialize `a_row_idx = 1`
* Initialize `common_idx = 2`
* Initialize `a_value = 3`

Iterate over the columns of `B`:

<center>

| `other_col_idx` | `B[common_idx, other_col_idx]` | Non-Zero? | Operation |
|-----------------|--------------------------------|-----------|-----------|
| 0               | $B[2, 0] = 0$                 | No        | Skip multiplication |
| 1               | $B[2, 1] = 0$              | No        | Skip multiplication |
| 2               | $B[2, 2] = 1$                 | Yes       | - $A[1, 2] \times B[2, 2] = 3 \times 1 = 3$ <br> Update $C[1, 2] = 3$ |

</center>

The final sparse matrix `C` is:

```python
C = {(0, 0): 7, (1, 0): -7, (1, 2): 3}
```

The dense matrix `C` is:

```python
C = [[7, 0, 0],
     [-7, 0, 3]]
```

## Time Complexity

If $A$ has $a$ non-zero elements and $B$ has $b$ non-zero elements, the time complexity of the multiplication is $O(a \times d)$, where $d$ is the average number of non-zero elements per column in $B$. This is because, for each non-zero element in $A$, we iterate over the columns of $B$, carying out a multiplication and addition operation per iteration.

## Space Complexity

The space complexity depends on the number of non-zero elements in the resultant matrix, which is typically proportional to the sparsity of A and B. 

In addition, because we use a dictionary to store the non-zero elements, the space complexity is $O(a + b)$, where $a$ and $b$ are the number of non-zero elements in $A$ and $B$, respectively.
