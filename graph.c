
#include <stdio.h>

int t=-1, f=-1, r=-1;
int q[20], s[20], a[20][20], v[20];

void push(int item){
    if(t==19){
        printf("Full");
    }
    else{
        s[++t] = item;
    }
}

int pop(){
    if(t==-1){
        return 0;
    }
    else{
        return s[t--];
    }
}

void dfs(int s,int n){
    int p,i;
    push(s);
    v[s]=1;
    p=pop();
    if(p!=0){
        printf("%d\n",p);
    }
    while(p!=0){
        for(i=1;i<=n;i++){
            if(a[p][i] == 0 && v[i]==0){
                push(i);
                v[i] = 1;
            }
        }
        p=pop();
        if(p!=0){
            printf("%d\n",p);
        }
    }
    for(i=1;i<n;i++){
        if(v[i] == 0){
            dfs(i,n);
        }
    }
}

void add(int item){
    if(r==19){
        printf("Full");
    }
    else{
        q[++r] = item;
        if(f==-1){
            f++;
        }
    }
}

int delete(){
    int k;
    if(f>r || f==-1){
        return 0;
    }
    else{
        k = q[f++];
    }
}

void bfs(int s, int n){
    int p,i;
    add(s);
    v[s]=1;
    p=delete();
    if(p!=0){
        printf("%d\n", p);
    }
    while(p!=0){
        for(i=1;i<=n;i++){
            if(a[p][i] == 0 && v[i] == 0){
                add(i);
                v[i] = 1;
            }
        }
        p=delete();
        if(p!=0){
            printf("%d\n",p);
        }
    }
    for(i=1;i<=n;i++){
        if(v[i] == 0){
            bfs(i,n);
        }
    }
}
void main()
{
    int n, i, s, ch, j;
    char c, d;
    printf("ENTER THE NUMBER OF VERTICES ");
    scanf("%d", &n);
    printf("Read the Adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("THE ADJACENCY MATRIX IS\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        for (i = 1; i <= n; i++){
            v[i] = 0;
        }
        printf("\nMENU");
        printf("\n1.B.F.S");
        printf("\n2.D.F.S");
        printf("\nENTER YOUR CHOICE");
        scanf("%d", &ch);
        printf("ENTER THE SOURCE VERTEX :");
        scanf("%d", &s);

        switch (ch)
        {
        case 1:
           bfs(s, n);
            break;
        case 2:
            dfs(s, n);
            break;
        }
        printf("DO U WANT TO CONTINUE(Y/N) ? \n");
        scanf(" %c", &c);
    } while ((c == 'y') || (c == 'Y'));
}