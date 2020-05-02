#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;


void comp_split(string num , float &r, float &i)
{

    string auth = num;
    int len= num.length();
    int sep,n=0,neg=0;

    if(num == "i")
    {
        r=0;
        i=1;
    }
    else if(num == "-i")
    {
        r=0;
        i=-1;
    }

    else
    {
            if(num.find("+") != -1)
    {

        if(num.find("+i")!= -1)
        {
            for(int j=0;j<len;j++)
            {
                if(num[j] == '+' || num[j] == '-')
                {
                    sep=j;
                }
            }
        num.erase(sep);
        r=atof(num.c_str());
        i=1;
        }

        else
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
    }

    else if(num.find("-") != -1)
    {

        if(num.find("-",1)!=-1)
        {
            for(int j=0;j<len;j++)
            {
                if(num[j] == '-')
                    {
                        sep=j;
                    }
            }

        num.erase(sep);
        r = atof(num.c_str());

        for(int j=sep;j<len-1;j++)
            {
                auth[n] = auth[j];
                n+=1;
            }
        auth.erase(n);

        if(auth == "-")
        {
            i= -1;
        }
        else
        {
            i = atof(auth.c_str());
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

    string res = re+im;
    int reslen = res.length();

    if(res.find("1i") != -1)
    {
        res[res.find("1i")] = 'i';
        res.erase(reslen-1);
        if(res[0] == '0')
        {
            if(res[1]=='+')
            {
                res = "i";
            }
            else if(res[1] == '-')
            {
                res = "-i";
            }
        }
    }
    else if(res.find("0i") != -1)
    {
        res.erase(reslen - 3);
    }

    else if(res[0] == '0')
    {
        if(res[1] == '+')
        {
            for(int i=2;i<reslen;i++)
            {
                res[i-2] = res[i];
            }
            res.erase(reslen -2);
        }
        else if(res[1] == '-')
        {
            for(int i=1;i<reslen;i++)
            {
                res[i-1] = res[i];
            }
            res.erase(reslen -1);
        }
    }

    return res;
}


string comp_add(string num1 , string num2)
{
    float real1,real2,imag1,imag2;
    comp_split(num1 , real1 , imag1);
    comp_split(num2 , real2 , imag2);
    float SumReal=real1+real2;
    float SumImag=imag1+imag2;
    return comp_combine(SumReal , SumImag);
}

string comp_sub(string num1 , string num2)
{
    float real1,real2,imag1,imag2;
    comp_split(num1 , real1 , imag1);
    comp_split(num2 , real2 , imag2);
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

    comp_split("3+i" , real , imag);
    //cout << real << " " << imag;

    cout << comp_sub("2+2i" , "1+3i");


    return 0;
}
