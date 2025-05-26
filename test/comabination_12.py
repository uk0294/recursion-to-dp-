class Solution:
    def sum(self,i:int,arr:List[int],ans:List[List[int]],curr:List[int],target:int,n:int):
        if target==0:
            ans.append(list(curr))
            return
        for j in range(i,n):
            if j!=i and arr[j]==arr[j-1]:
                continue
            if arr[j]>target :
                break

            curr.append(arr[j])
            self.sum(j,arr,ans,curr,target-arr[j],n)
            curr.pop()
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n=len(candidates)
        ans=[]
        curr=[]
        self.sum(0,candidates,ans,curr,target,n)
        return ans 
        