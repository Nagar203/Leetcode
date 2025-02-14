#include <vector>

class ProductOfNumbers {
public:
    ProductOfNumbers() { prefixProducts = {1}; }

    void add(int num) {
        if (num == 0)
            prefixProducts = {1}; 
        else
            prefixProducts.push_back(prefixProducts.back() * num);
    }

    int getProduct(int k) {
        if (k >= prefixProducts.size())
            return 0;
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - k - 1];
    }

private:
    std::vector<int> prefixProducts; 
};