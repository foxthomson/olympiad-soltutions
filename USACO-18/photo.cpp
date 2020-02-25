#include <fstream>
#include

using namespace std;

int pp[1024];
int order[1024];
int pos[1024];

int main(int argc, char** argv) 
{
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n; i++)
    {
        fin >> order[i];
        pos[order[i]] = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            pp[i] = pp[i-1];
        }
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (order[j] == i)
            {
                found = true;
            }
            if (found && order[j] < i)
            {
                pp[i]++;
            }
        }
    }
    
    int bottom = 0;
    int top = n;
    int check = n;
    
    while (top - bottom > 0)
    {
        
    }
    
    return 0;
}

