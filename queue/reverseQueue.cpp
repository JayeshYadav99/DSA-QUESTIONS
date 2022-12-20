


void Rev(queue<int> &q)
{
  if(q.empty())
       {
           return ;
       }
      int k=q.front();
      q.pop();
      Rev(q);
      q.push(k);
    
}
queue<int> rev(queue<int> q)
{
Rev(q);
return q;
         

}