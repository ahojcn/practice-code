class fuck {
public:
    int _id;
    double _x;
    double _y;
    
    bool _in_circle;
};

class aoe {
public:
    double _x;
    double _y;
    double _r;
}

fuck f[10000];
aoe a[10000];

bool func(fuck f, aoe a) {
    int d = sqrt((f._x - a._x) * (f._x - a._x) + (f._y - a._y) * (f._y - a._y));
    if (d <= r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    using namespace std;
    int n, w, h, r;
    cin >> n >> w >> h >> r;
    for (int i = 0; i < n; ++i) {
        cin >> f[i]._id >> f[i]._x >> f[i]._y;
    }

    int m = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i]._x >> a[i]._y >> a[i]._r;
    }

    int cnt = 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++i) {
            if (func(f[i], m[i])) {
                f[i]._in_circle = true;
                cnt+=1;
            }
        }
    }

    return 0;
}





class fuck {
public:
    int _id;
    double _x;
    double _y;

    bool _in_circle;
};

class aoe {
public:
    double _x;
    double _y;
    double _r;
};

fuck f[10000];
aoe a[10000];

bool func(fuck f, aoe a) {
    int d = sqrt((f._x - a._x) * (f._x - a._x) + (f._y - a._y) * (f._y - a._y));
    return d <= a._r;
}

int main() {
    using namespace std;
    int n, w, h, r;
    cin >> n >> w >> h >> r;
    for (int i = 0; i < n; ++i) {
        cin >> f[i]._id >> f[i]._x >> f[i]._y;
    }

    int m = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i]._x >> a[i]._y >> a[i]._r;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++i) {
            if (func(f[i], a[i])) {
                f[i]._in_circle = true;
                cnt+=1;
            }
        }
    }

    return 0;
}