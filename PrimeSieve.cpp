#include<bits/stdc++.h>

using namespace std;

int prime[300000], nPrime;
int mark[1000002]; //1 if not prime, 0 if prime

void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;
    mark[1] = 1;
    for(i = 4; i <= n; i += 2) mark[i] = 1; //all evens are not prime except 2.
    prime[nPrime++] = 2;
    for(i = 3; i <= n; i += 2) //odd number loop
    {
        if(!mark[i]) //if not prime, no need to do "multiple cutting"
        {
            prime[nPrime++] = i;
            if(i <= limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

int main()
{
    int n;
    sieve(100000);
    for(int i = 0; i < 100; i++) cout<<prime[i]<<endl; //print the first 100 prime numbers
    return 0;
}

