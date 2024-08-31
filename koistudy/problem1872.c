
long long int f(int k)
{
    if(k==1)
    {
        return 1;
    }
    else
    {
        long long int s;
        s=(long long)k*f(k-1);
        return s;

    }

}
