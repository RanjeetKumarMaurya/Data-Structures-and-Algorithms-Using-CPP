void printPatt(int n)
{
    //write your code here
    for(int i=1; i<=n; i++){
        int p1='A'+n-i;
        for(int j=1; j<=i; j++){
            cout<<(char)p1;
            p1++;
        }
        cout<<endl;
    }
}

