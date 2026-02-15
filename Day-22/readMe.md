# Smallest window containing 0, 1 and 2
##### first find in this problem our substring having 0,1,2 for that we use every index variable if 1 exist then we change to true do for alls 0 and one also then we calculate index at every time and we calculate len when all exist in subarray and finding max - min of there index max is for last index like 2 find at some index at 5 then all three condtion true and min is our first true is start and cal difference between then and add +1 then give this our len and comare with prev and upadte this is logic



# second approch is using sliding windo
##### first we have check all three values are exist or not for this we use freq array and of size 3 contain 0,1,2 index and update index every time and using i and k pointer we slide the windo k for next and i for shrinking then first we update freq then check this elemnt occour at ones then we increase count then if count is 3 then we conclude that all are inclues in string then for recheck some elemnt in i sides are dulicates so usinf while we moves i to last of duplicates and aslo update freq aftert that we update min_len with new len and update freq then update i and last we update k

