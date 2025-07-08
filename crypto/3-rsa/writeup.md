# Writeup for `3 rsa`

|      author     | category | value |
|-----------------|----------|-------|
| yellowsubmarine | crypto  |  100  |

The NSA kindly invited themselves into my house, poured themselves a cup of tea (shared) and told me to use consecutive prime numbers in my encryptions. OK!

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

We're given three flags (flag1, flag2, flag3) which are encrypted in three different RSA systems; they all share the same public exponent $65537$, but are encrypted under different moduli $ax$, $by$ and $cz$, for primes $a, b, c, x, y, z$ (like in RSA, the moduli are known but not their prime factorisations). This challenge would be (theoretically) impossible if the systems were completely unrelated, however it is asserted that $z - y = y - x$ and $c - b = b - a$. Note this means $x, y, z$ and $a, b, c$ are in an arithmetic progression (the adjacent elements have a common difference)!

The general idea is to combine the previous relation with the three products to form an equation with two variables, and then turn the equation into a quadratic in terms of their product (or ratio), solve this quadratic and take its GCD with one of the public moduli.

I think this method is the most "attainable" for someone doing this problem (since, if you've worked with algebraic equations before, you'll know the goal is to reduce the number of unknown variables as much as possible in a given equation), so I shall showcase it first.

We have three equations involving two equations already with the moduli, but we know integer factorisation is hard - this should motivate us to form some sort of "crossover" equation. Rewriting the differences to group variables together gives

$$z = 2y - x$$
and
$$c = 2b - a.$$

This gives us the idea of writing $n_3 = cz = (2b - a)(2y - x) = 4by - 2ay - 2bx + ax$. Observe that $by, ax$ are known - they are $n_2$ and $n_1$. Again, we want to reduce unknowns as much as possible, so we can try substituting $y = \frac{n_2}b$ and $a = \frac{n_1}x$ to get:

$$n_3 = 4n_2 - \frac{2n_1n_2}{bx} - 2bx + n_1.$$

Note that $bx$ can be treated as "one" thing (e.g. substituting a dummy variable $t$), and after multiplying both sides by $bx$ (or $t$), we get a quadratic in terms of $bx$ we can solve to get two equations. Now we just take the gcd of $bx$ with $ab$ to get $b$, and we can progressively recover the other primes in a similar way and decrypt the flag with standard RSA decryption (as we now know the prime).

Further notes:
- The quadratic can be solved programmatically with the quadratic formula and `math.isqrt` in Python.
- Calculating the GCD is very fast, in that the time taken scales logarithmically to the sizes of the numbers (all known factorisation algorithms scale linearly, which is very slow for $1024$-bit numbers)
- If we took $y = \frac{n_2}b$ and $x = \frac{n_1}a$, we would get an equation in terms of $\frac ab$ - fractions are a little more annoying to work with (this is still doable with integer computations - note that the square of a rational number must have both its numerator and denominator be squares when full reduced). Swapping $b$ with $y$ and $a$ with $x$ gives an equation in terms of $\frac xy$.
- There's a super clean way compute the solution: note that $b$ is the average of $a$ and $c$, and $y$ is the average of $x$ and $z$. Then, $4n_2 = (a+c)(x+z) = n_1 + n_3 + az + cx$. Now, $(az + cx)^2 = (az)^2 + (cx)^2 + 2azcx = (az)^2 + (cx)^2 - 2azcx + 4axcz = (az - cx)^2 + 4n_1n_3$. This means we can calculate $az - cx = \sqrt{(az + cx)^2 - 4n_1n_3}$, which upon adding with $az - cx$ gives $2az$, which can be taken in GCD with $ab$ to get $a$.

### Walkthrough

The last mentioned method is demonstrated in [solution.py](solution.py).

### Flag(s)

- `RCR{RSA_1s_4wes0me!!_4d9hf2a}`

</details>
