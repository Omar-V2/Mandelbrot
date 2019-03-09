#include <iostream>
#include <complex>

using namespace std;


// computes the number of iterations required to escape the mandelbrot set
// or alternatively if the given complex number c, never satisifes the escape criteria
// the function terminates upon executing a predefined number of iterations, maxiter.
int mandel(std::complex<double> c, int maxiter){
    std::complex<double> z (0.0, 0.0);
    int iter = 0;
    for (iter; iter < maxiter; iter++){
        z = (z*z) + c;
        if (abs(z) > 4){
            break;
        }
    }
    return iter;
}

int main(){
    std::complex<double> c1 (0.2, 0.01);
    std::complex<double> c2 (3.2, 5.1); //outside mandlerbot set
    int iter_1 = mandel(c1, 1000);
    int iter_2 = mandel(c2, 1000);
    cout << iter_1 << endl;
    cout << iter_2 << endl;
    return 0;
}