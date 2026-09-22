#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int bound(int &i){
    if(i >= 0 && i <= 2) return 0;
    if(i >= 3 && i <= 5) return 3;
    return 6;
}

bool full(int m[9][9]){

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            if(m[i][j] == -1) return 0;
        }
            
    
    return 1;
}

bool update(int m[9][9], pair<int,int> pos){

    set<int> r = {1,2,3,4,5,6,7,8,9};
    
    int l = pos.first;
    int c = pos.second;

    for(int i = 0; i < 9; i++)
        if(m[l][i] != -1)
            r.erase(m[l][i]);

    for(int i = 0; i < 9; i++)
        if(m[i][c] != -1)
            r.erase(m[i][c]);
    
    int l_bound = bound(l);
    int c_bound = bound(c);

    for(int i = l_bound; i < l_bound+3; i++){
        for(int j = c_bound; j < c_bound+3; j++){
            if(m[i][j] != -1)
                r.erase(m[i][j]);
        }
    }

    // for(auto x: r) cout<<x<<" "; cout<<endl;

    if(r.size() == 1){
        m[l][c] = *r.begin();
        return 1;
    }
    
    return 0;

}

int main(){

    auto start = steady_clock::now();

    int m[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>m[i][j];
        }
    }

    while(!full(m)){

        bool ok = 0;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(m[i][j] == -1){
                    pair<int,int> pos = {i,j};
                    ok+= update(m, pos);
                }
            }
        }

        if(!ok){
            cout<<"not a sudoki game"<<endl;
            break;
        }

    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    auto end = steady_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " us\n";

    return 0;
}
