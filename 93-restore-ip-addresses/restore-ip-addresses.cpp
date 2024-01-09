
class Solution {
private:
    int pos[4];
public:
    bool check(string ip)
    {
        if(ip.size()==1)
        {
            return "0"<=ip && ip<="9";
        }
        if(ip.size()==2)
        {
            return "10"<=ip && ip<="99";
        }
        if(ip.size()==3)
        {
            return "100"<=ip && ip<="255";
        }
        return false;
    }
    
    void dfs(string &s,int start,int dep,int maxDep,vector<string>& res)
    {
        if(dep==maxDep)
        {
            if(start==s.size())
            {
                int begin=0;
                string add="";
                for(int i=0;i<maxDep;++i)
                {
                    string ip(s,begin,pos[i]-begin+1);
                    begin=pos[i]+1;
                    add+=i==0?ip:"."+ip;
                }
                res.push_back(add);
                
            }
            return;
        }
        for(int i=start;i<s.size();++i)
        {
            string ip(s,start,i-start+1);
            if(check(ip))
            {
                pos[dep]=i;
                dfs(s,i+1,dep+1,maxDep,res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        //res.clear();
        if(s.size()>12)
            return res;
        dfs(s,0,0,4,res);
        return res;
    }
};