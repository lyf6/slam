#include <Eigen/Dense>
#include "utils.h"

int main()
{
    const int n = 3;
    Eigen::MatrixXf a(3, 3);
    // a << 0, 3, 1, 0, 4, -2, 2, 1, 1;
    a << 25, 15, -5, 15, 18, 0, -5, 0, 11;
    Eigen::VectorXf b(3);
    b << 35, 33, 6;
    Cholesky_solve(a, b);
    // Eigen::MatrixXf A = Eigen::MatrixXf::Random(n, n);
    // QR_Householder(a);
    // Cholesky(a);
}
