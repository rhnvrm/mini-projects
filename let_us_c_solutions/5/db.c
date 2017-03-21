int power(int a,int b)
{
    int s=1;
    while(b>0)
    {
        s=s*a;
        b--;
    }
    return s;
}

int main(){
    int a ,b;
    scanf("%d %d", &a, &b);

    printf("%d", power(a,b));
    return 0;
}
