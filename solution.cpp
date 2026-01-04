using state=pair<int,int>;
#define F first
#define S second
const int INF=1000;
class Solution {
public:
    //0/1 BFS
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int dir[4]={3,1,4,2};
    int n,m;
    vector<vector<bool>>vis;
    vector<vector<int>>dist;
    vector<vector<int>>arr;
    bool is_valid(int x,int y){
        if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]){
            return true;
        }
        else
        return false;
    }
    vector<pair<state,int>> neighbours(state node){
        vector<pair<state,int>>neigh;
        for(int i=0;i<4;i++){
            int nx=node.F+dx[i];
            int ny=node.S+dy[i];
            if(is_valid(nx,ny)){
                int cost=1;
                if(arr[node.F][node.S]==dir[i]){
                    cost=0;
                }
                neigh.push_back({{nx,ny},cost});
            }
        }
        return neigh;
    }
    void bfs(state st){
        vis.assign(n,vector<bool>(m,false));
        dist.assign(n,vector<int>(m,INF));
        deque<state>dq;
        dq.push_front(st);
        dist[st.F][st.S]=0;
        while(!dq.empty()){
            state curr=dq.front();
            dq.pop_front();
            if(vis[curr.F][curr.S]){
                continue;
            }
            vis[curr.F][curr.S]=true;
            for(auto[v,wt]:neighbours(curr)){
                if(!vis[v.F][v.S]&&dist[v.F][v.S]>dist[curr.F][curr.S]+wt){
                    dist[v.F][v.S]=dist[curr.F][curr.S]+wt;
                }
                if(wt==0){
                    dq.push_front(v);
                }
                else
                dq.push_back(v);
            }
        }
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        arr=grid;
        bfs({0,0});
        return dist[n-1][m-1];
    }
};
