#include <Eigen/Dense>
#include <glog/logging.h>
#include <math.h>
#include <tuple>
std::tuple<Eigen::MatrixXf, Eigen::MatrixXf> QR_Householder(Eigen::MatrixXf &A);
Eigen::MatrixXf Rk(Eigen::MatrixXf &A, int k);
Eigen::MatrixXf Cholesky(Eigen::MatrixXf &a);
void QR_solve(Eigen::MatrixXf &A, Eigen::VectorXf &b);
void Cholesky_solve(Eigen::MatrixXf &A, Eigen::VectorXf &b);