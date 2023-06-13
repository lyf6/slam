#include <Eigen/Dense>
#include <glog/logging.h>
#include <math.h>
#include <tuple>
#include <utils.h>
std::tuple<Eigen::MatrixXf, Eigen::MatrixXf> QR_Householder(Eigen::MatrixXf &A)
{

    int cols = A.cols();
    Eigen::MatrixXf At = A;
    // LOG(INFO) << A;
    Eigen::MatrixXf R = Eigen::MatrixXf::Identity(cols, cols);
    for (int i = 1; i < cols; i++)
    {
        // int k =
        R = Rk(At, i) * R;
        At = R * A;
    }
    // LOG(INFO) << At;
    // LOG(INFO) << R.transpose();
    // LOG(INFO) << R.transpose() * At;
    return std::make_tuple(R.transpose(), At);
}

Eigen::MatrixXf Rk(Eigen::MatrixXf &A, int k)
{
    int const cols = A.cols();
    Eigen::MatrixXf result = Eigen::MatrixXf::Identity(cols, cols);
    int s_r = k - 1;
    int s_c = k - 1;
    int m = cols - s_r;
    int n = cols - s_c;

    Eigen::MatrixXf sub_a = A.block(s_r, s_c, m, n);
    int sub_cols = sub_a.cols();
    // Eigen::MatrixXf::Identity()
    Eigen::VectorXf u = sub_a.leftCols(1);
    float l2 = u.norm();
    u[0] = u[0] - l2;
    u.normalize();
    Eigen::MatrixXf mat = Eigen::MatrixXf::Identity(sub_cols, sub_cols);
    sub_a = mat - 2 * u * u.transpose();
    result.block(s_r, s_c, m, n) = sub_a;
    return result;
}

Eigen::MatrixXf Cholesky(Eigen::MatrixXf &a)
{
    int n = a.rows();
    // int cols = a.cols();
    Eigen::MatrixXf g = Eigen::MatrixXf::Zero(n, n);
    Eigen::VectorXf v = Eigen::VectorXf::Zero(n);
    for (int j = 0; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            v(i) = a(i, j);
            for (int k = 0; k <= j - 1; k++)
            {
                v(i) = v(i) - g(j, k) * g(i, k);
            }
            g(i, j) = v(i) / sqrt(v(j));
        }
    }
    // LOG(INFO) << g;
    return g;
}
void QR_solve(Eigen::MatrixXf &A, Eigen::VectorXf &b)
{
    int cols = A.cols();
    Eigen::VectorXf x = Eigen::VectorXf::Zero(cols);
    Eigen::MatrixXf Q = Eigen::MatrixXf::Zero(cols, cols);
    Eigen::MatrixXf R = Eigen::MatrixXf::Zero(cols, cols);
    std::tie(Q, R) = QR_Householder(A);
    R = R.inverse();
    x = R * Q.transpose() * b;
    LOG(INFO) << x;
    LOG(INFO) << A * x;
}
void Cholesky_solve(Eigen::MatrixXf &A, Eigen::VectorXf &b)
{
    int cols = A.cols();
    Eigen::VectorXf x = Eigen::VectorXf::Zero(cols);
    Eigen::MatrixXf g = Cholesky(A).inverse();
    x = g.transpose() * g * b;
    LOG(INFO) << x;
    LOG(INFO) << A * x;
}