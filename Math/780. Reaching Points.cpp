class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx <= tx && sy <= ty)
        {
            if(sx == tx && sy == ty)
                return true;
            if(tx == ty)
                return false;
            if(sx == tx)
                return (ty-sy) % sx == 0;
            if(sy == ty)
                return (tx-sx) % sy == 0;
            if(ty > tx)
                ty -= tx;
            if(tx > ty)
                tx -= ty;
        }
        return false;
    }
};