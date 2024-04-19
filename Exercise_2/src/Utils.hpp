#pragma once
#include <iostream>

using namespace std;

bool ImportData(const string& inputFilePath,
                size_t& n,
                double& s,
                double*& w,
                double*& r);

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

double FinalValueOfPortfolio(const size_t& n,
                             const double& s,
                             const double* const& w,
                             const double* const& r);

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double& s,
                  const double* const& w,
                  const double* const& r,
                  double& rateOfReturn,
                  double& value);

string ArrayToString(const size_t&n,
                     const double* const& v);
