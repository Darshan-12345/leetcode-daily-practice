# minimum windo substring

 for solving this question we think about windo in check a windo in this windo our char in t is exist then we shrink this windo beacause we need to find min len for storing  char we use freqarrayor unoreder map  all char first store in hash map then we chek in s first make needed varibles like min_len,then right  then left and count if count is equal to count of all char in t then we shrink it also make starting idex for return our substinf=g first we find our index uisng loop first and last then we return string in for loop or while loop we start looping first i check right char freq is postive if positive then this exist in t then we incremwnt count and then remove this right char beacause reptedly count not increse then we chek count is equal to our len of t then update minlen then update starting index then now try to srink this windo increment left in freq cy then check freq is postive when this is positive when our char is impotant char is drop out in windo then count-- and move left and after this incremnt right and lastly return our string 

- Positive freq → character still needed

- Zero freq → perfect count

- Negative freq → extra character

