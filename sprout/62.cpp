#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int sz;
bool flag = false;
vector<pii> em;


void print(vector<vector<int>>& b){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(pii pos, int val, vector<vector<int>>& b){ 
    if(val == 0) return true;
    // print(b);
    // debug(pos, val);
    for(int i=0;i<9;i++){
        if((b[pos.X][i] == val) && (i != pos.Y)){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(b[i][pos.Y] == val && (i != pos.X)){
            return false;
        }
    }
    int x = (pos.X/3)*3;
    int y = (pos.Y/3)*3;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(b[i][j] == val && (i != pos.X || j != pos.Y)){
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<int>>& b){
    // debug(dep);

    // debug(ori);
    // print(b);
    for(auto z:em){
        int i = z.X;
        int j = z.Y;
        if(b[i][j] == 0){
            for(int num=1;num<=9;num++){
                // debug(i, j, num);
                if(check(mp(i, j), num, b)){      
                    // debug(i, j);              
                    b[i][j] = num;
                    if(solve(b)){
                        return true;
                    }
                    b[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    string s;
    vector<vector<int>> ori(9, vector<int>(9));
    while(true){
        cin >> s;
        if(s == "end") break;
        sz = 0;
        REP(i, 9){
            REP(j, 9){
                int idx = i*9 + j;
                ori[i][j] = (s[idx] == '.' ? 0 : s[idx] - '0');
                if(ori[i][j] == 0){
                    sz ++;
                    em.eb(i, j);
                }
            }
        }
        flag = false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(check(mp(i, j), ori[i][j], ori) == false){
                    cout << "No solution." << endl;
                    flag = true;
                    break;
                }   
            }
            if(flag) break;
        }
        if(flag) continue;
        if(solve(ori)){
            for(int i=0;i<9;i++) for(int j=0;j<9;j++) cout << ori[i][j];
            cout << endl;
        } else {
            cout << "No solution." << endl;
        }

    }

    return 0;
}