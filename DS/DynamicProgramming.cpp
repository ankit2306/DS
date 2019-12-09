unsigned long UglyNumbers(unsigned int n)
{
    int factor[] = {0};
    int max_num = 0;
    int* ugly = new int[n];
    ugly[0] = 1;
    
}

unsigned int min(unsigned int a, unsigned int b, unsigned int c)
{
    if(a < b)
        return b < c ? a : b;
    else
        return b > c ? c : b;   
}