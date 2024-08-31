int f(int k)
{
    int t;
    if(k==1)
    {
        return 1;
    }
    else
    {
        t=k+f(k-1);
        return t;
    }

}

