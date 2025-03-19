#include <stdio.h>

int a[10][10], vis[10], indegree[10], queue[10];
int i, j, n, f = -1, b = -1,count=0;

void toposort();
void enqueue(int);
int dequeue();

void main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");

    
    for (i = 1; i <= n; i++) {
        vis[i] = 0;
        indegree[i] = 0;
    }

    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            indegree[j] += a[i][j];
        }
    }

    
    for (i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
            vis[i] = 1;
        }
    }

    for (i = 1; i <= n; i++) {
        if (indegree[i] != 0) {
            count++;
        }
    }
    
    if(count<n)
    {
    printf("The Topologic sort sequence is: ");
    }

    else{
        printf("Cycle hence error!");
    }
    toposort();
}

void toposort() {
    while (f != -1) {
        int v = dequeue();
        if (v == -1) break; 
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (a[v][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0 && vis[i] == 0) {
                    enqueue(i);
                    vis[i] = 1;
                }
            }
        }
    }
}

void enqueue(int x) {
    if (b == n - 1) {
        printf("Overflow\n");
        return;
    }

    if (f == -1 && b == -1) {
        f = 0;
        b = 0;
    } else {
        b = b + 1;
    }
    queue[b] = x;
}

int dequeue() {
    if (f == -1) {
        printf("Underflow\n");
        return -1;
    }

    int item = queue[f];
    if (f == b) {
        f = -1;
        b = -1;
    } else {
        f = f + 1;
    }

    return item;
}
