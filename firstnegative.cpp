//First negative integer in every window of size K

//Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

 
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {  
deque<int> q;
vector<long long> ans;
 int i;
for(int i=0;i<K;i++)
{
   if(A[i]<0)
   {
       q.push_back(i);
   }
}
if(!q.empty())
       {
           ans.push_back(A[q.front()]);
       }
       else{
           ans.push_back(0);
       }
      
   for(i=K;i<N;i++)
   {
       
       while((!q.empty()) && i-q.front()>=K)
       {
           q.pop_front();
       }
        if(A[i]<0)
        {
           q.push_back(i);
        }
      if(!q.empty())
       {
           ans.push_back(A[q.front()]);
       }
       else{
           ans.push_back(0);
       }
       
   }
   return ans;


   
                                                 
 }
 
 
 