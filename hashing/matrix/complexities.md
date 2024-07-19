# Set Matrix Zeroes

Given an $m \times n$ integer matrix matrix, if an element is 0, set its entire row and column to 0's. 

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

This effectively marked the rows and columns that need to be set to zero.

### Zero Rows and Columns Based on Marks

#### Zero Columns

For `row` in `1, 2`:

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

For `col` in `1, 2`:

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

### Zero First Row and Column If Necessary

Since both `first_row_zero` and `first_col_zero` are `False`, no action is needed in this case.

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

The work done inside these loops, i.e., `matrix.row(row).setZero()` and `matrix.col(col).setZero()`, runs in $O(n)$ and $O(m)$ times, respectively.

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

These last two loops are not run if `firstRowZero` and `firstColZero` are `False`. So if we consider the worst case, i.e., both `firstRowZero` and `firstColZero` are `True`, the time complexity is $O(m + n)$. 

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
