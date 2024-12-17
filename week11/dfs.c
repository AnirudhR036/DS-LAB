#include<stdio.h>
void dfs(int v,int n);
int a[10][10], vis[10];
void main(){

int i,j,n,m,flag;
printf("Enter the Number of vertices ");
scanf("%d",&n);
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("Enter element %d %d ",i,j);
        scanf("%d",&a[i][j]);
    }
}
for(int i=1;i<=n;i++){
    vis[i]=0;
}
printf("Enter the vertex to start DFS from ");
scanf("%d",&m);
dfs(m,n);
for(int i=1;i<=n;i++){
    if(vis[i]==0){
        int flag=1;
    }
}
if(flag==1){
    printf("\nThe graph is not connected");
}
else{
    printf("\nThe graph is connected");
}
}
void dfs(int v,int n){
    vis[v]=1;
    printf("%d",v);
    for(int k=1;k<=n;k++){
    if(a[v][k]==1 && vis[k]==0){
        dfs(k,n);}
    }
}
