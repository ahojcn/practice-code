//#include <stdio.h>
//#include <string.h>
//
///*
//6
//0 12 0 0 0 0
//0 0 10 0 0 7
//0 0 0 3 5 6
//0 0 0 0 4 0
//0 0 0 0 0 2
//16 0 0 0 0 0
//2 4
// */
//
//#define max 10000;
//
////int arcs[100][100]; //保存邻接矩阵
//int arcs[101][101] = {
//        0, 12, 0, 0, 0, 0,
//        0, 0, 10, 0, 0, 7,
//        0, 0, 0, 3, 5, 6,
//        0, 0, 0, 0, 4, 0,
//        0, 0, 0, 0, 0, 2,
//        16, 0, 0, 0, 0, 0,
//};
//int d[100]; // 记录源点到各节点的最短路径
//int fina[100]; // 记录节点是否已经判断过，1代表已经运算过(在集合s中)
//int n; // 邻接矩阵的边数
//int v0, v1; // 表示起始点和终点
//char vc0, vc1;
//int p[100]; // 记录路径
//
//int len = 0;
//
//char *city = "ABCDEF";
//
//void dijkstra() {
//    int v, k;
//    int min;
//    for (v = 0; v < n; v++) //初始化
//    {
//        fina[v] = 0;
//        d[v] = arcs[v0][v];
//    }
//    d[v0] = 0;
//    fina[v0] = 1;
//    //主循环
//    for (int i = 1; i < n; i++) {
//        min = max;
//        //选出权值最小的点
//        for (k = 0; k < n; k++) {
//            if (fina[k] == 0) //k点在v-s中，尚未进行处理
//            {
//                if (d[k] < min) {
//                    v = k;
//                    min = d[k];
//                    len += 1; ////
//                }
//            }
//        }
//        fina[v] = 1; //表示已经处理过，加入集合s
//        for (k = 0; k < n; k++) {
//            if (fina[k] == 0 && (min + arcs[v][k] < d[k])) {
//                p[k] = v;
//                d[k] = min + arcs[v][k];
//            }
//        }
//    }
//}
//
//void print(int sec, int n)       //sec为出发节点，n表示图中节点总数
//{
//    int i, j;
//    int m, p2[100] = {0};
//    int t = 0, k;
//    j = v1;
//
//    printf("%d\n", len);
//
//    while (p[j] != -1) {
//        p2[t++] = p[j];
//        j = p[j];
//    }
//    printf("%c ", city[v0]);
////    printf("%d",v0);
//    for (k = 0; k < t; k++) {
//        if (p2[k] != 0) {
//            printf("%c ", city[p2[k]]);
////            printf("%d\n",p2[k]);
//        }
//    }
//    printf("%c\n", city[v1]);
////    printf("%d",v1);
//}
//
//int main() {
//    n = 6;
//
//    while(scanf("%c %c", &vc0, &vc1) != EOF) {
//        for (int i = 0; i < strlen(city); i++) {
//            if (city[i] == vc0)
//                v0 = i;
//            if (city[i] == vc1)
//                v1 = i;
//        }
////    printf("%d %d ----- %c %c\n", v0, v1, vc0, vc1);
//
//        for (int i = 0; i < 100; i++) //路径初始化为-1
//        {
//            p[i] = -1;
//        }
//        dijkstra();
//        print(v0, n);
//    }
//    return 0;
//}





/*
6
9
1 2 12
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
6 1 16
*/

//第一遍看代码的时候 可以忽略所有带有path的行，只看路径长度算法
//第二遍再看带有path的行，得到路径上的节点序列

//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//#include <math.h>
//#include <stdlib.h>
//
//using namespace std;
//
//void shortest_path(int n,int cost[101][101]){
//    bool s[101];    //判断该节点是否已经被加入
//    int dist[101];    //存结果的数组
//    string path[101];   //存路径的数组，没更新一次dist,路径也更新一次
//    string init_path="v1";
//    //初始化
//    dist[1]=0;
//    s[1]=true;
//
//    for(int i=2;i<=n;i++){
//        s[i]=false;
//        dist[i]=-1;
//    }
//
//    //只加入了第一个节点的dist数组
//    for(int i=2;i<=n;i++){
//        dist[i]=cost[1][i];
//        path[i]=init_path+"v"+to_string(i);//初始化 每个节点的路径就是v1到这个节点vi
//    }
//    //cout<<dist[2]<<endl;
//    //cout<<dist[3]<<endl;
//    //上述步骤已经完成了只有第一个节点的初始化
//    //下一步：从dist中 找到一个距离最短的边，并把顶点加入s数组
//
//    for(int i=2;i<=n;i++){ //剩下的N-1轮迭代
//        int ii = 0; //记录该轮被加入的节点
//        for(int j=2;j<=n;j++){//从第二个节点 到最后一个节点
//            int min=1000;
//            if(s[i]==false && dist[i]>0 && dist[i]<min){
//                min=dist[i];
//                ii=i;
//            }
//        }
//
//        s[ii]=true;
//
//        for(int i=2;i<=n;i++){
//            if(cost[ii][i]!=-1 && s[i]==false){//如果新加入的节点ii到i节点有路径 而且i不在已选取的节点中
//                if(dist[i]!=-1){ //v1到i节点有路径
//                    if(dist[i]>dist[ii]+cost[ii][i]){//而且 经过ii节点的路径更短
//                        dist[i]=dist[ii]+cost[ii][i]; //更新dist
//                        path[i]=path[ii]+"v"+to_string(i);
//                    }
//                }
//                else{//v1到i没有路径
//                    dist[i]=dist[ii]+cost[ii][i];
//                    path[i]=path[ii]+"v"+to_string(i);
//                }
//            }
//        }
//    }
//    //cout<<dist[n];
//    cout<<"start"<<"   "<<"end"<<"   "<<"length"<<"   "<<"nodes list"<<endl;
//    for(int i =2;i<=n;i++){
//        if(dist[i]<100){//决定输出的空格数 控制格式
//            cout<<"v1      "<<"v"<<i<<"    "<<dist[i]<<"       "<<path[i]<<endl;
//        }
//        else{
//            cout<<"v1      "<<"v"<<i<<"    "<<dist[i]<<"      "<<path[i]<<endl;
//        }
//    }
//}
//
//int main(){
//    // insert code here...
//    int n;  //节点个数
//    int m;  //边的个数
//    int a,b,c;
//    int cost[101][101];   //保存各节点间的代价
//
//    while(scanf("%d%d",&n,&m)!=0){
//        //cost数组的初始化
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++){
//                cost[i][j]=-1;
//            }
//        }
//        for(int i = 0;i<m;i++){
//            scanf("%d%d%d",&a,&b,&c);
//            cost[a][b]=c;
//        }
//        //cout<<"第一次初始化";
//        shortest_path(n,cost);
//    }
//
//}












//#include <stdio.h>
//
//
//typedef struct Node
//{
//    int data;
//    struct Node* next;
//} Node, *LinkList;
//
//int main()
//{
//    Node n{};
//
//    typedef int i, *pint;
//    int a = 10;
//
//    pint p = &a;
//    i aaa = 20;
//
//    printf("%d\n", *p);
//    printf("%d\n", aaa);
//
//    return 0;
//}





































