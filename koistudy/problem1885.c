int  findi(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(k==d[i])
        {
            return i;
        }
    }
    return -1;
}
