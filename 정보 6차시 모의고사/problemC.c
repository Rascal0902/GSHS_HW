bool isPrime(int k)
{
    if(k==1)
    {
        return 0;
    }
    int i;
    for(i=2;i<k;i++)
    {
        if(k%i==0)
           {
               return 0;
           }
    }
    return 1;
}

