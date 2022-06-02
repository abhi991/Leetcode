class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int tot=0 , cnt = 0 , ans=0;
        queue <pair <int,int>> rotten;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] != 0) {
                    tot++; //total oranges
                }
                if(grid[i][j] == 2){
                    rotten.push({i,j}); //rotten ones
                }
            }
        }
        
        int dx[4] = {0 ,0, 1 ,-1};
        int dy[4] = {1 , -1 , 0 ,0};
        
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt+=k;
            while(k--){
                int x = rotten.front().first , y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 1) continue;
                    grid[nx][ny]=2;
                    rotten.push({nx ,ny});
                }
            }
            if(!rotten.empty()) ans++;
            
        }
        if(tot == cnt)return ans;
        return -1;
    }
};