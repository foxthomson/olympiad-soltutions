/*
ID: 11athom1
TASK: ratios
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");
    
    // goal
    int x, y, z;
    fin >> x >> y >> z;
    
    // mixtures
    int a, b, c;
    int d, e, f;
    int g, h, i;
    fin >> a >> b >> c;
    fin >> d >> e >> f;
    fin >> g >> h >> i;

    int best = 0;
    int balpha, bbeta, bgamma;
    bool found = false;
    int bdelta;
    
    for (int alpha = 0; alpha <= 100; alpha++)
        for (int beta = 0; beta <= 100; beta++)
            for (int gamma = 0; gamma <= 100; gamma++)
            {
//                cout << alpha << " " << beta << " " << gamma << endl;
                if ((x==0 && alpha*a + beta*d + gamma*g == 0 || (x!=0 && (alpha*a + beta*d + gamma*g)%x == 0)))
                    if ((y==0 && (alpha*b + beta*e + gamma*h) == 0 || (y!=0 && (alpha*b + beta*e + gamma*h)%y == 0)))
                        if ((z==0 && (alpha*c + beta*f + gamma*i) == 0 || (z!=0 && (alpha*c + beta*f + gamma*i)%z == 0)))
                            if (!(x*y) || ((alpha*a + beta*d + gamma*g)/x == (alpha*b + beta*e + gamma*h)/y))
                                if (!(x*z) || (alpha*a + beta*d + gamma*g)/x == (alpha*c + beta*f + gamma*i)/z)
                                    if (!(alpha==beta && alpha==gamma && alpha==0))
                                        if (!found || alpha+beta+gamma < best)
                                        {
                                            found = true;
                                            best = alpha+beta+gamma;
                                            balpha = alpha;
                                            bbeta = beta;
                                            bgamma = gamma;
                                            bdelta = (alpha*a + beta*d + gamma*g)/x;
                                        }
            }
    if (found)
        fout << balpha << " " << bbeta << " " << bgamma << " " << bdelta << endl;
    else
        fout << "NONE" << endl;
    
    return 0;
}

