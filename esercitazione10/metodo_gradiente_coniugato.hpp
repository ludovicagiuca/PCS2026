#pragma once
#include <stdexcept>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

Eigen::VectorXd gradiente_coniugato (const Eigen::MatrixXd& B){

    if (B.rows()!= B.cols()){
       throw std::invalid_argument("ERRORE, la matrice non è quadrata");
    } //Se la matrice non è quadrata errore

    const double tol = 1.0e-15;
    int n = B.cols();
    if (abs(B.determinant()) < tol){
       throw std::invalid_argument("ERRORE, la matrice è singolare");
    }
  
    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd res = b - A * x;
    Eigen::VectorXd p = res;
    double res_norm_0 = res.norm();

    const unsigned int it_max = 10000;
    unsigned int it = 0;
    const double res_tol = 1.0e-12;

    while (it < it_max &&
            res.norm() > res_tol * res_norm_0)
    {
      const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value(); //Senza value il prodotto scalare genera in Eigen una matrice 1x1
      x = x + alpha_k * p;
      res = res - alpha_k * A * p;
      const double beta_k = ((p.transpose() * A * res) / (p.transpose() * A * p)).value();
      p = res - beta_k * p;
      it++;
    }

    std::cout << "Iterazioni effettuate per raggiungere soluzione: " << it << std::endl;
    return x;

  }

     
