//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/* Function to print an array */
function printArray(arr, size) {
  let i;
  let s = "";
  for (i = 0; i < size; i++) {
    s += arr[i] + " ";
  }
  console.log(s);
}

function main() {
  let t = parseInt(readLine());
  let i = 0;
  for (; i < t; i++) {
    let n = parseInt(readLine()); 
    let arr = new Array(n);
    let inputArr2 = readLine().split(" ").map((x) => parseInt(x));
    for(let j = 0;j < n;j++){
      arr[j] = inputArr2[j];
    }
    let obj = new Solution();
    let res = obj.minJumps(arr,n);
    console.log(res);
  }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 * @return {number}
 */ 
class Solution {
 
    find(arr,n)
    {
        let mxld=arr[0];
        let currmax=0;
        let ans=1; 
        for(let i=1;i<n-1;i++)
        {   

            currmax=Math.max(currmax,i+arr[i]);
            if(mxld==i)
            {

                // console.log(currmax) 
                mxld=currmax; 
                currmax=i+arr[i]; 
                
                ans++;
            }
                if(mxld<=i){
                   return -1;
                }
            
        }
        
        return ans; 
    }
    minJumps(arr,n){
        return this.find(arr,n);
    }
}                                  