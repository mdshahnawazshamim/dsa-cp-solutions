class MinHeap {
  private:
    // Initialize your data members
    vector<int> v;

  public:

    void push(int x) {
        // Insert x into the heap
        v.push_back(x);
        int i = v.size()-1;
        
        while(i!=0)
        {
            int p = (i-1)/2;
            
            if(v[p]>v[i])
            {
                swap(v[p],v[i]);
            }
            else
            {
                break;
            }
            i=p;
        }
    }

    void pop() {
        // Remove the top (minimum) element
        int N = v.size();
        swap(v[0],v[N-1]);
        
        v.pop_back();
        N--;
        
       int i=0;
       while((2*i)+1<N)
       {
        int mini = (2*i)+1;
        if(((2*i)+2) < N && v[(2*i)+2]<v[(2*i)+1])
        {
            mini = (2*i)+2;
        }
        
        if(v[i]>v[mini])
        {
            swap(v[i],v[mini]);
            i=mini;
        }
        else
        {
            break;
        }
       }
        
    }

    int peek() {
        // Return the top element or -1 if empty
        if(v.size()!=0)
        {
            return v[0];
        }
        else
        {
            return -1;
        }
    }

    int size() {
        // Return the number of elements in the heap
        return v.size();
    }
};
