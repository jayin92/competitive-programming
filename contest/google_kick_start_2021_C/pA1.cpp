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


string minus_1(string s, int k){
    int sz = s.size();
    if(sz % 2 == 1){
        int i = sz / 2;
        s[i] --;
        if(s[i] >= 'a') return s;
        
        s[i] = 'a' + k - 1;
        for(i--;i>=0;i--){
            s[i] = s[sz - i - 1] = s[i] - 1;
            if(s[i] >= 'a') return s;            
            s[i] = s[sz - i - 1] = 'a' + k - 1;
        }
    } else {
        for(int i=sz/2-1;i>=0;i--){
            s[i] = s[sz - i - 1] = s[i] - 1;
            if(s[i] >= 'a') return s;            
            s[i] = s[sz - i - 1] = 'a' + k - 1;        
        }
    }

    return "-1";
}

string add_1(string s, int k){
    int sz = s.size();
    if(sz % 2 == 1){
        int i = sz / 2;
        s[i] ++;
        if(s[i] - 'a' + 1 <= k) return s;
        
        s[i] = 'a';        
        for(i--;i>=0;i--){
            s[i] = s[sz - i - 1] = s[i] + 1;
            if(s[i] - 'a' + 1 <= k) return s;            
            s[i] = s[sz - i - 1] = 'a';        
        }
    } else {
        for(int i=sz/2-1;i>=0;i--){
            s[i] = s[sz - i - 1] = s[i] + 1;
            if(s[i] - 'a' + 1 <= k) return s;            
            s[i] = s[sz - i - 1] = 'a';        
        }
    }

    return "-1";
}

bool check(string s){
    int sz = s.size();
    for(int i=0;i<sz/2;i++){
        if(s[i] != s[sz-i-1]) return false;
    }
    return true;
}
/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    int case_ = 1;
    while(t--){
        ll ans = 1;
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << "Case #" << case_++ << ": ";
        int sz = s.size();
        string ss(s);
        for(int i=0;i<sz/2;i++){
            ss[sz - i - 1] = ss[i];
        }
        bool flag = false;
        while(ss >= s){
            ss = minus_1(ss, k);
            if(ss == "-1"){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        int szz = 0;
        if(sz % 2 == 0){
            szz = sz / 2 - 1;
        } else {
            szz = sz / 2;
        }
        ll tmp = 1;
        debug(ss, szz);
        for(int i=szz;i>=0;i--){
            ans += (ss[i] - 'a') * tmp;
            ans %= MOD;
            tmp *= k;
            tmp %= MOD;
            while(tmp <= 0) tmp += MOD;
            while(ans <= 0) ans += MOD;
            ans %= MOD;
            tmp %= MOD;
        }
        while(ans <= 0) ans += MOD;
        cout << ans % MOD << endl;
    }

    return 0;
}