#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
  string inputFilePath = "./data.csv";
  size_t n = 0;
  double s = 0.0;
  double* w = nullptr;
  double* r = nullptr;

  if(!ImportData(inputFilePath, n, s, w, r))
  {
      cerr << "File not imported correctly" << endl;
      return 1;
  }

  double rateOfReturn = RateOfReturn(n, w, r);
  double value = FinalValueOfPortfolio(n, s, w, r);
  cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
  cout << "V: " << fixed << setprecision(2) << value << endl;

  string outputFilePath = "result.txt";

  if(!ExportResult(outputFilePath, n, s, w, r, rateOfReturn, value))
    {
        cerr << "Error in exporting data" << endl;
        return -1;
    }
    else
        cout << "Exported successfully"<< endl;

    delete[] w;
    delete[] r;

  return 0;
}

