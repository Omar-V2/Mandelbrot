#include <iostream>
#include <fstream>
#include <complex>
#include <vector>

using namespace std;
int width = 1000, height = 1000, maxval = 255;

// Generates an evenly spaced vector over a specific interval
// Analgous to np.linspace from Python's NumPy
std::vector<float> linspace(float start, float end, int num_points){
    vector<float> points;
    float delta = (end - start);
    float step = delta / (num_points - 1);
    for (int i = 0; i < num_points; i++){
        points.push_back(i*step);
    }
    return points;
}
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
    std::vector<float> x_values = linspace(-2.5, -2, width);
    std::vector<float> y_values = linspace(-1, -0.5, height);
    ofstream img ("mandelbrot.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << maxval << endl;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            std::complex<double> c (x_values[x], y_values[y]);
            int n = mandel(c, 1000);
            int r = n % 255;
            int g = 2*n % 255;
            int b = n*g % 255;

            img << r << " " << g << " " << b << endl;
        }
    }
    system("open mandelbrot.ppm");
    return 0;
}