#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "metodo_gradiente_coniugato.hpp"

int main()
{
    Eigen::MatrixXd B(3,3);

    B << 1,2,3,
         0,1,4,
         5,6,0;

    Eigen::MatrixXd A = B.transpose() * B;
    std::cout.precision(2);
    std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

    Eigen::VectorXd x = gradiente_coniugato(B);
    int n = B.cols();
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
                                            (x - x_ex).norm() / x_ex.norm();

    std::cout.precision(4);
    std::cout<< std::scientific<< "err_rel"<< std::endl;
    std::cout<< std::scientific<< err_rel<< std::endl;
    std::cout<< std::scientific<< "soluzione"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;

    return 0;

}

