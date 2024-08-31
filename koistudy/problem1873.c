int f(int k)
{
    int i,t=0;
    for(i=1;i<=k;i++)
    {
        if(k%i==0)
        {
            t++;
        }
    }
    return t;
}
