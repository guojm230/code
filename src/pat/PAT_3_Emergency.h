#pragma once
#include <iostream>
#include <queue>

/**
*description:
*一个无向图，其中每个点和边均有权重，边权重均>=1，给定两个顶点C1,C2
*找出C1到C2的最短路径，并记录路径条数，
*多条路径时选择输出路径节点上点权重和最大的那条，并输出节点的权重值和。
*和常规深度遍历不同的是，该题需要找出多条最短路径.
*/
namespace PAT_3_Emergency_adj{
    #include <iostream>
    using namespace std;
    struct Edge {
        int v1 = -1;
        int v2 = -1;
        int length = 0;
        Edge *next = nullptr;
    };
    struct Vertex {
        int index;
        int val;
        bool marked;
        Edge *next;
    };

    Vertex *buildGraph();
    void dijkstra();
    Vertex* findMinVertex();
    inline Vertex* other(Vertex *vertex,Edge *edge);

    int N, M, C1, C2, i = 0;
    int* dist = nullptr;
    int* num = nullptr;
    int* teams = nullptr;

    Vertex* vs = nullptr;

    int main() {
        iostream::sync_with_stdio(false);
        cin >> N >> M >> C1 >> C2;
        vs = buildGraph();
        dist = new int[N];
        num = new int[N]();
        teams = new int[N]();
        for (; i < N; ++i) {
            dist[i] = INT32_MAX;
        }
        teams[C1] = vs[C1].val;
        num[C1] = 1;
        dijkstra(C1);
        cout<<num[C2]<<" "<<teams[C2]<<endl;
        return 0;
    }

    void dijkstra(){
        dist[C1] = 0;
        Vertex *min = nullptr,*oe = nullptr;
        Edge* temp = nullptr;
        while((min = findMinVertex()) != nullptr){
            min->marked = true;
            temp = min->next;
            while(temp != nullptr){
                oe = other(min,temp);
                if (dist[oe->index] > dist[min->index] + temp->length) {
                    dist[oe->index] = dist[min->index] + temp->length;
                    num[oe->index] = num[min->index];
                    teams[oe->index] = teams[min->index] + oe->val;
                } else if (dist[oe->index] == dist[min->index] + temp->length) {
                    num[oe->index] += num[min->index];
                    if(teams[oe->index] < teams[min->index] + oe->val){
                        teams[oe->index] = teams[min->index] + oe->val;
                    }
                }
                temp = temp->next;
            }
        }
    }

    Vertex* findMinVertex(){
        int min = INT32_MAX;
        int minIndex = -1;
        for (i = 0; i < N; ++i) {
            if(!vs[i].marked && dist[i] < min){
                min = dist[i];
                minIndex = i;
            }
        }
        return minIndex == -1 ? nullptr : vs + minIndex;
    }

    inline Vertex* other(Vertex *vertex,Edge *edge){
        return vertex->index != edge->v1 ? vs+edge->v1 : vs+ edge->v2;
    }

    Vertex* buildGraph() {
        int j = 0, k = 0, l = 0;
        vs = new Vertex[N];
        for (; i < N; i++) {
            cin >> j;
            vs[i] = Vertex{i,j,false,nullptr};
        }
        //add edge
        for (i = 0; i < M; i++) {
            cin >> j >> k >> l;
            auto *e = new Edge{j, k, l, nullptr};
            Edge *temp = vs[j].next;
            e->next = temp;
            vs[j].next = e;
            e = new Edge{k, j, l, nullptr};
            temp = vs[k].next;
            e->next = temp;
            vs[k].next = e;
        }
        return vs;
    }


    void printGraph() {
        cout << "共有" << N << "个顶点" << M << "条边" << "\n";
        Edge *edge = nullptr;
        for (i = 0; i < N; i++) {
            cout << "第" << i << "个顶点,值为：" << vs[i].val << " 边为:";
            edge = vs[i].next;
            while (edge != nullptr) {
                cout << edge->v1 << "-" << edge->v2 << ":" << edge->length << "; ";
                edge = edge->next;
            }
            cout << "\n";
        }
        cout << endl;
    }
}

//临界矩阵实现
namespace PAT_3_Emergency_matrix{
#define MAX_SIZE 500
#include <iostream>
    using namespace std;

    int graph[MAX_SIZE][MAX_SIZE];
    int dist[MAX_SIZE];
    int num[MAX_SIZE];
    int teams[MAX_SIZE];
    int maxTeams[MAX_SIZE];
    bool vis[MAX_SIZE];
    int N,M,C1,C2;

    void buildGraph(){
        cin>>N>>M>>C1>>C2;
        int i = 0,j=0,k=0,l=0;
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                graph[i][j] = INT32_MAX;
            }
        }

        for(i = 0;i < N; i++){
            graph[i][i] = 0;
            cin>>teams[i];
        }

        for(i = 0;i < M; i++){
            cin>>j>>k>>l;
            graph[k][j] = graph[j][k] = l;
        }
    }

    void dijkstra(){
        //fina min vertex unknown
        while(true){
            int minDist = INT32_MAX;
            int minIndex = -1;
            for(int i = 0;i< N;i++){
                if(!vis[i] && dist[i] < minDist){
                    minDist = dist[i];
                    minIndex = i;
                }
            }
            if(minIndex == -1)
                break;
            vis[minIndex] = true;
            for(int i = 0;i < N;i++){
                if(graph[minIndex][i] < INT32_MAX && i != minIndex){
                    if(dist[i] > minDist + graph[minIndex][i] ){
                        num[i] = num[minIndex];
                        dist[i] = minDist + graph[minIndex][i];
                        maxTeams[i] = maxTeams[minIndex] + teams[i];
                    } else if (dist[i] == minDist + graph[minIndex][i] ){
                        num[i] += num[minIndex];
                        if(maxTeams[i] < maxTeams[minIndex] + teams[i]){
                            maxTeams[i] = maxTeams[minIndex] + teams[i];
                        }
                    }
                }
            }
        }
    }

    int main(){
        std::iostream::sync_with_stdio(false);
        buildGraph();
        for (int & i : dist) {
            i = INT32_MAX;
        }
        dist[C1] = 0;
        num[C1] = 1;
        maxTeams[C1] = teams[C1];
        dijkstra();
        cout<<num[C2]<<" "<<maxTeams[C2];
        return 0;
    }
}
