const generateFibonacci=(n)=>{
    let fib=[0,1];

    if (n<=0){
        return "Please enter a positive number of terms: ";
    }
    else if(n===1){
        return [0];
    }
    else {
        for(let i=2;i<n;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib.slice(0,n);
    }
};

const terms=7;
const result=generateFibonacci(terms)


if(Array.isArray(result)){
    console.log(`Fibonacci series: ${result.join(",")}`);
}
else{
    console.log(result)
}
