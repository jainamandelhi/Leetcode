int nt,dis;
map<int,int>prod;
int cnt=0;
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt=0;
        nt=n;
        dis=discount;
        for(int i=0;i<products.size();i++)
            prod[products[i]]=prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans=0;
        for(int i=0;i<product.size();i++)
        {
            ans=ans+amount[i]*prod[product[i]];
        }
        cnt++;
        if(cnt==nt)
        {
            cnt=0;
            double temp=1-dis/100.0;
            ans=ans*temp;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */