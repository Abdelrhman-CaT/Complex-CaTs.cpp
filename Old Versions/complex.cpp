#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;


void comp_splitter(string num , float &r, float &i)
{

    string auth = num;
    int len= num.length();
    int sep,n=0,neg=0;

    if(num.find("+") != -1)
    {

        for(int j=0;j<len;j++)
    {
        if(num[j] == '+' || num[j] == '-')
        {
            sep=j;
        }
    }
    if(num[sep] == '-')
        {
            neg=1;
        }

        num.erase(sep);
        r = atof(num.c_str());

        for(int j=sep+1;j<len-1;j++)
        {
           auth[n] = auth[j];
           n+=1;
        }
        auth.erase(n);
        i = atof(auth.c_str());
        if(neg == 1)
        {
            i= -i;
        }
    }

    else if(num.find("-") != -1)
    {

        if(num.find("-",1)!=-1)
        {
            for(int j=0;j<len;j++)
    {
        if(num[j] == '+' || num[j] == '-')
        {
            sep=j;
        }
    }
    if(num[sep] == '-')
        {
            neg=1;
        }

        num.erase(sep);
        r = atof(num.c_str());

        for(int j=sep+1;j<len-1;j++)
        {
           auth[n] = auth[j];
           n+=1;
        }
        auth.erase(n);
        i = atof(auth.c_str());
        if(neg == 1)
        {
            i= -i;
        }
        }
        else
        {
            if(num.find("i") != -1)
            {
                r=0;
                num.erase(len-1);
                i=atof(num.c_str());
            }
            else
            {
                r=atof(num.c_str());
                i=0;
            }
        }
    }

    else
    {
        if(num.find("i") != -1)
        {
            r=0;
            num.erase(len-1);
            i=atof(num.c_str());
        }
        else
        {
            i=0;
            r=atof(num.c_str());
        }
    }

}

string comp_combine(float r , float i)
{
    int neg=0;
    if(i < 0)
    {
        neg=1;
    }
    ostringstream rr;
    rr << r;
    string re = rr.str();

    ostringstream ii;
    ii << i;
    string im = ii.str();

    if(neg != 1)
    {
        im.insert(0, "+");
    }
    int lenIm = im.length();
    im.insert(lenIm , "i");
    return re+im;
}


string comp_add(string num1 , string num2)
{
    float real1,real2,imag1,imag2;
    comp_splitter(num1 , real1 , imag1);
    comp_splitter(num2 , real2 , imag2);
    float SumReal=real1+real2;
    float SumImag=imag1+imag2;
    return comp_combine(SumReal , SumImag);
}

string comp_sub(string num1 , string num2)
{
    float real1,real2,imag1,imag2;
    comp_splitter(num1 , real1 , imag1);
    comp_splitter(num2 , real2 , imag2);
    float SumReal=real1-real2;
    float SumImag=imag1-imag2;
    return comp_combine(SumReal , SumImag);
}




int main()
{

    float real;
    float imag;

    string num;
    num="33-4444i";

    comp_splitter("-3.55-4.21i" , real , imag);
    //cout << real << " " << imag;

    cout << comp_add("1+3i" , "2+4i");


    return 0;
}
