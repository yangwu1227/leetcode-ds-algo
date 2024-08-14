## Big-O Notation

> Definition: $f(n)=O(g(n))$ $\;$ ($f$ is Big-O of $g$) or ($f \preceq g$) if there exist constants $N$ and $c$ such that $\forall \; n \geq N, \; f(n) \leq c \cdot g(n)$.

In words, this means that $f$ is bounded above by some constant multiple of $g$ for sufficiently large $n$. Two other ways to say this are:

* $f$ grows no faster than $g$ asymptotically

* $\frac{f(n)}{g(n)}$ is bounded as $n \rightarrow \infty$, meaning $\frac{f(n)}{g(n)}$ approaches a constant $c$ or remains less than or equal to a constant $c$ as $n$ increases

## Common Rules

### Multiplicative Constants

The multiplicative constant rule states that if $f(n) = c \cdot g(n)$ for some constant $c$, then $f(n) = O(g(n))$.

* $7n^3 = O(n^3)$

* $\frac{n^2}{2} = O(n^2)$

### Power of $n$

If $n^a \prec n^b$ for $0 < a < b$, then $n^a = O(n^b)$.

* $n = O(n^2)$

* $\sqrt{n} = O(n)$

As $n$ gets large, the term with the larger power of $n$ will always grow faster.

### Exponential 

If we have $n^a \prec b^n$ for $a > 0, \; b > 1$, then $n^a = O(b^n)$.

* $n^5 = O(\sqrt{2}^n)$

* $n^100 = O(1.1^n)$

As $n$ gets large, the exponential function will always grow faster than any polynomial function.

### Logarithmic

If $(\log n)^a \prec n^b$ for $a > 0, \; b > 0$, then $(\log n)^a = O(n^b)$.

* $(\log n)^3 = O(\sqrt{n})$

* $n \log n = O(n^2)$

As $n$ gets large, any power of $\log n$ will grow slower than any power of $n$.

### Summation 

Smaller terms can be dropped in Big-O notation.

* $n^2 + n = O(n^2)$

* $2^n + n^9 = O(2^n)$

## Big-Omega & Big-Theta Notations

For functions $f, \; g: \mathbb{N} \rightarrow \mathbb{R}^{+}$, we say that:

> Big-Omega ($\Omega$): $f(n) = \Omega(g(n))$ (or $f \succeq g$) if there exists some constant $c > 0$ such that $f(n) \geq c \cdot g(n)$ for all sufficiently large $n$. In other words, $f$ grows **no slower** than $g$ asymptotically; it is bounded below by $g$.

> Big-Theta ($\Theta$): $f(n) = \Theta(g(n))$ (or $f \asymp g$) if $f = O(g)$ and $f = \Omega(g)$. This means that $f$ grows at the same rate as $g$.

## Little-o Notation

> Definition: For functions $f, \; g: \mathbb{N} \rightarrow \mathbb{R}^{+}$ we say that: $f(n)=o(g(n))$ or $(f \prec g)$ if $\frac{f(n)}{g(n)} \rightarrow 0$ as $n \rightarrow \infty$ ($f$ grows strictly slower than $g$).

## Other Examples

* $\log_2{n} = O(n^2)$

* $n^2 = O(n^3)$

* $n^2 = O(5^{\log_2{n}}) = O(n^{\log_2{5}}) = O(n^{\sim2.32})$

* $2^{3\log_2{n}} = n^{3\log_2{2}} = (n^{\log_2{2}})^3 = (n^1)^3 = O(n^5)$

* $2^n = O(2^{n + 1}) = O(2^1 \cdot 2^n) = O(2^n)$ since $2^1$ is a constant and can be dropped
