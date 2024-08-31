int f(int a)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a==d[i])
        {
            return i;
        }
    }
    return -1;
}
