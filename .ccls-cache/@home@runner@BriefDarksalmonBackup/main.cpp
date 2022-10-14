
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <iostream>
#include <vector>




int main()
{
    int x = 5614;
    // static_cast
    double d = static_cast<double>(x);
    std::cout << d << " " << x << "\n";
    // reinterpret_cast
    std::cout << *reinterpret_cast<double*>(&x) << "\n";
    float dd = 3.14;
    std::cout << *reinterpret_cast<int*>(&dd) << "\n";
    // 
    
    
    return 0;
}
