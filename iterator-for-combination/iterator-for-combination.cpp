class CombinationIterator 
{
    public:
    vector<int> p;
    string c;
    int f=0;
    int l,n;
    CombinationIterator(string characters, int combinationLength) 
    {
        c=characters;
        l=characters.length();
        n=combinationLength;
        for(int i=0;i<combinationLength;i++) p.push_back(i);
    }
    
    string next() 
    {
        string result="";
        if(f==0)
        {
            for(int i=0;i<n;i++) result+=c[p[i]];
            f=1;
            return result;
        }
        for(int i=n-1;i>-1;i--)
        {
            if(p[i]!=i+l-n)
            {
                p[i]++;
                for(int j=i+1;j<n;j++) p[j]=p[i]+j-i;
                break;
            }
        }
        for(int i=0;i<n;i++) result+=c[p[i]];
        return result;
    }
    
    bool hasNext() 
    {
        return p[0]!=l-n||f==0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */