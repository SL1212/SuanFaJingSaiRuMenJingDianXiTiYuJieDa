// Symmetry, ACM/ICPC Seoul 2004, UVa1595
// 陈锋
#include<cassert>
#include<cmath>
#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
using namespace std;
int readint() { int x; scanf("%d", &x); return x;}

const double eps = 1e-7;
int dcmp(double x) { if(fabs(x) < eps) return 0; return x < 0 ? -1 : 1; }
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {}
    bool operator<(const Point& rhs) const {
        return dcmp(x-rhs.x) < 0 || dcmp(x-rhs.x) == 0 && dcmp(y-rhs.y) < 0;
    }
};

Point points[1024];
set<Point> pIndice;

int main()
{
    int T = readint();
    while(T--) {
        int N = readint();
        double sx = 0;
        pIndice.clear();
        for(int i = 0; i < N; i++) {
            Point& p = points[i];
            p.x = readint();
            p.y = readint();
            sx += p.x;
            pIndice.insert(p);
        }
        sx /= N;
        
        bool ans = true;
        for(int i = 0; i < N; i++) {            
            const Point& p = points[i];
            if(dcmp(p.x-sx) == 0) continue;
            Point p2(sx*2 - p.x, p.y);
            if(!pIndice.count(p2)) { ans = false; break; }
        }        
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
// 14804235	1595	Symmetry	Accepted	C++	0.052	2015-01-15 00:20:13