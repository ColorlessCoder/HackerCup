#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define MAX 50010
#define LL double
#define inf 1e15
#define INF 10000000
#define mod 1000000007
#define N 502
#define mMax 30010
#define nMax 2010
#define SZ(a) a.size()
#define pb push_back
#define mp make_pair
using namespace std;
#define pll pair<LL,LL>
set<pll >::iterator next(set<pll >::iterator it)
{
set<pll >::iterator it2;
it2=it;
it2++;
return it2;
}
set<pll >::iterator prev(set<pll >::iterator it)
{
set<pll >::iterator it2;
it2=it;
it2--;
return it2;
}
//LL bigmod(LL a,LL p)
//{
//    if(p==0ll) return 1ll;
//    if(p%2==1) return ((a%mod) * bigmod(a,p-1))%mod;
//    LL b=bigmod(a,p/2ll);
//    return (b*b)%mod;
//}
set<pll > S;
int main()
{

   freopen("big_top.txt","r",stdin);
   freopen("output.txt","w",stdout);
    int T,I=1;
    cin>>T;
    while(T--)
    {
        printf("Case #%d: ",I++);
        S.clear();
        int n;
        scanf("%d",&n);
        LL Ax,Bx,Ah,Bh,Cx,Ch;
        LL X,H;
        scanf("%lf %lf %lf %lf",&X,&Ax,&Bx,&Cx);
        scanf("%lf %lf %lf %lf",&H,&Ah,&Bh,&Ch);
        double area=H*H;
        S.insert(mp(X,H));
        double total=area;
        for(int i=1;i<n;i++)
        {
                X=fmod((X*Ax   +Bx),Cx)+1;
                H=fmod((H*Ah   +Bh),Ch)+1;
                set<pll >::iterator it,it2,it3;
                it=S.upper_bound(mp(X,H));
                if(it!=S.begin()){
                    it2=prev(it);
                    if(it2->sc>H && (X-it2->fr) <= (it2->sc -H))
                        {
                            total+=area;
                            continue;
                        }
                }
                if(it!=S.end()){
                    it2=it;
                    if(it2->sc>H && (it2->fr-X) <= (it2->sc -H)){
                            total+=area;
                        continue;
                    }
                }
                S.insert(mp(X,H));
                it=S.find(mp(X,H));
                if(next(it)==S.end())
                {
                    it2=prev(it);
                    area-= 0.5*it2->sc*it2->sc;
                }
                else if(it==S.begin())
                {
                    it2=next(it);
                    area-= 0.5*it2->sc*it2->sc;
                }
                else{
                    it2=prev(it);
                    it3=next(it);
                    double y=max(0.0,it2->sc+it3->sc - it3->fr+it2->fr);
                    y/=2;
                    LL x=(it2->sc - y);
                    area-= x*(y + it2->sc)*0.5;
                    x=(it3->sc - y);
                    area-= x*(y + it3->sc)*0.5;
                }
                it3=next(it);
                while(1)
                {
                    if(it3==S.end())
                    {
                        area+= 0.5*H*H;
                        break;
                    }
                    LL y=max(0.0,H+it3->sc - it3->fr+X);
                    y/=2;
                    if(it3->sc >= H || y<it3->sc)
                    {
                        LL x=(H-y);
                        area+= 0.5*x*(H+y);
                        x=(it3->sc-y);
                        area+= 0.5*x*(it3->sc+y);
                        break;
                    }
                    it2=next(it3);
                    if(it2==S.end())
                    {
                        area-= 0.5*it3->sc*it3->sc;
                    }
                    else
                    {
                    y=max(0.0,it2->sc+it3->sc - it2->fr+it3->fr);
                    y/=2;
                    LL x=(it2->sc - y);
                    area-= x*(y + it2->sc)*0.5;
                    x=(it3->sc - y);
                    area-= x*(y + it3->sc)*0.5;
                    }
                        it2=next(it3);
                        S.erase(it3);
                        it3=it2;
                }
                if(it!=S.begin()) it2=prev(it);
                while(1)
                {
                    if(it==S.begin())
                    {
                        area+= 0.5*H*H;
                        break;
                    }
                    it3=it2;
                    LL y=max(0.0,H+it3->sc - X+it3->fr);
                    y/=2;
                    if(it3->sc >= H || y<it3->sc)
                    {
                        LL x=(H-y);
                        area+= 0.5*x*(H+y);
                        x=(it3->sc-y);
                        area+= 0.5*x*(it3->sc+y);
                        break;
                    }
                    if(it3==S.begin())
                    {
                        area-= 0.5*it3->sc*it3->sc;
                    }
                    else
                    {
                    it2=prev(it3);
                    y=max(0.0,it2->sc+it3->sc - it3->fr+it2->fr);
                    y/=2;
                    LL x=(it2->sc - y);
                    area-= x*(y + it2->sc)*0.5;
                    x=(it3->sc - y);
                    area-= x*(y + it3->sc)*0.5;
                    }
                    if(it3!=S.begin()) it2=prev(it3);
                        S.erase(it3);
                }
                total+=area;
        }
        printf("%.7lf\n",total);
    }
    return 0;
}
