class Solution:
    MOD = 10**9 + 7

    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        factorial, inverseFactorial = self.getFactorialAndInverse(n)
        return (
            m * self.modPow(m - 1, n - k - 1) % self.MOD *
            self.nCk(n - 1, k, factorial, inverseFactorial) % self.MOD
        )

    def modPow(self, base: int, exponent: int) -> int:
        if exponent == 0:
            return 1
        if exponent % 2 == 1:
            return base * self.modPow(base % self.MOD, exponent - 1) % self.MOD
        return self.modPow(base * base % self.MOD, exponent // 2) % self.MOD

    def getFactorialAndInverse(self, n: int):
        factorial = [1] * (n + 1)
        inverseFactorial = [1] * (n + 1)
        modularInverse = [0] * (n + 1)
        modularInverse[0] = modularInverse[1] = 1

        for i in range(2, n + 1):
            modularInverse[i] = self.MOD - self.MOD // i * modularInverse[self.MOD % i] % self.MOD

        for i in range(1, n + 1):
            factorial[i] = factorial[i - 1] * i % self.MOD
            inverseFactorial[i] = inverseFactorial[i - 1] * modularInverse[i] % self.MOD

        return factorial, inverseFactorial

    def nCk(self, n: int, k: int, factorial: list[int], inverseFactorial: list[int]) -> int:
        return factorial[n] * inverseFactorial[k] % self.MOD * inverseFactorial[n - k] % self.MOD
