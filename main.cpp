//بسم الله الرحمن الرحيم


#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
//using u128 = __uint128_t;
#define el << '\n'
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while(_--)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
ll gcd ( ll  a, ll b ) { return __gcd ( a, b ) ; }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ) ; }
int dx[]={0,0,+1,-1,+1,-1,-1,+1} ;
int dy[]={+1,-1,0,0,+1,-1,+1,-1} ;
///   ***   ---   |||__________LET'S BEGIN (-_^)________|||   ---   ***   ///

const ll infLL = 1e15 ;
const int inf = 1e9 ;
const ll mod = 1e6+3 ;
const int mx = 1e2+123;
int n , a[mx] , dp[mx][mx][mx];

int solve(int index,int premin, int premax)
{
    if(index>n) return 0 ;
    else if(dp[index][premin][premax]!=-1) return dp[index][premin][premax];
    int res=202;
    if(a[index]>premin) res=min(res,solve(index+1,a[index],premax));
    if(a[index]<premax) res=min(res,solve(index+1,premin,a[index]));
    res=min(res,1+solve(index+1,premin,premax));
    return dp[index][premin][premax]=res;
}

int main( )
{
    while(cin >> n)
    {
        if(n==-1) break ;
        memset(dp,-1,sizeof dp);
        set<int>s;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        unordered_map<int,int>m;
        int flag=1;
        for(auto i:s)
            m[i]=flag++;
        for(int i=1;i<=n;i++)
            a[i]=m[a[i]];

        cout << solve(1,0,201) el;

    }
}

///////////* ________ *  N A Y E M  * ________ *///////////