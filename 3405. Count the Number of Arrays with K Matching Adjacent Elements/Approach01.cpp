class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const auto [factorial, inverseFactorial] = getFactorialAndInverse(n);
        return m * modPow(m - 1, n - k - 1) % kMod *
               nCk(n - 1, k, factorial, inverseFactorial) % kMod;
    }

private:
    static constexpr int kMod = 1'000'000'007;

    long modPow(long base, long exponent) {
        if (exponent == 0)
            return 1;
        if (exponent % 2 == 1)
            return base * modPow(base % kMod, exponent - 1) % kMod;
        return modPow(base * base % kMod, exponent / 2) % kMod;
    }

    pair<vector<long>, vector<long>> getFactorialAndInverse(int n) {
        vector<long> factorial(n + 1);
        vector<long> inverseFactorial(n + 1);
        vector<long> modularInverse(n + 1);
        factorial[0] = inverseFactorial[0] = 1;
        modularInverse[0] = modularInverse[1] = 1;

        for (int i = 1; i <= n; ++i) {
            if (i >= 2)
                modularInverse[i] = kMod - kMod / i * modularInverse[kMod % i] % kMod;
            factorial[i] = factorial[i - 1] * i % kMod;
            inverseFactorial[i] = inverseFactorial[i - 1] * modularInverse[i] % kMod;
        }
        return {factorial, inverseFactorial};
    }

    int nCk(int n, int k, const vector<long>& factorial,
            const vector<long>& inverseFactorial) {
        return factorial[n] * inverseFactorial[k] % kMod * inverseFactorial[n - k] % kMod;
    }
};
