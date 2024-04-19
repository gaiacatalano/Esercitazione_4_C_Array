#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;

bool ImportData(const string& inputFilePath,
                size_t& n,
                double& s,
                double*& w,
                double*& r)
{
    ifstream inFile(inputFilePath);
    if(inFile.fail())
    {
        cerr << "Error in opening the file" << endl;
        return false;
    }
    string line;
    string ignore;
    string fraction_w;
    string rate_r;
    int counter = 1;
    while(!inFile.eof())
    {

        if(counter==1)
        {
            getline(inFile, ignore, ';');
            getline(inFile, line);
            istringstream convertS;
            convertS.str(line);
            convertS >> s;
            counter++;
        }
        if(counter==2)
        {
            getline(inFile, ignore, ';');
            getline(inFile, line);
            istringstream convertN;
            convertN.str(line);
            convertN >> n;
            w = new double[n];
            r = new double[n];
            counter++;
        }
        if(counter==3)
        {
            getline(inFile, ignore);
            counter++;
        }
        else
        {
            getline(inFile, fraction_w,';');
            getline(inFile, rate_r);
            istringstream convertW;
            istringstream convertR;
            convertW.str(fraction_w);
            convertR.str(rate_r);
            convertW >> w[counter-4];
            convertR >> r[counter-4];
            counter++;
        }
    }
    inFile.close();
    return true;
}

double RateOfReturn(const size_t& n,
                  const double* const& w,
                  const double* const& r)
{
    double rateOfReturn = 0;
    for(unsigned int i = 0; i < n; i++)
    {
        rateOfReturn += w[i] * r[i];
    }
    return rateOfReturn;

}

double FinalValueOfPortfolio(const size_t& n,
                             const double& s,
                             const double* const& w,
                             const double* const& r)
{
    double value = 0;
    for(unsigned int i = 0; i < n; i++)
    {
        value += (1+r[i])*w[i]*s;
    }
    return value;
}

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double& s,
                  const double* const& w,
                  const double* const& r,
                  double& rateOfReturn,
                  double& value)
{
    ofstream outFile(outputFilePath);
    if(outFile.fail())
    {
        cerr << "Error in opening the file" << endl;
        return false;
    }
    outFile << "S = " << fixed << setprecision(2) << s << ", n = " << n << endl;
    outFile << "w = " << ArrayToString(n, w) << endl;
    outFile << "r = " << ArrayToString(n, r) << endl;
    outFile << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    outFile << "V: " << fixed << setprecision(2) << value << endl;
    outFile.close();
    return true;
}

string ArrayToString(const size_t&n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";
    return toString.str();
}



